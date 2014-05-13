#include "Interface.hpp"

Interface::Interface()
{
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
