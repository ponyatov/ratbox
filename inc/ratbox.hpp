/// @file
/// @brief RatBox protocol processor (`ragel`)

#pragma once

#include <Arduino.hpp>
#include <stdint>

/// @defgroup config config

/// @brief device address header (@ref MAC)
/// @ingroup config
extern const uint8_t MAC[6];

/// @defgroup arduino Arduino
/// @brief `library`

/// @brief Arduino API object
/// @ingroup arduino
class RatBox {
   public:
    RatBox();
    ~RatBox();
};
