#pragma once

// Global benchmarking variables
uint32_t benchStartTime, benchEndTime; // Unsigned long for millis()
float    benchResult, benchAverage, benchOverhead;


void benchmark(uint16_t loops) {

    benchResult = ( (float)benchEndTime - (float)benchStartTime ) / ( (float)loops ); // Calculate benchmark time for an individual loop
    benchResult = benchResult * (float)1000; // Convert milli (10^-3) to micro (10^-6) seconds
    benchResult = benchResult - benchOverhead; // Remove overhead of 1 loop and loop counter, from results

    // Bonus: render the screen buffer
    arduboy.display(CLEAR_BUFFER);
    delay(200);
}