#pragma once

/*
 *  Smallest 1x1px image – the mighty, mini, mono pixel!
 *
 */

#include <stdint.h> // For uint8_t
#include <avr/pgmspace.h> // For PROGMEM


constexpr uint8_t kMonopixWidth = 1;
constexpr uint8_t kMonopixHeight = 1;


namespace images1x1 {

    namespace sprites {

        const uint8_t PROGMEM std[] = {
            kMonopixWidth, kMonopixHeight, // 1x1 px image
            0x01   // ▓▓▓▓▓▓▓░
        };

        const uint8_t PROGMEM mask[] = {
            kMonopixWidth, kMonopixHeight, // 1x1 px image
            0x01   // ▓▓▓▓▓▓▓░
        };

        const uint8_t PROGMEM plusMask[] = {
            kMonopixWidth, kMonopixHeight, // 1x1 px image
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

        const uint8_t PROGMEM slow[] = {
            // 1x1 px image
            0x80   // ░▓▓▓▓▓▓▓
        };

        const uint8_t PROGMEM slowMask[] = {
            // 1x1 px image
            0x80   // ░▓▓▓▓▓▓▓
        };

        const uint8_t PROGMEM cabi[] = {
            (kMonopixWidth-1), (kMonopixHeight-1), // 1x1 px image
            0xd3
        };

        const uint8_t PROGMEM cabiMask[] = {
            (kMonopixWidth-1), (kMonopixHeight-1), // 1x1 px image
            0xd3
        };

    }
}