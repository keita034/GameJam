#include "Enemy.h"
Enemy::Enemy()
{
	pos_ = { 0,0 };
	speed_ = { 2,2 };
	playerPos_ = { 0,0 };
	pattern_ = heightUp;
}

Enemy::~Enemy()
{
	
}

void Enemy::Initialize(Pattern pattern, Vec2 pos, Vec2 speed)
{
	pattern_ = pattern;
	pos_ = pos;
	speed_ = speed;
}

void Enemy::Update()
{
	Vec2 centerPos = playerPos_;

	Vec2 enemyPos = pos_;

	switch (pattern_)
	{
	case heightUp:

		break;
	case heightDown:

		break;
	case widthL:

		break;
	case widthR:

		break;
	case upperL:

		break;
	case upperR:

		break;
	case diagonallyDownL:

		break;
	case diagonallyDownR:

		break;
	case traking:

		break;
	default:
		break;
	}
}

void Enemy::Draw()
{

}
