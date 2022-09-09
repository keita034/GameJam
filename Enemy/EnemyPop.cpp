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
		snakeEenmy_ = std::make_unique<SnakeEnemy>();
		snakeEenmy_.get()->SnakeEnemyPop({ 1080.0f ,240.0f });
	}

	// 4ÉEÉFÅ[Éuñ⁄(17ïb)
	if (Poptimer == 17 * 50)
	{
		for (int i = 0; i < 3; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(DiagonallyDownR, { 180.0f + 100 * i ,540.0f - 100 * i }, 3.0f);
			enemys_.push_back(std::move(enemy));
		}
		for (int i = 0; i < 3; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(DiagonallyDownL, { 2380.0f - 100 * i ,540.0f - 100 * i }, 3.0f);
			enemys_.push_back(std::move(enemy));
		}
		for (int i = 0; i < 3; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(UpperR, { 180.0f + 100 * i ,540.0f + 100 * i }, 3.0f);
			enemys_.push_back(std::move(enemy));
		}
		for (int i = 0; i < 3; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(UpperL, { 2380.0f - 100 * i ,540.0f + 100 * i }, 3.0f);
			enemys_.push_back(std::move(enemy));
		}
		for (int i = 0; i < 2; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(HeightDown, { 1130.0f - 150 * i ,440.0f }, 3.0f);
			enemys_.push_back(std::move(enemy));
		}
		for (int i = 0; i < 2; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(HeightUp, { 1130.0f - 150 * i ,1040.0f }, 3.0f);
			enemys_.push_back(std::move(enemy));
		}
	}

	// 5ÉEÉFÅ[Éuñ⁄(23ïb)
	if (Poptimer == 23 * 50) 
	{
		for (int i = 0; i < 5; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(HeightDown, { 880.0f + 200 * i ,240.0f }, 3.0f);
			enemys_.push_back(std::move(enemy));
		}
		for (int i = 0; i < 2; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(UpperR, { 880.0f + 200 * i ,840.0f + 100 * i }, 3.0f);
			enemys_.push_back(std::move(enemy));
		}
		for (int i = 0; i < 2; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(UpperL, { 1680.0f + 200 * i ,840.0f - 100 * i }, 3.0f);
			enemys_.push_back(std::move(enemy));
		}
	}
}

void EnemyPop::EnemyPopUpdate(Player *player_)
{

	Vec2 playerToEnemy = { 100.0f,100.0f };

	enemys_.remove_if([](std::unique_ptr<Enemy>& enemy)
	{
			return enemy->IsDeath();
	});

	player_->Attack();
	if (Poptimer >= 13 * 50)
	{
		snakeEenmy_.get()->SnakeEnemyUpdate(player_);
	}
	for (std::unique_ptr<Enemy>& enemy : enemys_)
	{
		enemy->Update(player_->GetPos());

		if (player_->AttackTriggerFlag())
		{
			if (CheckSphere2Sphere(player_->GetPos(), 100, enemy->GetPos(), enemy->GetRadius()))
			{
				if (playerToEnemy > enemy->GetPos() - player_->GetPos())
				{
					playerToEnemy = enemy->GetPos() - player_->GetPos();
				}
			}
		}
	}
	
	player_->LevelUpdate(playerToEnemy);

	player_->MoveLimit();
}

void EnemyPop::EnemyPopDraw(Player* player_)
{
	for (std::unique_ptr<Enemy>& enemy : enemys_)
	{
		enemy->Draw(player_->GetScreen());
	}
	if (Poptimer >= 13 * 50)
	{
		snakeEenmy_.get()->SnakeEnemyDraw(player_);
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
			enemy->HPSub(0);
		}
	}
}


