# Blit Racer 🏁

Race different blitting functions on the Arduboy!
_Vrooom!!_ The smell of bytes skidding across SPI. 

- All race times are transmitted via serial USB.


## TODO

Essentials (Race Stages):

- [ ] 1x1 pixel
- [ ] Font
- [ ] 8x8 Hero (with animation)
- [ ] Chunky sprite (not modulo 8)
- [ ] Banner
- [ ] Full screen


Extras:

- [ ] Splash screen + fun!
- [ ] Podium / stats at the end of all races.
- [ ] Record core temperature at start and end of run. Does this affect clock oscillator and correlate to variance? `power_adc_enable(); // Re-enable Analog to Digital Converter module for temperature reading`. [1](http://web.archive.org/web/20180820131636/http://www.narkidae.com/research/atmega-core-temperature-sensor/) [2](https://github.com/MLXXXp/Arduboy2/pull/8/commits/c962257488bc4c8e7f12c66cfcd9e91990151b39)
- [ ] Explicitly stop compiler inlining any of the blitting functions. Test benefit of [inlining](https://www.youtube.com/watch?v=kmHyRaiJLpQ)? 



Other formats to add:

- [ ] SpritesB!! (Consider how best to add to the existing test framework)
- [ ] [ArdBitmap](https://github.com/igvina/ArdBitmap) [forum](https://community.arduboy.com/t/ardbitmap-bitmap-library-tools/2631)
- [ ] [FX::drawBitmap](https://github.com/MrBlinky/Arduboy-homemade-package/blob/694837952dbfb74ea8326cf009717cccf530b78b/board-package-source/libraries/ArduboyFX/src/ArduboyFX.h#L42-L64) (Perhaps use `#define FX_BUILD` for original hardware compatibility?)


## Acknowledgements

Heavily inspired by @SyncChannel's [Arduino_Speed_Tests](https://gist.github.com/SyncChannel/1e509ae9e8a34cc1e56a).

Special thanks to @bateske, @filmote, @joshgoebel, @MLXXXp, @MrBlinky, @Pharap.

Images converted using:

 - [ABSpriteEditor](https://github.com/Pharap/ABSpriteEditor)
 - [image2cpp](http://javl.github.io/image2cpp/)
 - [cabi](https://github.com/MLXXXp/Arduboy2/tree/master/extras/cabi)