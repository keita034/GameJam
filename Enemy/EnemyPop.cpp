#include "EnemyPop.h"


void EnemyPop::EnemyPopInit()
{
	Poptimer += 1;
	// �c���Ɉړ�����G�͔��ʁA�΂߂ƒ��S�Ɉړ�����G�͎w�̓G��`��

	// �P�E�F�[�u��(2�b)-------------���A�G
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

		//-----------------------------------------------���A�G
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
		// --------------------------------����
		for (int i = 0; i < 4; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(HeightDown, { 1055.0f + 150 * i ,440.0f }, 3.0f,3);
			enemys_.push_back(std::move(enemy));
		}
		for (int i = 0; i < 4; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(HeightUp, { 1055.0f + 150 * i ,1040.0f }, 3.0f,3);
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

	// 6�E�F�[�u��(30�b)
	if (Poptimer == 30 * 50)
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

			enemy->Initialize(HeightDown, { 768.0f + 1024 * i ,440.0f }, 3.0f, 3);
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

			enemy->Initialize(HeightUp, { 768.0f + 1024 * i ,1100.0f }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}
	}

	// 7�E�F�[�u��(35�b)
	if (Poptimer == 35 * 50)
	{
		for (int i = 0; i < 6; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(WidthR, { 200.0f ,200.0f + 200.0f * i }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}

		for (int i = 0; i < 6; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(WidthL, { 2360.0f ,200.0f + 200.0f * i }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}
	}

	// 8�E�F�[�u��(42�b)
	if (Poptimer == 42 * 50)
	{
		for (int i = 0; i < 2; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(HeightDown, { 365.0f + 1830.0f * i ,190.0f }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}

		for (int i = 0; i < 4; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(HeightDown, { 730.0f + 365.0f * i,360.0f }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}

		for (int i = 0; i < 2; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(HeightUp, { 365.0f + 1830.0f * i ,1250.0f }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}

		for (int i = 0; i < 4; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(HeightUp, { 730.0f + 365.0f * i,1080.0f }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}
	}

	// 9�E�F�[�u��(47�b)
	if (Poptimer == 47 * 50)
	{
		for (int i = 0; i < 2; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(Center, { 200.0f + 100.0f * i ,200.0f - 100.0f * i }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}
		for (int i = 0; i < 2; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(Center, { 2360.0f - 100.0f * i ,200.0f - 100.0f * i }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}

		for (int i = 0; i < 6; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(HeightUp, { 1030.0f + 100.0f * i,1240.0f }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}
	}

	// 10�E�F�[�u��(55�b)
	if (Poptimer == 55 * 50)
	{
		for (int i = 0; i < 6; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(Center, { 320.0f + 320.0f * i ,200.0f }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}
		for (int i = 0; i < 6; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(Center, { 320.0f + 320.0f * i ,1240.0f }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}
		for (int i = 0; i < 6; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(Center, { 220.0f ,173.0f + 173.0f*i }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}
		for (int i = 0; i < 6; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(Center, { 2240.0f ,173.0f + 173.0f*i }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}
	}

	// 11�E�F�[�u��(60�b)
	if (Poptimer == 60 * 50)
	{
		for (int i = 0; i < 4; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(WidthR, { 200.0f  ,360.0f + 270.0f * i }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}
		for (int i = 0; i < 2; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(WidthR, { 350.0f  ,405.0f + 630.0f * i }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}

		for (int i = 0; i < 4; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(WidthL, { 2360.0f  ,270.0f + 270.0f * i }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}
		for (int i = 0; i < 2; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(WidthL, { 2210.0f  ,405.0f + 630.0f * i }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}
	}

	// 12�E�F�[�u��(65�b)
	if (Poptimer == 65 * 50)
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

	// 13�E�F�[�u��(70�b)
	if (Poptimer == 70 * 50)
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

			enemy->Initialize(HeightDown, { 768.0f + 1024 * i ,440.0f }, 3.0f, 3);
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

			enemy->Initialize(HeightUp, { 768.0f + 1024 * i ,1100.0f }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}
	}

	// 14�E�F�[�u��(75�b)
	if (Poptimer == 75 * 50)
	{
		for (int i = 0; i < 5; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(HeightDown, { 1080.0f + 100 * i ,240.0f }, 3.0f, 3);
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
	}

	// 15�E�F�[�u��(80�b)
	if (Poptimer == 80 * 50)
	{
		for (int i = 0; i < 3; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(DiagonallyDownR, { 180.0f + 100 * i ,540.0f - 100 * i }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}
		for (int i = 0; i < 3; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(DiagonallyDownL, { 2380.0f - 100 * i ,540.0f - 100 * i }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}
		for (int i = 0; i < 3; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(UpperR, { 180.0f + 100 * i ,540.0f + 100 * i }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}
		for (int i = 0; i < 3; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(UpperL, { 2380.0f - 100 * i ,540.0f + 100 * i }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}
		for (int i = 0; i < 4; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(HeightDown, { 1055.0f + 150 * i ,440.0f }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}
		for (int i = 0; i < 4; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(HeightUp, { 1055.0f + 150 * i ,1040.0f }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}
	}

	// 16�E�F�[�u��(85�b)
	if (Poptimer == 85 * 50) 
	{
		for (int i = 0; i < 2; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(HeightDown, { 365.0f + 1830.0f * i ,190.0f }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}

		for (int i = 0; i < 4; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(HeightDown, { 730.0f + 365.0f * i,360.0f }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}

		for (int i = 0; i < 2; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(HeightUp, { 365.0f + 1830.0f * i ,1250.0f }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}

		for (int i = 0; i < 4; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(HeightUp, { 730.0f + 365.0f * i,1080.0f }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}
	}

	// 17�E�F�[�u��(90�b)--------------���������ΎE���}��
	if (Poptimer == 90 * 50)
	{
		for (int i = 0; i < 10; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(HeightDown, { 230.4f + 230.4f * i ,100.0f }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}

		for (int i = 0; i < 10; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(HeightUp, { 230.4f + 230.4f * i ,1340.0f }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}

		for (int i = 0; i < 8; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(WidthR, { 100.0f,157.5f + 157.5f * i }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}
		for (int i = 0; i < 8; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(WidthL, { 2460.0f,157.5f + 157.5f * i }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}
	}

	// 18�E�F�[�u��(92�b)
	if (Poptimer == 92 * 50)
	{
		for (int i = 0; i < 10; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(HeightDown, { 230.4f + 230.4f * i ,100.0f }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}

		for (int i = 0; i < 10; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(HeightUp, { 230.4f + 230.4f * i ,1340.0f }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}

		for (int i = 0; i < 8; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(WidthR, { 100.0f,157.5f + 157.5f * i }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}
		for (int i = 0; i < 8; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(WidthL, { 2460.0f,157.5f + 157.5f * i }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}
	}

	// 19�E�F�[�u��(94�b)
	if (Poptimer == 94 * 50)
	{
		for (int i = 0; i < 10; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(HeightDown, { 230.4f + 230.4f * i ,100.0f }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}

		for (int i = 0; i < 10; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(HeightUp, { 230.4f + 230.4f * i ,1340.0f }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}

		for (int i = 0; i < 8; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(WidthR, { 100.0f,157.5f + 157.5f * i }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}
		for (int i = 0; i < 8; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(WidthL, { 2460.0f,157.5f + 157.5f * i }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}
	}

	// 20�E�F�[�u��(96�b)
	if (Poptimer == 96 * 50)
	{
		for (int i = 0; i < 10; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(HeightDown, { 230.4f + 230.4f * i ,100.0f }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}

		for (int i = 0; i < 10; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(HeightUp, { 230.4f + 230.4f * i ,1340.0f }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}

		for (int i = 0; i < 8; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(WidthR, { 100.0f,157.5f + 157.5f * i }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}
		for (int i = 0; i < 8; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(WidthL, { 2460.0f,157.5f + 157.5f * i }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}
	}

	// 21�E�F�[�u��(98�b)
	if (Poptimer == 98 * 50)
	{
		for (int i = 0; i < 10; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(HeightDown, { 230.4f + 230.4f * i ,100.0f }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}

		for (int i = 0; i < 10; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(HeightUp, { 230.4f + 230.4f * i ,1340.0f }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}

		for (int i = 0; i < 8; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(WidthR, { 100.0f,157.5f + 157.5f * i }, 3.0f, 3);
			enemys_.push_back(std::move(enemy));
		}
		for (int i = 0; i < 8; i++)
		{
			std::unique_ptr<Enemy> enemy;
			enemy = std::make_unique<Enemy>();

			enemy->Initialize(WidthL, { 2460.0f,157.5f + 157.5f * i }, 3.0f, 3);
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

	//DrawFormatString(100, 100, GetColor(255, 255, 255), "time=%d", Poptimer / 50);
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


