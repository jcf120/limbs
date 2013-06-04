// This is the main DLL file.

#include "stdafx.h"

#include "OpenGL.h"

using namespace OpenGL;

OpenGLControl::OpenGLControl()
{
	m_hDC = GetDC((HWND)this->Handle.ToPointer());

	if(m_hDC)
		Create30Context(m_hDC);
}

Void OpenGLControl::RenderScene(Void)
{
	glViewport(0, 0, Width, Height); // Set the viewport size to fill the window
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT); // Clear required buffers
	SwapBuffers(m_hDC);
}

OpenGLControl::~OpenGLControl(System::Void)
{
	wglMakeCurrent(m_hDC, 0); // Remove the rendering context from our device context
    wglDeleteContext(m_hglrc); // Delete our rendering context

	this->DestroyHandle();
}

bool OpenGLControl::Create30Context(HDC hdc) {

	PIXELFORMATDESCRIPTOR pfd ;
	memset(&pfd, 0, sizeof(PIXELFORMATDESCRIPTOR));
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1; 
	pfd.dwFlags = PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;  
	pfd.iPixelType = PFD_TYPE_RGBA; 
	pfd.cColorBits = 32;
	pfd.cDepthBits = 32; 
	pfd.iLayerType = PFD_MAIN_PLANE;
	   
	int nPixelFormat = ChoosePixelFormat(hdc, &pfd);
 
	if (nPixelFormat == 0) return false; 

	BOOL bResult = SetPixelFormat (hdc, nPixelFormat, &pfd);
   
	if (!bResult) return false; 

	// --- OpenGL 3.x ---
	HGLRC tempContext = wglCreateContext(hdc); 
	wglMakeCurrent(hdc,tempContext);

	InitAPI();

	int major, minor;
	GetGLVersion(&major, &minor);

	if( major < 3 || ( major == 3 && minor < 2 ) )
		Console::WriteLine("OpenGL 3.2 is not supported!");

	int attribs[] =
	{
		WGL_CONTEXT_MAJOR_VERSION_ARB, major,
		WGL_CONTEXT_MINOR_VERSION_ARB, minor, 
		WGL_CONTEXT_FLAGS_ARB, WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB,
		WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
		0
	};

	PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB = NULL;
	wglCreateContextAttribsARB = (PFNWGLCREATECONTEXTATTRIBSARBPROC) wglGetProcAddress("wglCreateContextAttribsARB");
	if(wglCreateContextAttribsARB != NULL)
	{
		m_hglrc = wglCreateContextAttribsARB(hdc,0, attribs);
	}

	wglMakeCurrent(NULL,NULL); 
	wglDeleteContext(tempContext);

 
	if (!m_hglrc) 
	{
		Console::WriteLine("OpenGL 3.x RC was not created!");
		return false; 
	}

	return true; // We have successfully created a context, return true
}

Void OpenGLControl::InitAPI()
{
	// Program
	glCreateProgram =  (PFNGLCREATEPROGRAMPROC)wglGetProcAddress("glCreateProgram");
	glDeleteProgram = (PFNGLDELETEPROGRAMPROC)wglGetProcAddress("glDeleteProgram");
	glUseProgram = (PFNGLUSEPROGRAMPROC)wglGetProcAddress("glUseProgram");
	glAttachShader = (PFNGLATTACHSHADERPROC)wglGetProcAddress("glAttachShader");
	glDetachShader = (PFNGLDETACHSHADERPROC)wglGetProcAddress("glDetachShader");
	glLinkProgram = (PFNGLLINKPROGRAMPROC)wglGetProcAddress("glLinkProgram");
	glGetProgramiv = (PFNGLGETPROGRAMIVPROC)wglGetProcAddress("glGetProgramiv");
	glGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC)wglGetProcAddress("glGetShaderInfoLog");
	glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC)wglGetProcAddress("glGetUniformLocation");
	glUniform1i = (PFNGLUNIFORM1IPROC)wglGetProcAddress("glUniform1i");
	glUniform1iv = (PFNGLUNIFORM1IVPROC)wglGetProcAddress("glUniform1iv");
	glUniform2iv = (PFNGLUNIFORM2IVPROC)wglGetProcAddress("glUniform2iv");
	glUniform3iv = (PFNGLUNIFORM3IVPROC)wglGetProcAddress("glUniform3iv");
	glUniform4iv = (PFNGLUNIFORM4IVPROC)wglGetProcAddress("glUniform4iv");
	glUniform1f = (PFNGLUNIFORM1FPROC)wglGetProcAddress("glUniform1f");
	glUniform1fv = (PFNGLUNIFORM1FVPROC)wglGetProcAddress("glUniform1fv");
	glUniform2fv = (PFNGLUNIFORM2FVPROC)wglGetProcAddress("glUniform2fv");
	glUniform3fv = (PFNGLUNIFORM3FVPROC)wglGetProcAddress("glUniform3fv");
	glUniform4fv = (PFNGLUNIFORM4FVPROC)wglGetProcAddress("glUniform4fv");
	glUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVPROC)wglGetProcAddress("glUniformMatrix4fv");
	glGetAttribLocation = (PFNGLGETATTRIBLOCATIONPROC)wglGetProcAddress("glGetAttribLocation");
	glVertexAttrib1f = (PFNGLVERTEXATTRIB1FPROC)wglGetProcAddress("glVertexAttrib1f");
	glVertexAttrib1fv = (PFNGLVERTEXATTRIB1FVPROC)wglGetProcAddress("glVertexAttrib1fv");
	glVertexAttrib2fv = (PFNGLVERTEXATTRIB2FVPROC)wglGetProcAddress("glVertexAttrib2fv");
	glVertexAttrib3fv = (PFNGLVERTEXATTRIB3FVPROC)wglGetProcAddress("glVertexAttrib3fv");
	glVertexAttrib4fv = (PFNGLVERTEXATTRIB4FVPROC)wglGetProcAddress("glVertexAttrib4fv");
	glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC)wglGetProcAddress("glEnableVertexAttribArray");
	glBindAttribLocation = (PFNGLBINDATTRIBLOCATIONPROC)wglGetProcAddress("glBindAttribLocation");

	// Shader
	glCreateShader = (PFNGLCREATESHADERPROC)wglGetProcAddress("glCreateShader");
	glDeleteShader = (PFNGLDELETESHADERPROC)wglGetProcAddress("glDeleteShader");
	glShaderSource = (PFNGLSHADERSOURCEPROC)wglGetProcAddress("glShaderSource");
	glCompileShader = (PFNGLCOMPILESHADERPROC)wglGetProcAddress("glCompileShader");
	glGetShaderiv = (PFNGLGETSHADERIVPROC)wglGetProcAddress("glGetShaderiv");

	// VBO
	glGenBuffers = (PFNGLGENBUFFERSPROC)wglGetProcAddress("glGenBuffers");
	glBindBuffer = (PFNGLBINDBUFFERPROC)wglGetProcAddress("glBindBuffer");
	glBufferData = (PFNGLBUFFERDATAPROC)wglGetProcAddress("glBufferData");
	glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC)wglGetProcAddress("glVertexAttribPointer");
}

Void OpenGLControl::GetGLVersion(int* major, int* minor)
{
      // for all versions
      char* ver = (char*)glGetString(GL_VERSION); // ver = "3.2.0"

      *major = ver[0] - '0';
      if( *major >= 3)
      {
       // for GL 3.x
       glGetIntegerv(GL_MAJOR_VERSION, major); // major = 3
       glGetIntegerv(GL_MINOR_VERSION, minor); // minor = 2
      }
      else
      {
            *minor = ver[2] - '0';
      }

      // GLSL
      ver = (char*)glGetString(GL_SHADING_LANGUAGE_VERSION); // ver = "1.50 NVIDIA via Cg compiler"
}