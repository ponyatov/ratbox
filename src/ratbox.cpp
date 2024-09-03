#include "ratbox.hpp"

const uint8_t MAC[6] = {0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC};

#ifndef ARDUINO

int main(int argc, char *argv[]) {  //
    arg(0, argv[0]);
    for (int i = 1; i < argc; i++) {  //
        arg(i, argv[i]);
        RatBox *rb;
        assert(rb = new RatBox(argv[i]));
        rb->parse();
        delete rb;
    }
}

void arg(int argc, char argv[]) {  //
    fprintf(stderr, "argv[%i] = <%s>\n", argc, argv);
}

#endif

void RatBox::restart() {
    if (fin) {               // \ clean up files
        fclose(fin);         //
        fin = nullptr;       //
    }                        // /
    if (in) free(in);        // dealloc buffer memory
    p = pe = eof = nullptr;  // reset input pointer
}

RatBox::~RatBox() { restart(); }

RatBox::RatBox() { restart(); }

// RatBox::RatBox(const uint8_t mac[6]) : RatBox() { depricated with `ragel` }

#ifndef ARDUINO
/// @brief version with file system (semihosted)
RatBox::RatBox(char *binfile) {
    // open file
    assert(fin = fopen(binfile, "rb"));        // open file
    fseek(fin, 0, SEEK_END);                   // \ get size
    fsize = ftell(fin);                        // (size limited to one packet)
    rewind(fin);                               // /
    assert(fsize >= RatBox::PKG_MIN_LEN);      // \ check size
    assert(fsize <= RatBox::PKG_MAX_LEN);      // /
    if (in) free(in);                          // \ (re)alloc buffer
    assert(in = (uint8_t *)malloc(fsize));     // /
    assert(fsize = fread(in, 1, fsize, fin));  // read file
    p = in;                                    // \ set parser pointers
    pe = p + fsize;                            //
    eof = pe;                                  // /
    fclose(fin);                               // \ close file
    fin = nullptr;                             // /
    dump();
}
#endif

void RatBox::dump() {
    for (size_t t = 0; t < fsize; t++) {  //
        if (t % 0x10 == 0) printf("%.4X: ", t);
        if (t % 0x10 == 8) printf(" - ");
        printf("%.2X ", in[t]);
    }
    printf("\n");
}

void RatBox::token(const char *prefix) {
    printf("\t%s:\t", prefix);
    for (uint8_t *t = ts; t < te; t++) { printf("%.2X ", *t); }
    printf("\n");
}
