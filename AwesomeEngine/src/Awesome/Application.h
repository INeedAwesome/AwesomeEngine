#pragma once

#include "Window/Window.h"

namespace Awe {

	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void SetRunning(int32_t run) { m_Running = run; }

	private:
		Awe::Window* m_Window;
		int32_t m_Running;

	};


	// define in client
	Application* CreateApplication();
}
