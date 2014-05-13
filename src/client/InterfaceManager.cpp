#include "InterfaceManager.hpp"

#include "InterfaceWorldEditor.hpp"
#include "InterfaceWorldEditorFirst.hpp"
#include "InterfaceMenuMain.hpp"

#include <iostream>
using namespace std;

InterfaceManager::InterfaceManager()
{
	in = 0;
	userData = 0;
	scene = 0;
}

InterfaceManager::~InterfaceManager()
{
	
	if (in != 0){ in->remove(desktop);  delete in; }
	desktop.RemoveAll();
	desktop.Refresh();

	desktop.Update(1.0f);
	
	cout << "~IMANAGE" << endl;

}

void InterfaceManager::setScene(Scene* s)
{
	scene = s;
}

void InterfaceManager::set(const int& i)
{
	if (in != 0)
	{
		in->remove(desktop);
		delete in;
	}

	desktop.RemoveAll();
	desktop.Refresh();

	desktop.Update(1.0f);
	
	in = 0;

	switch (i)
	{
		case INTERFACE_MENU_MAIN:				in = new InterfaceMenuMain(scene);			break;
		case INTERFACE_WORLD_EDITOR_FIRST:		in = new InterfaceWorldEditorFirst(scene);	break;
		case INTERFACE_WORLD_EDITOR_MAIN:		in = new InterfaceWorldEditor(scene);		break;
	}

	if (in == 0){ return; }

	in->setup(desktop);
}

Interface* InterfaceManager::getInterface()
{
	return in;
}

void InterfaceManager::pollEvent(Event& event)
{
	desktop.HandleEvent(event);
}

void InterfaceManager::update(const RenderWindow& window, const Time& time)
{
	desktop.Update(1.0f);
}

void InterfaceManager::draw(RenderWindow& window)
{
	gui.Display(window);
}

void InterfaceManager::setUser(void* user)
{
	userData = user;
	if (in != 0)
	{
		in->setUser(userData);
	}
}

void* InterfaceManager::getUser()
{
	return userData;
}