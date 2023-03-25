#include "Sandbox.h"

Sandbox::Sandbox()
{

}

Sandbox::~Sandbox()
{

}

Awe::Application* Awe::CreateApplication()
{
	return new Sandbox();
}


