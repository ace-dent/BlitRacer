#pragma once

#include <avr/pgmspace.h> // For PROGMEM


constexpr bool newLine = true;


// Print a string in program memory to the Arduboy screen
void logArduboy(const char* str, bool newline = false) {
    arduboy.setCursor(2,8);
    arduboy.print((__FlashStringHelper*)(str));
    if (newline) arduboy.print("\n");
    arduboy.display();
    delay(1000);
}

// Print a string in program memory to the serial console
void logConsole(const char* str, bool newline = false) {
    Serial.print((__FlashStringHelper*)(str));
    if (newline) Serial.print("\n");
    delay(50);
}


// Message text
const char PROGMEM msgSetup[]               = "Setup complete...\n";

const char PROGMEM msgBaselineTest[]        = "* CPU baseline test *\n";
const char PROGMEM msgFCPU[]                = "F_CPU = ";
const char PROGMEM msgHertz[]               = " Hz\n";
const char PROGMEM msgOneCycle[]            = "1 cycle             : ";
const char PROGMEM msgNop[]                 = "nop                 : ";
const char PROGMEM msgLoopOverhead[]        = "Loop overhead       : ";

const char PROGMEM msgMonopixTest[]         = "* Monopixel test    *\n";

const char PROGMEM msgHeroTest[]            = "* 8x8 'Hero' test   *\n";

const char PROGMEM msgBannerTest[]          = "* Banner test       *\n";


// Common text
const char PROGMEM msgBlank[]               = "";
const char PROGMEM msgTitleBreak[]          = "*********************\n\n";
const char PROGMEM msgHorizontalRule[]      = "---------------------\n\n";
const char PROGMEM msgMicros[]              = " µs\n";
const char PROGMEM msgTestAlign[]           = "   - Byte aligned\n";
const char PROGMEM msgTestUnalign[]         = "   - Byte unaligned\n";

const char PROGMEM msgSpritesOverwrite[]    = "Sprites Overwrite   : ";
const char PROGMEM msgSpritesErase[]        = "Sprites Erase       : ";
const char PROGMEM msgSpritesSelfMask[]     = "Sprites Self masked : ";
const char PROGMEM msgSpritesEraseMasked[]  = "Sprites Self w/mask : ";
const char PROGMEM msgSpritesExtMask[]      = "Sprites Ext' mask   : ";
const char PROGMEM msgSpritesPlusMask[]     = "Sprites Plus mask   : ";

const char PROGMEM msgBitmapsStd[]          = "Bitmaps Standard    : ";
const char PROGMEM msgBitmapsSlow[]         = "Bitmaps Slow XY     : ";
const char PROGMEM msgBitmapsComp[]         = "Bitmaps Compressed  : ";
const char PROGMEM msgBitmapsStdMasked[]    = "Bitmaps Std w/mask  : ";
const char PROGMEM msgBitmapsSlowMasked[]   = "Bitmaps Slow w/mask : ";
const char PROGMEM msgBitmapsCompMasked[]   = "Bitmaps Comp w/mask : ";
