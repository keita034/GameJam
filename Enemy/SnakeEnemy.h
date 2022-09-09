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

private:
	// にょろにょろ敵用の配列
	std::unique_ptr<Enemy> snakeEnemy[5];

};

