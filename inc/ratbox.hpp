/// @file
/// @brief RatBox protocol processor

#pragma once

#ifdef ARDUINO
#include <Arduino.hpp>
#else
#include <cstdlib>
#include <cstdio>
#endif
#include <cstdint>
#include <cassert>

/// @defgroup config config

/// @brief device address header (@ref MAC)
/// @ingroup config
extern const uint8_t MAC[6];

/// @defgroup arduino Arduino
/// @brief `library`

/// @defgroup host host
/// @brief on-host debug
/// @{

/// @brief program entry point
/// @param[in] argc number of command line arguments
/// @param[in] argv [program binary file + arguments]
extern int main(int argc, char *argv[]);

/// @brief print command line argument
/// @param[in] argc index
/// @param[in] argv value
extern void arg(int argc, char argv[]);

/// @}

/// @brief Arduino API object
/// @ingroup arduino
class RatBox {
   public:
    /// @name constructor

    /// @brief default constructor
    RatBox();
    // /// @brief depricated: @ref MAC hardened in `.ragel`
    // RatBox(const uint8_t mac[6]);  // = MAC);
    /// @brief constructor from binary file
    RatBox(char *binfile);
    /// @brief destructor
    ~RatBox();

    /// @name limits

    /// @brief minimal package length, bytes
    static const int PKG_MIN_LEN = 10;
    /// @brief maximal package length, bytes
    static const int PKG_MAX_LEN = 20;

    /// @name misc

    /// @brief restart & move to init state
    void restart();  // { inp=0; }

    /// @brief dump @ref in
    void dump();

   private:
    /// @name with file system
#ifndef ARDUINO

    /// @brief package input buffer
    /// (static or dynamic allocated with mmap)
    uint8_t *in;
    /// @brief input file handler
    FILE *fin;
    /// @brief size of loaded file
    size_t fsize;
#endif

    /// @name parser

    /// @brief input pointer (must be in @ref in `[0..max]`)
    /// @ingroup parser
    uint8_t *p;
    /// @brief end of message pointer (must be in @ref in `[0..max]`)
    /// @ingroup parser
    uint8_t *pe;
    /// @brief current state in parser state machine
    /// @ingroup parser
    uint8_t cs;
    /// @brief token start
    /// @ingroup parser
    uint8_t *ts;
    /// @brief token end
    /// @ingroup parser
    uint8_t *te;
    /// @ingroup parser
    uint8_t *act;
    /// @brief end-of-file pointer = @ref pe
    /// @ingroup parser
    uint8_t *eof;
    /// @brief dump parsed token as hexes
    /// @param[in] prefix `prefix:`
    /// @ingroup parser
    void token(const char *prefix);

   public:
    /// @brief parse prepared packet ( @ref p / @ref pe must be preloaded)
    /// @param[in] *p @ref p packet start
    /// @param[in] *pe @ref pe packet end
    /// @ingroup parser
    void parse();
};
