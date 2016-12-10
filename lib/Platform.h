#ifndef PLATFORM_H
#define PLATFORM_H

#include "GraphicsDevice.h"
#include "InputReader.h"
#include "GameInterface.h"

// note: we marked these global variables as extern to avoid linker errors

// global reference to the graphics device and input reader
// as this program is render agnostic, any script can
// import the Game.h file and change these to their platform specific overrides
extern GraphicsDevice* graphicsDevice;
extern InputReader* inputReader;
extern GameInterface* gameInterface;

#endif