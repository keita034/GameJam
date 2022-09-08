#pragma once
#include "Enemy.h"
#include "Player.h"
#include "Collision.h"
#include<memory>
#include<list>
class EnemyPop
{
public:
	// �����o�[�֐�

	// �G�̏�����
	void EnemyPopInit();

	// �G�̍X�V����
	void EnemyPopUpdate(Player* player_);

	// �G�̕`�揈��
	void EnemyPopDraw(Player* player_);

	void CheckCollisions(Player* player_);
private:
	// �����o�[�ϐ�
	int Poptimer = 0;
	float timerInterval = 1 * 50;

	// �G�̃��X�g
	std::list<std::unique_ptr<Enemy>>enemys_;

};

