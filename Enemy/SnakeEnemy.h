#pragma once
#include "Enemy.h"
#include "Player.h"
#include "Collision.h"
#include "Util.h"
#include<memory>
#include<list>
#include"Smoke.h"
#include"Sound.h"
#include"Pause.h"

class SnakeEnemy
{
public:
	// にょろにょろ敵のを生成
	void SnakeEnemyPop(Vec2 pos, int siroGh);

	// にょろにょろ敵の更新処理
	void SnakeEnemyUpdate(Player* player_);

	// にょろにょろ敵の描画処理
	void SnakeEnemyDraw(Player* player_);

	// にょろにょろとプレイヤーとの当たり判定
	void SnakeEnemyCheckCollisions(Player* player_);

	// どれぐらいにょろにょろのパーツが死んだか
	int GetDeathCount();

private:
	// にょろにょろ敵用の配列
	std::unique_ptr<Enemy> snakeEnemy[5];
	Smoke* smoke_ = nullptr;

	// にょろにょろの体が死んだ数
	int deathNum = 0;

	// にょろにょろとの当たり判定をとる間隔
	int collisionTimer = 0;
	int collisionInterval = 18;


	int smokeTimer = 0;

	int isEnemyDie[5];

	//音ワッカ
	Sound* sound_ = nullptr;
	Pause* pause_ = nullptr;
};

