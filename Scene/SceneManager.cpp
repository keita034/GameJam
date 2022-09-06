#include "SceneManager.h"

SceneManager::SceneManager() {}

SceneManager::~SceneManager() {

}

void SceneManager::Initialize() {
	//newする
	titleScene_ = new TitleScene();
	gameScene_ = new GameScene();
	resultScene_ = new ResultScene();

	//イニシャライズする
	//titleScene_->Initialize();
	//gameScene_->Initialize();
	//resultScene_->Initialize();

}

void SceneManager::Update(char* keys, char* oldkeys) {

	switch (scene_) {
	case SceneManager::Scene::Blackout://暗転シーン
		Blackout(keys, oldkeys);

		break;
	case SceneManager::Scene::Title://タイトル
		Title();

		break;
	case SceneManager::Scene::Tutorial://チュートリアル
		Tutorial();

		break;
	case SceneManager::Scene::Stage://バトルステージ
		Stage();

		break;
	case SceneManager::Scene::Result://リザルト
		Result();

		break;
	default:
		break;
	}

}

void SceneManager::Draw() {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, pal);
	DrawBox(0, 0, 1280, 720, GetColor(0, 0, 0), true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}



//シーン切り替え
void SceneManager::Blackout(char* keys, char* oldkeys) {
	if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
		isBlackOut = 1;
		pal = 0;
	}
	if (isBlackOut == 1) {
		if (pal < 255) {
			pal += 30;
		}
	}
}

void SceneManager::Title() {

}

void SceneManager::Tutorial() {

}

void SceneManager::Stage() {

}

void SceneManager::Result() {

}
