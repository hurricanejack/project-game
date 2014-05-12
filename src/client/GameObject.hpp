#pragma once

#define PPM 30.0f
#include "Body.hpp"
#include <Box2D\Box2D.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
using sf::RenderWindow;
using sf::Time;
using sf::Vector2;

class GameObject
{

	protected:

			float x{ 0.0f }, y{ 0.0f }, angle{ 0.0f };

			struct
			{
				b2Body*			body;
				b2FixtureDef	fixture;
				b2BodyDef		bodyDef;
			} physics;

	public:
		GameObject();
		~GameObject();

		// Setters
		virtual void setAngle(const float&);
		virtual void setPosition(const Vector2<float>&);
		virtual void setPosition(const float&, const float&);

		// Getters
		virtual float getAngle();
		virtual Vector2<float> getPosition();
		virtual float getPositionX();
		virtual float getPositionY();

		// Physics related
		virtual bool hasBody();

		// Events
		virtual void update(const RenderWindow&);
		virtual void draw(RenderWindow&);

};
