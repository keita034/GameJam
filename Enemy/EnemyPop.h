#pragma once
#include "Enemy.h"
#include "SnakeEnemy.h"
#include "RareEnemy.h"
#include "Player.h"
#include "Collision.h"
#include "Util.h"
#include<memory>
#include<list>
#include"Sound.h"
#include"Pause.h"

class EnemyPop
{
public:
	// �����o�[�֐�

	EnemyPop();

	// �G�̏�����
	void EnemyPopInit();

	// �G�̍X�V����
	void EnemyPopUpdate(Player* player_);

	// �G�̕`�揈��
	void EnemyPopDraw(Player* player_);

	// �G�ƃv���C���[�̓����蔻��
	void CheckCollisions(Player* player_);

	
private:
	// �����o�[�ϐ�
	int Poptimer = 0;
	float timerInterval = 1 * 50;
	int siroGh = 0;

	// �G�̃��X�g
	std::list<std::unique_ptr<Enemy>>enemys_;

	// �ւ̓G
	std::unique_ptr<SnakeEnemy> snakeEenmy_;

	// ���A�G
	std::unique_ptr<RareEnemy> rareEenmy_;

	//�����b�J
	Sound* sound_ = nullptr;
	Pause* pause_ = nullptr;

	Smoke* smoke_ = nullptr;
};

