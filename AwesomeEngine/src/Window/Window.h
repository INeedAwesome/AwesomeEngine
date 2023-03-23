#pragma once

#include <Windows.h>

namespace Awe {

	class Window
	{
	public:
		Window();
		~Window();

	private:
		HWND m_HWND;

	};
}
