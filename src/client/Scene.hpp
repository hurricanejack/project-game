#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "InterfaceManager.hpp"

using sf::RenderWindow;
using sf::Time;
using sf::Event;

class Scene
{
	private:

	protected:
		int nextScene;
		InterfaceManager interfaceManager;
		int guiWidth, guiHeight;

	public:
		Scene();

		// Scene events
		virtual void pollEvent(Event&);
		virtual void update(const RenderWindow&, const Time&);
		virtual void draw(RenderWindow&);

		int getGUIWidth();
		int getGUIHeight();

		int getNextScene();

};