#include "Enemy.h"
Enemy::Enemy()
{
	pos_ = { 0,0 };
	speed_ = { 2,2 };
	playerPos_ = { 1280.0f,720.0f };
	radius_ = 5;
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

void Enemy::Update(Vec2 playerNpos)
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
		pos_ += velocity;
		break;
	case heightDown:
		speed_ = { 0,2 };
		velocity *= speed_;
		pos_ += velocity;
		break;
	case widthL:
		speed_ = { -2,0 };
		velocity *= speed_;
		pos_ += velocity;
		break;
	case widthR:
		speed_ = { 2,0 };
		velocity *= speed_;
		pos_ += velocity;
		break;
	case upperL:
		speed_ = { 2,2 };
		velocity *= speed_;
		pos_ += velocity;
		break;
	case upperR:
		speed_ = { -2,2 };
		velocity *= speed_;
		pos_ += velocity;
		break;
	case diagonallyDownL:
		speed_ = { 2,-2 };
		velocity *= speed_;
		pos_ += velocity;
		break;
	case diagonallyDownR:
		speed_ = { -2,-2 };
		velocity *= speed_;
		pos_ += velocity;
		break;
	case traking:
		// �v���C���[�̌��݂̈ʒu���擾�ƃG�l�~�[�̈ʒu�Ńx�N�g�������
		velocity = playerNpos - pos_;
		velocity.Normalized();
		speed_ = { 2,2 };
		velocity *= speed_;
		pos_ += velocity;
		break;
	default:

		break;
	}
}

void Enemy::Draw(Vec2 screen)
{
	DrawCircle(pos_.x - screen.x, pos_.y - screen.y, radius_, GetColor(255, 255, 255), true);
}

bool Enemy::IsDeath()
{
	return isDeath_;
}