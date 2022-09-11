#include "Enemy.h"

Enemy::Enemy()
{
	pos_ = { 0,0 };
	speed_ = 2;
	playerPos_ = { 1280.0f,720.0f };
	radius_ = 32;
	pattern_ = HeightUp;
	isDeath_ = false;
}

Enemy::~Enemy()
{
	
}

void Enemy::Initialize(Pattern pattern, Vec2 pos, float speed, int hp_)
{
	pattern_ = pattern;
	pos_ = pos;
	speed_ = speed;

	hp = hp_;

	// プレイヤーの初期位置からエネミーの位置のベクトル
	velocity_ = playerPos_ - pos_;
	velocity_ = velocity_.Normalized();
	tarkingEnemyPosLength = tarkingEnemyPos - pos_;
}

void Enemy::Update(Vec2 playerNpos)
{
	switch (pattern_)
	{
	case HeightUp:
		velocity_ = { 0,-speed_ };
		pos_ += velocity_;
		break;
	case HeightDown:
		velocity_ = { 0,speed_ };
		pos_ += velocity_;
		break;
	case WidthL:
		velocity_ = { -speed_,0 };
		pos_ += velocity_;
		break;
	case WidthR:
		velocity_ = { speed_,0 };
		pos_ += velocity_;
		break;
	case UpperL:
		velocity_ = { -speed_ / 2.0f, -speed_ / 2.0f };
		pos_ += velocity_;
		break;
	case UpperR:
		velocity_ = { speed_ / 2.0f,-speed_ / 2.0f };
		pos_ += velocity_;
		break;
	case DiagonallyDownL:
		velocity_ = { -speed_ / 2.0f,speed_ / 2.0f };
		pos_ += velocity_;
		break;
	case DiagonallyDownR:
		velocity_ = { speed_ / 2.0f,speed_ / 2.0f };
		pos_ += velocity_;
		break;
	case Traking:
		// プレイヤーの現在の位置を取得とエネミーの位置でベクトルを作る
		velocity_ = playerNpos - pos_;
		velocity_ = velocity_.Normalized();
		velocity_ *= speed_;
		pos_ += velocity_;
		break;
	case Center:
		pos_ += velocity_* speed_;
		break;
	case TrakingEnemy:
		tarkingEnemyPosLengthN= tarkingEnemyPos - pos_;
		velocity_ = tarkingEnemyPos - pos_;
		velocity_ = velocity_.Normalized();
		if (tarkingEnemyPosLengthN.Length() >= tarkingEnemyPosLength.Length())
		{
			velocity_ *= speed_;
		}
		
		pos_ += velocity_;
		break;
	case None:
		break;
	default:
		break;
	}

	if (!damageFlag)
	{
		damageInterval--;

		if (damageInterval == 0)
		{
			damageInterval = maxDamageInterval;

			damageFlag = true;

		}
	}

	if (hp <= 0)
	{
		isDeath_ = true;
	}

	if (pos_.x < -MaxPos.x || pos_.x > fieldSize.x + MaxPos.x||
		pos_.y < -MaxPos.y || pos_.y > fieldSize.y + MaxPos.y)
	{
		isDeath_ = true;
	}
}

void Enemy::Draw(Vec2 screen)
{
	DrawCircle(pos_.x - screen.x, pos_.y - screen.y, radius_, GetColor(255, 0, 255), true);
}

bool Enemy::IsDeath()
{
	return isDeath_;
}

Vec2 Enemy::GetPos()
{
	return pos_;
}

int Enemy::GetRadius()
{
	return radius_;
}

void Enemy::Death()
{
	isDeath_ = true;
}

void Enemy::HPSub(int subNum)
{
	if (damageFlag)
	{
		hp -= subNum;

		damageFlag = false;
	}

}

void Enemy::HPAdd(int addNum)
{
	hp += addNum;
}

void Enemy::SetTrakingEnemyPos(Vec2 &enemyPos)
{
	tarkingEnemyPos = enemyPos;
}

void Enemy::SetEnemyPos(Vec2& pos)
{
	pos_ = pos;
}

bool Enemy::GetDamageFlag()
{
	return damageFlag;
}
