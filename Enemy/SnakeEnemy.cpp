#include "SnakeEnemy.h"
void SnakeEnemy::SnakeEnemyPop(Vec2 pos)
{
	snakeEnemy[0] = std::make_unique<Enemy>();
	snakeEnemy[0]->Initialize(Traking, { pos.x ,pos.y }, 3.0f);

	for (int i = 1; i < 5; i++)
	{
		snakeEnemy[i] = std::make_unique<Enemy>();
		int j = i - 1;
		Vec2 EPos = snakeEnemy[j].get()->GetPos();
		snakeEnemy[i].get()->SetTrakingEnemyPos(EPos);
		snakeEnemy[i]->Initialize(TrakingEnemy, { pos.x + 75 * i ,pos.y }, 3.0f);
	}
}

void SnakeEnemy::SnakeEnemyUpdate(Player* player_)
{
	snakeEnemy[0].get()->Update(player_->GetPos());
	for (int i = 1; i < 5; i++)
	{
		int j = i - 1;
		Vec2 EPos = snakeEnemy[j].get()->GetPos();
		snakeEnemy[i].get()->SetTrakingEnemyPos(EPos);
		snakeEnemy[i].get()->Update(player_->GetPos());
	}
}

void SnakeEnemy::SnakeEnemyDraw(Player* player_)
{
	for (int i = 0; i < 5; i++)
	{
		snakeEnemy[i].get()->Draw(player_->GetScreen());
	}
}