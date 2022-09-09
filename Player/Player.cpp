#include"Player.h"

void Player::Initialize()
{
	pos = { 1280.0f,720.0f };
	angle = -DX_PI_F / 2;
}

void Player::Update()
{
	Vec2 screenCentral = { 640.0f,360.0f };
	int mosePosX=0;
	int mosePosY=0;

	GetMousePoint(&mosePosX, &mosePosY);
	Vec2 mosePos = { (float)mosePosX ,(float)mosePosY };

	frontVec = mosePos - screenCentral;
	frontVec = frontVec.Normalized();//正面ベクトルの正規化

	Vec2 tmpSpeed = frontVec * speed;

	oldPos = pos;
	if (!attackFlag)
	{
		pos += tmpSpeed;
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

	DrawLine(
		pos.x - screen.x, pos.y - screen.y,
		pos.x + frontVec.x * 100 - screen.x, pos.y + frontVec.y*100 - screen.y, 
		GetColor(255, 0, 0), 3);
	DrawCircle(pos.x - screen.x, pos.y - screen.y, radius, GetColor(255, 0, 0));

	DrawFormatString(0, 0, GetColor(255, 0, 255), "Pos:%f,%f", pos.x, pos.y);
	DrawFormatString(0, 20, GetColor(255, 0, 255), "Screen:%f,%f", screen.x, screen.y);
	DrawFormatString(0, 40, GetColor(255, 0, 255), "Level:%d", level);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
	DrawCircle(pos.x - screen.x, pos.y - screen.y, levelUpDistance, GetColor(255, 155, 0));
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	if (attackFlag)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
		DrawCircle(pos.x - screen.x, pos.y - screen.y, attackRadius, GetColor(255, 255, 0));
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}

	for (size_t i = 0; i < hp; i++)
	{
		DrawBox(1036 + (20 * i), 275, 1056 + (20 * i), 312, GetColor(255, 0, 0), true);
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

void Player::LevelUpdate(Vec2 vec)
{
	//ベクトルの長ささレベルが上がる距離より短かったら
	if (vec.Length()<levelUpDistance)
	{
		switch (level)
		{
		case 0:
			attackRadius = 128;
			attackPower = 1;
			maxAttackTime = 50 * 1;
			attackDistance = 200;
			break;

		case 1:
			attackRadius = 128;
			attackPower = 1;
			maxAttackTime = 50 * 1;
			attackDistance = 200;
			break;

		case 2:
			attackRadius = 128;
			attackPower = 1;
			maxAttackTime = 50 * 1;
			attackDistance = 200;
			break;

		case 3:
			attackRadius = 128;
			attackPower = 1;
			maxAttackTime = 50 * 1;
			attackDistance = 200;
			break;

		case 4:
			finalLevel = true;
			attackRadius = 128;
			attackPower = 1;
			maxAttackTime = 50 * 1;
			attackDistance = 200;
			break;
		}

		level++;
	}

}

void Player::MoveLimit()
{
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
		attackDirectionVec = frontVec;
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
		if (!finalLevel)
		{
			pos.x = attackBeginPos.x + Ease::easeInOutQuart(time) * (attackDirectionVec.x * attackDistance);
			pos.y = attackBeginPos.y + Ease::easeInOutQuart(time) * (attackDirectionVec.y * attackDistance);
		}
		else//最終レベル
		{
			pos.x = attackBeginPos.x + Ease::easeInBack(time) * (attackDirectionVec.x * attackDistance);
			pos.y = attackBeginPos.y + Ease::easeInBack(time) * (attackDirectionVec.y * attackDistance);
		}

		if (time >= 1.0f)
		{
			attackFlag = false;
			attackFrameTime = 0;
			attackInterval = maxAttackInterval;

			if (finalLevel)
			{
				finalLevel = false;
				//初期値に
				attackRadius = 128;
				attackPower = 1;
				maxAttackTime = 50 * 1;
				attackDistance = 200;
			}
		}
	}
}
