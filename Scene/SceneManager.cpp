#include "SceneManager.h"

SceneManager::SceneManager() {}

SceneManager::~SceneManager() {

}

void SceneManager::Initialize() {

	//newする
	titleScene_ = new TitleScene();
	gameScene_ = new GameScene();
	resultScene_ = new ResultScene();
	pause_ = new Pause();
	sound_ = new Sound();

	//初期化処理
	titleScene_->Initialize();
	gameScene_->Initialize();
	//resultScene_->Initialize();
	pause_->Initialize();
	sound_->Initialize();

}

void SceneManager::Update(char* keys, char* oldkeys) {

	switch (scene_) {
	case SceneManager::Scene::Blackout://暗転シーン
		Blackout(keys, oldkeys);

		break;
	case SceneManager::Scene::Title://タイトル
		Title(keys, oldkeys);
		titleScene_->Update();
		
		if (key.GetKeyTrigger(KEY_INPUT_ESCAPE)) {
			if (isESC == 0) {
				pause_->TimerReset(0);
				pause_->SetIsEsc(isESC);
				isESC = 1;
			}
			else if (isESC == 1) {
				pause_->TimerReset(0);
				pause_->SetIsEsc(isESC);
				isESC = 0;
			}
		}

		pause_->Update();
		sound_->SetSound(pause_->GetSoundVolum());
		sound_->TitleUpdate();
		sound_->Updata(pause_->GetSoundVolum());

		break;
	case SceneManager::Scene::Tutorial://チュートリアル
		Tutorial(keys, oldkeys);

		break;
	case SceneManager::Scene::Stage://バトルステージ
		//Stage(keys, oldkeys);

		if (key.GetKeyTrigger(KEY_INPUT_ESCAPE)) {
			if (isESC == 0) {
				pause_->TimerReset(0);
				pause_->SetIsEsc(isESC);
				isESC = 1;
			}
			else if (isESC == 1) {
				pause_->TimerReset(0);
				pause_->SetIsEsc(isESC);
				isESC = 0;
			}
		}

		pause_->Update();
		vx = pause_->GetSoundVolum();
		sound_->SetSound(vx);
		sound_->gameSceneUpdate();
		sound_->Updata(vx);

		gameScene_->Update();


		break;
	case SceneManager::Scene::Result://リザルト
		Result(keys, oldkeys);

		break;
	default:
		break;
	}

}

void SceneManager::Draw() {

	switch (scene_)
	{
	case SceneManager::Scene::Title://タイトル
		titleScene_->Draw();
		pause_->Draw();
		break;
	case SceneManager::Scene::Tutorial://チュートリアル

		break;
	case SceneManager::Scene::Stage://バトルステージ
		gameScene_->Draw();
		pause_->Draw();

		break;
	case SceneManager::Scene::Result://リザルト

		break;
	default:
		break;
	}

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, pal);
	DrawBox(0, 0, 1280, 720, GetColor(0, 0, 0), true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}



//シーン切り替え
void SceneManager::Blackout(char* keys, char* oldkeys) {
	if (isBlackOut == 0) {
		isBlackOut = 1;
		pal = 255;
	}
	else if (isBlackOut == 1) {
		if (pal < 255) {
			pal += 5;
		}
		else if (pal >= 255) {
			if (justBefore == 1) {
				pal = 0;
				scene_ = Scene::Tutorial;
			}
			else if (justBefore == 2) {
				pal = 0;
				scene_ = Scene::Stage;
			}
			else if (justBefore == 3) {
				pal = 0;
				scene_ = Scene::Result;
			}
		}
	}
}

void SceneManager::Title(char* keys, char* oldkeys) {
	justBefore = 2;
	if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
		blackFlag = 1;
		pal = 0;
	}
	if (blackFlag == 1) {
		pal = pal + 5;
		if (pal >= 255) {
			scene_ = Scene::Blackout;
		}
	}

}

void SceneManager::Tutorial(char* keys, char* oldkeys) {
	justBefore = 2;
	if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
		scene_ = Scene::Blackout;
	}
}

void SceneManager::Stage(char* keys, char* oldkeys) {
	justBefore = 3;
	if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
		scene_ = Scene::Blackout;
	}
}

void SceneManager::Result(char* keys, char* oldkeys) {
	justBefore = 4;
	if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
		scene_ = Scene::Blackout;
	}
}


int SceneManager::GetFinish() {
	isFinish = pause_->GetFinish();

	return isFinish;
}


void SceneManager::TestMove() {

	if (key.GetKey(KEY_INPUT_W)) {
		y--;
	}
	if (key.GetKey(KEY_INPUT_S)) {
		y++;
	}
	if (key.GetKey(KEY_INPUT_A)) {
		x--;
	}
	if (key.GetKey(KEY_INPUT_D)) {
		x++;
	}

}