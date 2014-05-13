#include "Interface.hpp"

Interface::Interface()
{
	userData = 0;
	cout << "Interface::" << getName() << " -> Construct" << endl;
}

Interface::~Interface()
{
	cout << "Interface::" << getName() << " -> Destruct" << endl;
}

string Interface::getName()
{
	return "Interface";
}

void Interface::setup(sfg::Desktop& desktop)
{

}

void Interface::remove(sfg::Desktop& desktop)
{

}

void Interface::setUser(void*r)
{
	userData = r;
}