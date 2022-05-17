/* 
 *  Benchmark: 8x8 Hero
 */
#include <ArduboyFX.h>

constexpr uint24_t Hero8x8_FX[] = { 
    Images::Hero8x8_frame0,
    Images::Hero8x8_frame1,
    Images::Hero8x8_frame2,
};

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
    for (uint8_t i = 0; i < 3; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < yEnd; y = y + yStep) {
            for (int16_t x = xStart; x < xEnd; x = x + xStep) {
                Sprites::drawOverwrite(x, y, images8x8::sprites::std, i);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::spritesOverwrite, 3);


#ifdef TEST_SPRITES_B
    // --- SpritesB::drawOverwrite ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < 3; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < yEnd; y = y + yStep) {
            for (int16_t x = xStart; x < xEnd; x = x + xStep) {
                SpritesB::drawOverwrite(x, y, images8x8::sprites::std, i);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::spritesBOverwrite, 3, newLine);
#endif

    /* --- */


    invertScreen(true); 


    // --- Sprites::drawErase ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < 3; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < yEnd; y = y + yStep) {
            for (int16_t x = xStart; x < xEnd; x = x + xStep) {
                Sprites::drawErase(x, y, images8x8::sprites::std, i);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
        arduboy.fillScreen(WHITE); // Clear to 'white' for next render
    }
    logConsoleAveragedResult(text::spritesErase, 3);


#ifdef TEST_SPRITES_B
    // --- SpritesB::drawErase ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < 3; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < yEnd; y = y + yStep) {
            for (int16_t x = xStart; x < xEnd; x = x + xStep) {
                SpritesB::drawErase(x, y, images8x8::sprites::std, i);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
        arduboy.fillScreen(WHITE); // Clear to 'white' for next render
    }
    logConsoleAveragedResult(text::spritesBErase, 3);
#endif


    invertScreen(false);


    // --- Sprites::drawSelfMasked ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < 3; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < yEnd; y = y + yStep) {
            for (int16_t x = xStart; x < xEnd; x = x + xStep) {
                Sprites::drawSelfMasked(x, y, images8x8::sprites::std, i);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::spritesSelfMask, 3);


#ifdef TEST_SPRITES_B
    // --- SpritesB::drawSelfMasked ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < 3; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < yEnd; y = y + yStep) {
            for (int16_t x = xStart; x < xEnd; x = x + xStep) {
                SpritesB::drawSelfMasked(x, y, images8x8::sprites::std, i);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::spritesBSelfMask, 3);
#endif


    // --- arduboy.drawBitmap ~ Sprites::drawSelfMasked ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < 3; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < yEnd; y = y + yStep) {
            for (int16_t x = xStart; x < xEnd; x = x + xStep) {
                arduboy.drawBitmap(x, y, images8x8::bitmaps::std[i], heroWidth, heroHeight, WHITE);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::bitmapsStd, 3);


    // --- arduboy.drawSlowXYBitmap ~  Sprites::drawSelfMasked ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < 3; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < yEnd; y = y + yStep) {
            for (int16_t x = xStart; x < xEnd; x = x + xStep) {
                arduboy.drawSlowXYBitmap(x, y, images8x8::bitmaps::slow[i], heroWidth, heroHeight, WHITE);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::bitmapsSlow, 3);
    
    
    // --- arduboy.drawCompressed ~  Sprites::drawSelfMasked ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < 3; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < yEnd; y = y + yStep) {
            for (int16_t x = xStart; x < xEnd; x = x + xStep) {
                arduboy.drawCompressed(x, y, images8x8::bitmaps::cabi[i], WHITE);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::bitmapsComp, 3, newLine);


    /* --- */


    // --- Sprites::drawExternalMask ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < 3; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < yEnd; y = y + yStep) {
            for (int16_t x = xStart; x < xEnd; x = x + xStep) {
                Sprites::drawExternalMask(x, y, images8x8::sprites::std, images8x8::sprites::mask, i, i);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::spritesExtMask, 3);


    // --- SpritesB::drawExternalMask ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < 3; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < yEnd; y = y + yStep) {
            for (int16_t x = xStart; x < xEnd; x = x + xStep) {
                SpritesB::drawExternalMask(x, y, images8x8::sprites::std, images8x8::sprites::mask, i, i);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::spritesBExtMask, 3);


    // --- Sprites::drawPlusMask ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < 3; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < yEnd; y = y + yStep) {
            for (int16_t x = xStart; x < xEnd; x = x + xStep) {
                Sprites::drawPlusMask(x, y, images8x8::sprites::plusMask, i);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::spritesPlusMask, 3);


    // --- SpritesB::drawPlusMask ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < 3; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < yEnd; y = y + yStep) {
            for (int16_t x = xStart; x < xEnd; x = x + xStep) {
                SpritesB::drawPlusMask(x, y, images8x8::sprites::plusMask, i);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
    }
    logConsoleAveragedResult(text::spritesBPlusMask, 3);


    // --- Sprites::drawSelfMasked with extra masking step ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < 3; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < yEnd; y = y + yStep) {
            for (int16_t x = xStart; x < xEnd; x = x + xStep) {
                Sprites::drawErase(x, y, images8x8::sprites::mask, i);
                Sprites::drawSelfMasked(x, y, images8x8::sprites::std, i);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
        
    }
    logConsoleAveragedResult(text::spritesEraseMasked, 3);
    
    
    // --- arduboy.drawBitmap with extra masking step ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < 3; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < yEnd; y = y + yStep) {
            for (int16_t x = xStart; x < xEnd; x = x + xStep) {
                arduboy.drawBitmap(x, y, images8x8::bitmaps::stdMask[i], heroWidth, heroHeight, BLACK);
                arduboy.drawBitmap(x, y, images8x8::bitmaps::std[i], heroWidth, heroHeight, WHITE);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
        
    }
    logConsoleAveragedResult(text::bitmapsStdMasked, 3);
    
    
    // --- arduboy.drawSlowXYBitmap with extra masking step ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < 3; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < yEnd; y = y + yStep) {
            for (int16_t x = xStart; x < xEnd; x = x + xStep) {
                arduboy.drawSlowXYBitmap(x, y, images8x8::bitmaps::slowMask[i], heroWidth, heroHeight, BLACK);
                arduboy.drawSlowXYBitmap(x, y, images8x8::bitmaps::slow[i], heroWidth, heroHeight, WHITE);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
        
    }
    logConsoleAveragedResult(text::bitmapsSlowMasked, 3);
    
    
    // --- arduboy.drawCompressed with extra masking step ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < 3; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < yEnd; y = y + yStep) {
            for (int16_t x = xStart; x < xEnd; x = x + xStep) {
                arduboy.drawCompressed(x, y, images8x8::bitmaps::cabiMask[i], BLACK);
                arduboy.drawCompressed(x, y, images8x8::bitmaps::cabi[i], WHITE);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
        
    }
    logConsoleAveragedResult(text::bitmapsCompMasked, 3);
    

    // --- fx data ---
    benchAverage = 0.0F; // Reset running average
    for (uint8_t i = 0; i < 3; i = i + 1) {
        benchStartTime = millis();
        for (int16_t y = yStart; y < yEnd; y = y + yStep) {
            for (int16_t x = xStart; x < xEnd; x = x + xStep) {
                FX::drawBitmap(23, 48, Hero8x8_FX[i], 0, dbmNormal);
                FX::drawBitmap(23, 48, Hero8x8_FX[i], 0, dbmNormal);
            }
        }
        benchEndTime = millis();
        benchmark(loopCount); // Benchmark for given loops
        
    }
    logConsoleAveragedResult(text::bitmapsCompMasked, 3);
    logConsole(text::horizontalRule);           
    
}
