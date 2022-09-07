#include "GameScene.h"

GameScene::GameScene()
{
	player_ = std::make_unique<Player>();
}

void GameScene::Initialize(){
	player_->Initialize();
}

void GameScene::Update(){
	player_->Update();

	if (key.GetKeyTrigger(KEY_INPUT_0))
	{
		std::unique_ptr<Enemy> enemy;
		enemy = std::make_unique<Enemy>();

		enemy->Initialize(UpperL, { 640.0f ,1440.0f }, 5.0f);
		enemys_.push_back(std::move(enemy));
	}

	enemys_.remove_if([](std::unique_ptr<Enemy>& enemy)
		{
			return enemy->IsDeath();
		});

	for (std::unique_ptr<Enemy>& enemy : enemys_)
	{
		enemy->Update(player_->GetPos());
	}
}

void GameScene::Draw(){

	player_->Draw();

	for (std::unique_ptr<Enemy>& enemy : enemys_)
	{
		enemy->Draw(player_->GetScreen());
	}
}

void GameScene::CheckCollisions()
{
	
}
