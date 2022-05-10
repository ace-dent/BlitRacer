#pragma once

// Global benchmarking variables
uint32_t benchStartTime, benchEndTime; // Unsigned long for millis()
float    benchResult, benchAverage, benchOverhead;


void benchmark(uint16_t loops, bool render = true) {

    benchResult = ( (float)benchEndTime - (float)benchStartTime ) / ( (float)loops ); // Calculate benchmark time for an individual loop
    benchResult *= 1000.0F; // Convert milli (10^-3) to micro (10^-6) seconds
    benchResult = benchResult - benchOverhead; // Remove overhead of 1 loop from results

    benchAverage = benchAverage + benchResult;

    // Bonus: render the screen buffer
    if (render) {
        arduboy.display(CLEAR_BUFFER);
        delay(200);
    }
}


void invertScreen (bool invert = false) {
    if (invert) {
        arduboy.fillScreen(WHITE);
    } else {
        arduboy.fillScreen(BLACK);
    }
    arduboy.invert(invert);
    arduboy.display();
}