#include <Arduboy2.h>
Arduboy2 arduboy;
Sprites sprites;

#include "src/images/Images.h"
#include "src/utils/Messages.h"
#include "src/utils/Utils.h"

void setup() {
  
    Serial.begin(9600);
 
    arduboy.begin();
    arduboy.setFrameRate(30);
    arduboy.clear();

    logConsole(msgSetup, newLine); // "Setup complete.\n"
    logArduboy(msgSetup);

    blitRace(); // Vroom!
}


void loop() {} // Blank


void blitRace(void) {

// Race the passes...
    testBaseline();     // CPU baseline
//  testMonopixel();    // Single pixel test
    test8x8Hero(true);  // 8x8 sprite, byte aligned
    test8x8Hero(false); // 8x8 sprite, byte unaligned
//  testBanner(true);   // Banner test
}
