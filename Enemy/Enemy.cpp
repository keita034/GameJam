#include "Enemy.h"
#include <math.h>
#include "GameScene.h"

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

void Enemy::Initialize(Pattern pattern,Vec2 pos, float speed, int hp_)
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
		angle += 0.1;
		// アニメーション回す処理
		animetionTimer++;
		if (animetionTimer == 20)
		{
			Siratamaflame++;
			animetionTimer = 0;
		}
		if (Siratamaflame >= 4)
		{
			Siratamaflame = 0;
		}
		break;
	case HeightDown:
		velocity_ = { 0,speed_ };
		pos_ += velocity_;
		angle += 0.1;
		// アニメーション回す処理
		animetionTimer++;
		if (animetionTimer == 20)
		{
			Siratamaflame++;
			animetionTimer = 0;
		}
		if (Siratamaflame >= 4)
		{
			Siratamaflame = 0;
		}
		break;
	case WidthL:
		velocity_ = { -speed_,0 };
		pos_ += velocity_;
		angle += 0.1;
		// アニメーション回す処理
		animetionTimer++;
		if (animetionTimer == 20)
		{
			Siratamaflame++;
			animetionTimer = 0;
		}
		if (Siratamaflame >= 4)
		{
			Siratamaflame = 0;
		}
		break;
	case WidthR:
		velocity_ = { speed_,0 };
		pos_ += velocity_;
		angle += 0.1;
		// アニメーション回す処理
		animetionTimer++;
		if (animetionTimer == 20)
		{
			Siratamaflame++;
			animetionTimer = 0;
		}
		if (Siratamaflame >= 4)
		{
			Siratamaflame = 0;
		}
		break;
	case UpperL:
		velocity_ = { -speed_ / 2.0f, -speed_ / 2.0f };
		pos_ += velocity_;
		angle += 0.1;

		// アニメーション回す処理
		animetionTimer++;
		if (animetionTimer == 20)
		{
			Yubiflame++;
			animetionTimer = 0;
		}
		if (Yubiflame >= 9)
		{
			Yubiflame = 0;
		}
		break;
	case UpperR:
		velocity_ = { speed_ / 2.0f,-speed_ / 2.0f };
		pos_ += velocity_;
		angle += 0.1;
		// アニメーション回す処理
		animetionTimer++;
		if (animetionTimer == 20)
		{
			Yubiflame++;
			animetionTimer = 0;
		}
		if (Yubiflame >= 9)
		{
			Yubiflame = 0;
		}
		break;
	case DiagonallyDownL:
		velocity_ = { -speed_ / 2.0f,speed_ / 2.0f };
		pos_ += velocity_;
		angle += 0.1;
		// アニメーション回す処理
		animetionTimer++;
		if (animetionTimer == 20)
		{
			Yubiflame++;
			animetionTimer = 0;
		}
		if (Yubiflame >= 9)
		{
			Yubiflame = 0;
		}
		break;
	case DiagonallyDownR:
		velocity_ = { speed_ / 2.0f,speed_ / 2.0f };
		pos_ += velocity_;
		angle += 0.1;
		// アニメーション回す処理
		animetionTimer++;
		if (animetionTimer == 20)
		{
			Yubiflame++;
			animetionTimer = 0;
		}
		if (Yubiflame >= 9)
		{
			Yubiflame = 0;
		}
		break;
	case Traking:
		// プレイヤーの現在の位置を取得とエネミーの位置でベクトルを作る
		velocity_ = playerNpos - pos_;

		// 正規化した方向ベクトルをAngleに代入
		angle = atan2(playerNpos.y - pos_.y, playerNpos.x - pos_.x);
		angle += 1.5708;

		velocity_ = velocity_.Normalized();
		velocity_ *= speed_;
		pos_ += velocity_;
		
		break;
	case Center:
		pos_ += velocity_* speed_;
		angle += 0.1;
		// アニメーション回す処理
		animetionTimer++;
		if (animetionTimer == 20)
		{
			Yubiflame++;
			animetionTimer = 0;
		}
		if (Yubiflame >= 9)
		{
			Yubiflame = 0;
		}
		break;
	case TrakingEnemy:
		tarkingEnemyPosLengthN= tarkingEnemyPos - pos_;
		velocity_ = tarkingEnemyPos - pos_;

		// 正規化した方向ベクトルをAngleに代入
		angle = atan2(tarkingEnemyPos.y - pos_.y, tarkingEnemyPos.x - pos_.x);
		angle += 1.5708;

		velocity_ = velocity_.Normalized();
		if (tarkingEnemyPosLengthN.Length() >= tarkingEnemyPosLength.Length())
		{
			velocity_ *= speed_;
		}
		
		pos_ += velocity_;
		break;
	case RareEnemy_:
		// アニメーション回す処理
		animetionTimer++;
		if (animetionTimer == 10)
		{
			RareEnemyFlame++;
			animetionTimer = 0;
		}
		if (RareEnemyFlame >= 5)
		{
			RareEnemyFlame = 0;
		}

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
	if (pattern_ >= HeightUp && pattern_ <= WidthR)
	{
		if (hp == 3)
		{
			DrawRotaGraph(pos_.x - screen.x, pos_.y - screen.y, 1.0f, angle, GameScene::Siratama1Handle[Siratamaflame], true);
		}
		if (hp == 2)
		{
			DrawRotaGraph(pos_.x - screen.x, pos_.y - screen.y, 1.0f, angle, GameScene::Siratama2Handle[Siratamaflame], true);
		}
		if (hp == 1)
		{
			DrawRotaGraph(pos_.x - screen.x, pos_.y - screen.y, 1.0f, angle, GameScene::Siratama3Handle[Siratamaflame], true);
		}
	}
	if ((pattern_ >= UpperL && pattern_ <= DiagonallyDownR) || pattern_ == 9)
	{
		if (hp == 3)
		{
			DrawRotaGraph(pos_.x - screen.x, pos_.y - screen.y, 1.0f, angle, GameScene::Yubi1Handle[Yubiflame], true);
		}
		if (hp == 2)
		{
			DrawRotaGraph(pos_.x - screen.x, pos_.y - screen.y, 1.0f, angle, GameScene::Yubi2Handle[Yubiflame], true);
		}
		if (hp == 1)
		{
			DrawRotaGraph(pos_.x - screen.x, pos_.y - screen.y, 1.0f, angle, GameScene::Yubi3Handle[Yubiflame], true);
		}
	}
	if (pattern_ == Traking)
	{
		DrawRotaGraph(pos_.x - screen.x, pos_.y - screen.y, 1.0f, angle, GameScene::SnakeEnemyHandle[0], true);
	}
	if (pattern_ == TrakingEnemy)
	{
		DrawRotaGraph(pos_.x - screen.x, pos_.y - screen.y , 1.0f, angle, GameScene::SnakeEnemyHandle[1], true);
	}
	if (pattern_ == RareEnemy_)
	{
		if (hp == 3)
		{
			DrawRotaGraph(pos_.x - screen.x, pos_.y - screen.y , 1.0f, angle, GameScene::RareEnemy1Handle[RareEnemyFlame], true);
		}
		if (hp == 2)
		{
			DrawRotaGraph(pos_.x - screen.x, pos_.y - screen.y , 1.0f, angle, GameScene::RareEnemy2Handle[RareEnemyFlame], true);
		}
		if (hp == 1)
		{
			DrawRotaGraph(pos_.x - screen.x, pos_.y - screen.y , 1.0f, angle, GameScene::RareEnemy3Handle[RareEnemyFlame], true);
		}
	}
	//DrawCircle(pos_.x - screen.x , pos_.y - screen.y , radius_, GetColor(255, 0, 255), true);
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

void Enemy::SetAngle(float angle_)
{
	angle = angle_;
}

bool Enemy::GetDamageFlag()
{
	return damageFlag;
}
