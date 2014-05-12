#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "SceneManager.hpp"

using sf::RenderWindow;
using sf::Time;

class Game
{
	private:
		SceneManager scene;
		sf::Clock splashClock;
		bool splash;

	public:
		Game();
		~Game();

		void update(const RenderWindow&, const Time&);
		void draw(RenderWindow&);
};


