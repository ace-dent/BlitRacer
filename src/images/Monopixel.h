#pragma once

#include <stdint.h> // For uint8_t
#include <avr/pgmspace.h> // For PROGMEM


/*
 *  Smallest 1x1px image – the mighty, mini, mono pixel!
 *
 */



namespace images1x1 {

    constexpr uint8_t width = 1;
    constexpr uint8_t height = 1;


    namespace sprites {

        const uint8_t PROGMEM std[] = {
            images1x1::width, images1x1::height, // 1x1 px image
            0x01   // ▓▓▓▓▓▓▓░
        };

        const uint8_t PROGMEM mask[] = {
            // 1x1 px image
            0x01   // ▓▓▓▓▓▓▓░
        };

        const uint8_t PROGMEM eraseMask[] = {
            images1x1::width, images1x1::height, // 1x1 px image
            0x01   // ▓▓▓▓▓▓▓░
        };

        const uint8_t PROGMEM plusMask[] = {
            images1x1::width, images1x1::height, // 1x1 px image
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
            (images1x1::width-1), (images1x1::height-1), // 1x1 px image
            0xd3
        };

        const uint8_t PROGMEM cabiMask[] = {
            (images1x1::width-1), (images1x1::height-1), // 1x1 px image
            0xd3
        };
#endif

    }
}