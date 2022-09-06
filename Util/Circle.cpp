#include "DxLib.h"
#include "Circle.h"

Circle::Circle()
{
	x = 0;
	y = 0;
	radius = 0;
}

Circle::Circle(float x, float y, float radius)
{
	this->x = x;
	this->y = y;
	this->radius = radius;
}