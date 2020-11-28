#pragma once

#include "sdl_header.h"
#include <stdint.h>

// Color Format Def:  0xffffffff
//                      R G B A

void GetColorRGBA(uint32_t color, uint8_t* outR, uint8_t* outG, uint8_t* outB, uint8_t* outA);

uint8_t GetColorR(uint32_t color);

uint8_t GetColorG(uint32_t color);

uint8_t GetColorB(uint32_t color);

uint8_t GetColorA(uint32_t color);

