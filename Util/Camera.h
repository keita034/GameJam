#pragma once
#include "Util.h"
class Camera
{
private:
	Vec2 pos;
	Vec2 target_pos;
public:
	Camera();
	void Update();
	int GetPosX();
	int GetPosY();
	void SetPos(float pos_x, float pos_y);
	void Shake(int x_min, int x_max, int y_min, int y_max);
};
extern Camera camera;