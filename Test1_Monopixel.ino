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
    for (i = 0; i < 3; i = i + 1) {
        loopCount = 0;
    benchAverage = 0.0F;
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
    logConsoleAveragedResult(text::spritesOverwrite, (4*3)); // 4 blitter op's x 3 loops

    // --- SpritesB::drawOverwrite ---
    for (i = 0; i < 3; i = i + 1) {
        loopCount = 0;
    benchAverage = 0.0F;
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
    logConsoleAveragedResult(text::spritesBOverwrite, (4*3)); // 4 blitter op's x 3 loops


    /* --- */

    
    invertScreen(true); 
    


    // --- Sprites::drawErase ---
    for (i = 0; i < 3; i = i + 1) {
        loopCount = 0;
    benchAverage = 0.0F;
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
    logConsoleAveragedResult(text::spritesErase, (4*3)); // 4 blitter op's x 3 loops
    
    
    invertScreen(false); 
    

    
    // --- Sprites::drawSelfMasked ---
    for (i = 0; i < 3; i = i + 1) {
        loopCount = 0;
    benchAverage = 0.0F;
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
    logConsoleAveragedResult(text::spritesSelfMask, (4*3)); // 4 blitter op's x 3 loops
    
    
    // --- arduboy.drawBitmap ~ Sprites::drawSelfMasked ---
    for (i = 0; i < 3; i = i + 1) {
        loopCount = 0;
    benchAverage = 0.0F;
        benchStartTime = millis();
        for (y = yStart; y < HEIGHT; y = y + yStep) {
            for (x = xStart; x < WIDTH; x = x + xStep) {
                arduboy.drawBitmap(x, y, images1x1::bitmaps::std, monopixWidth, monopixHeight, WHITE);
                arduboy.drawBitmap(x, y+2, images1x1::bitmaps::std, monopixWidth, monopixHeight, WHITE);
                arduboy.drawBitmap(x, y+4, images1x1::bitmaps::std, monopixWidth, monopixHeight, WHITE);
                arduboy.drawBitmap(x, y+6, images1x1::bitmaps::std, monopixWidth, monopixHeight, WHITE);
                loopCount += 1;
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
        benchAverage = benchAverage + benchResult; // Update the running average
    }
    logConsoleAveragedResult(text::bitmapsStd, (4*3)); // 4 blitter op's x 3 loops
    
    
    // --- arduboy.drawSlowXYBitmap ~  Sprites::drawSelfMasked ---
    for (i = 0; i < 3; i = i + 1) {
        loopCount = 0;
    benchAverage = 0.0F;
        benchStartTime = millis();
        for (y = yStart; y < HEIGHT; y = y + yStep) {
            for (x = xStart; x < WIDTH; x = x + xStep) {
                arduboy.drawSlowXYBitmap(x, y, images1x1::bitmaps::slow, monopixWidth, monopixHeight, WHITE);
                arduboy.drawSlowXYBitmap(x, y+2, images1x1::bitmaps::slow, monopixWidth, monopixHeight, WHITE);
                arduboy.drawSlowXYBitmap(x, y+4, images1x1::bitmaps::slow, monopixWidth, monopixHeight, WHITE);
                arduboy.drawSlowXYBitmap(x, y+6, images1x1::bitmaps::slow, monopixWidth, monopixHeight, WHITE);
                loopCount += 1;
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
        benchAverage = benchAverage + benchResult; // Update the running average
    }
    logConsoleAveragedResult(text::bitmapsSlow, (4*3)); // 4 blitter op's x 3 loops
    
    
    // --- arduboy.drawCompressed ~  Sprites::drawSelfMasked ---
    for (i = 0; i < 3; i = i + 1) {
        loopCount = 0;
    benchAverage = 0.0F;
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
    logConsoleAveragedResult(text::bitmapsComp, (4*3)); // 4 blitter op's x 3 loops
    
    
    
    
    // --- Sprites::drawExternalMask ---
    for (i = 0; i < 3; i = i + 1) {
        loopCount = 0;
    benchAverage = 0.0F;
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
    logConsoleAveragedResult(text::spritesExtMask, (4*3)); // 4 blitter op's x 3 loops
    
    
    // --- Sprites::drawPlusMask ---
    for (i = 0; i < 3; i = i + 1) {
        loopCount = 0;
    benchAverage = 0.0F;
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
    logConsoleAveragedResult(text::spritesPlusMask, (4*3)); // 4 blitter op's x 3 loops
    
    
    // --- Sprites::drawSelfMasked with extra masking step ---
    for (i = 0; i < 3; i = i + 1) {
        loopCount = 0;
    benchAverage = 0.0F;
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
    logConsoleAveragedResult(text::spritesEraseMasked, (4*3)); // 4 blitter op's x 3 loops
    
    
    // --- arduboy.drawBitmap with extra masking step ---
    for (i = 0; i < 3; i = i + 1) {
        loopCount = 0;
    benchAverage = 0.0F;
        benchStartTime = millis();
        for (y = yStart; y < HEIGHT; y = y + yStep) {
            for (x = xStart; x < WIDTH; x = x + xStep) {
                arduboy.drawBitmap(x, y, images1x1::bitmaps::stdMask, monopixWidth, monopixHeight, BLACK);
                arduboy.drawBitmap(x, y, images1x1::bitmaps::std, monopixWidth, monopixHeight, WHITE);
                arduboy.drawBitmap(x, y+2, images1x1::bitmaps::stdMask, monopixWidth, monopixHeight, BLACK);
                arduboy.drawBitmap(x, y+2, images1x1::bitmaps::std, monopixWidth, monopixHeight, WHITE);
                arduboy.drawBitmap(x, y+4, images1x1::bitmaps::stdMask, monopixWidth, monopixHeight, BLACK);
                arduboy.drawBitmap(x, y+4, images1x1::bitmaps::std, monopixWidth, monopixHeight, WHITE);
                arduboy.drawBitmap(x, y+6, images1x1::bitmaps::stdMask, monopixWidth, monopixHeight, BLACK);
                arduboy.drawBitmap(x, y+6, images1x1::bitmaps::std, monopixWidth, monopixHeight, WHITE);
                loopCount += 1;
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
        benchAverage = benchAverage + benchResult; // Update the running average
    }
    logConsoleAveragedResult(text::bitmapsStdMasked, (4*3)); // 4 blitter op's x 3 loops
    
    
    // --- arduboy.drawSlowXYBitmap with extra masking step ---
    for (i = 0; i < 3; i = i + 1) {
        loopCount = 0;
    benchAverage = 0.0F;
        benchStartTime = millis();
        for (y = yStart; y < HEIGHT; y = y + yStep) {
            for (x = xStart; x < WIDTH; x = x + xStep) {
                arduboy.drawSlowXYBitmap(x, y, images1x1::bitmaps::slowMask, monopixWidth, monopixHeight, BLACK);
                arduboy.drawSlowXYBitmap(x, y, images1x1::bitmaps::slow, monopixWidth, monopixHeight, WHITE);
                arduboy.drawSlowXYBitmap(x, y+2, images1x1::bitmaps::slowMask, monopixWidth, monopixHeight, BLACK);
                arduboy.drawSlowXYBitmap(x, y+2, images1x1::bitmaps::slow, monopixWidth, monopixHeight, WHITE);
                arduboy.drawSlowXYBitmap(x, y+4, images1x1::bitmaps::slowMask, monopixWidth, monopixHeight, BLACK);
                arduboy.drawSlowXYBitmap(x, y+4, images1x1::bitmaps::slow, monopixWidth, monopixHeight, WHITE);
                arduboy.drawSlowXYBitmap(x, y+6, images1x1::bitmaps::slowMask, monopixWidth, monopixHeight, BLACK);
                arduboy.drawSlowXYBitmap(x, y+6, images1x1::bitmaps::slow, monopixWidth, monopixHeight, WHITE);
                loopCount += 1;
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
        benchAverage = benchAverage + benchResult; // Update the running average
    }
    logConsoleAveragedResult(text::bitmapsSlowMasked, (4*3)); // 4 blitter op's x 3 loops
    
    
    // --- arduboy.drawCompressed with extra masking step ---
    for (i = 0; i < 3; i = i + 1) {
        loopCount = 0;
    benchAverage = 0.0F;
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
    logConsoleAveragedResult(text::bitmapsCompMasked, (4*3)); // 4 blitter op's x 3 loops
    
    
    logConsole(text::horizontalRule);           // "---------------------\n\n"
    
}
