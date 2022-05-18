/* 
 *  Benchmark: 1x1 Monopixel
 *  - Each blitting function is called 4x times, to help avoid compiler inlining.
 */

void testMonopixel() {

    arduboy.clear();
    logArduboy(text::monopixTest);
    logConsole(text::monopixTest);          // "* Monopixel test    *\n"
    logConsole(text::titleBreak);           // "*********************\n\n"
    arduboy.clear();


    // Parameters for rendering loops
    constexpr int16_t xStart = 0;
    constexpr int16_t yStart = 0;
    constexpr int16_t xEnd = WIDTH;
    constexpr int16_t yEnd = HEIGHT;
    constexpr uint8_t xStep = 2;
    constexpr uint8_t yStep = 8;

    // Determine the total count for the inner x,y loops
    // This does not change between tests of different functions within a set
    uint16_t loopCount = divideAndRoundUp((xEnd-xStart), xStep) * divideAndRoundUp((yEnd-yStart), yStep);



    // --- Sprites::drawOverwrite ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < testRepeats; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < HEIGHT; y = y + yStep) {
            for (int16_t x = xStart; x < WIDTH; x = x + xStep) {
                Sprites::drawOverwrite(x, y, images1x1::sprites::std, 0);
                Sprites::drawOverwrite(x, y+2, images1x1::sprites::std, 0);
                Sprites::drawOverwrite(x, y+4, images1x1::sprites::std, 0);
                Sprites::drawOverwrite(x, y+6, images1x1::sprites::std, 0);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::spritesOverwrite, (4*testRepeats)); // 4 blitter op's per loop


#ifdef TEST_SPRITES_B
    // --- SpritesB::drawOverwrite ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < testRepeats; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < HEIGHT; y = y + yStep) {
            for (int16_t x = xStart; x < WIDTH; x = x + xStep) {
                SpritesB::drawOverwrite(x, y, images1x1::sprites::std, 0);
                SpritesB::drawOverwrite(x, y+2, images1x1::sprites::std, 0);
                SpritesB::drawOverwrite(x, y+4, images1x1::sprites::std, 0);
                SpritesB::drawOverwrite(x, y+6, images1x1::sprites::std, 0);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::spritesBOverwrite, (4*testRepeats), newLine); // 4 blitter op's per loop 
#endif


    /* --- */


    invertScreen(true); 


    // --- Sprites::drawErase ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < testRepeats; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < HEIGHT; y = y + yStep) {
            for (int16_t x = xStart; x < WIDTH; x = x + xStep) {
                Sprites::drawErase(x, y, images1x1::sprites::std, 0);
                Sprites::drawErase(x, y+2, images1x1::sprites::std, 0);
                Sprites::drawErase(x, y+4, images1x1::sprites::std, 0);
                Sprites::drawErase(x, y+6, images1x1::sprites::std, 0);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
        arduboy.fillScreen(WHITE); // Prepare 'white' screen for next loop
    }
    logConsoleAveragedResult(text::spritesErase, (4*testRepeats)); // 4 blitter op's per loop


#ifdef TEST_SPRITES_B
    // --- SpritesB::drawErase ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < testRepeats; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < HEIGHT; y = y + yStep) {
            for (int16_t x = xStart; x < WIDTH; x = x + xStep) {
                SpritesB::drawErase(x, y, images1x1::sprites::std, 0);
                SpritesB::drawErase(x, y+2, images1x1::sprites::std, 0);
                SpritesB::drawErase(x, y+4, images1x1::sprites::std, 0);
                SpritesB::drawErase(x, y+6, images1x1::sprites::std, 0);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
        arduboy.fillScreen(WHITE); // Prepare 'white' screen for next loop
    }
    logConsoleAveragedResult(text::spritesBErase, (4*testRepeats)); // 4 blitter op's per loop
#endif


    invertScreen(false); 


    // --- Sprites::drawSelfMasked ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < testRepeats; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < HEIGHT; y = y + yStep) {
            for (int16_t x = xStart; x < WIDTH; x = x + xStep) {
                Sprites::drawSelfMasked(x, y, images1x1::sprites::std, 0);
                Sprites::drawSelfMasked(x, y+2, images1x1::sprites::std, 0);
                Sprites::drawSelfMasked(x, y+4, images1x1::sprites::std, 0);
                Sprites::drawSelfMasked(x, y+6, images1x1::sprites::std, 0);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::spritesSelfMask, (4*testRepeats)); // 4 blitter op's per loop



    // --- arduboy.drawBitmap ~ Sprites::drawSelfMasked ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < testRepeats; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < HEIGHT; y = y + yStep) {
            for (int16_t x = xStart; x < WIDTH; x = x + xStep) {
                arduboy.drawBitmap(x, y, images1x1::bitmaps::std, monopixWidth, monopixHeight, WHITE);
                arduboy.drawBitmap(x, y+2, images1x1::bitmaps::std, monopixWidth, monopixHeight, WHITE);
                arduboy.drawBitmap(x, y+4, images1x1::bitmaps::std, monopixWidth, monopixHeight, WHITE);
                arduboy.drawBitmap(x, y+6, images1x1::bitmaps::std, monopixWidth, monopixHeight, WHITE);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::bitmapsStd, (4*testRepeats)); // 4 blitter op's per loop
    
    
    // --- arduboy.drawSlowXYBitmap ~  Sprites::drawSelfMasked ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < testRepeats; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < HEIGHT; y = y + yStep) {
            for (int16_t x = xStart; x < WIDTH; x = x + xStep) {
                arduboy.drawSlowXYBitmap(x, y, images1x1::bitmaps::slow, monopixWidth, monopixHeight, WHITE);
                arduboy.drawSlowXYBitmap(x, y+2, images1x1::bitmaps::slow, monopixWidth, monopixHeight, WHITE);
                arduboy.drawSlowXYBitmap(x, y+4, images1x1::bitmaps::slow, monopixWidth, monopixHeight, WHITE);
                arduboy.drawSlowXYBitmap(x, y+6, images1x1::bitmaps::slow, monopixWidth, monopixHeight, WHITE);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::bitmapsSlow, (4*testRepeats)); // 4 blitter op's per loop
    
    
    // --- arduboy.drawCompressed ~  Sprites::drawSelfMasked ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < testRepeats; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < HEIGHT; y = y + yStep) {
            for (int16_t x = xStart; x < WIDTH; x = x + xStep) {
                arduboy.drawCompressed(x, y, images1x1::bitmaps::cabi, WHITE);
                arduboy.drawCompressed(x, y+2, images1x1::bitmaps::cabi, WHITE);
                arduboy.drawCompressed(x, y+4, images1x1::bitmaps::cabi, WHITE);
                arduboy.drawCompressed(x, y+6, images1x1::bitmaps::cabi, WHITE);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::bitmapsComp, (4*testRepeats), newLine); // 4 blitter op's per loop
    
    
    
    
    // --- Sprites::drawExternalMask ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < testRepeats; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < HEIGHT; y = y + yStep) {
            for (int16_t x = xStart; x < WIDTH; x = x + xStep) {
                Sprites::drawExternalMask(x, y, images1x1::sprites::std, images1x1::sprites::mask, 0, 0);
                Sprites::drawExternalMask(x, y+2, images1x1::sprites::std, images1x1::sprites::mask, 0, 0);
                Sprites::drawExternalMask(x, y+4, images1x1::sprites::std, images1x1::sprites::mask, 0, 0);
                Sprites::drawExternalMask(x, y+6, images1x1::sprites::std, images1x1::sprites::mask, 0, 0);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::spritesExtMask, (4*testRepeats)); // 4 blitter op's per loop
    
    
    // --- Sprites::drawPlusMask ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < testRepeats; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < HEIGHT; y = y + yStep) {
            for (int16_t x = xStart; x < WIDTH; x = x + xStep) {
                Sprites::drawPlusMask(x, y, images1x1::sprites::plusMask, 0);
                Sprites::drawPlusMask(x, y+2, images1x1::sprites::plusMask, 0);
                Sprites::drawPlusMask(x, y+4, images1x1::sprites::plusMask, 0);
                Sprites::drawPlusMask(x, y+6, images1x1::sprites::plusMask, 0);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::spritesPlusMask, (4*testRepeats)); // 4 blitter op's per loop
    
    
    // --- Sprites::drawSelfMasked with extra masking step ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < testRepeats; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < HEIGHT; y = y + yStep) {
            for (int16_t x = xStart; x < WIDTH; x = x + xStep) {
                Sprites::drawErase(x, y, images1x1::sprites::mask, 0);
                Sprites::drawSelfMasked(x, y, images1x1::sprites::std, 0);
                Sprites::drawErase(x, y+2, images1x1::sprites::mask, 0);
                Sprites::drawSelfMasked(x, y+2, images1x1::sprites::std, 0);
                Sprites::drawErase(x, y+4, images1x1::sprites::mask, 0);
                Sprites::drawSelfMasked(x, y+4, images1x1::sprites::std, 0);
                Sprites::drawErase(x, y+6, images1x1::sprites::mask, 0);
                Sprites::drawSelfMasked(x, y+6, images1x1::sprites::std, 0);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::spritesEraseMasked, (4*testRepeats)); // 4 blitter op's per loop
    
    
    // --- arduboy.drawBitmap with extra masking step ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < testRepeats; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < HEIGHT; y = y + yStep) {
            for (int16_t x = xStart; x < WIDTH; x = x + xStep) {
                arduboy.drawBitmap(x, y, images1x1::bitmaps::stdMask, monopixWidth, monopixHeight, BLACK);
                arduboy.drawBitmap(x, y, images1x1::bitmaps::std, monopixWidth, monopixHeight, WHITE);
                arduboy.drawBitmap(x, y+2, images1x1::bitmaps::stdMask, monopixWidth, monopixHeight, BLACK);
                arduboy.drawBitmap(x, y+2, images1x1::bitmaps::std, monopixWidth, monopixHeight, WHITE);
                arduboy.drawBitmap(x, y+4, images1x1::bitmaps::stdMask, monopixWidth, monopixHeight, BLACK);
                arduboy.drawBitmap(x, y+4, images1x1::bitmaps::std, monopixWidth, monopixHeight, WHITE);
                arduboy.drawBitmap(x, y+6, images1x1::bitmaps::stdMask, monopixWidth, monopixHeight, BLACK);
                arduboy.drawBitmap(x, y+6, images1x1::bitmaps::std, monopixWidth, monopixHeight, WHITE);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::bitmapsStdMasked, (4*testRepeats)); // 4 blitter op's per loop
    
    
    // --- arduboy.drawSlowXYBitmap with extra masking step ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < testRepeats; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < HEIGHT; y = y + yStep) {
            for (int16_t x = xStart; x < WIDTH; x = x + xStep) {
                arduboy.drawSlowXYBitmap(x, y, images1x1::bitmaps::slowMask, monopixWidth, monopixHeight, BLACK);
                arduboy.drawSlowXYBitmap(x, y, images1x1::bitmaps::slow, monopixWidth, monopixHeight, WHITE);
                arduboy.drawSlowXYBitmap(x, y+2, images1x1::bitmaps::slowMask, monopixWidth, monopixHeight, BLACK);
                arduboy.drawSlowXYBitmap(x, y+2, images1x1::bitmaps::slow, monopixWidth, monopixHeight, WHITE);
                arduboy.drawSlowXYBitmap(x, y+4, images1x1::bitmaps::slowMask, monopixWidth, monopixHeight, BLACK);
                arduboy.drawSlowXYBitmap(x, y+4, images1x1::bitmaps::slow, monopixWidth, monopixHeight, WHITE);
                arduboy.drawSlowXYBitmap(x, y+6, images1x1::bitmaps::slowMask, monopixWidth, monopixHeight, BLACK);
                arduboy.drawSlowXYBitmap(x, y+6, images1x1::bitmaps::slow, monopixWidth, monopixHeight, WHITE);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::bitmapsSlowMasked, (4*testRepeats)); // 4 blitter op's per loop
    
    
    // --- arduboy.drawCompressed with extra masking step ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < testRepeats; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < HEIGHT; y = y + yStep) {
            for (int16_t x = xStart; x < WIDTH; x = x + xStep) {
                arduboy.drawCompressed(x, y, images1x1::bitmaps::cabiMask, BLACK);
                arduboy.drawCompressed(x, y, images1x1::bitmaps::cabi, WHITE);
                arduboy.drawCompressed(x, y+2, images1x1::bitmaps::cabiMask, BLACK);
                arduboy.drawCompressed(x, y+2, images1x1::bitmaps::cabi, WHITE);
                arduboy.drawCompressed(x, y+4, images1x1::bitmaps::cabiMask, BLACK);
                arduboy.drawCompressed(x, y+4, images1x1::bitmaps::cabi, WHITE);
                arduboy.drawCompressed(x, y+6, images1x1::bitmaps::cabiMask, BLACK);
                arduboy.drawCompressed(x, y+6, images1x1::bitmaps::cabi, WHITE);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::bitmapsCompMasked, (4*testRepeats)); // 4 blitter op's per loop


    logConsole(text::horizontalRule);           // "---------------------\n\n"

}