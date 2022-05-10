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
    for (i = 0; i < 3; i = i + 1) {
    benchAverage = 0.0F; // Reset running average
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
    }
    logConsoleAveragedResult(text::spritesOverwrite, 3);


    // --- SpritesB::drawOverwrite ---
    for (i = 0; i < 3; i = i + 1) {
    benchAverage = 0.0F; // Reset running average
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
    }
    logConsoleAveragedResult(text::spritesBOverwrite, 3, newLine);

    /* --- */


    invertScreen(true); 


    // --- Sprites::drawErase ---
    for (i = 0; i < 3; i = i + 1) {
    benchAverage = 0.0F; // Reset running average
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
        arduboy.fillScreen(WHITE); // Clear to 'white' for next render
    }
    logConsoleAveragedResult(text::spritesErase, 3);


    invertScreen(false);



    // --- Sprites::drawSelfMasked ---
    for (i = 0; i < 3; i = i + 1) {
    benchAverage = 0.0F; // Reset running average
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
    }
    logConsoleAveragedResult(text::spritesSelfMask, 3);
    
    
    // --- arduboy.drawBitmap ~ Sprites::drawSelfMasked ---
    for (i = 0; i < 3; i = i + 1) {
    benchAverage = 0.0F; // Reset running average
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
        
    }
    logConsoleAveragedResult(text::bitmapsStd, 3);
    
    
    // --- arduboy.drawSlowXYBitmap ~  Sprites::drawSelfMasked ---
    for (i = 0; i < 3; i = i + 1) {
    benchAverage = 0.0F; // Reset running average
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
        
    }
    logConsoleAveragedResult(text::bitmapsSlow, 3);
    
    
    // --- arduboy.drawCompressed ~  Sprites::drawSelfMasked ---
    for (i = 0; i < 3; i = i + 1) {
    benchAverage = 0.0F; // Reset running average
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
        
    }
    logConsoleAveragedResult(text::bitmapsComp, 3, newLine);
    
    
    
    
    // --- Sprites::drawExternalMask ---
    for (i = 0; i < 3; i = i + 1) {
    benchAverage = 0.0F; // Reset running average
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
    }
    logConsoleAveragedResult(text::spritesExtMask, 3);
    
    
    // --- Sprites::drawPlusMask ---
    for (i = 0; i < 3; i = i + 1) {
    benchAverage = 0.0F; // Reset running average
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
        
    }
    logConsoleAveragedResult(text::spritesPlusMask, 3);
    
    
    // --- Sprites::drawSelfMasked with extra masking step ---
    for (i = 0; i < 3; i = i + 1) {
    benchAverage = 0.0F; // Reset running average
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
        
    }
    logConsoleAveragedResult(text::spritesEraseMasked, 3);
    
    
    // --- arduboy.drawBitmap with extra masking step ---
    for (i = 0; i < 3; i = i + 1) {
    benchAverage = 0.0F; // Reset running average
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
        
    }
    logConsoleAveragedResult(text::bitmapsStdMasked, 3);
    
    
    // --- arduboy.drawSlowXYBitmap with extra masking step ---
    for (i = 0; i < 3; i = i + 1) {
    benchAverage = 0.0F; // Reset running average
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
        
    }
    logConsoleAveragedResult(text::bitmapsSlowMasked, 3);
    
    
    // --- arduboy.drawCompressed with extra masking step ---
    for (i = 0; i < 3; i = i + 1) {
    benchAverage = 0.0F; // Reset running average
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
        
    }
    logConsoleAveragedResult(text::bitmapsCompMasked, 3);
    
    
    logConsole(text::horizontalRule);           // "---------------------\n\n"
    
}
