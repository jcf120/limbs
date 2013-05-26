#pragma once


#include <windows.h>
#include <GL/gl.h>

#using <System.dll>
#using <System.Windows.Forms.dll>


using namespace System;
using namespace System::Windows::Forms;

namespace Limbs
{

	public ref class OpenGLControl : public System::Windows::Forms::Control
	{

	public:
		OpenGLControl();

		virtual Void Render(Void);

		Void SwapOpenGLBuffers(Void);

	private:
		HDC m_hDC;
		HGLRC m_hglrc;

	protected:

		~OpenGLControl();

		GLint InternalSetPixelFormat(HDC hdc);
	};

}