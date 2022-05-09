/* 
 *  Benchmark: 8x8 Hero
 */

void test8x8Hero(bool byteAligned) {

    uint8_t  i, xStep, yStep;       // Indices to control rendering loops
    int16_t  x, y, xStart, yStart;  // Image position for rendering loops
    uint32_t loopCount = 0;         // Keep large integer, as used for CPU baseline

    arduboy.clear();
    logArduboy(text::heroTest);
    logConsole(text::heroTest);                 // "* 8x8 'Hero' test   *\n"
    if (byteAligned) {
        logConsole(text::byteAlign);            // "   - Byte aligned\n"
    } else {
        logConsole(text::byteUnalign);          // "   - Byte unaligned\n"
    }
    logConsole(text::titleBreak);               // "*********************\n\n"
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
    benchAverage = (float)0;
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
    benchAverage /= (float)3;
    logConsole(text::spritesOverwrite);         // "Sprites Overwrite   : "
    Serial.print(benchAverage,3);               // Result (3 d.p.)
    logConsole(text::micros);                   // " µs\n"


    // --- SpritesB::drawOverwrite ---
    benchAverage = (float)0;
    for (i = 0; i < 3; i = i + 1) {
        loopCount = 0;
        benchStartTime = millis();
        for (y = yStart; y < HEIGHT; y = y + yStep) {
            for (x = xStart; x < WIDTH; x = x + xStep) {
                SpritesB::drawOverwrite(x, y, images8x8::sprites::std, i);
                loopCount += 1;
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
        benchAverage = benchAverage + benchResult;
    }
    benchAverage /= (float)3;
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
    benchAverage /= (float)3;
    logConsole(text::spritesErase);              // "Sprites Erase       : "
    Serial.print(benchAverage,3);               // Result (3 d.p.)
    logConsole(text::micros, newLine);          // " µs\n"
    
    
    // --- Sprites::drawSelfMasked ---
    benchAverage = (float)0;
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
    benchAverage /= (float)3;
    logConsole(text::spritesSelfMask);           // "Sprites Self masked : "
    Serial.print(benchAverage,3);               // Result (3 d.p.)
    logConsole(text::micros);                   // " µs\n"
    
    
    // --- arduboy.drawBitmap ~ Sprites::drawSelfMasked ---
    benchAverage = (float)0;
    for (i = 0; i < 3; i = i + 1) {
        loopCount = 0;
        benchStartTime = millis();
        for (y = yStart; y < HEIGHT; y = y + yStep) {
            for (x = xStart; x < WIDTH; x = x + xStep) {
                arduboy.drawBitmap(x, y, images8x8::bitmaps::std[i], heroWidth, heroHeight, WHITE);
                loopCount += 1;
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
        benchAverage = benchAverage + benchResult; // Update the running average
    }
    benchAverage /= (float)3;
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
                arduboy.drawSlowXYBitmap(x, y, images8x8::bitmaps::slow[i], heroWidth, heroHeight, WHITE);
                loopCount += 1;
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
        benchAverage = benchAverage + benchResult; // Update the running average
    }
    benchAverage /= (float)3;
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
                arduboy.drawCompressed(x, y, images8x8::bitmaps::cabi[i], WHITE);
                loopCount += 1;
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
        benchAverage = benchAverage + benchResult; // Update the running average
    }
    benchAverage /= (float)3;
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
                Sprites::drawExternalMask(x, y, images8x8::sprites::std, images8x8::sprites::mask, i, i);
                loopCount += 1;
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
        benchAverage = benchAverage + benchResult;
    }
    benchAverage /= (float)3;
    logConsole(text::spritesExtMask);            // "Sprites Ext' mask   : "
    Serial.print(benchAverage,3);               // Result (3 d.p.)
    logConsole(text::micros);                   // " µs\n"
    
    
    // --- Sprites::drawPlusMask ---
    benchAverage = (float)0;
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
    benchAverage /= (float)3;
    logConsole(text::spritesPlusMask);           // "Sprites Plus mask   : "
    Serial.print(benchAverage,3);               // Result (3 d.p.)
    logConsole(text::micros);                       // " µs\n"
    
    
    // --- Sprites::drawSelfMasked with extra masking step ---
    benchAverage = (float)0;
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
    benchAverage /= (float)3;
    logConsole(text::spritesEraseMasked);        // "Sprites Self w/mask : "
    Serial.print(benchAverage,3);               // Result (3 d.p.)
    logConsole(text::micros);                   // " µs\n"
    
    
    // --- arduboy.drawBitmap with extra masking step ---
    benchAverage = (float)0;
    for (i = 0; i < 3; i = i + 1) {
        loopCount = 0;
        benchStartTime = millis();
        for (y = yStart; y < HEIGHT; y = y + yStep) {
            for (x = xStart; x < WIDTH; x = x + xStep) {
                arduboy.drawBitmap(x, y, images8x8::bitmaps::stdMask[i], heroWidth, heroHeight, BLACK);
                arduboy.drawBitmap(x, y, images8x8::bitmaps::std[i], heroWidth, heroHeight, WHITE);
                loopCount += 1;
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
        benchAverage = benchAverage + benchResult; // Update the running average
    }
    benchAverage /= (float)3;
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
                arduboy.drawSlowXYBitmap(x, y, images8x8::bitmaps::slowMask[i], heroWidth, heroHeight, BLACK);
                arduboy.drawSlowXYBitmap(x, y, images8x8::bitmaps::slow[i], heroWidth, heroHeight, WHITE);
                loopCount += 1;
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
        benchAverage = benchAverage + benchResult; // Update the running average
    }
    benchAverage /= (float)3;
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
                arduboy.drawCompressed(x, y, images8x8::bitmaps::cabiMask[i], BLACK);
                arduboy.drawCompressed(x, y, images8x8::bitmaps::cabi[i], WHITE);
                loopCount += 1;
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
        benchAverage = benchAverage + benchResult; // Update the running average
    }
    benchAverage /= (float)3;
    logConsole(text::bitmapsCompMasked);        // "Bitmaps Comp w/mask : "
    Serial.print(benchAverage,3);               // Result (3 d.p.)
    logConsole(text::micros);                   // " µs\n"
    
    
    logConsole(text::horizontalRule);           // "---------------------\n\n"
    
}
