#pragma once
#include "Enemy.h"
#include "Player.h"
#include "Collision.h"
#include "Util.h"
#include<memory>
#include<list>
class SnakeEnemy
{
public:
	// �ɂ��ɂ��G�̂𐶐�
	void SnakeEnemyPop(Vec2 pos);

	// �ɂ��ɂ��G�̍X�V����
	void SnakeEnemyUpdate(Player* player_);

	// �ɂ��ɂ��G�̕`�揈��
	void SnakeEnemyDraw(Player* player_);

	// �ɂ��ɂ��ƃv���C���[�Ƃ̓����蔻��
	void SnakeEnemyCheckCollisions(Player* player_);

	// �ǂꂮ�炢�ɂ��ɂ��̃p�[�c�����񂾂�
	int GetDeathCount();

private:
	// �ɂ��ɂ��G�p�̔z��
	std::unique_ptr<Enemy> snakeEnemy[5];

	// �ɂ��ɂ��̑̂����񂾐�
	int deathNum = 0;

	// �ɂ��ɂ��Ƃ̓����蔻����Ƃ�Ԋu
	int collisionTimer = 0;
	int collisionInterval = 18;
};

