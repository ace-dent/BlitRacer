/* 
 *  Benchmark: 8x8 Hero
 */

void test8x8Hero(bool byteAligned) {

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


    // Parameters for rendering loops
    constexpr int16_t xStart = -heroWidth;
    constexpr int16_t yStart = -heroHeight;
    constexpr int16_t xEnd = WIDTH + heroWidth;
    constexpr int16_t yEnd = HEIGHT + heroHeight;
    uint8_t xStep = heroWidth;
    uint8_t yStep = heroHeight;
    if (!byteAligned) {
        xStep -= 1;
        yStep -= 1;  
    }

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
                Sprites::drawOverwrite(x, y, images8x8::sprites::std, (i % 3) );
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
                SpritesB::drawOverwrite(x, y, images8x8::sprites::std, (i % 3) );
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
                Sprites::drawSelfMasked(x, y, images8x8::sprites::std, (i % 3) );
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
                SpritesB::drawSelfMasked(x, y, images8x8::sprites::std, (i % 3) );
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
                Sprites::drawErase(x, y, images8x8::sprites::std, (i % 3) );
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
                SpritesB::drawErase(x, y, images8x8::sprites::std, (i % 3) );
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
                arduboy.drawBitmap(x, y, images8x8::bitmaps::std[(i % 3)], heroWidth, heroHeight, WHITE);
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
                arduboy.drawSlowXYBitmap(x, y, images8x8::bitmaps::slow[(i % 3)], heroWidth, heroHeight, WHITE);
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
                arduboy.drawCompressed(x, y, images8x8::bitmaps::cabi[(i % 3)], WHITE);
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
                Sprites::drawPlusMask(x, y, images8x8::sprites::plusMask, (i % 3));
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
                SpritesB::drawPlusMask(x, y, images8x8::sprites::plusMask, (i % 3));
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
                Sprites::drawExternalMask(x, y, images8x8::sprites::std, images8x8::sprites::mask, (i % 3), (i % 3));
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
                SpritesB::drawExternalMask(x, y, images8x8::sprites::std, images8x8::sprites::mask, (i % 3), (i % 3));
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
                Sprites::drawErase(x, y, images8x8::sprites::eraseMask, (i % 3));
                Sprites::drawSelfMasked(x, y, images8x8::sprites::std, (i % 3));
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
                SpritesB::drawErase(x, y, images8x8::sprites::eraseMask, (i % 3));
                SpritesB::drawSelfMasked(x, y, images8x8::sprites::std, (i % 3));
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
                arduboy.drawBitmap(x, y, images8x8::bitmaps::stdMask[(i % 3)], heroWidth, heroHeight, BLACK);
                arduboy.drawBitmap(x, y, images8x8::bitmaps::std[(i % 3)], heroWidth, heroHeight, WHITE);
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
                arduboy.drawSlowXYBitmap(x, y, images8x8::bitmaps::slowMask[(i % 3)], heroWidth, heroHeight, BLACK);
                arduboy.drawSlowXYBitmap(x, y, images8x8::bitmaps::slow[(i % 3)], heroWidth, heroHeight, WHITE);
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
                arduboy.drawCompressed(x, y, images8x8::bitmaps::cabiMask[(i % 3)], BLACK);
                arduboy.drawCompressed(x, y, images8x8::bitmaps::cabi[(i % 3)], WHITE);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount, text::bitmapsCompMasked, i); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::bitmapsCompMasked, testRepeats);
#endif


    logConsole(text::horizontalRule);           // "---------------------\n\n"

}
