#pragma once

#include <windows.h>

namespace Limbs {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainWindow
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		MainWindow(void)
		{
			InitializeComponent();
			Console::WriteLine("Main");
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: OpenGL::OpenGLControl^  openGLControl1;
	protected: 

	protected: 


	private: System::ComponentModel::IContainer^  components;
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->openGLControl1 = (gcnew OpenGL::OpenGLControl());
			this->SuspendLayout();
			// 
			// openGLControl1
			// 
			this->openGLControl1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left));
			this->openGLControl1->Location = System::Drawing::Point(0, 0);
			this->openGLControl1->Name = L"openGLControl1";
			this->openGLControl1->Size = System::Drawing::Size(240, 334);
			this->openGLControl1->TabIndex = 0;
			this->openGLControl1->Text = L"openGLControl1";
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(504, 332);
			this->Controls->Add(this->openGLControl1);
			this->Name = L"MainWindow";
			this->Text = L"MainWindow";
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
