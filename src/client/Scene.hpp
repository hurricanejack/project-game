#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

using sf::RenderWindow;
using sf::Time;
using sf::Event;

class Scene
{
	private:

	protected:
		Scene* nextScene;

	public:
		Scene();

		// Scene events
		virtual void pollEvent(Event&);
		virtual void update(const RenderWindow&, const Time&);
		virtual void draw(RenderWindow&);

		Scene* getNextScene();

};