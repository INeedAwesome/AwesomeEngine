#include "Application.h"
#include "Awesome.h"

#ifndef _DIST 

int main(int argc, char** argv)
{
	Awe::Print();

	return 0;
}

#endif // _DIST

#ifdef _DIST

INT WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd )
{
	Awesome::Print();

	return 0;
}

#endif // _DIST
