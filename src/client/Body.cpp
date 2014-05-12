#include "Body.hpp"

vector<b2Body*> bodyRemoveList;

Body::Body(const b2BodyDef &b)
{
	body = world->CreateBody(&b);
}

Body::~Body()
{
	// Schedule removal of this body
	if (body != 0)
	{
		bodyRemoveList.push_back(body);
	}
}

b2Body* Body::operator->()
{
	return body;
}

b2Body& Body::operator*()
{
	return *body;
}

Body::operator b2Body*() const
{
	return body;
}

void removeBodies()
{

	for (unsigned int i = 0; i < bodyRemoveList.size(); i++)
	{
		if (bodyRemoveList.at(i) != 0)
		{
			b2Body* body = bodyRemoveList.at(i);
			if (body->GetWorld() != 0)
			{
				body->GetWorld()->DestroyBody(body);
			}
		}
	}
	bodyRemoveList.clear();

}