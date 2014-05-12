#pragma once

#include <Box2D\Box2D.h>
#include <SFML/System.hpp>

using sf::Vector2f;

class World
{
	private:
		b2World* world;

	public:

		World();
		~World();

		//void setGravity(const float &x, const float &y);
		//void setGravity(const Vector2f &vec);
		b2World* operator->();
		b2World& operator*();
		operator b2World*() const;
		World& operator = (const World&);

};