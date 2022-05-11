#include <Arduboy2.h>
#include <ArduboyFX.h>
Arduboy2 arduboy;

#include "src/images/Images.h"
#include "src/utils/Messages.h"
#include "src/utils/Utils.h"
#include "fxdata/fxdata.h"


void setup() {
  
    Serial.begin(9600);
 
    arduboy.begin();
    arduboy.setFrameRate(30);
    arduboy.clear();

    logConsole(text::setup, newLine); // "Setup complete.\n"
    logArduboy(text::setup);

    blitRace(); // Start your engines!
}


void loop() {} // Blank


void blitRace() {

// Race the passes...
    testBaseline();     // CPU baseline
    testMonopixel();    // Single pixel test
    test8x8Hero(true);  // 8x8 sprite, byte aligned
    test8x8Hero(false); // 8x8 sprite, byte unaligned
//  testBanner(true);   // Banner test
}
