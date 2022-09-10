#include "EnemyPop.h"


void EnemyPop::EnemyPopInit()
{
	Poptimer += 1;
	
	// �P�E�F�[�u��(2�b)
	if (Poptimer == 2 * 50)
	{
		for (int i = 0; i < 5; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(HeightDown, { 1080.0f + 100 * i ,240.0f }, 3.0f,3);
			enemys_.push_back(std::move(enemy));
		}

		for (int i = 0; i < 5; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(HeightUp, { 1080.0f + 100 * i ,1240.0f }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}

		for (int i = 0; i < 5; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(Center, { 2260.0f , 520.0f + 100 * i }, 4.0f, 3);
			enemys_.push_back(std::move(enemy));
		}
		for (int i = 0; i < 5; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(Center, { 300.0f , 520.0f + 100 * i }, 4.0f, 3);
			enemys_.push_back(std::move(enemy));
		}
		rareEenmy_= std::make_unique<RareEnemy>();
		rareEenmy_.get()->RareEnemyInit({ 1280, -70 });
	}

	// �Q�E�F�[�u��(�V�b)
	if (Poptimer == 7 * 50)
	{
		for (int i = 0; i < 5; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(DiagonallyDownR, { 180.0f + 100 * i ,540.0f - 100 * i }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}

		for (int i = 0; i < 5; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(DiagonallyDownL, { 2380.0f - 100 * i ,540.0f - 100 * i }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}
		for (int i = 0; i < 5; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(UpperR, { 180.0f + 100 * i ,540.0f + 100 * i }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}
		for (int i = 0; i < 5; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(UpperL, { 2380.0f - 100 * i ,540.0f + 100 * i }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}
	}

	// 3�E�F�[�u��(12�b)----��
	if (Poptimer == 13 * 50)
	{
		snakeEenmy_ = std::make_unique<SnakeEnemy>();
		snakeEenmy_.get()->SnakeEnemyPop({ 1080.0f ,240.0f });
	}

	// 4�E�F�[�u��(17�b)
	if (Poptimer == 17 * 50)
	{
		for (int i = 0; i < 3; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(DiagonallyDownR, { 180.0f + 100 * i ,540.0f - 100 * i }, 3.0f,3);
			enemys_.push_back(std::move(enemy));
		}
		for (int i = 0; i < 3; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(DiagonallyDownL, { 2380.0f - 100 * i ,540.0f - 100 * i }, 3.0f,3);
			enemys_.push_back(std::move(enemy));
		}
		for (int i = 0; i < 3; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(UpperR, { 180.0f + 100 * i ,540.0f + 100 * i }, 3.0f,3);
			enemys_.push_back(std::move(enemy));
		}
		for (int i = 0; i < 3; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(UpperL, { 2380.0f - 100 * i ,540.0f + 100 * i }, 3.0f,3);
			enemys_.push_back(std::move(enemy));
		}
		for (int i = 0; i < 2; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(HeightDown, { 1130.0f - 150 * i ,440.0f }, 3.0f,3);
			enemys_.push_back(std::move(enemy));
		}
		for (int i = 0; i < 2; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(HeightUp, { 1130.0f - 150 * i ,1040.0f }, 3.0f,3);
			enemys_.push_back(std::move(enemy));
		}
	}

	// 5�E�F�[�u��(23�b)
	if (Poptimer == 23 * 50) 
	{
		for (int i = 0; i < 5; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(HeightDown, { 880.0f + 200 * i ,240.0f }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}
		for (int i = 0; i < 2; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(UpperR, { 880.0f + 200 * i ,840.0f + 100 * i }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}
		for (int i = 0; i < 2; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(UpperL, { 1680.0f + 200 * i ,840.0f - 100 * i }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}
	}

	// 6�E�F�[�u��(28�b)
	if (Poptimer == 28 * 50)
	{
		for (int i = 0; i < 4; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(HeightDown, { 512.0f + 512 * i ,240.0f }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}

		for (int i = 0; i < 2; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(HeightDown, { 852.0f + 852 * i ,440.0f }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}

		for (int i = 0; i < 4; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(HeightUp, { 512.0f + 512 * i ,1300.0f }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}

		for (int i = 0; i < 2; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(HeightUp, { 852.0f + 852 * i ,1100.0f }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}
	}

	// 7�E�F�[�u��(33�b)
	if (Poptimer == 33 * 50)
	{
		for (int i = 0; i < 6; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(HeightDown, { 200.0f ,240.0f + 240.0f * i }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}

		for (int i = 0; i < 6; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(HeightDown, { 2360.0f ,240.0f + 240.0f * i }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}
	}

	// 8�E�F�[�u��(38�b)
	if (Poptimer == 38 * 50)
	{
		for (int i = 0; i < 2; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(HeightDown, { 200.0f ,240.0f + 240.0f * i }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}

		for (int i = 0; i < 4; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(HeightDown, { 2360.0f ,240.0f + 240.0f * i }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}
	}
}

void EnemyPop::EnemyPopUpdate(Player *player_)
{

	Vec2 playerToEnemy = { 900.0f,900.0f };

	enemys_.remove_if([](std::unique_ptr<Enemy>& enemy)
	{
			return enemy->IsDeath();
	});

	

	player_->Attack();

	if (Poptimer >= 2 * 50)
	{
		if (rareEenmy_ != nullptr)
		{
			if (rareEenmy_->IsDeath() == true)
			{
				rareEenmy_.release();
			}
		}
		if (rareEenmy_!= nullptr)
		{
			rareEenmy_.get()->RareEnemyUpdate(player_);
		}
	}

	if (Poptimer >= 13 * 50)
	{
		if (snakeEenmy_ != nullptr)
		{
			if (snakeEenmy_->GetDeathCount() >= 5)
			{
				snakeEenmy_.release();
			
			}
			if (snakeEenmy_ != nullptr)
			{
				snakeEenmy_->SnakeEnemyUpdate(player_);
			}
		}
		
	}


	Enemy* tmpEnemy = nullptr;

	for (std::unique_ptr<Enemy>& enemy : enemys_)
	{
		enemy->Update(player_->GetPos());

		if (player_->AttackTriggerFlag())
		{
			if (CheckSphere2Sphere(player_->GetPos(), 100, enemy->GetPos(), enemy->GetRadius()))
			{
				if (playerToEnemy > enemy->GetPos() - player_->GetPos())
				{
					tmpEnemy = enemy.get();
					playerToEnemy = enemy->GetPos() - player_->GetPos();
				}
			}
		}
	}
	
	player_->LevelUpdate(playerToEnemy,tmpEnemy);

	player_->MoveLimit();
}

void EnemyPop::EnemyPopDraw(Player* player_)
{
	for (std::unique_ptr<Enemy>& enemy : enemys_)
	{
		enemy->Draw(player_->GetScreen());
	}
	if (Poptimer >= 2 * 50)
	{
		if (rareEenmy_ != nullptr)
		{
			rareEenmy_.get()->RareEnemyDraw(player_);
		}
	}
	if (Poptimer >= 13 * 50)
	{
		if (snakeEenmy_ != nullptr)
		{
			snakeEenmy_.get()->SnakeEnemyDraw(player_);
		}
	}
}

void EnemyPop::CheckCollisions(Player* player_)
{

	for (std::unique_ptr<Enemy>& enemy : enemys_)
	{

		//�G�Ǝ��@
		if (!player_->GetAttackFlag() && CheckSphere2Sphere(player_->GetPos(), player_->GetRadius(), enemy->GetPos(), enemy->GetRadius()))
		{
			player_->HPSub(1);
			enemy->Death();
		}

		if (player_->GetAttackFlag())
		{
			//���@�̍U���ƓG
			if (CheckSphere2Sphere(player_->GetPos(), player_->GetAttackRadius(), enemy->GetPos(), enemy->GetRadius()))
			{
				if (enemy->GetDamageFlag())
				{
					player_->AddCombo();
				}

				enemy->HPSub(player_->GetAttackPower());

			}
		}
	}
}


