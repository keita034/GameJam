#include "SceneManager.h"

SceneManager::SceneManager() {}

SceneManager::~SceneManager() {

}

void SceneManager::Initialize() {
	siroGh = LoadGraph("Resources/haiiroMoku.png", true);

	//new����
	titleScene_ = new TitleScene();
	gameScene_ = new GameScene();
	resultScene_ = new ResultScene();
	pause_ = new Pause();
	smoke_ = new Smoke();
	playerFootprints_ = new PlayerFootprints();

	//����������
	//titleScene_->Initialize();
	gameScene_->Initialize();
	//resultScene_->Initialize();
	pause_->Initialize();
	smoke_->Initialize(siroGh);
	playerFootprints_->Initialize();
}

void SceneManager::Update(char* keys, char* oldkeys) {

	switch (scene_) {
	case SceneManager::Scene::Blackout://�Ó]�V�[��
		Blackout(keys, oldkeys);

		break;
	case SceneManager::Scene::Title://�^�C�g��
		//Title(keys, oldkeys);
		gameScene_->Update();
		
		if (key.GetKey(KEY_INPUT_SPACE)) {

			//smoke_->MakeEnemySmoke(300, 300);

		}

		//smoke_->Update();
		TestMove();
		playerFootprints_->Update(x, y);

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

		break;
	case SceneManager::Scene::Tutorial://�`���[�g���A��
		Tutorial(keys, oldkeys);

		break;
	case SceneManager::Scene::Stage://�o�g���X�e�[�W
		Stage(keys, oldkeys);

		break;
	case SceneManager::Scene::Result://���U���g
		Result(keys, oldkeys);

		break;
	default:
		break;
	}

}

void SceneManager::Draw() {




	SetDrawBlendMode(DX_BLENDMODE_ALPHA, pal);
	DrawBox(0, 0, 1280, 720, GetColor(0, 0, 0), true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	switch (scene_)
	{
	case SceneManager::Scene::Title://�^�C�g��
		gameScene_->Draw();
		pause_->Draw();
		//smoke_->Draw();
		playerFootprints_->Draw();

		break;
	case SceneManager::Scene::Tutorial://�`���[�g���A��

		break;
	case SceneManager::Scene::Stage://�o�g���X�e�[�W

		break;
	case SceneManager::Scene::Result://���U���g

		break;
	default:
		break;
	}
}



//�V�[���؂�ւ�
void SceneManager::Blackout(char* keys, char* oldkeys) {
	if (isBlackOut == 0) {
		isBlackOut = 1;
		pal = 70;
	}
	else if (isBlackOut == 1) {
		if (pal < 255) {
			pal += 20;
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
	justBefore = 1;
	if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
		scene_ = Scene::Blackout;
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