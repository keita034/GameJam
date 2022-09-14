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
	// メンバー関数

	EnemyPop();

	// 敵の初期化
	void EnemyPopInit();

	// 敵の更新処理
	void EnemyPopUpdate(Player* player_);

	// 敵の描画処理
	void EnemyPopDraw(Player* player_);

	// 敵とプレイヤーの当たり判定
	void CheckCollisions(Player* player_);

	
private:
	// メンバー変数
	int Poptimer = 0;
	float timerInterval = 1 * 50;
	int siroGh = 0;

	// 敵のリスト
	std::list<std::unique_ptr<Enemy>>enemys_;

	// 蛇の敵
	std::unique_ptr<SnakeEnemy> snakeEenmy_;

	// レア敵
	std::unique_ptr<RareEnemy> rareEenmy_;

	//音ワッカ
	Sound* sound_ = nullptr;
	Pause* pause_ = nullptr;

	Smoke* smoke_ = nullptr;
};

