#include "Sandbox.h"

Sandbox::Sandbox()
{
	std::cout << "From sandbox" << std::endl;
}

Sandbox::~Sandbox()
{

}

Awe::Application* Awe::CreateApplication()
{
	return new Sandbox();
}


