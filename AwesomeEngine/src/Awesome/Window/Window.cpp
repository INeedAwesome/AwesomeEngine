#include "pchawe.h"
#include "Window.h"

namespace Awe {

	Window::Window(const wchar_t* title, uint32_t width, uint32_t height)
		: m_Title(title), m_Width(width), m_Height(height), m_HWND(nullptr)
	{
		{
			m_WndClass.style = 0;
			m_WndClass.lpfnWndProc = WindowProcedure;
			m_WndClass.cbClsExtra = 0;
			m_WndClass.cbWndExtra = 0;
			m_WndClass.hInstance = GetInstance();
			m_WndClass.hIcon = 0;
			m_WndClass.hCursor = 0;
			m_WndClass.hbrBackground = 0;
			m_WndClass.lpszMenuName = 0;
			m_WndClass.lpszClassName = ClassName();
			
			RegisterClass(&m_WndClass);
		}
		
		DWORD style = WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU;

		RECT rect;
		{
			rect.left = 250;
			rect.top = 250;
			rect.right = rect.left + m_Width;
			rect.bottom = rect.top + m_Height;
		}

		AdjustWindowRect(&rect, style, false);

		m_HWND = CreateWindowEx(
			/*extra styles*/ 0,
			/*class name*/ ClassName(),
			/*title*/ m_Title,
			/*style*/ style,
			/*pos x*/ rect.left,
			/*pos y*/ rect.top,
			/*size x*/ rect.right - rect.left,
			/*size y*/ rect.bottom - rect.top,
			/*hwnd parent*/ 0,
			/*hMenu*/ 0,
			/*hInstance*/ GetInstance(),
			/*lpParam*/ 0
		);

		if (m_HWND == 0)
		{
			std::cout << "ERROR WINDOW" << std::endl;
			return;
		}

		ShowWindow(m_HWND, SW_SHOW);
	}
	
	Window::~Window()
	{
		UnregisterClass(ClassName(), GetInstance());
	}

	int32_t Window::ShouldClose()
	{
		MSG msg = { };
		while (PeekMessageW(&msg, NULL, 0, 0, PM_REMOVE) > 0)
		{
			if (msg.message == WM_QUIT)
			{
				return 1;
			}

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		return 0;
	}

	LRESULT WindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		switch (message)
		{
		case WM_CLOSE:
		{
			if (MessageBox(hwnd, L"Really quit?", L"Awesome Engine.", MB_OKCANCEL) == IDOK)
			{
				DestroyWindow(hwnd);
			}
		}
		case WM_DESTROY:
		{
			PostQuitMessage(0);
		}

		default:
			return DefWindowProc(hwnd, message, wParam, lParam);
		}
	}

}
