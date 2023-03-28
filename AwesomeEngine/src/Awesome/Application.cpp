#include "pchawe.h"
#include "Application.h"

#include "Window/Window.h"

namespace Awe {

	Application::Application()
	{
		this->SetRunning(1);

		// Init window
		m_Window = new Awe::Window(L"Want some extra juice!", 1280, 720);
		m_Window->SetStopProc([this]() {
			this->SetRunning(0);
		});

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
			while (PeekMessageW(&msg, NULL, 0, 0, PM_REMOVE) > 0)
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
	}

	


}