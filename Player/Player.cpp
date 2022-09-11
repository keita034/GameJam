#include"Player.h"
#include"Enemy.h"
#include"Collision.h"

bool Complement(float& x1, float x2, float flame)//移動補完
{
	float distanceX = x2 - x1;//距離を出す

	if (distanceX == 0)
	{
		return false;
	}
	float dividedDistanceX = distanceX / flame;//距離をflameで割った値

	x1 += dividedDistanceX;//距離をflameで割った値を足す

	return true;
}

void Player::Initialize()
{
	pos = { 1280.0f,720.0f };
	angle = -DX_PI_F / 2;
	playerImg = LoadGraph("Resources/playerTop01.png");
}

void Player::Update()
{
	int mosePosX = 0;
	int mosePosY = 0;

	GetMousePoint(&mosePosX, &mosePosY);

	Vec2 mosePos = { (float)mosePosX ,(float)mosePosY };

	frontVec = mosePos - screenInit;
	frontVec = frontVec.Normalized();//正面ベクトルの正規化

	Vec2 tmpSpeed = frontVec * speed;

	oldPos = pos;
	if (!attackFlag)
	{
		pos += tmpSpeed;
	}

	//1フレーム前の攻撃フラグを保存
	oldAttackFlag = attackFlag;

	if (levelUpExtensionTime > 0 && levelUpExtensionFlag)
	{
		levelUpExtensionTime--;
	}
	else if (levelUpExtensionTime <= 0 && levelUpExtensionFlag && !attackFlag)
	{
		level = 0;

		//コンボの猶予時間を初期値に
		levelUpExtensionTime = maxLevelUpExtensionTime;
		levelUpExtensionFlag = false;

		//攻撃レベルが上がる距離
		levelUpDistance = 200;
		attackDistance = 400;
		attackPower = 1;
		attackRadius = 260;
		maxAttackTime = 90;
	}

	angle = atan2((pos.y - screen.y) - (pos.y + frontVec.y * 100 - screen.y), (pos.x - screen.x) - (pos.x + frontVec.x * 100 - screen.x));
}

void Player::Draw()
{
	DrawBox(zero.x - screen.x, zero.y - screen.y, fieldSize.x / 2 - screen.x, fieldSize.y / 2 - screen.y, GetColor(50, 50, 50), true);
	DrawBox((fieldSize.x / 2) - screen.x, zero.y - screen.y, fieldSize.x - screen.x, fieldSize.y / 2 - screen.y, GetColor(100, 100, 100), true);

	DrawBox(zero.x - screen.x, fieldSize.y / 2 - screen.y, (fieldSize.x / 2) - screen.x, fieldSize.y - screen.y, GetColor(150, 150, 150), true);
	DrawBox((fieldSize.x / 2) - screen.x, fieldSize.y / 2 - screen.y, fieldSize.x - screen.x, fieldSize.y - screen.y, GetColor(200, 200, 200), true);

	DrawLine(
		pos.x - screen.x, pos.y - screen.y,
		pos.x + frontVec.x * 100 - screen.x, pos.y + frontVec.y * 100 - screen.y,
		GetColor(255, 0, 0), 3);

	DrawRotaGraph3(pos.x - screen.x, pos.y - screen.y, 64, 64, 0.8, 0.8, angle, playerImg, true);

	DrawFormatString(130, 60, GetColor(255, 0, 255), "Pos:%f,%f", pos.x, pos.y);
	DrawFormatString(130, 80, GetColor(255, 0, 255), "Screen:%f,%f", screen.x, screen.y);

	DrawFormatString(130, 100, GetColor(255, 0, 255), "comboExtensionTime:%f", comboExtensionTime);
	DrawFormatString(130, 120, GetColor(255, 0, 255), "combo:%d", combo);

	DrawFormatString(130, 140, GetColor(255, 0, 255), "levelUpExtensionTime:%f", levelUpExtensionTime);
	DrawFormatString(130, 160, GetColor(255, 0, 255), "Level:%d", level);

	DrawFormatString(130, 180, GetColor(255, 0, 255), "angle:%f", angle);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
	DrawCircle(pos.x - screen.x, pos.y - screen.y, levelUpDistance, GetColor(255, 155, 0));
	DrawCircle(pos.x - screen.x, pos.y - screen.y, radius, GetColor(255, 0, 0));
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

void Player::LevelUpdate(Vec2 vec, Enemy* enemy)
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
			levelUpExtensionFlag = true;
			levelUpExtensionTime = maxLevelUpExtensionTime;

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

			if (finalLevel && levelUpExtensionTime < 0)
			{
				levelUpExtensionTime += 0.1f;
			}
		}
	}
}

void Player::ComboUpdate()
{
	if (comboExtensionFlag)
	{
		if (combo <= 0)
		{
			comboExtensionFlag = false;
			return;
		}

		comboExtensionTime--;

		if (comboExtensionTime < 0)
		{
			comboExtensionFlag = false;
			comboExtensionTime = maxComboExtensionTime;
			combo = 0;
		}
	}
}

void Player::MoveLimit()
{
	bool limitX = false;
	bool limitY = false;

	//移動制限
	if (pos.x - radius < zero.x)
	{
		limitX = true;
		pos.x = zero.x + radius;
	}
	if (pos.y - radius < zero.y)
	{
		limitY = true;
		pos.y = zero.x + radius;
	}
	if (pos.x + radius > fieldSize.x)
	{
		limitX = true;
		pos.x = fieldSize.x - radius;
	}
	if (pos.y + radius > fieldSize.y)
	{
		limitY = true;
		pos.y = fieldSize.y - radius;
	}

	//現在の座標から1フレーム前の座標を引いて
	//スクリーンの移動量を決める
	if (!attackFlag)
	{
		screen += pos - oldPos;
	}
	else
	{
		if (!limitX)
		{
			screen.x = attackScreenBeginPos.x + Ease::easeOutQuad(attackTime) * (attackDirectionVec.x * attackDistance);
		}
		else
		{
			float movex = pos.x - screen.x - screenInit.x;
			Complement(screen.x, screen.x + movex, maxAttackTime - attackFrameTime);
		}

		if (!limitY)
		{
			screen.y = attackScreenBeginPos.y + Ease::easeOutQuad(attackTime) * (attackDirectionVec.y * attackDistance);
		}
		else
		{
			float movey = pos.y - screen.y - screenInit.y;
			Complement(screen.y, screen.y + movey, maxAttackTime - attackFrameTime);
		}

		if (attackTime >= 1.0f)
		{
			attackFlag = false;
			attackFrameTime = 0;
			attackInterval = maxAttackInterval;
		}
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

	if (key.GetKeyTrigger(KEY_INPUT_UP))
	{
		level++;
	}

	if (key.GetKeyTrigger(KEY_INPUT_DOWN))
	{
		level--;
	}

	if (key.GetKeyTrigger(KEY_INPUT_RETURN))
	{
		switch (level)
		{
		case 0:
			attackRadius = 239;
			attackPower = 1;
			maxAttackTime = 80;
			attackDistance = 480;
			levelUpDistance = 179;
			break;

		case 1:
			attackRadius = 218;
			attackPower = 1;
			maxAttackTime = 70;
			attackDistance = 560;
			levelUpDistance = 158;
			break;

		case 2:
			attackRadius = 197;
			attackPower = 2;
			maxAttackTime = 60;
			attackDistance = 640;
			levelUpDistance = 137;
			break;

		case 3:
			attackRadius = 176;
			attackPower = 2;
			maxAttackTime = 50;
			attackDistance = 720;
			levelUpDistance = 116;
			break;

		case 4:
			finalLevel = true;
			attackRadius = 155;
			attackPower = 3;
			maxAttackTime = 40;
			attackDistance = 800;
			levelUpDistance = 96;
			break;

		default:

			break;
		}
	}

	attackStanceFlag = key.GetKey(KEY_INPUT_SPACE);

	if (!attackFlag && key.GetKeyReleased(KEY_INPUT_SPACE) && attackInterval == 0)
	{
		attackFlag = true;
		attackCameraFlag = true;
		comboExtensionFlag = true;

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

		attackTime = attackFrameTime / maxAttackTime;

		//イージング
		pos.x = attackBeginPos.x + Ease::easeOutCubic(attackTime) * (attackDirectionVec.x * attackDistance);
		pos.y = attackBeginPos.y + Ease::easeOutCubic(attackTime) * (attackDirectionVec.y * attackDistance);
	}
	else
	{
		float movey = pos.y - screen.y - screenInit.y;
		Complement(screen.y, screen.y + movey, 15);
		float movex = pos.x - screen.x - screenInit.x;
		Complement(screen.x, screen.x + movex, 15);
	}
}

int Player::GetCombo()
{
	return combo;
}

void Player::AddCombo()
{
	combo++;
	comboExtensionTime = maxComboExtensionTime;
	comboExtensionFlag = true;
}
