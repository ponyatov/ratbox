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
    RatBox(const uint8_t mac[6] = MAC);
    ~RatBox();

    /// @brief minimal package length, bytes
    static const int PKG_MIN_LEN = 10;
    /// @brief maximal package length, bytes
    static const int PKG_MAX_LEN = 20;

   private:
    /// @brief package input buffer
    uint8_t in[PKG_MAX_LEN];
};
