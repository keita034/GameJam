#include "EnemyPop.h"

void EnemyPop::EnemyPopInit()
{
	Poptimer += 1;

	// ÇPÉEÉFÅ[Éuñ⁄(2ïb)
	if (Poptimer == 2 * 50)
	{
		for (int i = 0; i < 5; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(HeightDown, { 1080.0f + 100 * i ,240.0f }, 3.0f);
			enemys_.push_back(std::move(enemy));
		}

		for (int i = 0; i < 5; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(HeightUp, { 1080.0f + 100 * i ,1240.0f }, 3.0f);
			enemys_.push_back(std::move(enemy));
		}

		for (int i = 0; i < 5; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(Center, { 2260.0f , 520.0f + 100 * i },4.0f);
			enemys_.push_back(std::move(enemy));
		}
		for (int i = 0; i < 5; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(Center, { 300.0f , 520.0f + 100 * i },4.0f);
			enemys_.push_back(std::move(enemy));
		}
	}

	// ÇQÉEÉFÅ[Éuñ⁄(ÇVïb)
	if (Poptimer == 7 * 50)
	{
		for (int i = 0; i < 5; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(DiagonallyDownR, { 180.0f + 100 * i ,540.0f - 100 * i }, 3.0f);
			enemys_.push_back(std::move(enemy));
		}

		for (int i = 0; i < 5; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(DiagonallyDownL, { 2380.0f - 100 * i ,540.0f - 100 * i }, 3.0f);
			enemys_.push_back(std::move(enemy));
		}
		for (int i = 0; i < 5; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(UpperR, { 180.0f + 100 * i ,540.0f + 100 * i }, 3.0f);
			enemys_.push_back(std::move(enemy));
		}
		for (int i = 0; i < 5; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(UpperL, { 2380.0f - 100 * i ,540.0f + 100 * i }, 3.0f);
			enemys_.push_back(std::move(enemy));
		}
	}

	// 3ÉEÉFÅ[Éuñ⁄(12ïb)
	if (Poptimer == 13 * 50)
	{

	}
}

void EnemyPop::EnemyPopUpdate(Player *player_)
{
	enemys_.remove_if([](std::unique_ptr<Enemy>& enemy)
	{
			return enemy->IsDeath();
	});
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

void EnemyPop::CheckCollisions(Player* player_)
{
	for (std::unique_ptr<Enemy>& enemy : enemys_)
	{
		//ìGÇ∆é©ã@
		if (!player_->GetAttackFlag() && CheckSphere2Sphere(player_->GetPos(), player_->GetRadius(), enemy->GetPos(), enemy->GetRadius()))
		{
			player_->HPSub(1);
			enemy->Death();
		}

		if (player_->GetAttackFlag())
		{
			//é©ã@ÇÃçUåÇÇ∆ìG
			if (CheckSphere2Sphere(player_->GetPos(), player_->GetAttackRadius(), enemy->GetPos(), enemy->GetRadius()))
			{
				enemy->HPSub(player_->GetAttackPower());
			}
		}
		else
		{
			enemy->HPSub(1);
		}
	}
}
