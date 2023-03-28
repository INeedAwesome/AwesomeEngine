#include "pchawe.h"
#include "Application.h"

#include "Window/Window.h"

namespace Awe {

	Application::Application()
	{
		this->SetRunning(1);

		// Init window
		m_Window = new Awe::Window(L"Want some extra juice!", 1280, 720);

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
			if (m_Window->ShouldClose())
			{
				std::cout << "Closing Window!" << std::endl;
				m_Running = false;
			}

			Sleep(2);
		}
	}
}