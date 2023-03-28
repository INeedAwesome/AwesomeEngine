#pragma once
#include "pchawe.h"

namespace Awe {

	class Window
	{
	public:
		Window(const wchar_t* title, uint32_t width, uint32_t height);
		~Window();

		Window(const Window&) = delete;

		static Window& Get() 
		{ 
			static Window s_Instance;
			return s_Instance; 
		}

		int32_t ShouldClose();
		HWND GetHWND() { return m_HWND; }

	private:
		Window() {};
		const HINSTANCE GetInstance() { return GetModuleHandle(nullptr); }
		const wchar_t* ClassName() { return L"Awesome_Engine"; }

		const wchar_t* m_Title;
		uint32_t m_Width;
		uint32_t m_Height;

		HWND m_HWND;
		WNDCLASS m_WndClass = { 0 };

	};

	LRESULT WindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);



}

