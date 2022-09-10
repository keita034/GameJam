#include"Player.h"
#include"Enemy.h"
#include"Collision.h"

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

	if (comboExtensionTime > 0 && comboExtensionFlag)
	{
		comboExtensionTime--;
	}
	else
	{
		level = 0;
		combo = 0;
		
		//コンボの猶予時間を初期値に
		comboExtensionTime = maxComboExtensionTime;
		comboExtensionFlag = false;
	}
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

	DrawFormatString(130, 60, GetColor(255, 0, 255), "Pos:%f,%f", pos.x, pos.y);
	DrawFormatString(130, 80, GetColor(255, 0, 255), "Screen:%f,%f", screen.x, screen.y);
	DrawFormatString(130, 100, GetColor(255, 0, 255), "Level:%d", level);
	DrawFormatString(130, 120, GetColor(255, 0, 255), "comboExtensionTime:%f", comboExtensionTime);

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

void Player::LevelUpdate(Vec2 vec,Enemy* enemy)
{
	if (!enemy)
	{
		return;
	}

	//ベクトルの長ささレベルが上がる距離より短かったら
	if (vec.Length() < levelUpDistance && AttackTriggerFlag())
	{
		if (CheckSphere2Sphere(pos, attackRadius, enemy->GetPos(), enemy->GetRadius()))
		{
			comboExtensionFlag = true;
			comboExtensionTime = maxComboExtensionTime;

			switch (level)
			{
			case 0:
				attackRadius = 239;
				attackPower = 1;
				maxAttackTime = 80;
				attackDistance = 480;
				levelUpDistance = 179;
				level++;
				break;

			case 1:
				attackRadius = 218;
				attackPower = 1;
				maxAttackTime = 70;
				attackDistance = 560;
				levelUpDistance = 158;
				level++;
				break;

			case 2:
				attackRadius = 197;
				attackPower = 2;
				maxAttackTime = 60;
				attackDistance = 640;
				levelUpDistance = 137;
				level++;
				break;

			case 3:
				attackRadius = 176;
				attackPower = 2;
				maxAttackTime = 50;
				attackDistance = 720;
				levelUpDistance = 116;
				level++;
				break;

			case 4:
				finalLevel = true;
				attackRadius = 155;
				attackPower = 3;
				maxAttackTime = 40;
				attackDistance = 800;
				levelUpDistance = 96;
				level++;
				break;

			default:

				break;
			}

			combo++;

			if (finalLevel && comboExtensionTime < 0)
			{
				comboExtensionTime += 0.1f;
			}
		}
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
	if (!attackFlag)
	{
		screen += pos - oldPos;
	}

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
		attackCameraFlag = true;

		attackBeginPos = pos;
		attackDirectionVec = frontVec;
		attackScreenBeginPos = screen;
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

			pos.x = attackBeginPos.x + Ease::easeOutCubic(time) * (attackDirectionVec.x * attackDistance);
			pos.y = attackBeginPos.y + Ease::easeOutCubic(time) * (attackDirectionVec.y * attackDistance);

			screen.x = attackScreenBeginPos.x + Ease::easeOutQuad(time) * (attackDirectionVec.x * attackDistance);
			screen.y = attackScreenBeginPos.y + Ease::easeOutQuad(time) * (attackDirectionVec.y * attackDistance);			pos.x = attackBeginPos.x + Ease::easeOutCubic(time) * (attackDirectionVec.x * attackDistance);


		if (time >= 1.0f)
		{
			attackFlag = false;
			attackFrameTime = 0;
			attackInterval = maxAttackInterval;
		}
	}
}

int Player::GetCombo()
{
	return combo;
}
