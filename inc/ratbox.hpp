/// @file
/// @brief RatBox protocol processor (`ragel`)

#pragma once

#ifdef ARDUINO
#include <Arduino.hpp>
#else
#include <cstdlib>
#include <cstdio>
#endif
#include <cstdint>

/// @defgroup config config

/// @brief device address header (@ref MAC)
/// @ingroup config
extern const uint8_t MAC[6];

/// @defgroup arduino Arduino
/// @brief `library`

/// @defgroup host host
/// @brief on-host debug

extern int main(int argc, char *argv[]);
extern void arg(int argc, char argv[]);

/// @brief Arduino API object
/// @ingroup arduino
class RatBox {
   public:
    RatBox(const uint8_t mac[6] = MAC);
    ~RatBox();

    static const int PKG_MAX_LEN = 0x10;

   private:
    /// @brief maximal package length, bytes
    uint8_t buf[PKG_MAX_LEN];
};
