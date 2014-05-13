#include "InterfaceManager.hpp"

#include "InterfaceWorldEditorFirst.hpp"
#include "InterfaceMenuMain.hpp"

InterfaceManager::InterfaceManager()
{
	in = 0;
}

InterfaceManager::~InterfaceManager()
{
	if (in != 0){ delete in; }
}

void InterfaceManager::setScene(Scene* s)
{
	scene = s;
}

void InterfaceManager::set(const int& i)
{
	if (in != 0)
	{
		delete in;
	}
	desktop.RemoveAll();
	
	in = 0;

	switch (i)
	{
		case INTERFACE_MENU_MAIN:				in = new InterfaceMenuMain(scene);		break;
		case INTERFACE_WORLD_EDITOR_FIRST:		in = new InterfaceWorldEditorFirst();	break;
	}

	if (in == 0){ return; }

	in->setup(desktop);
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