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

private:
	// �ɂ��ɂ��G�p�̔z��
	std::unique_ptr<Enemy> snakeEnemy[5];

};

