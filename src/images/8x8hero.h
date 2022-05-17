#pragma once

#include <stdint.h> // For uint8_t
#include <avr/pgmspace.h> // For PROGMEM


/*
 *  Typical 8x8px images used for a character sprite.
 *  3 frames of animation.
 *
 */


constexpr uint8_t heroWidth = 8;
constexpr uint8_t heroHeight = 8;

namespace images8x8 {

    namespace sprites {

        const uint8_t PROGMEM std[] = {
            heroWidth, heroHeight,  // 8x8 px images
            // Frame 0 - Hero jumping
            0x01,  // ▓▓▓▓▓▓▓░
            0x82,  // ░▓▓▓▓▓░▓
            0xC4,  // ░░▓▓▓░▓▓
            0x3B,  // ▓▓░░░▓░░
            0x3B,  // ▓▓░░░▓░░
            0xC4,  // ░░▓▓▓░▓▓
            0x82,  // ░▓▓▓▓▓░▓
            0x01,  // ▓▓▓▓▓▓▓░
            // Frame 1 - Hero standing
            0x10,  // ▓▓▓░▓▓▓▓
            0x88,  // ░▓▓▓░▓▓▓
            0xC4,  // ░░▓▓▓░▓▓
            0x3B,  // ▓▓░░░▓░░
            0x3B,  // ▓▓░░░▓░░
            0xC4,  // ░░▓▓▓░▓▓
            0x88,  // ░▓▓▓░▓▓▓
            0x10,  // ▓▓▓░▓▓▓▓
            // Frame 2 - Hero sitting
            0xC0,  // ░░▓▓▓▓▓▓
            0xA0,  // ░▓░▓▓▓▓▓
            0x90,  // ░▓▓░▓▓▓▓
            0xEC,  // ░░░▓░░▓▓
            0xEC,  // ░░░▓░░▓▓
            0x90,  // ░▓▓░▓▓▓▓
            0xA0,  // ░▓░▓▓▓▓▓
            0xC0   // ░░▓▓▓▓▓▓
        };

        const uint8_t PROGMEM mask[] = {
            // 8x8 px images
            // Frame 0 - Hero jumping (mask)
            0x01,  // ▓▓▓▓▓▓▓░
            0x82,  // ░▓▓▓▓▓░▓
            0xC4,  // ░░▓▓▓░▓▓
            0x3F,  // ▓▓░░░░░░
            0x3F,  // ▓▓░░░░░░
            0xC4,  // ░░▓▓▓░▓▓
            0x82,  // ░▓▓▓▓▓░▓
            0x01,  // ▓▓▓▓▓▓▓░
            // Frame 1 - Hero standing (mask)
            0x10,  // ▓▓▓░▓▓▓▓
            0x88,  // ░▓▓▓░▓▓▓
            0xC4,  // ░░▓▓▓░▓▓
            0x3F,  // ▓▓░░░░░░
            0x3F,  // ▓▓░░░░░░
            0xC4,  // ░░▓▓▓░▓▓
            0x88,  // ░▓▓▓░▓▓▓
            0x10,  // ▓▓▓░▓▓▓▓
            // Frame 2 - Hero sitting (mask)
            0xC0,  // ░░▓▓▓▓▓▓
            0xA0,  // ░▓░▓▓▓▓▓
            0x90,  // ░▓▓░▓▓▓▓
            0xFC,  // ░░░░░░▓▓
            0xFC,  // ░░░░░░▓▓
            0x90,  // ░▓▓░▓▓▓▓
            0xA0,  // ░▓░▓▓▓▓▓
            0xC0   // ░░▓▓▓▓▓▓
        };


        const uint8_t PROGMEM plusMask[] = {
            heroWidth, heroHeight,  // 8x8 px images
            // Frame 0 - Hero jumping
            0x01, 0x01,  // ▓▓▓▓▓▓▓░ Image  ▓▓▓▓▓▓▓░ +Mask  ·······░ Sprite
            0x82, 0x82,  // ░▓▓▓▓▓░▓        ░▓▓▓▓▓░▓        ░·····░·
            0xC4, 0xC4,  // ░░▓▓▓░▓▓        ░░▓▓▓░▓▓        ░░···░··
            0x3B, 0x3F,  // ▓▓░░░▓░░        ▓▓░░░░░░        ··░░░▓░░
            0x3B, 0x3F,  // ▓▓░░░▓░░        ▓▓░░░░░░        ··░░░▓░░
            0xC4, 0xC4,  // ░░▓▓▓░▓▓        ░░▓▓▓░▓▓        ░░···░··
            0x82, 0x82,  // ░▓▓▓▓▓░▓        ░▓▓▓▓▓░▓        ░·····░·
            0x01, 0x01,  // ▓▓▓▓▓▓▓░        ▓▓▓▓▓▓▓░        ·······░
            // Frame 1 - Hero standing
            0x10, 0x10,  // ▓▓▓░▓▓▓▓ Image  ▓▓▓░▓▓▓▓ +Mask  ···░···· Sprite
            0x88, 0x88,  // ░▓▓▓░▓▓▓        ░▓▓▓░▓▓▓        ░···░···
            0xC4, 0xC4,  // ░░▓▓▓░▓▓        ░░▓▓▓░▓▓        ░░···░··
            0x3B, 0x3F,  // ▓▓░░░▓░░        ▓▓░░░░░░        ··░░░▓░░
            0x3B, 0x3F,  // ▓▓░░░▓░░        ▓▓░░░░░░        ··░░░▓░░
            0xC4, 0xC4,  // ░░▓▓▓░▓▓        ░░▓▓▓░▓▓        ░░···░··
            0x88, 0x88,  // ░▓▓▓░▓▓▓        ░▓▓▓░▓▓▓        ░···░···
            0x10, 0x10,  // ▓▓▓░▓▓▓▓        ▓▓▓░▓▓▓▓        ···░····
            // Frame 2 - Hero sitting
            0xC0, 0xC0,  // ░░▓▓▓▓▓▓ Image  ░░▓▓▓▓▓▓ +Mask  ░░······ Sprite
            0xA0, 0xA0,  // ░▓░▓▓▓▓▓        ░▓░▓▓▓▓▓        ░·░·····
            0x90, 0x90,  // ░▓▓░▓▓▓▓        ░▓▓░▓▓▓▓        ░··░····
            0xEC, 0xFC,  // ░░░▓░░▓▓        ░░░░░░▓▓        ░░░▓░░··
            0xEC, 0xFC,  // ░░░▓░░▓▓        ░░░░░░▓▓        ░░░▓░░··
            0x90, 0x90,  // ░▓▓░▓▓▓▓        ░▓▓░▓▓▓▓        ░··░····
            0xA0, 0xA0,  // ░▓░▓▓▓▓▓        ░▓░▓▓▓▓▓        ░·░·····
            0xC0, 0xC0   // ░░▓▓▓▓▓▓        ░░▓▓▓▓▓▓        ░░······
        };

    }

    namespace bitmaps {

        const uint8_t* std[] = {
            &sprites::std[ (2+ (0*heroWidth)) ],
            &sprites::std[ (2+ (1*heroWidth)) ],
            &sprites::std[ (2+ (2*heroWidth)) ]
        };

        const uint8_t* stdMask[] = {
            &sprites::mask[ (2+ (0*heroWidth)) ],
            &sprites::mask[ (2+ (1*heroWidth)) ],
            &sprites::mask[ (2+ (2*heroWidth)) ]
        };


        const uint8_t PROGMEM slow0[] = {
            // 8x8 px image
            // Frame 0 - Hero jumping
            0x99,  // ░▓▓░░▓▓░
            0x5A,  // ▓░▓░░▓░▓
            0x24,  // ▓▓░▓▓░▓▓
            0x18,  // ▓▓▓░░▓▓▓
            0x18,  // ▓▓▓░░▓▓▓
            0x18,  // ▓▓▓░░▓▓▓
            0x24,  // ▓▓░▓▓░▓▓
            0x66   // ▓░░▓▓░░▓
        };
        const uint8_t PROGMEM slow1[] = {
            // 8x8 px image
            // Frame 1 - Hero standing
            0x18,  // ▓▓▓░░▓▓▓
            0x18,  // ▓▓▓░░▓▓▓
            0x24,  // ▓▓░▓▓░▓▓
            0x5A,  // ▓░▓░░▓░▓
            0x99,  // ░▓▓░░▓▓░
            0x18,  // ▓▓▓░░▓▓▓
            0x24,  // ▓▓░▓▓░▓▓
            0x66   // ▓░░▓▓░░▓
        };
        const uint8_t PROGMEM slow2[] = {
            // 8x8 px image
            // Frame 2 - Hero sitting
            0x00,  // ▓▓▓▓▓▓▓▓
            0x00,  // ▓▓▓▓▓▓▓▓
            0x18,  // ▓▓▓░░▓▓▓
            0x18,  // ▓▓▓░░▓▓▓
            0x24,  // ▓▓░▓▓░▓▓
            0x5A,  // ▓░▓░░▓░▓
            0x99,  // ░▓▓░░▓▓░
            0xFF   // ░░░░░░░░
        };
        const uint8_t* slow[] = {
            slow0,
            slow1,
            slow2
        };

        const uint8_t PROGMEM slow0Mask[] = {
            // 8x8 px image
            // Frame 0 - Hero jumping (mask)
            0x99,  // ░▓▓░░▓▓░
            0x5A,  // ▓░▓░░▓░▓
            0x3C,  // ▓▓░░░░▓▓
            0x18,  // ▓▓▓░░▓▓▓
            0x18,  // ▓▓▓░░▓▓▓
            0x18,  // ▓▓▓░░▓▓▓
            0x24,  // ▓▓░▓▓░▓▓
            0x66   // ▓░░▓▓░░▓
        };
        const uint8_t PROGMEM slow1Mask[] = {
            // 8x8 px image
            // Frame 1 - Hero standing (mask)
            0x18,  // ▓▓▓░░▓▓▓
            0x18,  // ▓▓▓░░▓▓▓
            0x3C,  // ▓▓░░░░▓▓
            0x5A,  // ▓░▓░░▓░▓
            0x99,  // ░▓▓░░▓▓░
            0x18,  // ▓▓▓░░▓▓▓
            0x24,  // ▓▓░▓▓░▓▓
            0x66   // ▓░░▓▓░░▓
        };
        const uint8_t PROGMEM slow2Mask[] = {
            // 8x8 px image
            // Frame 2 - Hero sitting (mask)
            0x00,  // ▓▓▓▓▓▓▓▓
            0x00,  // ▓▓▓▓▓▓▓▓
            0x18,  // ▓▓▓░░▓▓▓
            0x18,  // ▓▓▓░░▓▓▓
            0x3C,  // ▓▓░░░░▓▓
            0x5A,  // ▓░▓░░▓░▓
            0x99,  // ░▓▓░░▓▓░
            0xFF   // ░░░░░░░░
        };
        const uint8_t* slowMask[] = {
            slow0Mask,
            slow1Mask,
            slow2Mask
        };


        const uint8_t PROGMEM cabi0[] = {
            (heroWidth-1), (heroHeight-1),  // 8x8 px image
            // Frame 0 - Hero jumping
            0xF3, 0xC9, 0x4E, 0xB9, 0xD4, 0xA7, 0x5C, 0xEA, 0x92, 0x6B
        };
        const uint8_t PROGMEM cabi1[] = {
            (heroWidth-1), (heroHeight-1),  // 8x8 px image
            // Frame 1 - Hero standing
            0x5C, 0x36, 0xD5, 0x29, 0x97, 0xFA, 0x94, 0x4B, 0xAD, 0x52, 0xB9, 0x14
        };
        const uint8_t PROGMEM cabi2[] = {
            (heroWidth-1), (heroHeight-1),  // 8x8 px image
            // Frame 2 - Hero sitting
            0xEC, 0xB2, 0x72, 0xDD, 0xA7, 0x3E, 0xE5, 0x3A, 0x59, 0xD9, 0x01
        };
        const uint8_t* const cabi[] = {
            cabi0,
            cabi1,
            cabi2
        };

        const uint8_t PROGMEM cabi0Mask[] = {
            (heroWidth-1), (heroHeight-1),  // 8x8 px image
            // Frame 0 - Hero jumping (mask)
            0xF3, 0xC9, 0x4E, 0xF9, 0xAD, 0x4B, 0x5D, 0x72, 0x0D
        };
        const uint8_t PROGMEM cabi1Mask[] = {
            (heroWidth-1), (heroHeight-1),  // 8x8 px image
            // Frame 1 - Hero standing (mask)
            0x5C, 0x36, 0xD5, 0x29, 0xBF, 0x75, 0xA9, 0x55, 0x2A, 0x97, 0x02
        };
        const uint8_t PROGMEM cabi2Mask[] = {
            (heroWidth-1), (heroHeight-1),  // 8x8 px image
            // Frame 2 - Hero sitting (mask)
            0xEC, 0xB2, 0x72, 0xDD, 0x76, 0xEB, 0x3A, 0x59, 0xD9, 0x01
        };
        const uint8_t* const cabiMask[] = {
            cabi0Mask,
            cabi1Mask,
            cabi2Mask
        };

    }

}