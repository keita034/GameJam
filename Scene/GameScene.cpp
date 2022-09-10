#include "GameScene.h"

GameScene::GameScene()
{
	player_ = std::make_unique<Player>();
	enemypop_ = std::make_unique<EnemyPop>();
}

void GameScene::Initialize(){
	player_->Initialize();
	frameImg = LoadGraph("Resources/Flame.png");
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

	player_->Draw();
	enemypop_.get()->EnemyPopDraw(player_.get());
	//for (std::unique_ptr<Enemy>& enemy : enemys_)
	//{
	//	enemy->Draw(player_->GetScreen());
	//}

	DrawGraph(0-50, 0-50, frameImg, true);
}


