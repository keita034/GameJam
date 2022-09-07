#include "Collision.h"

bool CheckSphere2Sphere(Vec2 entityPos, int entityR, Vec2 entity2Pos, int entity2R)
{
	float a = entityPos.x - entity2Pos.x;
	float b = entityPos.y - entity2Pos.y;
	float c = sqrt(a * a + b * b);

	if (c <= entityR + entity2R)
	{
		return true;
	}

	return false;
}
