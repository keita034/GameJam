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
	// にょろにょろ敵のを生成
	void SnakeEnemyPop(Vec2 pos);

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

	// にょろにょろの体が死んだ数
	int deathNum = 0;

	// にょろにょろとの当たり判定をとる間隔
	int collisionTimer = 0;
	int collisionInterval = 18;
};

