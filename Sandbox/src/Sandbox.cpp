#include "Awesome.h"

class Sandbox : public Awe::Application
{
public:
	Sandbox();
	~Sandbox();

private:

};

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


