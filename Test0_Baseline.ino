/* 
 *  Benchmark: CPU baseline
 */

void testBaseline(void) {

    logArduboy(msgBaselineTest);
    logConsole(msgBaselineTest);      // "* CPU baseline test *\n"
    logConsole(msgTitleBreak);        // "*********************\n\n"
    logConsole(msgFCPU);              // "F_CPU = "
    Serial.print(F_CPU,DEC);          // 16000000 (expected)
    logConsole(msgHertz);             // " Hz\n"
    logConsole(msgOneCycle);          // "1 cycle             : "
    Serial.print((1000000.0/(float)F_CPU),4); // 0.0625 (625ns expected)
    logConsole(msgMicros);            // " µs\n"

    benchStartTime = millis();

    // Determine an indicative* overhead for 2x nested FOR loops
    // 100 x 10,000 (1M) loops are ~minimum for precision
    // * The rendering benchmarks have far less loops but we assume no affect on the overhead
    for (uint16_t a = 0; a < 100; a++) {
        for (uint16_t b = 0; b < 10000; b++) {
            // Uses NOP as a standard for 1 cycle
            // 20x instructions ~minimum for precision
            asm volatile ("nop");
            asm volatile ("nop");
            asm volatile ("nop");
            asm volatile ("nop");
            asm volatile ("nop");
            asm volatile ("nop");
            asm volatile ("nop");
            asm volatile ("nop");
            asm volatile ("nop");
            asm volatile ("nop");
            asm volatile ("nop");
            asm volatile ("nop");
            asm volatile ("nop");
            asm volatile ("nop");
            asm volatile ("nop");
            asm volatile ("nop");
            asm volatile ("nop");
            asm volatile ("nop");
            asm volatile ("nop");
            asm volatile ("nop");
        }
    }
    benchEndTime = millis();

    benchResult = ( (float)benchEndTime - (float)benchStartTime ) / (100.0 * 10000.0); // Calculate benchmark time for an individual loop
    benchResult = benchResult * 1000.0; // Convert milli (10^-3) to micro (10^-6) seconds
    benchOverhead = benchResult - (20.0 * (1000000.0/(float)F_CPU)); // Calculate overhead of nested FOR loops by subtracting 20x instruction cycles in microseconds
    benchResult = benchResult - benchOverhead; // Remove overhead from results
    benchResult = benchResult / 20.0; // Determine the result for an individual instruction

    logConsole(msgNop);               // "nop                 : "
    Serial.print(benchResult,4);      // ~0.0625 (625ns expected)
    logConsole(msgMicros);            // " µs\n"


    // Determine the overhead for incrementing a loop counter
    uint32_t loopCount = 0;
    for (uint16_t a = 0; a < 100; a++) {
        for (uint16_t b = 0; b < 10000; b++) {
            loopCount += 1;
        }
    }
    benchEndTime = millis();

    benchResult = ( (float)benchEndTime - (float)benchStartTime ) / (100.0 * 10000.0); // Calculate benchmark time for an individual loop
    benchResult = benchResult * 1000.0; // Convert milli (10^-3) to micro (10^-6) seconds
    benchResult = benchResult - benchOverhead; // Remove loop overhead from results
    benchOverhead += benchResult; // Include the time for incrementing the loop counter       

    logConsole(msgLoopOverhead);      // "Loop overhead       : "
    Serial.print(benchOverhead,4);    // ~1.6 (expected)
    logConsole(msgMicros);            // " µs\n"

    logConsole(msgHorizontalRule);    // "---------------------\n\n"
}
