#include "DxLib.h"
#include "Box.h"

Box::Box()
{
	x = 0;
	y = 0;
	width = 0;
	height = 0;
	left = x - width;
	right = x + width;
	up = y - height;
	down = y + height;
}

Box::Box(float x, float y)
{
	this->x = x;
	this->y = y;
	width = 0;
	height = 0;
	left = x - width;
	right = x + width;
	up = y - height;
	down = y + height;
}

Box::Box(float x, float y, float width, float height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	left = x - width;
	right = x + width;
	up = y - height;
	down = y + height;
}

void Box::PointsInitialize()
{
	left = x - width;
	right = x + width;
	up = y - height;
	down = y + height;
}

void Box::PointsUpdate()
{
	left = x - width;
	right = x + width - 1;
	up = y - height;
	down = y + height - 1;
}