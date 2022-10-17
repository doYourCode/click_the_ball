#include <stdio.h>

#define GLT_IMPLEMENTATION
#include "../vendor/include/glText.h"

#include "include/TextRenderer.h"


GLTtext* text1;
GLTtext* text2;
int count = 0;


void CreateTextRenderer(TextRenderer* textRenderer, Viewport* viewport)
{
	textRenderer->viewport = viewport;

	if (!gltInit())
	{
		fprintf(stderr, "Failed to initialize glText\n");
	}
}

void DeleteTextRenderer(TextRenderer* textRenderer)
{
	////////////////////////////////////////////////////////////////   TEXT RENDERING
	gltDeleteText(text1);
	gltDeleteText(text2);
	////////////////////////////////////////////////////////////////   TEXT RENDERING

	gltTerminate();
}

void DrawTextRenderer(TextRenderer* textRenderer)
{
	////////////////////////////////////////////////////////////////   TEXT RENDERING


	if (!gltInit())
	{
		fprintf(stderr, "Failed to initialize glText\n");     //// PQ não funciona a partir do outro código?
	}

	text1 = gltCreateText();

	char str2[5];
	_itoa_s(count, str2, 10); count++;
	gltSetText(text1, str2);

	text2 = gltCreateText();

	int viewportWidth = 1280, viewportHeight = 720;
	double time = 1;
	char str[30];
	////////////////////////////////////////////////////////////////   TEXT RENDERING

			////////////////////////////////////////////////////////////////   TEXT RENDERING
	//glViewport(0, 0, viewportWidth, viewportHeight);
	//glClear(GL_COLOR_BUFFER_BIT);

	gltBeginDraw();

	gltColor(1.0f, 1.0f, 1.0f, 1.0f);
	gltDrawText2D(text1, 0.0f, 0.0f, 1.0f); // x=0.0, y=0.0, scale=1.0

	gltDrawText2DAligned(text1, (GLfloat)(viewportWidth / 2), (GLfloat)(viewportHeight / 2), 6.0f, GLT_CENTER, GLT_CENTER);

	sprintf_s(str, "Time: %.4f", time);
	gltSetText(text2, str);

	gltColor(
		1.0f,
		0.0f,
		1.0f,
		1.0f);

	gltDrawText2DAligned(text2, 0.0f, (GLfloat)viewportHeight, 1.0f, GLT_LEFT, GLT_BOTTOM);

	gltEndDraw();
	////////////////////////////////////////////////////////////////   TEXT RENDERING
}

void SetTextColor(TextRenderer* textRenderer, float r, float g, float b, float a)
{

}