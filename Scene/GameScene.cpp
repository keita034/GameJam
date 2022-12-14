#include "GameScene.h"
int GameScene::Siratama1Handle[4], GameScene::Siratama2Handle[4], GameScene::Siratama3Handle[4];
int GameScene::Yubi1Handle[9], GameScene::Yubi2Handle[9], GameScene::Yubi3Handle[9];
int GameScene::RareEnemy1Handle[5], GameScene::RareEnemy2Handle[5], GameScene::RareEnemy3Handle[5];
int GameScene::SnakeEnemyHandle[2];

GameScene::GameScene()
{
	player_ = std::make_unique<Player>();
	enemypop_ = std::make_unique<EnemyPop>();

	frameImg = LoadGraph("Resources/Flame01.png");
	frameBarImg = LoadGraph("Resources/Flame_bar.png");

	// 白玉の敵のグラフハンドル
	LoadDivGraph("Resources/siratama01.png", 4, 4, 1, 128, 128, Siratama1Handle);
	LoadDivGraph("Resources/siratama02.png", 4, 4, 1, 128, 128, Siratama2Handle);
	LoadDivGraph("Resources/siratama03.png", 4, 4, 1, 128, 128, Siratama3Handle);

	// 指敵のグラフハンドル
	LoadDivGraph("Resources/Yubinobi01.png", 9, 9, 1, 128, 128, Yubi1Handle);
	LoadDivGraph("Resources/Yubinobi02.png", 9, 9, 1, 128, 128, Yubi2Handle);
	LoadDivGraph("Resources/Yubinobi03.png", 9, 9, 1, 128, 128, Yubi3Handle);

	// レア敵のグラフハンドル
	LoadDivGraph("Resources/gejigeji_128x128.png", 5, 5, 1, 128, 128, RareEnemy1Handle);
	LoadDivGraph("Resources/gejigeji02_128x128.png", 5, 5, 1, 128, 128, RareEnemy2Handle);
	LoadDivGraph("Resources/gejigeji03_128x128.png", 5, 5, 1, 128, 128, RareEnemy3Handle);

	// 蛇の敵のグラフハンドル
	LoadDivGraph("Resources/MukadeEnemy.png", 2, 2, 1, 128, 128, SnakeEnemyHandle);

	playerBackImg = LoadGraph("Resources/player_background.png");
	backScreenImg = LoadGraph("Resources/jimen.png");

	backScreenGrandImg = LoadGraph("Resources/GameSceneBackGround.png");

	siroGh = LoadGraph("Resources/haiiroMoku.png", true);
	FinishGh = LoadGraph("Resources/FinshFont.png", true);

	operationAttackImg = LoadGraph("Resources/spaceAttack.png", true);
	operationDirectionImg = LoadGraph("Resources/changeDirection.png", true);
	
	score = Score::GetInstance();

	playerFootprints_ = new PlayerFootprints();
	//イージング初期化
	ease_ = new Ease();
}

void GameScene::Initialize()
{
	player_->Initialize();

	enemypop_->EnemyPopInitInit();

	score->Initialize(player_.get());

	playerFootprints_->Initialize();

	gameFinish = 5500;
	finish = 0;
	changeFinish = 0;
	finishX = 300;
	finishY = -350;
	easeTimer = 0;
	finishYFinishY = 250;
	easeMaxTimer = 100;
	change = 0;
}

void GameScene::Update()
{
	if (gameFinish > 0) {
		gameFinish--;

		player_->Update();

		enemypop_.get()->EnemyPopInit();
		enemypop_.get()->EnemyPopUpdate(player_.get());

		playerFootprints_->Update(player_->GetPos().x, player_->GetPos().y, player_->GetAngle());

		enemypop_.get()->CheckCollisions(player_.get());

		player_->ComboUpdate();

		score->Update(gameFinish);

		if (player_->DamageFlag())
		{
			if (player_->shakeTime > 0)
			{
				int shake = 20 - player_->shakeTime;

				if (shake < 0)
				{
					shake = 0;
				}

				int shake2 = 10 - player_->shakeTime / 3;

				randX = GetRand((20 - shake)) - (10 - shake2);

				randY = GetRand((20 - shake)) - (10 - shake2);

				player_->shakeTime--;
			}
			else
			{
				randX = 0;
				randY = 0;
			}
		}
		else
		{
			player_->shakeTime = 20;
			randX = 0;
			randY = 0;
		}

		if (player_->GetHp() <= 0) {
			gameFinish = 0;
		}
	}


	if (gameFinish <= 0) {
		changeFinish = 1;
	}
	if (changeFinish == 1) {
		if (easeTimer < easeMaxTimer) {
			easeTimer++;
		}
	}
	if (easeTimer >= 100) {
		change = 1;
		easeTimer = 0;
		finishYFinishY = -300;
		finish = 1;
	}

	finishY = finishY + (finishYFinishY - finishY) * ease_->easeInOutCubic(easeTimer / easeMaxTimer);
}


void GameScene::Draw() {

	DrawRotaGraph(1280 - player_->GetScreen().x, 720 - player_->GetScreen().y, 1.0, 0.0, backScreenGrandImg, true);

	DrawGraph(1280 - backScreenXRadius - player_->GetScreen().x, 720 - backScreenYRadius - player_->GetScreen().y, backScreenImg, true);
	
	playerFootprints_->Draw(player_->GetScreen());

	enemypop_.get()->EnemyPopDraw(player_.get());


	DrawGraph(1136 - playerBackXRadius, 510 - playerBackYRadius, playerBackImg, true);

	player_->Draw();

	DrawGraph(640 - frameXRadius + randX, 360 - frameYRadius + randY, frameImg, true);

	score->Draw();

	DrawGraph(640 - frameXRadius, 360 - frameYRadius, frameBarImg, true);

	DrawGraph(80, 672, operationAttackImg, true);
	DrawGraph(435, 672, operationDirectionImg, true);
	DrawGraph(finishX, finishY, FinishGh, true);
}


int GameScene::GetFinish() {
	return finish;
}