#include "Enemy.h"
Enemy::Enemy()
{
	pos_ = { 0,0 };
	speed_ = 2;
	playerPos_ = { 1280.0f,720.0f };
	radius_ = 5;
	pattern_ = HeightUp;
	isDeath_ = false;
}

Enemy::~Enemy()
{
	
}

void Enemy::Initialize(Pattern pattern, Vec2 pos, float speed)
{
	pattern_ = pattern;
	pos_ = pos;
	speed_ = speed;

	// プレイヤーの初期位置からエネミーの位置のベクトル
	velocity_ = playerPos_ - pos_;
	velocity_ = velocity_.Normalized();
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
	default:
		break;
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