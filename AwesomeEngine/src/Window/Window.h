#pragma once
#include "pchawe.h"

namespace Awe {

	class Window
	{
	public:
		Window(const wchar_t* title, uint32_t width, uint32_t height, WNDPROC windowProcedure);
		~Window();

		void Open();
		void Close();

		inline void SetStopProcedure(int32_t& running) { m_Running = &running; }

	private:
		const HINSTANCE GetInstance() { return GetModuleHandle(nullptr); }
		const PCWSTR ClassName() { return L"Awesome_Engine"; }

		const wchar_t* m_Title;
		uint32_t m_Width;
		uint32_t m_Height;

		HWND m_HWND;
		WNDCLASS wc = { 0 };

		int32_t* m_Running;
		WNDPROC m_WindowProcedure;
		

		
	};

}

