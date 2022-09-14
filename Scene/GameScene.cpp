#include "GameScene.h"
int GameScene::Siratama1Handle[4], GameScene::Siratama2Handle[4], GameScene::Siratama3Handle[4];
int GameScene::Yubi1Handle[9], GameScene::Yubi2Handle[9], GameScene::Yubi3Handle[9];
int GameScene::RareEnemy1Handle[5], GameScene::RareEnemy2Handle[5], GameScene::RareEnemy3Handle[5];
int GameScene::SnakeEnemyHandle[2];

GameScene::GameScene()
{
	player_ = std::make_unique<Player>();
	enemypop_ = std::make_unique<EnemyPop>();

}

void GameScene::Initialize(){
	player_->Initialize();
	frameImg = LoadGraph("Resources/Flame.png");

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


	score = Score::GetInstance();

	//smoke_ = new Smoke();
	playerFootprints_ = new PlayerFootprints();

	score->Initialize(player_.get());

	playerFootprints_->Initialize();
	

}

void GameScene::Update(){
	player_->Update();

	/*if (key.GetKeyTrigger(KEY_INPUT_0))
	{
		enemypop_.get()->EnemyPopInit();
	}*/
	enemypop_.get()->EnemyPopInit();
	enemypop_.get()->EnemyPopUpdate(player_.get());

	playerFootprints_->Update(player_->GetPos().x, player_->GetPos().y,player_->GetAngle());


	enemypop_.get()->CheckCollisions(player_.get());



	player_->ComboUpdate();

	score->Update();

}

void GameScene::Draw(){

	DrawRotaGraph(1280 - player_->GetScreen().x, 720 - player_->GetScreen().y, 1.0, 0.0, backScreenGrandImg, true);

	DrawGraph(1280 - backScreenXRadius - player_->GetScreen().x, 720 - backScreenYRadius - player_->GetScreen().y, backScreenImg, true);

	enemypop_.get()->EnemyPopDraw(player_.get());
	//for (std::unique_ptr<Enemy>& enemy : enemys_)
	//{
	//	enemy->Draw(player_->GetScreen());
	//}


	DrawGraph(1136 - playerBackXRadius, 510 - playerBackYRadius, playerBackImg, true);

	DrawFormatString(700, 140, GetColor(0, 0, 0), "%f", player_->GetScreen().x, true);
	DrawFormatString(700, 160, GetColor(0, 0, 0), "%f", player_->GetScreen().y, true);

	playerFootprints_->Draw(player_->GetScreen());
	player_->Draw();
	
	DrawGraph(640 - frameXRadius, 360 - frameYRadius, frameImg, true);

	score->Draw();
}


