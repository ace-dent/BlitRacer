#define TEST_SPRITES_B
#define TEST_SLOW_BITMAP
#define TEST_COMPRESSED
// #define TEST_FX_CHIP

#include <Arduboy2.h>
Arduboy2 arduboy;

#ifdef TEST_FX_CHIP
#include <ArduboyFX.h>      // Access the FX external flash
#include "fxdata/fxdata.h"  // References to FX data
#endif

#include "src/images/Images.h"
#include "src/utils/Constants.h"
#include "src/utils/Messages.h"
#include "src/utils/Utils.h"


void setup() {

    Serial.begin(9600);
 
    arduboy.begin();
    arduboy.setFrameRate(30);
    arduboy.clear();

#ifdef TEST_FX_CHIP
    FX::begin(FX_DATA_PAGE); // Initialise FX chip
#endif

    logConsole(text::setup, newLine); // "Setup complete.\n"
    logArduboy(text::setup);

    blitRace(); // Start your engines!
}


void loop() {} // Blank


void blitRace() {

    // Race the passes...
    testBaseline();     // CPU baseline (always run first)
    testMonopixel();    // Single pixel test
    test8x8Hero(true);  // 8x8 sprite, byte aligned
    test8x8Hero(false); // 8x8 sprite, byte unaligned
    testBanner();       // Banner style image test
}
