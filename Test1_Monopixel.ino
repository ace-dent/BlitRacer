/* 
 *  Benchmark: 1x1 Monopixel
 *  - Each blitting function is called 4x times, to help avoid compiler inlining.
 */

void testMonopixel() {

    logTestTitle(text::monopixTest);

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



    // OVERWRITE FUNCTIONS                                          //
    // (replaces any underlying background with new image data)
    // ------------------------------------------------------------ //


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
        benchmark(loopCount, text::spritesOverwrite ,i); // Benchmark for given loops
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
        benchmark(loopCount, text::spritesBOverwrite ,i); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::spritesBOverwrite, (4*testRepeats)); // 4 blitter op's per loop 
#endif



    // SELF MASKED FUNCTIONS                                        //
    // (only binary `1` in the new image replaces the background)
    // ------------------------------------------------------------ //

    logConsole(text::blank, newLine);           // ""\n


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
        benchmark(loopCount, text::spritesSelfMask ,i); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::spritesSelfMask, (4*testRepeats)); // 4 blitter op's per loop


#ifdef TEST_SPRITES_B
    // --- SpritesB::drawSelfMasked ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < testRepeats; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < HEIGHT; y = y + yStep) {
            for (int16_t x = xStart; x < WIDTH; x = x + xStep) {
                SpritesB::drawSelfMasked(x, y, images1x1::sprites::std, 0);
                SpritesB::drawSelfMasked(x, y+2, images1x1::sprites::std, 0);
                SpritesB::drawSelfMasked(x, y+4, images1x1::sprites::std, 0);
                SpritesB::drawSelfMasked(x, y+6, images1x1::sprites::std, 0);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount, text::spritesBSelfMask , i); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::spritesBSelfMask, (4*testRepeats)); // 4 blitter op's per loop
#endif


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
        benchmark(loopCount, text::spritesErase, i); // Benchmark for given loops
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
        benchmark(loopCount, text::spritesBErase, i); // Benchmark for given loops
        arduboy.fillScreen(WHITE); // Prepare 'white' screen for next loop
    }
    logConsoleAveragedResult(text::spritesBErase, (4*testRepeats)); // 4 blitter op's per loop
#endif


    invertScreen(false); 


    // --- arduboy.drawBitmap ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < testRepeats; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < HEIGHT; y = y + yStep) {
            for (int16_t x = xStart; x < WIDTH; x = x + xStep) {
                arduboy.drawBitmap(x, y, images1x1::bitmaps::std, images1x1::width, images1x1::height, WHITE);
                arduboy.drawBitmap(x, y+2, images1x1::bitmaps::std, images1x1::width, images1x1::height, WHITE);
                arduboy.drawBitmap(x, y+4, images1x1::bitmaps::std, images1x1::width, images1x1::height, WHITE);
                arduboy.drawBitmap(x, y+6, images1x1::bitmaps::std, images1x1::width, images1x1::height, WHITE);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount, text::bitmapsStd, i); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::bitmapsStd, (4*testRepeats)); // 4 blitter op's per loop


#ifdef TEST_SLOW_BITMAP
    // --- arduboy.drawSlowXYBitmap ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < testRepeats; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < HEIGHT; y = y + yStep) {
            for (int16_t x = xStart; x < WIDTH; x = x + xStep) {
                arduboy.drawSlowXYBitmap(x, y, images1x1::bitmaps::slow, images1x1::width, images1x1::height, WHITE);
                arduboy.drawSlowXYBitmap(x, y+2, images1x1::bitmaps::slow, images1x1::width, images1x1::height, WHITE);
                arduboy.drawSlowXYBitmap(x, y+4, images1x1::bitmaps::slow, images1x1::width, images1x1::height, WHITE);
                arduboy.drawSlowXYBitmap(x, y+6, images1x1::bitmaps::slow, images1x1::width, images1x1::height, WHITE);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount, text::bitmapsSlow, i); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::bitmapsSlow, (4*testRepeats)); // 4 blitter op's per loop
#endif


#ifdef TEST_COMPRESSED
    // --- arduboy.drawCompressed ---
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
        benchmark(loopCount, text::bitmapsComp, i); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::bitmapsComp, (4*testRepeats)); // 4 blitter op's per loop
#endif



    // FULLY MASKED FUNCTIONS                                       //
    // (new images can have black, white or transparent pixels)
    // ------------------------------------------------------------ //

    logConsole(text::blank, newLine);           // ""\n


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
        benchmark(loopCount, text::spritesPlusMask, i); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::spritesPlusMask, (4*testRepeats)); // 4 blitter op's per loop


#ifdef TEST_SPRITES_B
    // --- SpritesB::drawPlusMask ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < testRepeats; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < HEIGHT; y = y + yStep) {
            for (int16_t x = xStart; x < WIDTH; x = x + xStep) {
                SpritesB::drawPlusMask(x, y, images1x1::sprites::plusMask, 0);
                SpritesB::drawPlusMask(x, y+2, images1x1::sprites::plusMask, 0);
                SpritesB::drawPlusMask(x, y+4, images1x1::sprites::plusMask, 0);
                SpritesB::drawPlusMask(x, y+6, images1x1::sprites::plusMask, 0);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount, text::spritesBPlusMask, i); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::spritesBPlusMask, (4*testRepeats)); // 4 blitter op's per loop
#endif


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
        benchmark(loopCount, text::spritesExtMask, i); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::spritesExtMask, (4*testRepeats)); // 4 blitter op's per loop


#ifdef TEST_SPRITES_B
    // --- SpritesB::drawExternalMask ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < testRepeats; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < HEIGHT; y = y + yStep) {
            for (int16_t x = xStart; x < WIDTH; x = x + xStep) {
                SpritesB::drawExternalMask(x, y, images1x1::sprites::std, images1x1::sprites::mask, 0, 0);
                SpritesB::drawExternalMask(x, y+2, images1x1::sprites::std, images1x1::sprites::mask, 0, 0);
                SpritesB::drawExternalMask(x, y+4, images1x1::sprites::std, images1x1::sprites::mask, 0, 0);
                SpritesB::drawExternalMask(x, y+6, images1x1::sprites::std, images1x1::sprites::mask, 0, 0);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount, text::spritesBExtMask, i); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::spritesBExtMask, (4*testRepeats)); // 4 blitter op's per loop
#endif


    // --- Sprites::drawSelfMasked with extra masking step ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < testRepeats; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < HEIGHT; y = y + yStep) {
            for (int16_t x = xStart; x < WIDTH; x = x + xStep) {
                Sprites::drawErase(x, y, images1x1::sprites::eraseMask, 0);
                Sprites::drawSelfMasked(x, y, images1x1::sprites::std, 0);
                Sprites::drawErase(x, y+2, images1x1::sprites::eraseMask, 0);
                Sprites::drawSelfMasked(x, y+2, images1x1::sprites::std, 0);
                Sprites::drawErase(x, y+4, images1x1::sprites::eraseMask, 0);
                Sprites::drawSelfMasked(x, y+4, images1x1::sprites::std, 0);
                Sprites::drawErase(x, y+6, images1x1::sprites::eraseMask, 0);
                Sprites::drawSelfMasked(x, y+6, images1x1::sprites::std, 0);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount, text::spritesEraseMasked, i); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::spritesEraseMasked, (4*testRepeats)); // 4 blitter op's per loop


#ifdef TEST_SPRITES_B
    // --- SpritesB::drawSelfMasked with extra masking step ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < testRepeats; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < HEIGHT; y = y + yStep) {
            for (int16_t x = xStart; x < WIDTH; x = x + xStep) {
                SpritesB::drawErase(x, y, images1x1::sprites::eraseMask, 0);
                SpritesB::drawSelfMasked(x, y, images1x1::sprites::std, 0);
                SpritesB::drawErase(x, y+2, images1x1::sprites::eraseMask, 0);
                SpritesB::drawSelfMasked(x, y+2, images1x1::sprites::std, 0);
                SpritesB::drawErase(x, y+4, images1x1::sprites::eraseMask, 0);
                SpritesB::drawSelfMasked(x, y+4, images1x1::sprites::std, 0);
                SpritesB::drawErase(x, y+6, images1x1::sprites::eraseMask, 0);
                SpritesB::drawSelfMasked(x, y+6, images1x1::sprites::std, 0);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount, text::spritesBEraseMasked, i); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::spritesBEraseMasked, (4*testRepeats)); // 4 blitter op's per loop
#endif


    // --- arduboy.drawBitmap with extra masking step ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < testRepeats; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < HEIGHT; y = y + yStep) {
            for (int16_t x = xStart; x < WIDTH; x = x + xStep) {
                arduboy.drawBitmap(x, y, images1x1::bitmaps::stdMask, images1x1::width, images1x1::height, BLACK);
                arduboy.drawBitmap(x, y, images1x1::bitmaps::std, images1x1::width, images1x1::height, WHITE);
                arduboy.drawBitmap(x, y+2, images1x1::bitmaps::stdMask, images1x1::width, images1x1::height, BLACK);
                arduboy.drawBitmap(x, y+2, images1x1::bitmaps::std, images1x1::width, images1x1::height, WHITE);
                arduboy.drawBitmap(x, y+4, images1x1::bitmaps::stdMask, images1x1::width, images1x1::height, BLACK);
                arduboy.drawBitmap(x, y+4, images1x1::bitmaps::std, images1x1::width, images1x1::height, WHITE);
                arduboy.drawBitmap(x, y+6, images1x1::bitmaps::stdMask, images1x1::width, images1x1::height, BLACK);
                arduboy.drawBitmap(x, y+6, images1x1::bitmaps::std, images1x1::width, images1x1::height, WHITE);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount, text::bitmapsStdMasked, i); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::bitmapsStdMasked, (4*testRepeats)); // 4 blitter op's per loop


#ifdef TEST_SLOW_BITMAP
    // --- arduboy.drawSlowXYBitmap with extra masking step ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < testRepeats; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < HEIGHT; y = y + yStep) {
            for (int16_t x = xStart; x < WIDTH; x = x + xStep) {
                arduboy.drawSlowXYBitmap(x, y, images1x1::bitmaps::slowMask, images1x1::width, images1x1::height, BLACK);
                arduboy.drawSlowXYBitmap(x, y, images1x1::bitmaps::slow, images1x1::width, images1x1::height, WHITE);
                arduboy.drawSlowXYBitmap(x, y+2, images1x1::bitmaps::slowMask, images1x1::width, images1x1::height, BLACK);
                arduboy.drawSlowXYBitmap(x, y+2, images1x1::bitmaps::slow, images1x1::width, images1x1::height, WHITE);
                arduboy.drawSlowXYBitmap(x, y+4, images1x1::bitmaps::slowMask, images1x1::width, images1x1::height, BLACK);
                arduboy.drawSlowXYBitmap(x, y+4, images1x1::bitmaps::slow, images1x1::width, images1x1::height, WHITE);
                arduboy.drawSlowXYBitmap(x, y+6, images1x1::bitmaps::slowMask, images1x1::width, images1x1::height, BLACK);
                arduboy.drawSlowXYBitmap(x, y+6, images1x1::bitmaps::slow, images1x1::width, images1x1::height, WHITE);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount, text::bitmapsSlowMasked, i); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::bitmapsSlowMasked, (4*testRepeats)); // 4 blitter op's per loop
#endif


#ifdef TEST_COMPRESSED
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
        benchmark(loopCount, text::bitmapsCompMasked, i); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::bitmapsCompMasked, (4*testRepeats)); // 4 blitter op's per loop
#endif


    logConsole(text::horizontalRule);           // "---------------------\n\n"

}