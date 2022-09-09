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
	// ‚É‚å‚ë‚É‚å‚ë“G‚Ì‚ğ¶¬
	void SnakeEnemyPop(Vec2 pos);

	// ‚É‚å‚ë‚É‚å‚ë“G‚ÌXVˆ—
	void SnakeEnemyUpdate(Player* player_);

	// ‚É‚å‚ë‚É‚å‚ë“G‚Ì•`‰æˆ—
	void SnakeEnemyDraw(Player* player_);

private:
	// ‚É‚å‚ë‚É‚å‚ë“G—p‚Ì”z—ñ
	std::unique_ptr<Enemy> snakeEnemy[5];

};

