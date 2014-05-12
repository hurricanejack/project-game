#include "GameObject.hpp"

GameObject::GameObject()
{
	physics.body = 0;
}

GameObject::~GameObject()
{
	if (hasBody())
	{
		bodyRemoveList.push_back(physics.body);
	}
}

void GameObject::update(const RenderWindow& window)
{

	// Update variables due to physics simulation
	if (hasBody())
	{
		b2Vec2 pos = physics.body->GetPosition();
		float  ang = physics.body->GetAngle();

		x = pos.x;
		y = pos.y;

		angle = ang;

	}

}

void GameObject::draw(RenderWindow&)
{

}
bool GameObject::hasBody()
{
	return (physics.body != 0);
}

Vector2<float> GameObject::getPosition()
{
	return Vector2<float>{x, y};
}

float GameObject::getPositionY()
{
	return y;
}

float GameObject::getPositionX()
{
	return x;
}

float GameObject::getAngle()
{
	return angle;
}

void GameObject::setPosition(const Vector2<float>& pos)
{

	bool bodyExists = hasBody();

	// Retreive angle
	if (bodyExists)
	{
		angle = physics.body->GetAngle();
	}

	// Convert coordinates
	b2Vec2 vec{ (pos.x*(1.0f / PPM)), (pos.y*(1.0f / PPM)) };

	// Update body
	if (bodyExists)
	{
		physics.body->SetTransform(vec, angle);
	}

	// Update variables
	x = pos.x;
	y = pos.y;

}

void GameObject::setPosition(const float& x, const float& y)
{
	setPosition(Vector2<float>{x, y});
}

void GameObject::setAngle(const float& ang)
{

	bool bodyExists = hasBody();

	// Gather position
	b2Vec2 vec{ x, y };

	// Update body
	if (bodyExists)
	{
		vec = physics.body->GetPosition();
		physics.body->SetTransform(vec, ang);
	}

	// Update variables
	angle = ang;

}