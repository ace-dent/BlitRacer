#pragma once

#include <stdint.h> // For uint8_t
#include <avr/pgmspace.h> // For PROGMEM


/*
 *  Smallest 1x1px image – the mighty, mini, mono pixel!
 *
 */


constexpr uint8_t monopixWidth = 1;
constexpr uint8_t monopixHeight = 1;


namespace images1x1 {

    namespace sprites {

        const uint8_t PROGMEM std[] = {
            monopixWidth, monopixHeight, // 1x1 px image
            0x01   // ▓▓▓▓▓▓▓░
        };

        const uint8_t PROGMEM mask[] = {
            // 1x1 px image
            0x01   // ▓▓▓▓▓▓▓░
        };

        const uint8_t PROGMEM eraseMask[] = {
            monopixWidth, monopixHeight, // 1x1 px image
            0x01   // ▓▓▓▓▓▓▓░
        };

        const uint8_t PROGMEM plusMask[] = {
            monopixWidth, monopixHeight, // 1x1 px image
            0x01, 0x01   // ▓▓▓▓▓▓▓░ Image  ▓▓▓▓▓▓▓░ +Mask  ·······░ Sprite            
        };

    }

    namespace bitmaps {

        const uint8_t PROGMEM std[] = {
            // 1x1 px image
            0x01   // ▓▓▓▓▓▓▓░
        };

        const uint8_t PROGMEM stdMask[] = {
            // 1x1 px image
            0x01   // ▓▓▓▓▓▓▓░
        };

#ifdef TEST_SLOW_BITMAP
        const uint8_t PROGMEM slow[] = {
            // 1x1 px image
            0x80   // ░▓▓▓▓▓▓▓
        };

        const uint8_t PROGMEM slowMask[] = {
            // 1x1 px image
            0x80   // ░▓▓▓▓▓▓▓
        };
#endif

#ifdef TEST_COMPRESSED
        const uint8_t PROGMEM cabi[] = {
            (monopixWidth-1), (monopixHeight-1), // 1x1 px image
            0xd3
        };

        const uint8_t PROGMEM cabiMask[] = {
            (monopixWidth-1), (monopixHeight-1), // 1x1 px image
            0xd3
        };
#endif

    }
}