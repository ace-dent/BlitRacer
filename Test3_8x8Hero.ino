/* 
 *  Benchmark: 8x8 Hero
 */

void test8x8Hero(bool byteAligned) {

    uint8_t  i, xStep, yStep;       // Indices to control rendering loops
    int16_t  x, y, xStart, yStart;  // Image position for rendering loops
    uint32_t loopCount = 0;         // Keep large integer, as used for CPU baseline

    arduboy.clear();
    logArduboy(msgHeroTest);
    logConsole(msgHeroTest);            // "* 8x8 'Hero' test   *\n"
    if (byteAligned) {
        logConsole(msgTestAlign);       // "   - Byte aligned\n"
    } else {
        logConsole(msgTestUnalign);     // "   - Byte unaligned\n"
    }
    logConsole(msgTitleBreak);          // "*********************\n\n"
    arduboy.clear();

    xStart = -8;
    yStart = -8;
    if (byteAligned) {
        xStep = 8;
        yStep = 8;
    } else {
        xStep = 7;
        yStep = 7;  
    }

    // --- Sprites::drawOverwrite ---
    benchAverage = 0.0;
    for (i = 0; i < 3; i = i + 1) {
        loopCount = 0;
        benchStartTime = millis();
        for (y = yStart; y < HEIGHT; y = y + yStep) {
            for (x = xStart; x < WIDTH; x = x + xStep) {
                Sprites::drawOverwrite(x, y, images8x8::sprites::std, i);
                loopCount += 1;
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
        benchAverage = benchAverage + benchResult;
    }
    benchAverage /= 3.0;
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
                Sprites::drawErase(x, y, images8x8::sprites::std, i);
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
    benchAverage /= 3.0;
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
                Sprites::drawSelfMasked(x, y, images8x8::sprites::std, i);
                loopCount += 1;
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
        benchAverage = benchAverage + benchResult;
    }
    benchAverage /= 3.0;
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
                arduboy.drawBitmap(x, y, images8x8::bitmaps::std[i], kHeroWidth, kHeroHeight, WHITE);
                loopCount += 1;
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
        benchAverage = benchAverage + benchResult; // Update the running average
    }
    benchAverage /= 3.0;
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
                arduboy.drawSlowXYBitmap(x, y, images8x8::bitmaps::slow[i], kHeroWidth, kHeroHeight, WHITE);
                loopCount += 1;
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
        benchAverage = benchAverage + benchResult; // Update the running average
    }
    benchAverage /= 3.0;
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
                arduboy.drawCompressed(x, y, images8x8::bitmaps::cabi[i], WHITE);
                loopCount += 1;
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
        benchAverage = benchAverage + benchResult; // Update the running average
    }
    benchAverage /= 3.0;
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
                Sprites::drawExternalMask(x, y, images8x8::sprites::std, images8x8::sprites::mask, i, i);
                loopCount += 1;
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
        benchAverage = benchAverage + benchResult;
    }
    benchAverage /= 3.0;
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
                Sprites::drawPlusMask(x, y, images8x8::sprites::plusMask, i);
                loopCount += 1;
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
        benchAverage = benchAverage + benchResult; // Update the running average
    }
    benchAverage /= 3.0;
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
                Sprites::drawErase(x, y, images8x8::sprites::mask, i);
                Sprites::drawSelfMasked(x, y, images8x8::sprites::std, i);
                loopCount += 1;
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
        benchAverage = benchAverage + benchResult; // Update the running average
    }
    benchAverage /= 3.0;
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
                arduboy.drawBitmap(x, y, images8x8::bitmaps::stdMask[i], kHeroWidth, kHeroHeight, BLACK);
                arduboy.drawBitmap(x, y, images8x8::bitmaps::std[i], kHeroWidth, kHeroHeight, WHITE);
                loopCount += 1;
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
        benchAverage = benchAverage + benchResult; // Update the running average
    }
    benchAverage /= 3.0;
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
                arduboy.drawSlowXYBitmap(x, y, images8x8::bitmaps::slowMask[i], kHeroWidth, kHeroHeight, BLACK);
                arduboy.drawSlowXYBitmap(x, y, images8x8::bitmaps::slow[i], kHeroWidth, kHeroHeight, WHITE);
                loopCount += 1;
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
        benchAverage = benchAverage + benchResult; // Update the running average
    }
    benchAverage /= 3.0;
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
                arduboy.drawCompressed(x, y, images8x8::bitmaps::cabiMask[i], BLACK);
                arduboy.drawCompressed(x, y, images8x8::bitmaps::cabi[i], WHITE);
                loopCount += 1;
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
        benchAverage = benchAverage + benchResult; // Update the running average
    }
    benchAverage /= 3.0;
    logConsole(msgBitmapsCompMasked); // "Bitmaps Comp w/mask : "
    Serial.print(benchAverage,3);     // Result (3 d.p.)
    logConsole(msgMicros);            // " µs\n"
    
    
    logConsole(msgHorizontalRule);    // "---------------------\n\n"
    
}
