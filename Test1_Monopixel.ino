/* 
 *  Benchmark: 1x1 Monopixel
 *  - Each blitting function is called 4x times, to help avoid compiler inlining.
 */

void testMonopixel() {

    uint8_t  i, xStep, yStep;       // Indices to control rendering loops
    int16_t  x, y, xStart, yStart;  // Image position for rendering loops
    uint32_t loopCount = 0;         // Keep large integer, as used for CPU baseline

    arduboy.clear();
    logArduboy(msgMonopixTest);
    logConsole(msgMonopixTest);         // "* Monopixel test    *\n"
    logConsole(msgTitleBreak);          // "*********************\n\n"
    arduboy.clear();

    xStart = 0;
    yStart = 0;
    xStep = 2;
    yStep = 8;  


    // --- Sprites::drawOverwrite ---
    benchAverage = 0.0;
    for (i = 0; i < 3; i = i + 1) {
        loopCount = 0;
        benchStartTime = millis();
        for (y = yStart; y < HEIGHT; y = y + yStep) {
            for (x = xStart; x < WIDTH; x = x + xStep) {
                Sprites::drawOverwrite(x, y, images1x1::sprites::std, 0);
                Sprites::drawOverwrite(x, y+2, images1x1::sprites::std, 0);
                Sprites::drawOverwrite(x, y+4, images1x1::sprites::std, 0);
                Sprites::drawOverwrite(x, y+6, images1x1::sprites::std, 0);
                loopCount += 1;
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
        benchAverage = benchAverage + benchResult;
    }
    benchAverage /= (4.0 * 3.0); // 4 function calls x 3 loops
    logConsole(msgSpritesOverwrite);  // "Sprites Overwrite   : "
    Serial.print(benchAverage,3);     // Result (3 d.p.)
    logConsole(msgMicros, newLine);   // " µs\n"
    
    
    // --- Sprites::drawErase ---
    benchAverage = 0.0;
    arduboy.fillScreen(WHITE); // Subtract the inverted sprite from 'white' screen
    arduboy.invert(true); // Invert the display for visual consistency
    arduboy.display();
    for (i = 0; i < 3; i = i + 1) {
        loopCount = 0;
        benchStartTime = millis();
        for (y = yStart; y < HEIGHT; y = y + yStep) {
            for (x = xStart; x < WIDTH; x = x + xStep) {
                Sprites::drawErase(x, y, images1x1::sprites::std, 0);
                Sprites::drawErase(x, y+2, images1x1::sprites::std, 0);
                Sprites::drawErase(x, y+4, images1x1::sprites::std, 0);
                Sprites::drawErase(x, y+6, images1x1::sprites::std, 0);
                loopCount += 1;
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
        benchAverage = benchAverage + benchResult;
        arduboy.fillScreen(WHITE); // Prepare 'white' screen for next loop
    }
    arduboy.fillScreen(BLACK); // Back to black to avoid white flash
    arduboy.invert(false); // Restore display
    arduboy.display();
    benchAverage /= (4.0 * 3.0); // 4 function calls x 3 loops
    logConsole(msgSpritesErase);  // "Sprites Erase       : "
    Serial.print(benchAverage,3);     // Result (3 d.p.)
    logConsole(msgMicros, newLine);            // " µs\n"
    
    
    // --- Sprites::drawSelfMasked ---
    benchAverage = 0.0;
    for (i = 0; i < 3; i = i + 1) {
        loopCount = 0;
        benchStartTime = millis();
        for (y = yStart; y < HEIGHT; y = y + yStep) {
            for (x = xStart; x < WIDTH; x = x + xStep) {
                Sprites::drawSelfMasked(x, y, images1x1::sprites::std, 0);
                Sprites::drawSelfMasked(x, y+2, images1x1::sprites::std, 0);
                Sprites::drawSelfMasked(x, y+4, images1x1::sprites::std, 0);
                Sprites::drawSelfMasked(x, y+6, images1x1::sprites::std, 0);
                loopCount += 1;
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
        benchAverage = benchAverage + benchResult;
    }
    benchAverage /= (4.0 * 3.0); // 4 function calls x 3 loops
    logConsole(msgSpritesSelfMask);  // "Sprites Self masked : "
    Serial.print(benchAverage,3);     // Result (3 d.p.)
    logConsole(msgMicros);            // " µs\n"
    
    
    // --- arduboy.drawBitmap ~ Sprites::drawSelfMasked ---
    benchAverage = 0.0;
    for (i = 0; i < 3; i = i + 1) {
        loopCount = 0;
        benchStartTime = millis();
        for (y = yStart; y < HEIGHT; y = y + yStep) {
            for (x = xStart; x < WIDTH; x = x + xStep) {
                arduboy.drawBitmap(x, y, images1x1::bitmaps::std, kMonopixWidth, kMonopixHeight, WHITE);
                arduboy.drawBitmap(x, y+2, images1x1::bitmaps::std, kMonopixWidth, kMonopixHeight, WHITE);
                arduboy.drawBitmap(x, y+4, images1x1::bitmaps::std, kMonopixWidth, kMonopixHeight, WHITE);
                arduboy.drawBitmap(x, y+6, images1x1::bitmaps::std, kMonopixWidth, kMonopixHeight, WHITE);
                loopCount += 1;
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
        benchAverage = benchAverage + benchResult; // Update the running average
    }
    benchAverage /= (4.0 * 3.0); // 4 function calls x 3 loops
    logConsole(msgBitmapsStd);        // "Bitmaps Standard    : "
    Serial.print(benchAverage,3);     // Result (3 d.p.)
    logConsole(msgMicros);            // " µs\n"
    
    
    // --- arduboy.drawSlowXYBitmap ~  Sprites::drawSelfMasked ---
    benchAverage = 0.0;
    for (i = 0; i < 3; i = i + 1) {
        loopCount = 0;
        benchStartTime = millis();
        for (y = yStart; y < HEIGHT; y = y + yStep) {
            for (x = xStart; x < WIDTH; x = x + xStep) {
                arduboy.drawSlowXYBitmap(x, y, images1x1::bitmaps::slow, kMonopixWidth, kMonopixHeight, WHITE);
                arduboy.drawSlowXYBitmap(x, y+2, images1x1::bitmaps::slow, kMonopixWidth, kMonopixHeight, WHITE);
                arduboy.drawSlowXYBitmap(x, y+4, images1x1::bitmaps::slow, kMonopixWidth, kMonopixHeight, WHITE);
                arduboy.drawSlowXYBitmap(x, y+6, images1x1::bitmaps::slow, kMonopixWidth, kMonopixHeight, WHITE);
                loopCount += 1;
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
        benchAverage = benchAverage + benchResult; // Update the running average
    }
    benchAverage /= (4.0 * 3.0); // 4 function calls x 3 loops
    logConsole(msgBitmapsSlow);       // "Bitmaps Slow XY     : "
    Serial.print(benchAverage,3);     // Result (3 d.p.)
    logConsole(msgMicros);            // " µs\n"
    
    
    // --- arduboy.drawCompressed ~  Sprites::drawSelfMasked ---
    benchAverage = 0.0;
    for (i = 0; i < 3; i = i + 1) {
        loopCount = 0;
        benchStartTime = millis();
        for (y = yStart; y < HEIGHT; y = y + yStep) {
            for (x = xStart; x < WIDTH; x = x + xStep) {
                arduboy.drawCompressed(x, y, images1x1::bitmaps::cabi, WHITE);
                arduboy.drawCompressed(x, y+2, images1x1::bitmaps::cabi, WHITE);
                arduboy.drawCompressed(x, y+4, images1x1::bitmaps::cabi, WHITE);
                arduboy.drawCompressed(x, y+6, images1x1::bitmaps::cabi, WHITE);
                loopCount += 1;
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
        benchAverage = benchAverage + benchResult; // Update the running average
    }
    benchAverage /= (4.0 * 3.0); // 4 function calls x 3 loops
    logConsole(msgBitmapsComp);       // "Bitmaps Compressed  : "
    Serial.print(benchAverage,3);     // Result (3 d.p.)
    logConsole(msgMicros, newLine);   // " µs\n"
    
    
    
    
    // --- Sprites::drawExternalMask ---
    benchAverage = 0.0;
    for (i = 0; i < 3; i = i + 1) {
        loopCount = 0;
        benchStartTime = millis();
        for (y = yStart; y < HEIGHT; y = y + yStep) {
            for (x = xStart; x < WIDTH; x = x + xStep) {
                Sprites::drawExternalMask(x, y, images1x1::sprites::std, images1x1::sprites::mask, 0, 0);
                Sprites::drawExternalMask(x, y+2, images1x1::sprites::std, images1x1::sprites::mask, 0, 0);
                Sprites::drawExternalMask(x, y+4, images1x1::sprites::std, images1x1::sprites::mask, 0, 0);
                Sprites::drawExternalMask(x, y+6, images1x1::sprites::std, images1x1::sprites::mask, 0, 0);
                loopCount += 1;
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
        benchAverage = benchAverage + benchResult;
    }
    benchAverage /= (4.0 * 3.0); // 4 function calls x 3 loops
    logConsole(msgSpritesExtMask);    // "Sprites Ext' mask   : "
    Serial.print(benchAverage,3);     // Result (3 d.p.)
    logConsole(msgMicros);            // " µs\n"
    
    
    // --- Sprites::drawPlusMask ---
    benchAverage = 0.0;
    for (i = 0; i < 3; i = i + 1) {
        loopCount = 0;
        benchStartTime = millis();
        for (y = yStart; y < HEIGHT; y = y + yStep) {
            for (x = xStart; x < WIDTH; x = x + xStep) {
                Sprites::drawPlusMask(x, y, images1x1::sprites::plusMask, 0);
                Sprites::drawPlusMask(x, y+2, images1x1::sprites::plusMask, 0);
                Sprites::drawPlusMask(x, y+4, images1x1::sprites::plusMask, 0);
                Sprites::drawPlusMask(x, y+6, images1x1::sprites::plusMask, 0);
                loopCount += 1;
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
        benchAverage = benchAverage + benchResult; // Update the running average
    }
    benchAverage /= (4.0 * 3.0); // 4 function calls x 3 loops
    logConsole(msgSpritesPlusMask);   // "Sprites Plus mask   : "
    Serial.print(benchAverage,3);     // Result (3 d.p.)
    logConsole(msgMicros);            // " µs\n"
    
    
    // --- Sprites::drawSelfMasked with extra masking step ---
    benchAverage = 0.0;
    for (i = 0; i < 3; i = i + 1) {
        loopCount = 0;
        benchStartTime = millis();
        for (y = yStart; y < HEIGHT; y = y + yStep) {
            for (x = xStart; x < WIDTH; x = x + xStep) {
                Sprites::drawErase(x, y, images1x1::sprites::mask, 0);
                Sprites::drawSelfMasked(x, y, images1x1::sprites::std, 0);
                Sprites::drawErase(x, y+2, images1x1::sprites::mask, 0);
                Sprites::drawSelfMasked(x, y+2, images1x1::sprites::std, 0);
                Sprites::drawErase(x, y+4, images1x1::sprites::mask, 0);
                Sprites::drawSelfMasked(x, y+4, images1x1::sprites::std, 0);
                Sprites::drawErase(x, y+6, images1x1::sprites::mask, 0);
                Sprites::drawSelfMasked(x, y+6, images1x1::sprites::std, 0);
                loopCount += 1;
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
        benchAverage = benchAverage + benchResult; // Update the running average
    }
    benchAverage /= (4.0 * 3.0); // 4 function calls x 3 loops
    logConsole(msgSpritesEraseMasked);// "Sprites Self w/mask : "
    Serial.print(benchAverage,3);     // Result (3 d.p.)
    logConsole(msgMicros);            // " µs\n"
    
    
    // --- arduboy.drawBitmap with extra masking step ---
    benchAverage = 0.0;
    for (i = 0; i < 3; i = i + 1) {
        loopCount = 0;
        benchStartTime = millis();
        for (y = yStart; y < HEIGHT; y = y + yStep) {
            for (x = xStart; x < WIDTH; x = x + xStep) {
                arduboy.drawBitmap(x, y, images1x1::bitmaps::stdMask, kMonopixWidth, kMonopixHeight, BLACK);
                arduboy.drawBitmap(x, y, images1x1::bitmaps::std, kMonopixWidth, kMonopixHeight, WHITE);
                arduboy.drawBitmap(x, y+2, images1x1::bitmaps::stdMask, kMonopixWidth, kMonopixHeight, BLACK);
                arduboy.drawBitmap(x, y+2, images1x1::bitmaps::std, kMonopixWidth, kMonopixHeight, WHITE);
                arduboy.drawBitmap(x, y+4, images1x1::bitmaps::stdMask, kMonopixWidth, kMonopixHeight, BLACK);
                arduboy.drawBitmap(x, y+4, images1x1::bitmaps::std, kMonopixWidth, kMonopixHeight, WHITE);
                arduboy.drawBitmap(x, y+6, images1x1::bitmaps::stdMask, kMonopixWidth, kMonopixHeight, BLACK);
                arduboy.drawBitmap(x, y+6, images1x1::bitmaps::std, kMonopixWidth, kMonopixHeight, WHITE);
                loopCount += 1;
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
        benchAverage = benchAverage + benchResult; // Update the running average
    }
    benchAverage /= (4.0 * 3.0); // 4 function calls x 3 loops
    logConsole(msgBitmapsStdMasked);  // "Bitmaps Std w/mask  : "
    Serial.print(benchAverage,3);     // Result (3 d.p.)
    logConsole(msgMicros);            // " µs\n"
    
    
    // --- arduboy.drawSlowXYBitmap with extra masking step ---
    benchAverage = 0.0;
    for (i = 0; i < 3; i = i + 1) {
        loopCount = 0;
        benchStartTime = millis();
        for (y = yStart; y < HEIGHT; y = y + yStep) {
            for (x = xStart; x < WIDTH; x = x + xStep) {
                arduboy.drawSlowXYBitmap(x, y, images1x1::bitmaps::slowMask, kMonopixWidth, kMonopixHeight, BLACK);
                arduboy.drawSlowXYBitmap(x, y, images1x1::bitmaps::slow, kMonopixWidth, kMonopixHeight, WHITE);
                arduboy.drawSlowXYBitmap(x, y+2, images1x1::bitmaps::slowMask, kMonopixWidth, kMonopixHeight, BLACK);
                arduboy.drawSlowXYBitmap(x, y+2, images1x1::bitmaps::slow, kMonopixWidth, kMonopixHeight, WHITE);
                arduboy.drawSlowXYBitmap(x, y+4, images1x1::bitmaps::slowMask, kMonopixWidth, kMonopixHeight, BLACK);
                arduboy.drawSlowXYBitmap(x, y+4, images1x1::bitmaps::slow, kMonopixWidth, kMonopixHeight, WHITE);
                arduboy.drawSlowXYBitmap(x, y+6, images1x1::bitmaps::slowMask, kMonopixWidth, kMonopixHeight, BLACK);
                arduboy.drawSlowXYBitmap(x, y+6, images1x1::bitmaps::slow, kMonopixWidth, kMonopixHeight, WHITE);
                loopCount += 1;
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
        benchAverage = benchAverage + benchResult; // Update the running average
    }
    benchAverage /= (4.0 * 3.0); // 4 function calls x 3 loops
    logConsole(msgBitmapsSlowMasked); // "Bitmaps Slow w/mask : "
    Serial.print(benchAverage,3);     // Result (3 d.p.)
    logConsole(msgMicros);            // " µs\n"
    
    
    // --- arduboy.drawCompressed with extra masking step ---
    benchAverage = 0.0;
    for (i = 0; i < 3; i = i + 1) {
        loopCount = 0;
        benchStartTime = millis();
        for (y = yStart; y < HEIGHT; y = y + yStep) {
            for (x = xStart; x < WIDTH; x = x + xStep) {
                arduboy.drawCompressed(x, y, images1x1::bitmaps::cabiMask, BLACK);
                arduboy.drawCompressed(x, y, images1x1::bitmaps::cabi, WHITE);
                arduboy.drawCompressed(x, y+2, images1x1::bitmaps::cabiMask, BLACK);
                arduboy.drawCompressed(x, y+2, images1x1::bitmaps::cabi, WHITE);
                arduboy.drawCompressed(x, y+4, images1x1::bitmaps::cabiMask, BLACK);
                arduboy.drawCompressed(x, y+4, images1x1::bitmaps::cabi, WHITE);
                arduboy.drawCompressed(x, y+6, images1x1::bitmaps::cabiMask, BLACK);
                arduboy.drawCompressed(x, y+6, images1x1::bitmaps::cabi, WHITE);
                loopCount += 1;
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
        benchAverage = benchAverage + benchResult; // Update the running average
    }
    benchAverage /= (4.0 * 3.0); // 4 function calls x 3 loops
    logConsole(msgBitmapsCompMasked); // "Bitmaps Comp w/mask : "
    Serial.print(benchAverage,3);     // Result (3 d.p.)
    logConsole(msgMicros);            // " µs\n"
    
    
    logConsole(msgHorizontalRule);    // "---------------------\n\n"
    
}
