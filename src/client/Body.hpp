#pragma once

#include "Common.hpp"
#include <Box2D\Box2D.h>
#include <vector>
using std::vector;

extern vector<b2Body*> bodyRemoveList;

void removeBodies();

class Body
{
	private:
		b2Body* body;

	public:

		Body(const b2BodyDef &b);
		~Body();

		b2Body* operator->();
		b2Body& operator*();
		operator b2Body*() const;

};