#pragma once
#include "pchawe.h"

namespace Awe {

	
	class Window
	{
	public:
		Window(const wchar_t* title, uint32_t width, uint32_t height);
		~Window();

		inline void SetStopProc(std::function<void()> func) { m_StopProcedure = func; }

	private:
		const HINSTANCE GetInstance() { return GetModuleHandle(nullptr); }
		const wchar_t* ClassName() { return L"Awesome_Engine"; }

		const wchar_t* m_Title;
		uint32_t m_Width;
		uint32_t m_Height;

		HWND m_HWND;
		WNDCLASS m_WndClass = { 0 };
		std::function<void()> m_StopProcedure;
		
	};

	LRESULT WindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);



}

