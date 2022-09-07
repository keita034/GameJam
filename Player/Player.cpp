#include"Player.h"

void Player::Initialize()
{
	pos = { 1280.0f,720.0f };
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

	front.x = pos.x + cosf(angle) * 100;
	front.y = pos.y + sinf(angle) * 100;

	frontVec = front - pos;//正面ベクトル
	frontVec = frontVec.Normalized();//正面ベクトルの正規化

	Vec2 tmpSpeed = frontVec * speed;

	Vec2 tmpPos = pos;

	pos += tmpSpeed;

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
	DrawBox(zero.x - screen.x, zero.y - screen.y, fieldSize.x / 2 - screen.x, fieldSize.y / 2 - screen.y, GetColor(50, 50, 50), true);
	DrawBox((fieldSize.x / 2) - screen.x, zero.y - screen.y, fieldSize.x - screen.x, fieldSize.y / 2 - screen.y, GetColor(100, 100, 100), true);

	DrawBox(zero.x - screen.x, fieldSize.y / 2 - screen.y, (fieldSize.x / 2) - screen.x, fieldSize.y - screen.y, GetColor(150, 150, 150), true);
	DrawBox((fieldSize.x / 2) - screen.x, fieldSize.y / 2 - screen.y, fieldSize.x - screen.x, fieldSize.y - screen.y, GetColor(200, 200, 200), true);

	DrawLine(pos.x - screen.x, pos.y - screen.y, front.x - screen.x, front.y - screen.y, GetColor(255, 0, 0),3);
	DrawCircle(pos.x - screen.x, pos.y - screen.y, radius, GetColor(255, 0, 0));

	DrawFormatString(0, 0, GetColor(255, 0, 255), "Pos:%f,%f", pos.x, pos.y);
	DrawFormatString(0, 20, GetColor(255, 0, 255), "Screen:%f,%f", screen.x, screen.y);


	if (attackFlag)
	{
		DrawCircle(pos.x - screen.x, pos.y - screen.y, attackRadius, GetColor(255, 255, 0));
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
			attackInterval = maxAttackInterval;
		}
	}
}
