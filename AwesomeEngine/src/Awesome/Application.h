#pragma once

#include "Window/Window.h"

namespace Awe {

	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	private:
		int32_t m_Running;

		Awe::Window* m_Window;
	};

	LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

	// define in client
	Application* CreateApplication();
}
