/* 
 *  Benchmark: 1x1 Monopixel
 *  - Each blitting function is called 4x times, to help avoid compiler inlining.
 */

void testMonopixel() {

    uint8_t  i, xStep, yStep;       // Indices to control rendering loops
    int16_t  x, y, xStart, yStart;  // Image position for rendering loops
    uint32_t loopCount = 0;         // Keep large integer, as used for CPU baseline

    arduboy.clear();
    logArduboy(text::monopixTest);
    logConsole(text::monopixTest);          // "* Monopixel test    *\n"
    logConsole(text::titleBreak);           // "*********************\n\n"
    arduboy.clear();

    xStart = 0;
    yStart = 0;
    xStep = 2;
    yStep = 8;  


    // --- Sprites::drawOverwrite ---
    benchAverage = (float)0;
    for (i = 0; i < 3; i = i + 1) {
        loopCount = 0;
        benchStartTime = millis();
        for (y = yStart; y < HEIGHT; y = y + yStep) {
            for (x = xStart; x < WIDTH; x = x + xStep) {
                Sprites::drawOverwrite(x, y, images1x1::sprites::std, 0);
                Sprites::drawOverwrite(x, y+2, images1x1::sprites::std, 0);
                Sprites::drawOverwrite(x, y+4, images1x1::sprites::std, 0);
                Sprites::drawOverwrite(x, y+6, images1x1::sprites::std, 0);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
        benchAverage = benchAverage + benchResult;
    }
    benchAverage /= ((float)4 * (float)3); // 4 function calls x 3 loops
    logConsole(text::spritesOverwrite);         // "Sprites Overwrite   : "
    Serial.print(benchAverage,3);               // Result (3 d.p.)
    logConsole(text::micros, newLine);          // " µs\n"

    // --- SpritesB::drawOverwrite ---
    benchAverage = (float)0;
    for (i = 0; i < 3; i = i + 1) {
        loopCount = 0;
        benchStartTime = millis();
        for (y = yStart; y < HEIGHT; y = y + yStep) {
            for (x = xStart; x < WIDTH; x = x + xStep) {
                SpritesB::drawOverwrite(x, y, images1x1::sprites::std, 0);
                SpritesB::drawOverwrite(x, y+2, images1x1::sprites::std, 0);
                SpritesB::drawOverwrite(x, y+4, images1x1::sprites::std, 0);
                SpritesB::drawOverwrite(x, y+6, images1x1::sprites::std, 0);
                loopCount += 1;
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
        benchAverage = benchAverage + benchResult;
    }
    benchAverage /= ((float)4 * (float)3); // 4 function calls x 3 loops
    logConsole(text::spritesBOverwrite);        // "Sprites Overwrite   : "
    Serial.print(benchAverage,3);               // Result (3 d.p.)
    logConsole(text::micros, newLine);          // " µs\n"


    /* --- */


    // --- Sprites::drawErase ---
    benchAverage = (float)0;
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
    benchAverage /= ((float)4 * (float)3); // 4 function calls x 3 loops
    logConsole(text::spritesErase);             // "Sprites Erase       : "
    Serial.print(benchAverage,3);               // Result (3 d.p.)
    logConsole(text::micros, newLine);          // " µs\n"
    
    
    // --- Sprites::drawSelfMasked ---
    benchAverage = (float)0;
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
    benchAverage /= ((float)4 * (float)3); // 4 function calls x 3 loops
    logConsole(text::spritesSelfMask);          // "Sprites Self masked : "
    Serial.print(benchAverage,3);               // Result (3 d.p.)
    logConsole(text::micros);                   // " µs\n"
    
    
    // --- arduboy.drawBitmap ~ Sprites::drawSelfMasked ---
    benchAverage = (float)0;
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
    benchAverage /= ((float)4 * (float)3); // 4 function calls x 3 loops
    logConsole(text::bitmapsStd);               // "Bitmaps Standard    : "
    Serial.print(benchAverage,3);               // Result (3 d.p.)
    logConsole(text::micros);                   // " µs\n"
    
    
    // --- arduboy.drawSlowXYBitmap ~  Sprites::drawSelfMasked ---
    benchAverage = (float)0;
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
    benchAverage /= ((float)4 * (float)3); // 4 function calls x 3 loops
    logConsole(text::bitmapsSlow);              // "Bitmaps Slow XY     : "
    Serial.print(benchAverage,3);               // Result (3 d.p.)
    logConsole(text::micros);                   // " µs\n"
    
    
    // --- arduboy.drawCompressed ~  Sprites::drawSelfMasked ---
    benchAverage = (float)0;
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
    benchAverage /= ((float)4 * (float)3); // 4 function calls x 3 loops
    logConsole(text::bitmapsComp);              // "Bitmaps Compressed  : "
    Serial.print(benchAverage,3);               // Result (3 d.p.)
    logConsole(text::micros, newLine);          // " µs\n"
    
    
    
    
    // --- Sprites::drawExternalMask ---
    benchAverage = (float)0;
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
    benchAverage /= ((float)4 * (float)3); // 4 function calls x 3 loops
    logConsole(text::spritesExtMask);           // "Sprites Ext' mask   : "
    Serial.print(benchAverage,3);               // Result (3 d.p.)
    logConsole(text::micros);                   // " µs\n"
    
    
    // --- Sprites::drawPlusMask ---
    benchAverage = (float)0;
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
    benchAverage /= ((float)4 * (float)3); // 4 function calls x 3 loops
    logConsole(text::spritesPlusMask);          // "Sprites Plus mask   : "
    Serial.print(benchAverage,3);               // Result (3 d.p.)
    logConsole(text::micros);                   // " µs\n"
    
    
    // --- Sprites::drawSelfMasked with extra masking step ---
    benchAverage = (float)0;
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
    benchAverage /= ((float)4 * (float)3); // 4 function calls x 3 loops
    logConsole(text::spritesEraseMasked);       // "Sprites Self w/mask : "
    Serial.print(benchAverage,3);               // Result (3 d.p.)
    logConsole(text::micros);                   // " µs\n"
    
    
    // --- arduboy.drawBitmap with extra masking step ---
    benchAverage = (float)0;
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
    benchAverage /= ((float)4 * (float)3); // 4 function calls x 3 loops
    logConsole(text::bitmapsStdMasked);         // "Bitmaps Std w/mask  : "
    Serial.print(benchAverage,3);               // Result (3 d.p.)
    logConsole(text::micros);                   // " µs\n"
    
    
    // --- arduboy.drawSlowXYBitmap with extra masking step ---
    benchAverage = (float)0;
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
    benchAverage /= ((float)4 * (float)3); // 4 function calls x 3 loops
    logConsole(text::bitmapsSlowMasked);        // "Bitmaps Slow w/mask : "
    Serial.print(benchAverage,3);               // Result (3 d.p.)
    logConsole(text::micros);                   // " µs\n"
    
    
    // --- arduboy.drawCompressed with extra masking step ---
    benchAverage = (float)0;
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
    benchAverage /= ((float)4 * (float)3); // 4 function calls x 3 loops
    logConsole(text::bitmapsCompMasked);        // "Bitmaps Comp w/mask : "
    Serial.print(benchAverage,3);               // Result (3 d.p.)
    logConsole(text::micros);                   // " µs\n"
    
    
    logConsole(text::horizontalRule);           // "---------------------\n\n"
    
}
