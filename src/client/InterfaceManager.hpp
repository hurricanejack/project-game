#include "Interface.hpp"
#include "Interfaces.hpp"

#pragma once

#include "Scene.hpp"
#include <SFGUI\SFGUI.hpp>
#include <SFML\Graphics.hpp>

using sf::RenderWindow;
using sf::Time;
using sf::Event;

class InterfaceManager
{
	private:
		Interface* in;
		sfg::SFGUI gui;
		sfg::Desktop desktop;
		Scene* scene;
	public:
		InterfaceManager();
		~InterfaceManager();

		void setScene(Scene* s);
		void set(const int&);

		void pollEvent(Event&);
		void update(const RenderWindow&, const Time&);
		void draw(RenderWindow&);
};

