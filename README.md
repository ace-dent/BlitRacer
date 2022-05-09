# 🏁 - Blit Racer - 🏁

Race different blitting functions on the Arduboy®!  
_Vrooom!!_ The sound of bytes tearing across SPI towards the final buffer.  

All race times are transmitted via serial USB.  


## Choose your vehicle

There are many ways to draw a bitmap image on the Arduboy®.
These blitting functions are grouped by rendering effect:

**Overwrite** (replaces any underlying background with new image data)

- `Sprites::drawOverwrite` 
- `SpritesB::drawOverwrite` 
- `FX::drawBitmap(,,,,dbmOverwrite)` (identical to `FX::drawBitmap(,,,,dbmNormal)`)
- `FX::drawBitmap(,,,,dbmReverse)` (equivalent with inverted graphics)


**Self masked** (only binary `1` in the new image replaces the underlying background)

- `Sprites::drawErase` (equivalent with inverted graphics)
- `SpritesB::drawErase` (equivalent with inverted graphics)
- `FX::drawBitmap(,,,,dbmBlack)` (equivalent with inverted graphics)
- `Sprites::drawSelfMasked`
- `SpritesB::drawSelfMasked`
- `FX::drawBitmap(,,,,dbmWhite)`
- `arduboy.drawBitmap`
- `arduboy.drawSlowXYBitmap`
- `arduboy.drawCompressed`


**Fully masked** (new images can have black, white or transparent pixels)

- `Sprites::drawExternalMask`
- `SpritesB::drawExternalMask` 
- `Sprites::drawPlusMask`
- `SpritesB::drawPlusMask`
- `FX::drawBitmap(,,,,dbmMasked)`
- `Sprites::drawSelfMasked` (with extra masking step `drawErase` for black pixels)
- `FX::drawBitmap(,,,,dbmWhite)` (with extra masking step `dbmBlack` for black pixels)
- `arduboy.drawBitmap` (with extra masking step for black pixels)
- `arduboy.drawSlowXYBitmap` (with extra masking step for black pixels)
- `arduboy.drawCompressed` (with extra masking step for black pixels)

**Special effects**

- `FX::drawBitmap(,,,,dbmInvert)` (Inverts the background using the new image)


## Race stages

Some blitting functions perform better with different content. 
A range of conditions (dimensions, frames of animation, byte alignment on rendering, etc.) are tested.

1. Monopixel (1x1px)
2. 
3. 'Hero' sprite (8x8px)
4. 
5. 
6. 

## TODO

Essentials (Race Stages):

- [x] *1* ~ 1x1 pixel
- [ ] *2* ~ Font
- [x] *3* ~ 8x8 Hero (with animation)
- [ ] *4* ~ Chunky sprite (not modulo 8)
- [ ] *5* ~ Banner
- [ ] *6* ~ Full screen


Extras:

- [ ] Add text overlay for each test(?)
- [ ] Splash screen + fun!
- [ ] Podium / stats at the end of all races.
- [ ] Record core temperature at start and end of run. Does this affect clock oscillator and correlate to variance? `power_adc_enable(); // Re-enable Analog to Digital Converter module for temperature reading`. [(1)](http://web.archive.org/web/20180820131636/http://www.narkidae.com/research/atmega-core-temperature-sensor/) [(2)](https://github.com/MLXXXp/Arduboy2/pull/8/commits/c962257488bc4c8e7f12c66cfcd9e91990151b39).
- [ ] Explicitly stop compiler inlining any of the blitting functions. Test benefit of [inlining](https://www.youtube.com/watch?v=kmHyRaiJLpQ)? 



Other formats to add:

- [ ] SpritesB!! (Consider how best to add to the existing test framework)
- [ ] [ArdBitmap](https://github.com/igvina/ArdBitmap) [(forum)](https://community.arduboy.com/t/ardbitmap-bitmap-library-tools/2631).
- [ ] [FX::drawBitmap](https://github.com/MrBlinky/Arduboy-homemade-package/blob/694837952dbfb74ea8326cf009717cccf530b78b/board-package-source/libraries/ArduboyFX/src/ArduboyFX.h#L42-L64) (Perhaps use `#define FX_BUILD` for original hardware compatibility?)


## Acknowledgements

Heavily inspired by @SyncChannel's [Arduino_Speed_Tests](https://gist.github.com/SyncChannel/1e509ae9e8a34cc1e56a).

Special thanks to @bateske, @filmote, @javl, @joshgoebel, @MLXXXp, @MrBlinky, @Pharap.

Images converted using:

 - [ABSpriteEditor](https://github.com/Pharap/ABSpriteEditor)
 - [image2cpp](http://javl.github.io/image2cpp/)
 - [cabi](https://github.com/MLXXXp/Arduboy2/tree/master/extras/cabi)


## Legal

Please read the associated LICENSE document for this software.

Arduboy® is a registered trademark of [Arduboy, Inc., USA](https://www.arduboy.com).