#include "GameScene.h"

GameScene::GameScene()
{
	player_ = std::make_unique<Player>();
	enemypop_ = std::make_unique<EnemyPop>();
}

void GameScene::Initialize(){
	player_->Initialize();
	frameImg = LoadGraph("Resources/Flame.png");
	playerBackImg = LoadGraph("Resources/player_background.png");
	backScreenImg = LoadGraph("Resources/jimen.png");
}

void GameScene::Update(){
	player_->Update();

	/*if (key.GetKeyTrigger(KEY_INPUT_0))
	{
		enemypop_.get()->EnemyPopInit();
	}*/
	enemypop_.get()->EnemyPopInit();
	enemypop_.get()->EnemyPopUpdate(player_.get());



	//for (std::unique_ptr<Enemy>& enemy : enemys_)
	//{
	//	enemy->Update(player_->GetPos());
	//}

	enemypop_.get()->CheckCollisions(player_.get());

	player_->ComboUpdate();
}

void GameScene::Draw(){

	DrawGraph(1280 - backScreenXRadius - player_->GetScreen().x, 720 - backScreenYRadius - player_->GetScreen().y, backScreenImg, true);

	enemypop_.get()->EnemyPopDraw(player_.get());
	//for (std::unique_ptr<Enemy>& enemy : enemys_)
	//{
	//	enemy->Draw(player_->GetScreen());
	//}

	DrawGraph(1136 - playerBackXRadius, 510 - playerBackYRadius, playerBackImg, true);
	DrawGraph(640 - frameXRadius, 360 - frameYRadius, frameImg, true);

	player_->Draw();

	
}


