#include "include/Viewport.h"


void CreateViewport(Viewport* viewport, int x, int y, int width, int height)
{
	SetViewport(viewport, x, y, width, height);
}

void inline SetViewport(Viewport* viewport, int x, int y, int width, int height)
{
	viewport->x = x;
	viewport->y = y;
	viewport->width = width;
	viewport->height = height;
}

void UseViewport(Viewport* viewport)
{
	glViewport(viewport->x, viewport->y, viewport->width, viewport->height);
}