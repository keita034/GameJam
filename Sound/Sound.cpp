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

void Sound::Updata(int vol) {

	ChangeVolumeSoundMem(vol, titleBGM);
	ChangeVolumeSoundMem(vol, gameBGM);
	ChangeVolumeSoundMem(vol, level1);
	ChangeVolumeSoundMem(vol, level2);
	ChangeVolumeSoundMem(vol, level3);
	ChangeVolumeSoundMem(vol, level4);
	ChangeVolumeSoundMem(vol, level5);
	ChangeVolumeSoundMem(vol, swing);
	ChangeVolumeSoundMem(vol, attackHit);
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
	ChangeVolumeSoundMem(volum, slsectSound);
	DrawFormatString(600, 200, GetColor(0, 0, 0), "%d", soundVolum);
}

void Sound::DecisionUpdate(int soundVolum) {
	if (CheckSoundMem(UIDecision) == 0) {
		PlaySoundMem(UIDecision, DX_PLAYTYPE_BACK, true);
		ChangeVolumeSoundMem(soundVolum, UIDecision);
	}
}

void Sound::levelUpdata(int level_, int soundVolum) {
	level = level_;

	if (level == 2) {
		if (CheckSoundMem(level2) == 0) {
			PlaySoundMem(level2, DX_PLAYTYPE_BACK, true);
			ChangeVolumeSoundMem(volum, level2);
		}
	}
	else if (level == 3) {
		if (CheckSoundMem(level3) == 0) {
			PlaySoundMem(level3, DX_PLAYTYPE_BACK, true);
			ChangeVolumeSoundMem(volum, level3);
		}
	}
	else if (level == 4) {
		if (CheckSoundMem(level4) == 0) {
			PlaySoundMem(level4, DX_PLAYTYPE_BACK, true);
			ChangeVolumeSoundMem(volum, level4);
		}
	}
	else if (level == 5) {
		if (CheckSoundMem(level5) == 0) {
			PlaySoundMem(level5, DX_PLAYTYPE_BACK, true);
			ChangeVolumeSoundMem(volum, level5);
		}
	}

}

void Sound::AttackHitUpdata(int soundVolum) {

	PlaySoundMem(attackHit, DX_PLAYTYPE_BACK, true);
	ChangeVolumeSoundMem(volum, attackHit);
}


void Sound::Swing() {

	PlaySoundMem(swing, DX_PLAYTYPE_BACK, true);

}



void Sound::SetSound(int soundVolum) {

	volum = soundVolum;


}

