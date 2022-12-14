#include "Sound.h"
#include <DxLib.h>

Sound::Sound() {


	titleBGM = LoadSoundMem("Resources/titel.mp3");
	gameBGM = LoadSoundMem("Resources/gameSceen_1.mp3");
	gameBGM2 = LoadSoundMem("Resources/gameSceen_2.mp3");
	resultBGM= LoadSoundMem("Resources/Result_Bgm.ogg");
	level1 = LoadSoundMem("Resources/level2.mp3");
	level2 = LoadSoundMem("Resources/level3.mp3");
	level3 = LoadSoundMem("Resources/level4.mp3");
	level4 = LoadSoundMem("Resources/level5.mp3");
	level5 = LoadSoundMem("Resources/level6.mp3");

	attackHit = LoadSoundMem("Resources/attackHit.mp3");
	swing = LoadSoundMem("Resources/Motion-Swish02-1.mp3");

	slsectSound = LoadSoundMem("Resources/selectUI.mp3");
	UIDecision = LoadSoundMem("Resources/UIDecision.mp3");

	damage = LoadSoundMem("Resources/blood.mp3");

}

Sound* Sound::GetInstance()
{
	static Sound instance;
	return &instance;
}

void Sound::Initialize() {



}

void Sound::Updata(int x) {

	ChangeVolumeSoundMem(x, titleBGM);
	ChangeVolumeSoundMem(x, gameBGM);
	ChangeVolumeSoundMem(x, gameBGM2);
	ChangeVolumeSoundMem(x, resultBGM);
	ChangeVolumeSoundMem(x, level1);
	ChangeVolumeSoundMem(x, level2);
	ChangeVolumeSoundMem(x, level3);
	ChangeVolumeSoundMem(x, level4); 
	ChangeVolumeSoundMem(x, level5);

	ChangeVolumeSoundMem(x, slsectSound);
	ChangeVolumeSoundMem(x, UIDecision);

	ChangeVolumeSoundMem(x, swing);
	ChangeVolumeSoundMem(x, attackHit);
	ChangeVolumeSoundMem(x, damage);

}



void Sound::TitleUpdate() {
	StopSoundMem(gameBGM);
	StopSoundMem(resultBGM);
	if (CheckSoundMem(titleBGM) == 0) {
		PlaySoundMem(titleBGM, DX_PLAYTYPE_LOOP, true);
	}
}

void Sound::gameSceneUpdate() {
	StopSoundMem(titleBGM);
	StopSoundMem(resultBGM);
	if (CheckSoundMem(gameBGM) == 0) {
		PlaySoundMem(gameBGM, DX_PLAYTYPE_LOOP, true);
	}
}

void Sound::resultSceneUpdate()
{
	StopSoundMem(gameBGM);
	if (CheckSoundMem(resultBGM) == 0) {
		PlaySoundMem(resultBGM, DX_PLAYTYPE_LOOP, true);
	}
}

void Sound::SelectUpdate() {


	PlaySoundMem(slsectSound, DX_PLAYTYPE_BACK, true);
}

void Sound::DecisionUpdate() {
	if (CheckSoundMem(UIDecision) == 0) {
		PlaySoundMem(UIDecision, DX_PLAYTYPE_BACK, true);
	}
}

void Sound::levelUpdata(int level_) {
	level = level_;

	if (level == 1) {

		PlaySoundMem(level1, DX_PLAYTYPE_BACK, true);

	}
	else if (level == 2) {

		PlaySoundMem(level2, DX_PLAYTYPE_BACK, true);

	}
	else if (level == 3) {

		PlaySoundMem(level3, DX_PLAYTYPE_BACK, true);

	}
	else if (level == 4) {

		PlaySoundMem(level4, DX_PLAYTYPE_BACK, true);

	}
	else if (level == 5) {

		PlaySoundMem(level5, DX_PLAYTYPE_BACK, true);

	}

}

void Sound::AttackHitUpdata() {

	PlaySoundMem(attackHit, DX_PLAYTYPE_BACK, true);
}


void Sound::Swing() {

	PlaySoundMem(swing, DX_PLAYTYPE_BACK, true);

}

void Sound::Damage() {
	PlaySoundMem(damage, DX_PLAYTYPE_BACK, true);
}

void Sound::SetSound(int soundVolum) {

	volum = soundVolum;

}


