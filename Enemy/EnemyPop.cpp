#include "EnemyPop.h"


void EnemyPop::EnemyPopInit()
{
	Poptimer += 1;
	// 縦横に移動する敵は白玉、斜めと中心に移動する敵は指の敵を描画

	// １ウェーブ目(2秒)-------------レア敵
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

		//-----------------------------------------------レア敵
		rareEenmy_= std::make_unique<RareEnemy>();
		rareEenmy_.get()->RareEnemyInit({ 1280, -70 });
	}

	// ２ウェーブ目(７秒)
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

	// 3ウェーブ目(12秒)----蛇
	if (Poptimer == 13 * 50)
	{
		snakeEenmy_ = std::make_unique<SnakeEnemy>();
		snakeEenmy_.get()->SnakeEnemyPop({ 1080.0f ,240.0f });
	}

	// 4ウェーブ目(17秒)
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
		// --------------------------------白玉
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

	// 5ウェーブ目(23秒)
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

	// 6ウェーブ目(30秒)
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

	// 7ウェーブ目(35秒)
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

	// 8ウェーブ目(42秒)
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

	// 9ウェーブ目(47秒)
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

	// 10ウェーブ目(55秒)
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

	// 11ウェーブ目(60秒)
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

	// 12ウェーブ目(65秒)
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

	// 13ウェーブ目(70秒)
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

	// 14ウェーブ目(75秒)
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

	// 15ウェーブ目(80秒)
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

	// 16ウェーブ目(85秒)
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

	// 17ウェーブ目(90秒)--------------ここから絶対殺すマン
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

	// 18ウェーブ目(92秒)
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

	// 19ウェーブ目(94秒)
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

	// 20ウェーブ目(96秒)
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

	// 21ウェーブ目(98秒)
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

		//敵と自機
		if (!player_->GetAttackFlag() && CheckSphere2Sphere(player_->GetPos(), player_->GetRadius(), enemy->GetPos(), enemy->GetRadius()))
		{
			player_->HPSub(1);
			enemy->Death();
		}

		if (player_->GetAttackFlag())
		{
			//自機の攻撃と敵
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


