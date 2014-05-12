#include "World.hpp"
#include "Common.hpp"

World::World()
{
	b2Vec2 gravity(0.0f, 0.0f);
	world = new b2World(gravity);
}

World::~World()
{
	delete world;
}
/*
void World::setGravity(const float &x, const float &y)
{
	world->SetGravity(b2Vec2(x, y));
}

void World::setGravity(const Vector2f &vec)
{
	world->SetGravity(b2Vec2(vec.x, vec.y));
}*/

b2World* World::operator->()
{
	return world;
}

b2World& World::operator*()
{
	return *world;
}

World::operator b2World*() const
{
	return world;
}

World& World::operator = (const World& w)
{
	world = w;
	return *this;
}