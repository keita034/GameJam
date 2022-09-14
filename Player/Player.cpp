#include"Player.h"
#include"Enemy.h"
#include"Collision.h"


Player::Player()
{
	playerImg = LoadGraph("Resources/playerTop01.png");
	LoadDivGraph("Resources/player_kurisuta_None.png", 5, 5, 1, 280, 320, playerFrameImg);
	damageEffectImg = LoadGraph("Resources/DamageEfect.png");
	LoadDivGraph("Resources/player_damege.png", 5, 5, 1, 280, 320, damagePlayerImg);
	swordImg = LoadGraph("Resources/sword.png");
	LoadDivGraph("Resources/swordSwing3205526.png", 5, 1, 5, 526, 320, swordAnimationImg);

	playerLevelUp_ = new PlayerLevelUp();
	sound_ = Sound::GetInstance();
}

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
	
	playerLevelUp_->Initialize();

	angle = 0.0f;
	hp = 10;
	screen = { 760.0f,360.0f };
	screenInit = { 520.0f,360.0f };
	attackTime = 0;
	attackFrameTime = 0;
	maxAttackTime = 60;
	attackInterval = 0;
	attackDistance = 640;
	attackFlag = false;
	attackStanceFlag = false;
	oldAttackFlag = false;
	attackRadius = 239;
	attackPower = 1;
	attackCameraFlag = false;
	levelUpDistance = 179;
	finalLevel = false;
	comboExtensionTime = 50 * 3;
	comboExtensionFlag = false;
	combo = 0;
	levelUpExtensionTime = 50 * 3.8;
	levelUpExtensionFlag = false;
	attackStanceEffectFlag = false;
	attackStanceEffectTriggerFlag = false;
	attackStanceEffectRadius = 0.0f;
	attackStanceEffectColor = 0x2c080b;
	damageFlag = false;
	swordMagnification = 0.91f;
	damageEffectImg = 0;
	damageEffectTime = 0;
	attackStanceEffectFrameTime = 0;
	attackStanceEffectTime = 0;
	level = 0;
	shakeTime = 20;
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
		attackRadius = 239;
		attackPower = 1;
		maxAttackTime = 60;
		attackDistance = 640;
		levelUpDistance = 179;
		attackStanceEffectColor = 0x2c080b;
		swordMagnification = 0.91f;
	}

	if (damageEffectTime > 0)
	{
		damageEffectTime -= 2;
	}
	else
	{
		damageFlag = false;
	}


	angle = atan2((pos.y - screen.y) - (pos.y + frontVec.y * 100 - screen.y), (pos.x - screen.x) - (pos.x + frontVec.x * 100 - screen.x));

	playerLevelUp_->Update(pos.x, pos.y);
}

void Player::Draw()
{

	playerLevelUp_->Draw(screen);

	SwordDraw();

	if (hp <= 0)
	{
		hp = 0;
	}

	//フレームのプレイヤー
	if (damageEffectTime <= 0)
	{
		DrawRotaGraph3(pos.x - screen.x, pos.y - screen.y, 64, 64, 0.8, 0.8, angle, playerImg, true);
	}
	else
	{
		SetDrawBright(100, 0, 0);
		DrawRotaGraph3(pos.x - screen.x, pos.y - screen.y, 64, 64, 0.8, 0.8, angle, playerImg, true);
		SetDrawBright(255, 255, 255);
	}

	if (attackStanceFlag && !attackFlag)
	{

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 50);
		DrawCircle(pos.x - screen.x, pos.y - screen.y, attackRadius, GetColor(255, 255, 255), false, 3);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}

	if (attackStanceEffectFlag && !attackFlag)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 40);
		DrawCircle(pos.x - screen.x, pos.y - screen.y, attackStanceEffectRadius, attackStanceEffectColor, false, 3);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		if (attackStanceEffectTime >= 1.0f)
		{
			attackStanceEffectFlag = false;
		}
	}

	//フレームのプレイヤー
	if (damageEffectTime <= 0)
	{
		DrawRotaGraph(1135, 503, 1.3, 0.0, playerFrameImg[level], true);
	}
	else
	{
		DrawRotaGraph(1135, 503, 1.3, 0.0, damagePlayerImg[level], true);
	}

	//ダメージエフェクト
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, damageEffectTime);
	SetDrawBright(255, 0, 0);
	DrawRotaGraph(1135, 512, 1.0, 0.0, damageEffectImg, true);
	SetDrawBright(255, 255, 255);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
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
	sound_->Damage();
	hp -= subNum;
	damageEffectTime = 100;
	damageFlag = true;
	shakeTime = 20;
}

void Player::HPAdd(int addNum)
{
	hp += addNum;
}

int Player::GetAttackPower()
{
	return attackPower;
}

int Player::GetHp()
{
	return hp;
}

float Player::GetAngle()
{
	return angle;
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
				maxAttackTime = 60;
				attackDistance = 640;
				levelUpDistance = 179;
				attackStanceEffectColor = 0x2c080b;
				swordMagnification = 0.91f;

				level++;
				playerLevelUp_->playerLevelUp(level);
				sound_->levelUpdata(level);
				break;

			case 1:
				attackRadius = 218;
				attackPower = 1;
				maxAttackTime = 58;
				attackDistance = 663;
				levelUpDistance = 158;
				attackStanceEffectColor = 0x500f14;
				swordMagnification = 0.81f;

				level++;
				playerLevelUp_->playerLevelUp(level);
				sound_->levelUpdata(level);
				break;

			case 2:
				attackRadius = 197;
				attackPower = 2;
				maxAttackTime = 52;
				attackDistance = 706;
				levelUpDistance = 137;
				attackStanceEffectColor = 0x841821;
				swordMagnification = 0.76f;

				level++;
				playerLevelUp_->playerLevelUp(level);
				sound_->levelUpdata(level);
				break;

			case 3:
				attackRadius = 176;
				attackPower = 2;
				maxAttackTime = 46;
				attackDistance = 749;
				levelUpDistance = 116;
				attackStanceEffectColor = 0xb4172b;
				swordMagnification = 0.66f;

				level++;
				playerLevelUp_->playerLevelUp(level);
				sound_->levelUpdata(level);
				break;

			case 4:
				finalLevel = true;
				attackRadius = 155;
				attackPower = 3;
				maxAttackTime = 40;
				attackDistance = 800;
				levelUpDistance = 96;
				attackStanceEffectColor = 0xcd3043;
				swordMagnification = 0.60f;
				sound_->levelUpdata(level);
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
			attackStanceEffectTriggerFlag = false;
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
	attackStanceFlag = key.GetKey(KEY_INPUT_SPACE) && attackInterval == 0;

	if (key.GetKeyTrigger(KEY_INPUT_SPACE) && attackInterval == 0)
	{
		attackStanceEffectTriggerFlag = true;
		attackStanceEffectFlag = true;
		attackStanceEffectFrameTime = 0;
		attackStanceEffectTime = 0;
	}

	if (attackFlag)
	{
		attackStanceEffectFrameTime = 0;
		attackStanceEffectTime = 0;
	}

	if (attackStanceFlag && !attackFlag)
	{
		if (!attackStanceEffectTriggerFlag)
		{
			attackStanceEffectTriggerFlag = true;
			attackStanceEffectFlag = true;
			attackStanceEffectFrameTime = 0;
			attackStanceEffectTime = 0;
		}
	}

	if (attackStanceEffectFlag)
	{
		attackStanceEffectFrameTime++;

		attackStanceEffectTime = attackStanceEffectFrameTime / maxAttackStanceEffectTime;

		//イージング
		attackStanceEffectRadius = Ease::easeOutCubic(attackStanceEffectTime) * (levelUpDistance);
	}

	if (!attackFlag && key.GetKeyReleased(KEY_INPUT_SPACE) && attackInterval == 0)
	{
		attackStanceEffectFlag = false;
		attackFlag = true;
		attackCameraFlag = true;
		comboExtensionFlag = true;
		sound_->Swing();

		attackBeginPos = pos;
		attackDirectionVec = frontVec;
		attackScreenBeginPos = screen;

		attackInterval = -1;
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

	if (combo > 99999)
	{
		combo = 99999;
	}
}

void Player::SwordDraw()
{
	int posX = pos.x - screen.x;
	int posY = pos.y - screen.y;

	if (attackStanceFlag && !attackFlag)
	{
		DrawRotaGraph2(posX, posY, 20, -10, swordMagnification, angle, swordImg, true);
		DrawRotaGraph2(posX, posY, 20, 48, swordMagnification, angle, swordImg, true, false, true);
	}

	if (attackFlag)
	{
		int time = (attackFrameTime + 15) / (maxAttackTime / static_cast<float>(5));
		if (time >= 4)
		{
			time = 4;
		}

		DrawRotaGraph2(posX, posY, 320, 300, swordMagnification, angle, swordAnimationImg[time], true, true);
		DrawRotaGraph2(posX, posY, 320, 30, swordMagnification, angle, swordAnimationImg[time], true, true, true);
	}
}

int Player::GetLevel()
{
	return level;
}

bool Player::DamageFlag()
{
	return damageFlag;
}

bool Player::GetLevelUpExtensionFlag()
{
	return levelUpExtensionFlag;
}

int Player::GetLevelUpExtensionTime()
{
	return levelUpExtensionTime;
}

unsigned int Player::GetAttackStanceEffectColor()
{
	return attackStanceEffectColor;
}