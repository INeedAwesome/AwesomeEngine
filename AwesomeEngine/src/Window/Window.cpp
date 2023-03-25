#include "pchawe.h"
#include "Window.h"

namespace Awe {

	Window::Window(const wchar_t* title, uint32_t width, uint32_t height, WNDPROC windowProcedure)
		: m_Title(title), m_Width(width), m_Height(height), m_HWND(nullptr), m_Running(0x00), m_WindowProcedure(windowProcedure)
	{
		std::cout << "window init" << std::endl;
	}

	Window::~Window()
	{
		std::cout << "window destruct" << std::endl;
	}

	void Window::Open()
	{
		{
			wc.style = 0;
			wc.lpfnWndProc = m_WindowProcedure;
			wc.cbClsExtra = 0;
			wc.cbWndExtra = 0;
			wc.hInstance = GetInstance();
			wc.hIcon = 0;
			wc.hCursor = 0;
			wc.hbrBackground = 0;
			wc.lpszMenuName = 0;
			wc.lpszClassName = ClassName();
		}

		RegisterClass(&wc);

		m_HWND = CreateWindowEx(
			/*extra styles*/ 0, 
			/*class name*/ ClassName(),
			/*title*/ m_Title,
			/*style*/ 0,
			/*pos x*/ CW_USEDEFAULT,
			/*pos y*/ CW_USEDEFAULT,
			/*size x*/ CW_USEDEFAULT,
			/*size y*/ CW_USEDEFAULT,
			/*hwnd parent*/ 0,
			/*hMenu*/ 0,
			/*hInstance*/ 0,
			/*lpParam*/ 0
		);

		if (m_HWND == 0)
		{
			std::cout << "ERROR WINDOW" << std::endl;
			return;
		}

		ShowWindow(m_HWND, SW_SHOW);

	}

	void Window::Close()
	{
		DestroyWindow(m_HWND);
		UnregisterClass(ClassName(), GetInstance());
		PostQuitMessage(0);
		*m_Running = 0;
	}



}