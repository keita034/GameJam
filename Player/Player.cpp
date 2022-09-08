#include"Player.h"

void Player::Initialize()
{
	pos = { 1280.0f,720.0f };
	angle = -DX_PI_F / 2;
}

void Player::Update()
{
	float rotSpeed = 0.05f;

	if (key.GetKey(KEY_INPUT_LEFT))
	{
		angle -= rotSpeed;
	}
	if (key.GetKey(KEY_INPUT_RIGHT))
	{
		angle += rotSpeed;
	}

	//方向ベクトルを回転
	front.x = pos.x + cosf(angle) * 100;
	front.y = pos.y + sinf(angle) * 100;

	frontVec = front - pos;//正面ベクトル
	frontVec = frontVec.Normalized();//正面ベクトルの正規化

	Vec2 tmpSpeed = frontVec * speed;

	oldPos = pos;
	if (!attackFlag)
	{
		pos += tmpSpeed;
	}

	//移動制限
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

	//1フレーム前の攻撃フラグを保存
	oldAttackFlag = attackFlag;
}

void Player::Draw()
{
	DrawBox(zero.x - screen.x, zero.y - screen.y, fieldSize.x / 2 - screen.x, fieldSize.y / 2 - screen.y, GetColor(50, 50, 50), true);
	DrawBox((fieldSize.x / 2) - screen.x, zero.y - screen.y, fieldSize.x - screen.x, fieldSize.y / 2 - screen.y, GetColor(100, 100, 100), true);

	DrawBox(zero.x - screen.x, fieldSize.y / 2 - screen.y, (fieldSize.x / 2) - screen.x, fieldSize.y - screen.y, GetColor(150, 150, 150), true);
	DrawBox((fieldSize.x / 2) - screen.x, fieldSize.y / 2 - screen.y, fieldSize.x - screen.x, fieldSize.y - screen.y, GetColor(200, 200, 200), true);

	DrawLine(pos.x - screen.x, pos.y - screen.y, front.x - screen.x, front.y - screen.y, GetColor(255, 0, 0), 3);
	DrawCircle(pos.x - screen.x, pos.y - screen.y, radius, GetColor(255, 0, 0));

	DrawFormatString(0, 0, GetColor(255, 0, 255), "Pos:%f,%f", pos.x, pos.y);
	DrawFormatString(0, 20, GetColor(255, 0, 255), "Screen:%f,%f", screen.x, screen.y);
	DrawFormatString(0, 40, GetColor(255, 0, 255), "Level:%d", level);


	if (attackFlag)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
		DrawCircle(pos.x - screen.x, pos.y - screen.y, attackRadius, GetColor(255, 255, 0));
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	}
}

Vec2 Player::GetPos()
{
	return pos;
}

int Player::GetRadius()
{
	return radius;
}

Vec2 Player::GetScreen()
{
	return screen;
}

bool Player::GetAttackFlag()
{
	return attackFlag;
}

int Player::GetAttackRadius()
{
	return attackRadius;
}

void Player::HPSub(int subNum)
{
	hp -= subNum;
}

void Player::HPAdd(int addNum)
{
	hp += addNum;
}

int Player::GetAttackPower()
{
	return attackPower;
}

void Player::AttackUpdate(Vec2 vec)
{

	if (vec.Length()<128.0f)
	{
		level++;
	}

	//現在の座標から1フレーム前の座標を引いて
	//スクリーンの移動量を決める
	screen += pos - oldPos;
}

bool Player::AttackTriggerFlag()
{
	if (!oldAttackFlag && attackFlag)
	{
		return true;
	}

	return false;
}

void Player::Attack()
{
	if (!attackFlag && key.GetKeyTrigger(KEY_INPUT_SPACE) && attackInterval == 0)
	{
		attackFlag = true;

		attackBeginPos = pos;
	}

	if (attackInterval > 0)
	{
		attackInterval--;
	}

	if (attackFlag)
	{
		attackFrameTime++;

		float time = attackFrameTime / maxAttackTime;

		//イージング
		pos.x = attackBeginPos.x + Ease::easeInOutQuart(time) * (frontVec.x * attackDistance);
		pos.y = attackBeginPos.y + Ease::easeInOutQuart(time) * (frontVec.y * attackDistance);

		if (time >= 1.0f)
		{
			attackFlag = false;
			attackFrameTime = 0;
			attackInterval = maxAttackInterval;
		}
	}
}
