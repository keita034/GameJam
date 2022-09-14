#include "SceneManager.h"

SceneManager::SceneManager() {
	escGh = LoadGraph("Resources/MenuButton1.png");
}

SceneManager::~SceneManager() {

}

void SceneManager::Initialize() {

	//newする
	titleScene_ = new TitleScene();
	gameScene_ = new GameScene();
	resultScene_ = new ResultScene();
	pause_ = new Pause();
	sound_ = Sound::GetInstance();

	//初期化処理
	titleScene_->Initialize();
	gameScene_->Initialize();
	resultScene_->Initialize();
	pause_->Initialize();
	sound_->Initialize();

}

void SceneManager::Update(char* keys, char* oldkeys) {

	switch (scene_) {
	case SceneManager::Scene::Blackout://暗転シーン
		Blackout();

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
		risetOrTitle(pause_->GetRisetOrTitle());
		sound_->SetSound(pause_->GetSoundVolum());
		sound_->TitleUpdate();
		sound_->Updata();

		break;
	case SceneManager::Scene::Tutorial://チュートリアル
		Tutorial(keys, oldkeys);

		break;
	case SceneManager::Scene::Stage://バトルステージ
		Stage();

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
		if (isESC == 0) {
			gameScene_->Update();
		}
		pause_->Update();
		vx = pause_->GetSoundVolum();
		risetOrTitle(pause_->GetRisetOrTitle());

		sound_->SetSound(vx);
		sound_->gameSceneUpdate();
		sound_->Updata();


		if (gameScene_->GetFinish() == 1) {
			pal += 5;
			if (pal >= 255) {
				scene_ = Scene::Blackout;
			}
		}

		break;
	case SceneManager::Scene::Result://リザルト
		

		resultScene_->Update();
		if (resultScene_->GetChangeGame() == true)
		{
			sceenSelect = 3;
		}
		if (resultScene_->GetChangeTitle() == true)
		{
			sceenSelect = 1;
		}
		if (sceenSelect == 1 || sceenSelect== 3) {
			pal += 5;
			if (pal >= 255) {
				scene_ = Scene::Initialize;
			}
		}

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
		sound_->resultSceneUpdate();
		sound_->Updata();

		break;
	case SceneManager::Scene::Initialize://初期化
		//ここにInitializeをぶち込む

		gameScene_->Initialize();
		pause_->Initialize();

		if (sceenSelect == 1) {
			pal = 0;
			sceenSelect = 0;
			isESC = 0;
			scene_ = Scene::Title;
		}
		else if (sceenSelect == 3) {
			pal = 0;
			sceenSelect = 0;
			isESC = 0;
			scene_ = Scene::Stage;
		}
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
		DrawGraph(60, 60, escGh, true);
		pause_->Draw();
		break;
	case SceneManager::Scene::Tutorial://チュートリアル

		break;
	case SceneManager::Scene::Stage://バトルステージ
		gameScene_->Draw();
		DrawGraph(60, 60, escGh, true);
		pause_->Draw();

		break;
	case SceneManager::Scene::Result://リザルト
		resultScene_->Draw();
		break;
	case SceneManager::Scene::Initialize://初期化
		
		break;
	default:
		break;
	}

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, pal);
	DrawBox(0, 0, 1280, 720, GetColor(0, 0, 0), true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}



//シーン切り替え
void SceneManager::Blackout() {
	if (isBlackOut == 0) {
		isBlackOut = 1;
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
		if (blackFlag == 0) {
			blackFlag = 1;
			pal = 0;
		}
	}
	if (blackFlag == 1) {
		pal = pal + 5;
		if (pal >= 255) {
			scene_ = Scene::Blackout;
			blackFlag = 0;
		}
	}

}

void SceneManager::Tutorial(char* keys, char* oldkeys) {
	justBefore = 2;
	if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
		scene_ = Scene::Blackout;
	}
}

void SceneManager::Stage() {
	justBefore = 3;
	
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

void SceneManager::risetOrTitle(int x) {
	if (x == 1) {
		if (pal < 255) {
			pal += 5;
		}
		if (pal >= 255) {
			sceenSelect = 3;
			scene_ = Scene::Initialize;
		}
	}
	else if (x == 2) {
		if (pal < 255) {
			pal += 5;
		}
		if (pal >= 255) {
			sceenSelect = 1;
			scene_ = Scene::Initialize;
		}
	}

}
