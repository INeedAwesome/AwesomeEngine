#pragma once

namespace Awe {

	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();


	};

	// define in client
	Application* CreateApplication();
}
