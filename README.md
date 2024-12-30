# Touhou for the Game Boy

Touhou demake

![alt text](game.png "Game")
![alt text](gameover.png "Game over")

## Dependencies

- [GBDK][GBDK] Game Boy Development Kit
- [mGBA][mGBA] Game Boy emulator
- C Compiler (gcc, ...)

## Build instructions

```sh
# Clone this repo
git clone https://github.com/chudware/touhou.git
cd touhou

# Create a build folder
mkdir build
cd build

# Build
make

# Run
mgba ./build/_Game.gb
```

***Note:*** Edit the makefile to point it to your GBDK installation

[GBDK]: https://github.com/gbdk-2020/gbdk-2020
[mGBA]: https://mgba.io/
[Git]: https://git-scm.com