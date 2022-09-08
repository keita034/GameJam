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
		SnakeEnemyPop(Vec2{ 1080.0f ,240.0f });
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
	if (Poptimer >= 13 * 50)
	{
		SnakeEnemyUpdate(player_);
	}

	player_->AttackUpdate(playerToEnemy);

}

void EnemyPop::EnemyPopDraw(Player* player_)
{
	for (std::unique_ptr<Enemy>& enemy : enemys_)
	{
		enemy->Draw(player_->GetScreen());
	}
	if (Poptimer >= 13 * 50)
	{
		SnakeEnemyDraw(player_);
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

void EnemyPop::SnakeEnemyPop(Vec2 pos)
{
	SnakeEnemy[0] = std::make_unique<Enemy>();
	SnakeEnemy[0]->Initialize(Traking, { pos.x ,pos.y }, 3.0f);
	
	for (int i = 1; i < 5; i++)
	{
		SnakeEnemy[i] = std::make_unique<Enemy>();
		int j = i - 1;
		Vec2 EPos = SnakeEnemy[j].get()->GetPos();
		SnakeEnemy[i].get()->SetTrakingEnemyPos(EPos);
		SnakeEnemy[i]->Initialize(TrakingEnemy, { pos.x + 75 * i ,pos.y }, 3.0f);
	}
}

void EnemyPop::SnakeEnemyUpdate(Player* player_)
{
	SnakeEnemy[0].get()->Update(player_->GetPos());
	for (int i = 1; i < 5; i++)
	{
		int j = i - 1;
		Vec2 EPos = SnakeEnemy[j].get()->GetPos();
		SnakeEnemy[i].get()->SetTrakingEnemyPos(EPos);
		SnakeEnemy[i].get()->Update(player_->GetPos());
	}
}

void EnemyPop::SnakeEnemyDraw(Player* player_)
{
	for (int i = 0; i < 5; i++)
	{
		SnakeEnemy[i].get()->Draw(player_->GetScreen());
	}
}
