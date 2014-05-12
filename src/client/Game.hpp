#pragma once

#include "Player.hpp"
#include "World.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

using sf::RenderWindow;
using sf::Time;

class Game
{
	private:
		//World world;
		Player player{ 20.0f, 40.0f };

		float32 timeStep = 1 / 60.0;
		int32 velocityIterations = 6;
		int32 positionIterations = 2;

	public:
		Game();
		~Game();

		void update(const RenderWindow&, const Time&);
		void draw(RenderWindow&);

		Player& getPlayer();
};


