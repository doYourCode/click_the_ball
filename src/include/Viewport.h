#pragma once

#define GLEW_STATIC

#include "../include/GL/glew.h"


struct Viewport
{
	int x;
	int y;
	int width;
	int height;
};
typedef struct Viewport Viewport;

void CreateViewport(Viewport* viewport, int x, int y, int width, int height);

void SetViewport(Viewport* viewport, int x, int y, int width, int height);

void UseViewport(Viewport* viewport);