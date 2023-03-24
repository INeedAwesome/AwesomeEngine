#pragma once

extern Awe::Application* Awe::CreateApplication();

#ifndef _DIST 
int main(int argc, char** argv)
#endif // _DIST
#ifdef _DIST
INT WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
#endif // _DIST
{
	auto app = Awe::CreateApplication();
	app->Run();
	delete app;

	return 0;
}
