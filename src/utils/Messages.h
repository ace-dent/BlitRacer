#pragma once

#include <avr/pgmspace.h> // For PROGMEM


constexpr bool newLine = true;


// Print a string from program memory to the Arduboy screen
void logArduboy(const char* str, bool newline = false) {
    arduboy.setCursor(2,8);
    arduboy.print((__FlashStringHelper*)(str));
    if (newline) arduboy.print(F("\n"));
    arduboy.display();
    delay(1000);
}

// Print a string from program memory to the serial console
void logConsole(const char* str, bool newline = false) {
    Serial.print((__FlashStringHelper*)(str));
    if (newline) Serial.print(F("\n"));
    delay(50);
}


// Message text
constexpr char PROGMEM msgSetup[]               = "Setup complete...\n";

constexpr char PROGMEM msgBaselineTest[]        = "* CPU baseline test *\n";
constexpr char PROGMEM msgFCPU[]                = "F_CPU = ";
constexpr char PROGMEM msgHertz[]               = " Hz\n";
constexpr char PROGMEM msgOneCycle[]            = "1 cycle             : ";
constexpr char PROGMEM msgNop[]                 = "nop                 : ";
constexpr char PROGMEM msgLoopOverhead[]        = "Loop overhead       : ";

constexpr char PROGMEM msgMonopixTest[]         = "* Monopixel test    *\n";
constexpr char PROGMEM msgHeroTest[]            = "* 8x8 'Hero' test   *\n";
constexpr char PROGMEM msgBannerTest[]          = "* Banner test       *\n";


// Common text
constexpr char PROGMEM msgBlank[]               = "";
constexpr char PROGMEM msgTitleBreak[]          = "*********************\n\n";
constexpr char PROGMEM msgHorizontalRule[]      = "---------------------\n\n";
constexpr char PROGMEM msgMicros[]              = " µs\n";
constexpr char PROGMEM msgTestAlign[]           = "   - Byte aligned\n";
constexpr char PROGMEM msgTestUnalign[]         = "   - Byte unaligned\n";

constexpr char PROGMEM msgSpritesOverwrite[]    = "Sprites Overwrite   : ";
constexpr char PROGMEM msgSpritesErase[]        = "Sprites Erase       : ";
constexpr char PROGMEM msgSpritesSelfMask[]     = "Sprites Self masked : ";
constexpr char PROGMEM msgSpritesEraseMasked[]  = "Sprites Self w/mask : ";
constexpr char PROGMEM msgSpritesExtMask[]      = "Sprites Ext' mask   : ";
constexpr char PROGMEM msgSpritesPlusMask[]     = "Sprites Plus mask   : ";

constexpr char PROGMEM msgBitmapsStd[]          = "Bitmaps Standard    : ";
constexpr char PROGMEM msgBitmapsSlow[]         = "Bitmaps Slow XY     : ";
constexpr char PROGMEM msgBitmapsComp[]         = "Bitmaps Compressed  : ";
constexpr char PROGMEM msgBitmapsStdMasked[]    = "Bitmaps Std w/mask  : ";
constexpr char PROGMEM msgBitmapsSlowMasked[]   = "Bitmaps Slow w/mask : ";
constexpr char PROGMEM msgBitmapsCompMasked[]   = "Bitmaps Comp w/mask : ";
