#include "Object.hpp"

Object::Object(b2World* w)
:world(*w)
{
	x = 0.0f;
	y = 0.0f;
	body = 0;
}

void Object::update(const RenderWindow&, const Time&)
{

}

void Object::draw(RenderWindow& window)
{

}