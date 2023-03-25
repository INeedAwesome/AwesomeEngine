#include "pchawe.h"
#include "Application.h"

#include "Window/Window.h"

namespace Awe {


	Application::Application()
	{
		m_Running = 1;
		// Init window
		m_Window = new Awe::Window(L"Want some extra juice!", 1280, 720, WindowProcedure);
		m_Window->Open(); // WIP
		m_Window->SetStopProcedure(m_Running);

		m_Window->Close();


		// init graphics api
		// init some extra
	}

	Application::~Application()
	{
		delete m_Window;
	}

	void Application::Run()
	{
		while (m_Running)
		{
			MSG msg = { };
			while (GetMessage(&msg, NULL, 0, 0) > 0)
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
	}


	LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		switch (message)
		{
		case WM_CLOSE:
		{
			if (MessageBox(hwnd, L"Really quit?", L"Awesome Engine.", MB_OKCANCEL) == IDOK)
			{
				PostQuitMessage(0);
			}
		}

		default:
			return DefWindowProc(hwnd, message, wParam, lParam);
		}
	}

}