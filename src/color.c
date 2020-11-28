#include "color.h"

uint8_t GetColorR(uint32_t color)
{
    return color >> 24u;
}

uint8_t GetColorG(uint32_t color)
{
    return color >> 16u;
}

uint8_t GetColorB(uint32_t color)
{
    return color >> 8u;
}

uint8_t GetColorA(uint32_t color)
{
    return color;
}

void GetColorRGBA(uint32_t color, uint8_t* outR, uint8_t* outG, uint8_t* outB, uint8_t* outA)
{
    *outR = GetColorR(color);
    *outG = GetColorG(color);
    *outB = GetColorB(color);
    *outA = GetColorA(color);
}