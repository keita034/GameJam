#include "SceneManager.h"

SceneManager::SceneManager() {}

SceneManager::~SceneManager() {

}

void SceneManager::Initialize() {
	//new����
	titleScene_ = new TitleScene();
	gameScene_ = new GameScene();
	resultScene_ = new ResultScene();

	//����������
	//titleScene_->Initialize();
	//gameScene_->Initialize();
	//resultScene_->Initialize();

}

void SceneManager::Update(char* keys, char* oldkeys) {

	switch (scene_) {
	case SceneManager::Scene::Blackout://�Ó]�V�[��
		Blackout(keys, oldkeys);

		break;
	case SceneManager::Scene::Title://�^�C�g��
		Title(keys, oldkeys);

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
}



//�V�[���؂�ւ�
void SceneManager::Blackout(char* keys, char* oldkeys) {
	if (isBlackOut == 0) {
		isBlackOut = 1;
		pal = 70;
	}
	else if (isBlackOut == 1) {
		if (pal < 255) {
			pal += 30;
		}
		else if (pal > 255) {
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
