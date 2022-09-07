#include"Player.h"

void Player::Initialize()
{
	pos = {1280.0f,720.0f};
	angle = -DX_PI_F / 2;
}

void Player::Update()
{
	float rotSpeed = 0.05f;
	float radius = 30.0f;

	if (key.GetKey(KEY_INPUT_LEFT))
	{
		angle -= rotSpeed;
	}
	if (key.GetKey(KEY_INPUT_RIGHT))
	{
		angle += rotSpeed;
	}

	front.x = pos.x + cosf(angle) * 50;
	front.y = pos.y + sinf(angle) * 50;

	frontVec = front - pos;//正面ベクトル
	frontVec = frontVec.Normalized();//正面ベクトルの正規化

	Vec2 tmpSpeed = frontVec * 5.0f;
	Vec2 tmpPos = pos;

	pos += tmpSpeed ;

	if (pos.x - radius < zero.x)
	{
		pos.x = zero.x + radius;
	}
	if (pos.y - radius < zero.y)
	{
		pos.y = zero.x + radius;
	}

	if (pos.x + radius > fieldSize.x)
	{
		pos.x = fieldSize.x - radius;
	}
	if (pos.y + radius > fieldSize.y)
	{
		pos.y = fieldSize.y - radius;
	}

	screen += pos - tmpPos;

	Attack();
}

void Player::Draw()
{
	DrawCircle(pos.x- screen.x, pos.y- screen.y , radius, GetColor(255, 0, 0));

	if (attackFlag)
	{
		DrawCircle(pos.x - screen.x, pos.y - screen.y, radius + 40, GetColor(255, 255, 0));
	}
}

void Player::Attack()
{
	if (key.GetKeyTrigger(KEY_INPUT_SPACE) && attackInterval == 0)
	{
		attackFlag = true;
	}

	if (attackInterval > 0)
	{
		attackInterval--;
	}

	if (attackFlag)
	{
		if (attackTime > 0)
		{
			attackTime--;
		}
		else
		{
			attackFlag = false;
			attackTime = 40;
		}
	}
}
