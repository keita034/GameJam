#include "EnemyPop.h"

void EnemyPop::EnemyPopInit()
{
	Poptimer++;

	// １ウェーブ目
	if (Poptimer == 2 * 50)
	{
		for (int i = 0; i < 5; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(HeightDown, { 640.0f + 80 * i ,740.0f }, 4.0f);
			enemys_.push_back(std::move(enemy));
		}

		for (int i = 0; i < 5; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(HeightDown, { 640.0f + 80 * i ,1440.0f }, 4.0f);
			enemys_.push_back(std::move(enemy));
		}


	}


}

void EnemyPop::EnemyPopUpdate(Player *player_)
{
	for (std::unique_ptr<Enemy>& enemy : enemys_)
	{
		enemy->Update(player_->GetPos());
	}
}

void EnemyPop::EnemyPopDraw(Player* player_)
{
	for (std::unique_ptr<Enemy>& enemy : enemys_)
	{
		enemy->Draw(player_->GetScreen());
	}
}
