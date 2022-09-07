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

	// �v���C���[�̍ŏ��̈ʒu���擾
	Vec2 centerPos = playerPos_;

	// �G�l�~�[�̈ʒu���擾
	Vec2 enemyPos = pos_;

	// �v���C���[�̏����ʒu����G�l�~�[�̈ʒu�̃x�N�g��
	Vec2 velocity = centerPos - enemyPos;
	velocity.Normalized();

	switch (pattern_)
	{
	case heightUp:
		speed_ = { 0,-2 };
		velocity *= speed_;
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
