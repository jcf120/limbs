#include "Renderer.h"

#ifdef __APPLE__
  // Mac Includes Here
    #include <OpenGL/gl.h>
#endif

#if defined(_WIN32) || defined(_WIN64)
  // Windows Includes Here
	#include <windows.h>
	#include <GL/gl.h>
#endif


Renderer::Renderer(void)
{
}


Renderer::~Renderer(void)
{
}


void Renderer::Render()
{
	glClearColor(0.0f, 0.0f, 0.0f, 255.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}


void Renderer::SetupViewport()
{

}