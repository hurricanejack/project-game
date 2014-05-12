#include "Math.hpp"

float pointDirection(const float &x1, const float &y1, const float &x2, const float &y2)
{
	float angle = atan2(y1 - y2, x1 - x2);
	return (angle * 180 / PI);
}

float pointDirection(const Vector2<float>& p1, const Vector2<float>& p2)
{
	return pointDirection(p1.x, p1.y, p2.x, p2.y);
}

float sqr(const float &value)
{
	return (value * value);
}

float pointDistance(const float &x1, const float &y1, const float &x2, const float &y2)
{
	return sqrt(sqr(x2 - x1) + sqr(y2 - y1));
}

float pointDistance(const Vector2<float>& p1, const Vector2<float>& p2)
{
	return pointDistance(p1.x, p1.y, p2.x, p2.y);
}

float lengthdirX(const float &length, const float &direction)
{
	return -(cos(direction * (PI / 180)) * length);
}

float lengthdirY(const float &length, const float &direction)
{
	return -sin(direction * (PI / 180)) * length;
}