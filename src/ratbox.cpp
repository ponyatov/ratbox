#include "ratbox.hpp"

const uint8_t MAC[6] = {0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC};

#ifndef ARDUINO

int main(int argc, char *argv[]) {  //
    arg(0, argv[0]);
    for (int i = 1; i < argc; i++) {  //
        arg(i, argv[i]);
    }
}

void arg(int argc, char argv[]) {  //
    fprintf(stderr, "argv[%i] = <%s>\n", argc, argv);
}

#endif
