#include "Math.hpp"
#include "Draw.hpp"
#include <Windows.h>
#include <stdexcept>
#include <iostream>
using std::cout;
using std::endl;

#pragma once

#include "GameObject.hpp"
#include "World.hpp"
#include <SFML/System.hpp>

extern sf::Font defaultFont;


#define SECOND 1000000

const float frameTime = 16666.66666666667f;
extern int fps;
extern int tps;
extern World world;

struct _mouse
{
	public:
	float x;
	float y;
	void update( const sf::RenderWindow& window )
	{
		sf::Vector2i vec = sf::Mouse::getPosition(window);
		x = vec.x;
		y = vec.y;
	}
};

extern _mouse mouse;

void clearConsole();