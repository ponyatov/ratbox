#include "ratbox.hpp"

const uint8_t MAC[6] = {0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC};

#ifndef ARDUINO

int main(int argc, char *argv[]) {  //
    arg(0, argv[0]);
    for (int i = 1; i < argc; i++) {  //
        arg(i, argv[i]);
        RatBox *rb;
        assert(rb = new RatBox(argv[i]));
        delete rb;
    }
}

void arg(int argc, char argv[]) {  //
    fprintf(stderr, "argv[%i] = <%s>\n", argc, argv);
}

#endif

void RatBox::restart() {
    inp = 0;
    if (fin) {
        fclose(fin);
        fin = nullptr;
    }
}

RatBox::~RatBox() { restart(); }

RatBox::RatBox() { restart(); }

// RatBox::RatBox(const uint8_t mac[6]) : RatBox() { depricated with `ragel` }

RatBox::RatBox(char *binfile) { assert(fin = fopen(binfile, "rb")); }
