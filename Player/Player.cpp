#include"Player.h"

void Player::Initialize()
{
	pos = {1280.0f,980.0f};
	front = {0,-1};
}

void Player::Update()
{
	Vec2 tmpSpeed = front * speed;
	
	float rotSpeed = 0.05f;
	float radius = 30.0f;

	if (key.GetKey(KEY_INPUT_LEFT) == 1)
	{
		angle -= rotSpeed;
	}
	if (key.GetKey(KEY_INPUT_RIGHT) == 1)
	{
		angle += rotSpeed;
	}

	front.x = pos.x + cosf(angle) * 50;
	front.y = pos.y + sinf(angle) * 50;

	frontVec = front - pos;//正面ベクトル
	frontVec = frontVec.Normalized();//正面ベクトルの正規化

	if (zero < pos + tmpSpeed && fieldSize>pos + tmpSpeed)
	{
		pos += tmpSpeed;
	}

}

void Player::Draw()
{
	DrawCircle(pos.x, pos.y, 10, GetColor(255, 255, 255));
}
