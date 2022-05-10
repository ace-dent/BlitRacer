#pragma once

#include <stdint.h>
#include <avr/pgmspace.h> // For PROGMEM
#include "Utils.h"


constexpr bool newLine = true;


namespace text {

    constexpr char PROGMEM setup[]              = "Setup complete...\n";
    
    constexpr char PROGMEM baselineTest[]       = "* CPU baseline test *\n";
    constexpr char PROGMEM FCPU[]               = "F_CPU = ";
    constexpr char PROGMEM hertz[]              = " Hz\n";
    constexpr char PROGMEM oneCycle[]           = "1 cycle             : ";
    constexpr char PROGMEM nop[]                = "nop                 : ";
    constexpr char PROGMEM loopOverhead[]       = "Loop overhead       : ";
    
    constexpr char PROGMEM monopixTest[]        = "* Monopixel test    *\n";
    constexpr char PROGMEM heroTest[]           = "* 8x8 'Hero' test   *\n";
    constexpr char PROGMEM bannerTest[]         = "* Banner test       *\n";
    
    
    // Common text
    constexpr char PROGMEM blank[]              = "";
    constexpr char PROGMEM titleBreak[]         = "*********************\n\n";
    constexpr char PROGMEM horizontalRule[]     = "---------------------\n\n";
    constexpr char PROGMEM micros[]             = " µs\n";
    constexpr char PROGMEM byteAlign[]          = "   - Byte aligned\n";
    constexpr char PROGMEM byteUnalign[]        = "   - Byte unaligned\n";

    // Sprites functions
    constexpr char PROGMEM spritesOverwrite[]   = "Sprites Overwrite   : ";
    constexpr char PROGMEM spritesErase[]       = "Sprites Erase       : ";
    constexpr char PROGMEM spritesSelfMask[]    = "Sprites Self masked : ";
    constexpr char PROGMEM spritesEraseMasked[] = "Sprites Self w/mask : ";
    constexpr char PROGMEM spritesExtMask[]     = "Sprites Ext' mask   : ";
    constexpr char PROGMEM spritesPlusMask[]    = "Sprites Plus mask   : ";

    // Arduboy bitmap functions
    constexpr char PROGMEM bitmapsStd[]         = "Bitmaps Standard    : ";
    constexpr char PROGMEM bitmapsSlow[]        = "Bitmaps Slow XY     : ";
    constexpr char PROGMEM bitmapsComp[]        = "Bitmaps Compressed  : ";
    constexpr char PROGMEM bitmapsStdMasked[]   = "Bitmaps Std w/mask  : ";
    constexpr char PROGMEM bitmapsSlowMasked[]  = "Bitmaps Slow w/mask : ";
    constexpr char PROGMEM bitmapsCompMasked[]  = "Bitmaps Comp w/mask : ";

#ifdef TEST_SPRITES_B
    // SpritesB functions
    constexpr char PROGMEM spritesBOverwrite[]  = "SpritesB Overwrite  : ";
    constexpr char PROGMEM spritesBErase[]      = "SpritesB Erase      : ";
    constexpr char PROGMEM spritesBSelfMask[]   = "SpritesB Self masked: ";
    constexpr char PROGMEM spritesBEraseMasked[]= "SpritesB Self w/mask: ";
    constexpr char PROGMEM spritesBExtMask[]    = "SpritesB Ext' mask  : ";
    constexpr char PROGMEM spritesBPlusMask[]   = "SpritesB Plus mask  : ";
#endif

#ifdef TEST_FXDBM
    // FX draw bitmap functions
    constexpr char PROGMEM fxDbmOverwrite[]     = "FX dbm Overwrite    : ";
    constexpr char PROGMEM fxDbmReverse[]       = "FX dbm Reverse      : ";
    constexpr char PROGMEM fxDbmBlack[]         = "FX dbm Black        : ";
    constexpr char PROGMEM fxDbmWhite[]         = "FX dbm White        : ";
    constexpr char PROGMEM fxDbmMasked[]        = "FX dbm Masked       : ";
    constexpr char PROGMEM fxDbmWhiteMasked[]   = "FX dbm White w/mask : ";
//  constexpr char PROGMEM fxDbmInvert[]        = "FX dbm Invert       : ";
#endif
}


// Print a string from program memory to the Arduboy screen
void logArduboy(const char* str, bool lineFeed = false) {
    arduboy.setCursor(2,8);
    arduboy.print(reinterpret_cast<const __FlashStringHelper*>(str));
    if (lineFeed) arduboy.print(F("\n"));
    arduboy.display();
    delay(1000);
}


// Print a string from program memory to the serial console
void logConsole(const char* str, bool lineFeed = false) {
    Serial.print(reinterpret_cast<const __FlashStringHelper*>(str));
    if (lineFeed) Serial.print(F("\n"));
    delay(50);
}

// Determine and print the average test result to the serial console
void logConsoleAveragedResult(const char* str, uint8_t sampleCount, bool lineFeed = false) {
    benchAverage /= (float)sampleCount;
    logConsole(str);                            // Function tested
    Serial.print(benchAverage,3);               // Result (3 d.p.)
    logConsole(text::micros);                   // " µs\n"
    if (lineFeed) logConsole(text::blank, newLine);
}