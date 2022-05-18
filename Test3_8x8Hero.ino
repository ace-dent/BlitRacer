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
        benchmark(loopCount); // Benchmark for given loops
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
        benchmark(loopCount); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::spritesBOverwrite, testRepeats, newLine);
#endif


#ifdef TEST_FX_CHIP
    FX::drawBitmap(x, y, FXlogo, 0, dbmNormal);
    FX::display(CLEAR_BUFFER);
#endif

    /* --- */


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
        benchmark(loopCount); // Benchmark for given loops
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
        benchmark(loopCount); // Benchmark for given loops
        arduboy.fillScreen(WHITE); // Clear to 'white' for next render
    }
    logConsoleAveragedResult(text::spritesBErase, testRepeats);
#endif


    invertScreen(false);


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
        benchmark(loopCount); // Benchmark for given loops
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
        benchmark(loopCount); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::spritesBSelfMask, testRepeats);
#endif


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
        benchmark(loopCount); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::bitmapsStd, testRepeats);


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
        benchmark(loopCount); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::bitmapsSlow, testRepeats);
    
    
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
        benchmark(loopCount); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::bitmapsComp, testRepeats, newLine);


    /* --- */


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
        benchmark(loopCount); // Benchmark for given loops
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
        benchmark(loopCount); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::spritesBExtMask, testRepeats);
#endif


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
        benchmark(loopCount); // Benchmark for given loops
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
        benchmark(loopCount); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::spritesBPlusMask, testRepeats);
#endif


    // --- Sprites::drawSelfMasked with extra masking step ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < testRepeats; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < yEnd; y = y + yStep) {
            for (int16_t x = xStart; x < xEnd; x = x + xStep) {
                Sprites::drawErase(x, y, images8x8::sprites::mask, (i % 3));
                Sprites::drawSelfMasked(x, y, images8x8::sprites::std, (i % 3));
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::spritesEraseMasked, testRepeats);


#ifdef TEST_SPRITES_B
    // --- SpritesB::drawSelfMasked with extra masking step ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < testRepeats; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < yEnd; y = y + yStep) {
            for (int16_t x = xStart; x < xEnd; x = x + xStep) {
                SpritesB::drawErase(x, y, images8x8::sprites::mask, (i % 3));
                SpritesB::drawSelfMasked(x, y, images8x8::sprites::std, (i % 3));
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
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
        benchmark(loopCount); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::bitmapsStdMasked, testRepeats);


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
        benchmark(loopCount); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::bitmapsSlowMasked, testRepeats);


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
        benchmark(loopCount); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::bitmapsCompMasked, testRepeats);


    logConsole(text::horizontalRule);           // "---------------------\n\n"

}
