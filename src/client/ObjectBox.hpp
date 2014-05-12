#pragma once

#include <Box2D\Box2D.h>
#include <SFML\Graphics.hpp>
#include "Object.hpp"

using sf::RenderWindow;

class ObjectBox : public Object
{
	private:
		sf::RectangleShape shape;

	public:
		// Construct the box
		ObjectBox(b2World* w) :Object(w)
		{

			// Define the body
			b2BodyDef bodyDef;
			bodyDef.type = b2_dynamicBody;
			bodyDef.position.Set(32.0f, 32.0f);

			// Create the body
			body = world.CreateBody(&bodyDef);

			// Create a shape
			b2PolygonShape boxShape;
			boxShape.SetAsBox(64.0f, 64.0f);

			// Define fixture
			b2FixtureDef fixtureDef;
			fixtureDef.shape = &boxShape;
			fixtureDef.density = 1.0f;
			fixtureDef.friction = 0.3f;

			// Create fixture
			body->CreateFixture(&fixtureDef);

			// Setup graphics
			shape.setPosition(0.0f, 0.0f);
			shape.setSize(sf::Vector2f(64.0f,64.0f));
			shape.setFillColor(sf::Color::Red);

		}

		// Apply tranformations to the box
		virtual void update(const RenderWindow& world, const Time& time)
		{

			// Update shape
			shape.setPosition(body->GetPosition().x,body->GetPosition().y);
			shape.setRotation(body->GetAngle());

		}

		// Draw the box
		virtual void draw(RenderWindow& window)
		{
			window.draw(shape);
		}

};

