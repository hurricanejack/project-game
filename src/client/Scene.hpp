#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

using sf::RenderWindow;
using sf::Time;

class Scene
{
	private:

	protected:
		Scene* nextScene;

	public:
		Scene();

		// Scene events
		virtual void update(const RenderWindow&, const Time&);
		virtual void draw(RenderWindow&);

		Scene* getNextScene();

};