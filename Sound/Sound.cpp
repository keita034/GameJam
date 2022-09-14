#include "Sound.h"
#include <DxLib.h>

Sound::Sound() {


	titleBGM = LoadSoundMem("Resources/titel.mp3");
	gameBGM = LoadSoundMem("Resources/gameSceen_1.mp3");
	gameBGM2 = LoadSoundMem("Resources/gameSceen_2.mp3");
	level1 = LoadSoundMem("Resources/level.mp3");
	level2 = LoadSoundMem("Resources/level2.mp3");
	level3 = LoadSoundMem("Resources/level3.mp3");
	level4 = LoadSoundMem("Resources/level4.mp3");
	level5 = LoadSoundMem("Resources/level5.mp3");

	attackHit = LoadSoundMem("Resources/attackHit.mp3");
	swing = LoadSoundMem("Resources/Motion-Swish02-1.mp3");

	slsectSound = LoadSoundMem("Resources/selectUI.mp3");
	UIDecision = LoadSoundMem("Resources/UIDecision.mp3");

}

Sound* Sound::GetInstance()
{
	static Sound instance;
	return &instance;
}

void Sound::Initialize() {



}

void Sound::Updata() {

	ChangeVolumeSoundMem(volum, titleBGM);
	ChangeVolumeSoundMem(volum, gameBGM);
	ChangeVolumeSoundMem(volum, level1);
	ChangeVolumeSoundMem(volum, level2);
	ChangeVolumeSoundMem(volum, level3);
	ChangeVolumeSoundMem(volum, level4);
	ChangeVolumeSoundMem(volum, level5);

	ChangeVolumeSoundMem(volum, slsectSound);
	ChangeVolumeSoundMem(volum, UIDecision);

	ChangeVolumeSoundMem(volum, swing);
	ChangeVolumeSoundMem(volum, attackHit);

}



void Sound::TitleUpdate() {
	if (CheckSoundMem(titleBGM) == 0) {
		PlaySoundMem(titleBGM, DX_PLAYTYPE_LOOP, true);
	}
}

void Sound::gameSceneUpdate() {
	StopSoundMem(titleBGM);
	if (CheckSoundMem(gameBGM) == 0) {
		PlaySoundMem(gameBGM, DX_PLAYTYPE_LOOP, true);
	}
}

void Sound::SelectUpdate(int soundVolum) {

	
	PlaySoundMem(slsectSound, DX_PLAYTYPE_BACK, true);
	DrawFormatString(600, 200, GetColor(0, 0, 0), "%d", soundVolum);
}

void Sound::DecisionUpdate(int soundVolum) {
	if (CheckSoundMem(UIDecision) == 0) {
		PlaySoundMem(UIDecision, DX_PLAYTYPE_BACK, true);
	}
}

void Sound::levelUpdata(int level_, int soundVolum) {
	level = level_;

	if (level == 2) {
		if (CheckSoundMem(level2) == 0) {
			PlaySoundMem(level2, DX_PLAYTYPE_BACK, true);
		}
	}
	else if (level == 3) {
		if (CheckSoundMem(level3) == 0) {
			PlaySoundMem(level3, DX_PLAYTYPE_BACK, true);
		}
	}
	else if (level == 4) {
		if (CheckSoundMem(level4) == 0) {
			PlaySoundMem(level4, DX_PLAYTYPE_BACK, true);
		}
	}
	else if (level == 5) {
		if (CheckSoundMem(level5) == 0) {
			PlaySoundMem(level5, DX_PLAYTYPE_BACK, true);
		}
	}

}

void Sound::AttackHitUpdata(int soundVolum) {

	PlaySoundMem(attackHit, DX_PLAYTYPE_BACK, true);
}


void Sound::Swing() {

	PlaySoundMem(swing, DX_PLAYTYPE_BACK, true);

}



void Sound::SetSound(int soundVolum) {

	volum = soundVolum;

}

