/* 
 *  Benchmark: Chunky 14x14px image
 */


void testChunky() {

    arduboy.clear();
    logArduboy(text::chunkyTest);
    logConsole(text::chunkyTest);               // "* Chunky img test   *\n"
    logConsole(text::titleBreak);               // "*********************\n\n"
    arduboy.clear();


    // Parameters for rendering loops
    constexpr int16_t xStart = -imagesChunky::width;
    constexpr int16_t yStart = -imagesChunky::height;
    constexpr int16_t xEnd = WIDTH - imagesChunky::width;
    constexpr int16_t yEnd = HEIGHT + imagesChunky::height;
    uint8_t xStep = 1;
    uint8_t yStep = imagesChunky::height +1;


    // Determine the total count for the inner x,y loops
    // This does not change between tests of different functions within a set
    const uint16_t loopCount = divideAndRoundUp((xEnd-xStart), xStep) * divideAndRoundUp((yEnd-yStart), yStep);



    // OVERWRITE FUNCTIONS                                          //
    // (replaces any underlying background with new image data)
    // ------------------------------------------------------------ //


    // --- Sprites::drawOverwrite ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < testRepeats; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < yEnd; y = y + yStep) {
            for (int16_t x = xStart; x < xEnd; x = x + xStep) {
                Sprites::drawOverwrite(x, y, imagesChunky::sprites::std, 0);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount, text::spritesOverwrite, i); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::spritesOverwrite, testRepeats);


#ifdef TEST_SPRITES_B
    // --- SpritesB::drawOverwrite ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < testRepeats; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < yEnd; y = y + yStep) {
            for (int16_t x = xStart; x < xEnd; x = x + xStep) {
                SpritesB::drawOverwrite(x, y, imagesChunky::sprites::std, 0);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount, text::spritesBOverwrite, i); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::spritesBOverwrite, testRepeats);
#endif



    // SELF MASKED FUNCTIONS                                        //
    // (only binary `1` in the new image replaces the background)
    // ------------------------------------------------------------ //

    logConsole(text::blank, newLine);           // ""\n


    // --- Sprites::drawSelfMasked ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < testRepeats; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < yEnd; y = y + yStep) {
            for (int16_t x = xStart; x < xEnd; x = x + xStep) {
                Sprites::drawSelfMasked(x, y, imagesChunky::sprites::std, 0);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount, text::spritesSelfMask, i); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::spritesSelfMask, testRepeats);


#ifdef TEST_SPRITES_B
    // --- SpritesB::drawSelfMasked ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < testRepeats; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < yEnd; y = y + yStep) {
            for (int16_t x = xStart; x < xEnd; x = x + xStep) {
                SpritesB::drawSelfMasked(x, y, imagesChunky::sprites::std, 0);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount, text::spritesBSelfMask, i); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::spritesBSelfMask, testRepeats);
#endif


    invertScreen(true); 


    // --- Sprites::drawErase ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < testRepeats; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < yEnd; y = y + yStep) {
            for (int16_t x = xStart; x < xEnd; x = x + xStep) {
                Sprites::drawErase(x, y, imagesChunky::sprites::std, 0);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount, text::spritesErase, i); // Benchmark for given loops
        arduboy.fillScreen(WHITE); // Clear to 'white' for next render
    }
    logConsoleAveragedResult(text::spritesErase, testRepeats);


#ifdef TEST_SPRITES_B
    // --- SpritesB::drawErase ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < testRepeats; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < yEnd; y = y + yStep) {
            for (int16_t x = xStart; x < xEnd; x = x + xStep) {
                SpritesB::drawErase(x, y, imagesChunky::sprites::std, 0);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount, text::spritesBErase, i); // Benchmark for given loops
        arduboy.fillScreen(WHITE); // Clear to 'white' for next render
    }
    logConsoleAveragedResult(text::spritesBErase, testRepeats);
#endif


    invertScreen(false);


    // --- arduboy.drawBitmap ~ Sprites::drawSelfMasked ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < testRepeats; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < yEnd; y = y + yStep) {
            for (int16_t x = xStart; x < xEnd; x = x + xStep) {
                arduboy.drawBitmap(x, y, imagesChunky::bitmaps::std, imagesChunky::width, imagesChunky::height, WHITE);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount, text::bitmapsStd, i); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::bitmapsStd, testRepeats);


#ifdef TEST_SLOW_BITMAP
    // --- arduboy.drawSlowXYBitmap ~  Sprites::drawSelfMasked ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < testRepeats; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < yEnd; y = y + yStep) {
            for (int16_t x = xStart; x < xEnd; x = x + xStep) {
                arduboy.drawSlowXYBitmap(x, y, imagesChunky::bitmaps::slow, imagesChunky::width, imagesChunky::height, WHITE);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount, text::bitmapsSlow, i); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::bitmapsSlow, testRepeats);
#endif


#ifdef TEST_COMPRESSED
    // --- arduboy.drawCompressed ~  Sprites::drawSelfMasked ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < testRepeats; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < yEnd; y = y + yStep) {
            for (int16_t x = xStart; x < xEnd; x = x + xStep) {
                arduboy.drawCompressed(x, y, imagesChunky::bitmaps::cabi, WHITE);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount, text::bitmapsComp, i); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::bitmapsComp, testRepeats);
#endif



    // FULLY MASKED FUNCTIONS                                       //
    // (new images can have black, white or transparent pixels)
    // ------------------------------------------------------------ //

    logConsole(text::blank, newLine);           // ""\n


    // --- Sprites::drawPlusMask ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < testRepeats; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < yEnd; y = y + yStep) {
            for (int16_t x = xStart; x < xEnd; x = x + xStep) {
                Sprites::drawPlusMask(x, y, imagesChunky::sprites::plusMask, 0);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount, text::spritesPlusMask, i); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::spritesPlusMask, testRepeats);


#ifdef TEST_SPRITES_B
    // --- SpritesB::drawPlusMask ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < testRepeats; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < yEnd; y = y + yStep) {
            for (int16_t x = xStart; x < xEnd; x = x + xStep) {
                SpritesB::drawPlusMask(x, y, imagesChunky::sprites::plusMask, 0);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount, text::spritesBPlusMask, i); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::spritesBPlusMask, testRepeats);
#endif


    // --- Sprites::drawExternalMask ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < testRepeats; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < yEnd; y = y + yStep) {
            for (int16_t x = xStart; x < xEnd; x = x + xStep) {
                Sprites::drawExternalMask(x, y, imagesChunky::sprites::std, imagesChunky::sprites::mask, 0, 0);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount, text::spritesExtMask, i); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::spritesExtMask, testRepeats);


#ifdef TEST_SPRITES_B
    // --- SpritesB::drawExternalMask ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < testRepeats; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < yEnd; y = y + yStep) {
            for (int16_t x = xStart; x < xEnd; x = x + xStep) {
                SpritesB::drawExternalMask(x, y, imagesChunky::sprites::std, imagesChunky::sprites::mask, 0, 0);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount, text::spritesBExtMask, i); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::spritesBExtMask, testRepeats);
#endif


    // --- Sprites::drawSelfMasked with extra masking step ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < testRepeats; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < yEnd; y = y + yStep) {
            for (int16_t x = xStart; x < xEnd; x = x + xStep) {
                Sprites::drawErase(x, y, imagesChunky::sprites::eraseMask, 0);
                Sprites::drawSelfMasked(x, y, imagesChunky::sprites::std, 0);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount, text::spritesEraseMasked, i); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::spritesEraseMasked, testRepeats);


#ifdef TEST_SPRITES_B
    // --- SpritesB::drawSelfMasked with extra masking step ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < testRepeats; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < yEnd; y = y + yStep) {
            for (int16_t x = xStart; x < xEnd; x = x + xStep) {
                SpritesB::drawErase(x, y, imagesChunky::sprites::eraseMask, 0);
                SpritesB::drawSelfMasked(x, y, imagesChunky::sprites::std, 0);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount, text::spritesBEraseMasked, i); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::spritesBEraseMasked, testRepeats);
#endif


    // --- arduboy.drawBitmap with extra masking step ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < testRepeats; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < yEnd; y = y + yStep) {
            for (int16_t x = xStart; x < xEnd; x = x + xStep) {
                arduboy.drawBitmap(x, y, imagesChunky::bitmaps::stdMask, imagesChunky::width, imagesChunky::height, BLACK);
                arduboy.drawBitmap(x, y, imagesChunky::bitmaps::std, imagesChunky::width, imagesChunky::height, WHITE);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount, text::bitmapsStdMasked, i); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::bitmapsStdMasked, testRepeats);


#ifdef TEST_SLOW_BITMAP
    // --- arduboy.drawSlowXYBitmap with extra masking step ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < testRepeats; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < yEnd; y = y + yStep) {
            for (int16_t x = xStart; x < xEnd; x = x + xStep) {
                arduboy.drawSlowXYBitmap(x, y, imagesChunky::bitmaps::slowMask, imagesChunky::width, imagesChunky::height, BLACK);
                arduboy.drawSlowXYBitmap(x, y, imagesChunky::bitmaps::slow, imagesChunky::width, imagesChunky::height, WHITE);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount, text::bitmapsSlowMasked, i); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::bitmapsSlowMasked, testRepeats);
#endif


#ifdef TEST_COMPRESSED
    // --- arduboy.drawCompressed with extra masking step ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < testRepeats; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < yEnd; y = y + yStep) {
            for (int16_t x = xStart; x < xEnd; x = x + xStep) {
                arduboy.drawCompressed(x, y, imagesChunky::bitmaps::cabiMask, BLACK);
                arduboy.drawCompressed(x, y, imagesChunky::bitmaps::cabi, WHITE);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount, text::bitmapsCompMasked, i); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::bitmapsCompMasked, testRepeats);
#endif


    logConsole(text::horizontalRule);           // "---------------------\n\n"

}
