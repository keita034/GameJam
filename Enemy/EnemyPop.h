#pragma once
#include "Enemy.h"
#include "Player.h"
#include "Collision.h"
#include<memory>
#include<list>
class EnemyPop
{
public:
	// メンバー関数

	// 敵の初期化
	void EnemyPopInit();

	// 敵の更新処理
	void EnemyPopUpdate(Player* player_);

	// 敵の描画処理
	void EnemyPopDraw(Player* player_);

	void CheckCollisions(Player* player_);
private:
	// メンバー変数
	int Poptimer = 0;
	float timerInterval = 1 * 50;

	// 敵のリスト
	std::list<std::unique_ptr<Enemy>>enemys_;

};

