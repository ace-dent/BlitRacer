#pragma once

#include <stdint.h>


// Global benchmarking variables
uint32_t benchStartTime, benchEndTime; // Unsigned long for millis()
float    benchResult, benchAverage, benchOverhead;


// Calculate the bench time, accumulates the running average and render the test screen
void benchmark(uint16_t loops, const char* testTitle = "", uint8_t testIteration = 0) {

    // Calculate benchmark time for an individual loop
    benchResult = ( (float)benchEndTime - (float)benchStartTime ) / ( (float)loops );
    benchResult *= 1000.0F; // Convert milli (10^-3) to micro (10^-6) seconds
    benchResult = benchResult - benchOverhead; // Remove overhead of 1 loop from results

    // Accumulate the running average
    benchAverage = benchAverage + benchResult;

    // Bonus: render the screen for the completed test
    if (testTitle != "") {
        arduboy.setCursor(0, HEIGHT - arduboy.getCharacterHeight());
        arduboy.print(reinterpret_cast<const __FlashStringHelper*>(testTitle));
        arduboy.setCursorX(WIDTH - arduboy.getCharacterWidth()-1);
        arduboy.print(testIteration);
    }
#ifdef TEST_FX_CHIP
    FX::display(CLEAR_BUFFER);
#else
    arduboy.display(CLEAR_BUFFER);
#endif
    delay(200);
}


void invertScreen (bool invert = false) {
    if (invert) {
        arduboy.fillScreen(WHITE);
        arduboy.setTextColor(BLACK);
        arduboy.setTextBackground(WHITE);
    } else {
        arduboy.fillScreen(BLACK);
        arduboy.setTextColor(WHITE);
        arduboy.setTextBackground(BLACK);
    }
    arduboy.invert(invert);
#ifdef TEST_FX_CHIP
    FX::display();
#else
    arduboy.display();
#endif
}


void fillScreenCandyCane(uint8_t offset, uint8_t color = WHITE) {
    if (offset < 2) {
        offset = 2;
    }
    for (uint16_t y = 0; y < (WIDTH*2); y+=offset) {
        arduboy.drawLine(y, 0, 0, y, color);
    }
}


// Maths utilities

int16_t divideAndRoundUp(int16_t numerator, int16_t denominator) {
    int16_t val = numerator / denominator;
    if((numerator % denominator) != 0) { // For any remainder, plus one
        val += 1;
    }
    return val;
}