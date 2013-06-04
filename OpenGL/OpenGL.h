// OpenGL.h

#pragma once

#include <windows.h>

#include "..\Limbs\Common\Renderer.h"

#using <System.dll>
#using <System.Windows.Forms.dll>

using namespace System;
using namespace System::Windows::Forms;

namespace OpenGL {

	public ref class OpenGLControl : public System::Windows::Forms::Control
	{

	public:
		OpenGLControl();

		Void RenderScene(Void);

	private:
		HDC m_hDC;
		HGLRC m_hglrc;

	protected:

		~OpenGLControl();

		bool OpenGLControl::Create30Context(HDC hdc);

		Void InitAPI(Void);

		Void OpenGLControl::GetGLVersion(int* major, int* minor);
	};
}
