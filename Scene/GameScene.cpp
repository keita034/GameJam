#include "GameScene.h"

GameScene::GameScene()
{
	player_ = new Player();
}

void GameScene::Initialize(){
	player_->Initialize();
}

void GameScene::Update(){
	player_->Update();
}

void GameScene::Draw(){
	player_->Draw();
}
