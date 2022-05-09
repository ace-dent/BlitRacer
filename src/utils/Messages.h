#pragma once

#include <avr/pgmspace.h> // For PROGMEM


constexpr bool newLine = true;


// Print a string from program memory to the Arduboy screen
void logArduboy(const char* str, bool carriageReturn = false) {
    arduboy.setCursor(2,8);
    arduboy.print((__FlashStringHelper*)(str));
    if (carriageReturn) arduboy.print(F("\n"));
    arduboy.display();
    delay(1000);
}

// Print a string from program memory to the serial console
void logConsole(const char* str, bool carriageReturn = false) {
    Serial.print((__FlashStringHelper*)(str));
    if (carriageReturn) Serial.print(F("\n"));
    delay(50);
}



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
    
    constexpr char PROGMEM spritesOverwrite[]   = "Sprites Overwrite   : ";
    constexpr char PROGMEM spritesErase[]       = "Sprites Erase       : ";
    constexpr char PROGMEM spritesSelfMask[]    = "Sprites Self masked : ";
    constexpr char PROGMEM spritesEraseMasked[] = "Sprites Self w/mask : ";
    constexpr char PROGMEM spritesExtMask[]     = "Sprites Ext' mask   : ";
    constexpr char PROGMEM spritesPlusMask[]    = "Sprites Plus mask   : ";

    constexpr char PROGMEM spritesBOverwrite[]  = "SpritesB Overwrite  : ";
    constexpr char PROGMEM spritesBErase[]      = "SpritesB Erase      : ";
    constexpr char PROGMEM spritesBSelfMask[]   = "SpritesB Self masked: ";
    constexpr char PROGMEM spritesBEraseMasked[]= "SpritesB Self w/mask: ";
    constexpr char PROGMEM spritesBExtMask[]    = "SpritesB Ext' mask  : ";
    constexpr char PROGMEM spritesBPlusMask[]   = "SpritesB Plus mask  : ";

    constexpr char PROGMEM bitmapsStd[]         = "Bitmaps Standard    : ";
    constexpr char PROGMEM bitmapsSlow[]        = "Bitmaps Slow XY     : ";
    constexpr char PROGMEM bitmapsComp[]        = "Bitmaps Compressed  : ";
    constexpr char PROGMEM bitmapsStdMasked[]   = "Bitmaps Std w/mask  : ";
    constexpr char PROGMEM bitmapsSlowMasked[]  = "Bitmaps Slow w/mask : ";
    constexpr char PROGMEM bitmapsCompMasked[]  = "Bitmaps Comp w/mask : ";

}