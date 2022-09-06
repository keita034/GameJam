#include "Camera.h"

Camera camera;

Camera::Camera()
{
	// カメラの座標の初期化
	pos.x = 0;
	pos.y = 0;

	// ターゲットカメラの座標
	target_pos.x = 0;
	target_pos.y = 0;
}

void Camera::Update()
{
	// カメラを少し遅らせて移動する
	pos.x += (target_pos.x - pos.x) * 0.09f;
	pos.y += (target_pos.y - pos.y) * 0.09f;
}

int Camera::GetPosX()
{
	return pos.x;
}

int Camera::GetPosY()
{
	return pos.y;
}

void Camera::SetPos(float pos_x, float pos_y)
{
	target_pos.x = pos_x;
	target_pos.y = pos_y;
}

void Camera::Shake(int x_min, int x_max, int y_min, int y_max)
{
	int sheck_x = GetRandomRange(-20, 20);
	int sheck_y = GetRandomRange(-20, 20);

	pos.x += sheck_x;
	pos.y += sheck_y;
}