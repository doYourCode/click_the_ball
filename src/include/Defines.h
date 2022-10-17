#pragma once

#include <stdint.h>


typedef int32_t boolean;
#define TRUE 1
#define FALSE 0

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

struct Color
{
	float r;
	float g;
	float b;
	float a;
};
typedef Color Color;
