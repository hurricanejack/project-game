#pragma once

#include <Box2D\Box2D.h>
#include <SFML\Graphics.hpp>

using sf::RenderWindow;
using sf::Time;

class Object
{
	private:


	protected:
		float x, y;
		b2Body* body;
		b2World& world;

	public:
		Object(b2World*);

		virtual void update(const RenderWindow&, const Time&);
		virtual void draw(RenderWindow&);

};

