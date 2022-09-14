#include"Pause.h"
#include<math.h>
#include"Sound.h"

void Pause::Initialize() {
	// 画像などのリソースデータの変数宣言と読み込み
	MenuGh = LoadGraph("Resources/Menu.png", true);
	SoundGh = LoadGraph("Resources/Sound.png", true);
	GameOutGh = LoadGraph("Resources/GameOut.png", true);
	GameOut2Gh = LoadGraph("Resources/GameOut2.png", true);
	ResetGh = LoadGraph("Resources/Reset.png", true);
	TitleGh = LoadGraph("Resources/Title.png", true);
	BackGh = LoadGraph("Resources/Back.png", true);
	Back2Gh = LoadGraph("Resources/Back2.png", true);
	backGroundGh = LoadGraph("Resources/SettingBackGround.png", true);
	soundBarGh = LoadGraph("Resources/soundBar.png", true);
	soundChangeGh = LoadGraph("Resources/soundChange.png", true);

	//イージング初期化
	ease_ = new Ease();

	sound_ = Sound::GetInstance();

	MaxTimer[0] = 100.0f;
	MaxTimer[1] = 90.0f;
	MaxTimer[2] = 100.0f;
	MaxTimer[3] = 105.0f;
	MaxTimer[4] = 120.0f;
	MaxTimer[5] = 20.0f;
	MaxTimer[6] = 120.0f;

	soundChangeLeftFinalX = 1000 - 16;
	soundChangeRightFinalX = 1000 + 16;
	keepSoundLeft = soundChangeLeftFinalX;
	keepSoundRight = soundChangeRightFinalX;

	selectSceen = 0;
	menuXFinal = -400; soundXFinal = -500; ResetXFinal = -500; TitleXFinal = -500; GameOutXFinal = -300;
	isSetting = 0;
	isSettingBack = 0;
	isSettingAndEsc = 0;
	isSoundChange = 0;
	menuX = -300;
	menuY = 20;
	soundX = -300;
	soundY = 170;
	ResetX = -300;
	ResetY = 175 + 64;
	TitleX = -300;
	TitleY = 180 + 128;
	GameOutX = -300;
	GameOutY = 500;
	isPause = 1;
}

void Pause::Update() {

	Move();
	MenuSelect();
	soundVolume = (keepSoundLeft - 590) / 2;
}

void Pause::Move() {


	for (int i = 0; i < 7; i++) {
		if (timer[i] < MaxTimer[i]) {
			timer[i]++;
		}
	}

	//エスケープ押されたとき
	if (isPause == 0) {
		menuXFinal = 150; soundXFinal = 30; ResetXFinal = 30; TitleXFinal = 30; GameOutXFinal = 120;
		menuX = menuX + (menuXFinal - menuX) * ease_->easeInOutCubic(timer[0] / MaxTimer[0]);
		soundX = soundX + (soundXFinal - soundX) * ease_->easeInOutCubic(timer[1] / MaxTimer[1]);
		ResetX = ResetX + (ResetXFinal - ResetX) * ease_->easeInOutCubic(timer[2] / MaxTimer[2]);
		TitleX = TitleX + (TitleXFinal - TitleX) * ease_->easeInOutCubic(timer[3] / MaxTimer[3]);
		GameOutX = GameOutX + (GameOutXFinal - GameOutX) * ease_->easeInOutCubic(timer[0] / MaxTimer[0]);
	}
	else if (isPause == 1) {
		menuXFinal = -400; soundXFinal = -500; ResetXFinal = -500; TitleXFinal = -500; GameOutXFinal = -300;
		menuX = menuX + (menuXFinal - menuX) * ease_->easeInOutCubic(timer[0] / MaxTimer[0]);
		soundX = soundX + (soundXFinal - soundX) * ease_->easeInOutCubic(timer[1] / MaxTimer[1]);
		ResetX = ResetX + (ResetXFinal - ResetX) * ease_->easeInOutCubic(timer[2] / MaxTimer[2]);
		TitleX = TitleX + (TitleXFinal - TitleX) * ease_->easeInOutCubic(timer[3] / MaxTimer[3]);
		GameOutX = GameOutX + (GameOutXFinal - GameOutX) * ease_->easeInOutCubic(timer[4] / MaxTimer[4]);
	}
	//設定押されたとき
	if (isSettingBack == 0) {
		if (isSetting == 1) {
			//位置決め
			backGroundLeftFinalX = 400; backGroundRightFinalX = 1200; backGroundTopFinalY = 100; backGroundDownFinalY = 600;
			backLeftFinalX = 800 - 62; backRightFinalX = 800 + 62; backTopFinalY = 490; backDownFinalY = 540;
			soundBarLeftFinalX = 590; soundBarRightFinalX = 1100; soundBarTopFinalY = 250; soundBarDownFinalY = 280;
			soundChangeTopFinalY = 265 - 16; soundChangeDownFinalY = 265 + 16;


			backGroundLeftX = backGroundLeftX + (backGroundLeftFinalX - backGroundLeftX) * ease_->easeInOutCubic(timer[5] / MaxTimer[5]);
			backGroundRightX = backGroundRightX + (backGroundRightFinalX - backGroundRightX) * ease_->easeInOutCubic(timer[5] / MaxTimer[5]);
			backGroundTopY = backGroundTopY + (backGroundTopFinalY - backGroundTopY) * ease_->easeInOutCubic(timer[5] / MaxTimer[5]);
			backGroundDownY = backGroundDownY + (backGroundDownFinalY - backGroundDownY) * ease_->easeInOutCubic(timer[5] / MaxTimer[5]);

			backLeftX = backLeftX + (backLeftFinalX - backLeftX) * ease_->easeInOutCubic(timer[5] / MaxTimer[5]);
			backRightX = backRightX + (backRightFinalX - backRightX) * ease_->easeInOutCubic(timer[5] / MaxTimer[5]);
			backTopY = backTopY + (backTopFinalY - backTopY) * ease_->easeInOutCubic(timer[5] / MaxTimer[5]);
			backDownY = backDownY + (backDownFinalY - backDownY) * ease_->easeInOutCubic(timer[5] / MaxTimer[5]);

			//サウンドバー
			if (isSoundChange == 0) {

				soundBarLeftX = soundBarLeftX + (soundBarLeftFinalX - soundBarLeftX) * ease_->easeInOutCubic(timer[5] / MaxTimer[5]);
				soundBarRightX = soundBarRightX + (soundBarRightFinalX - soundBarRightX) * ease_->easeInOutCubic(timer[5] / MaxTimer[5]);
				soundBarTopY = soundBarTopY + (soundBarTopFinalY - soundBarTopY) * ease_->easeInOutCubic(timer[5] / MaxTimer[5]);
				soundBarDownY = soundBarDownY + (soundBarDownFinalY - soundBarDownY) * ease_->easeInOutCubic(timer[5] / MaxTimer[5]);

				soundChangeLeftX = soundChangeLeftX + (keepSoundLeft - soundChangeLeftX) * ease_->easeInOutCubic(timer[5] / MaxTimer[5]);
				soundChangeRightX = soundChangeRightX + (keepSoundRight - soundChangeRightX) * ease_->easeInOutCubic(timer[5] / MaxTimer[5]);
				soundChangeTopY = soundChangeTopY + (soundChangeTopFinalY - soundChangeTopY) * ease_->easeInOutCubic(timer[5] / MaxTimer[5]);
				soundChangeDownY = soundChangeDownY + (soundChangeDownFinalY - soundChangeDownY) * ease_->easeInOutCubic(timer[5] / MaxTimer[5]);

			}

		}
	}
	else if (isSettingBack == 1) {

		backGroundLeftFinalX = 800; backGroundRightFinalX = 800; backGroundTopFinalY = 300; backGroundDownFinalY = 300;
		backLeftFinalX = 800; backRightFinalX = 800; backTopFinalY = 300; backDownFinalY = 300;
		soundBarLeftFinalX = 800; soundBarRightFinalX = 800; soundBarTopFinalY = 300; soundBarDownFinalY = 300;
		soundChangeLeftFinalX = 800; soundChangeRightFinalX = 800; soundChangeTopFinalY = 300; soundChangeDownFinalY = 300;

		backGroundLeftX = backGroundLeftX + (backGroundLeftFinalX - backGroundLeftX) * ease_->easeInOutCubic(timer[5] / MaxTimer[5]);
		backGroundRightX = backGroundRightX + (backGroundRightFinalX - backGroundRightX) * ease_->easeInOutCubic(timer[5] / MaxTimer[5]);
		backGroundTopY = backGroundTopY + (backGroundTopFinalY - backGroundTopY) * ease_->easeInOutCubic(timer[5] / MaxTimer[5]);
		backGroundDownY = backGroundDownY + (backGroundDownFinalY - backGroundDownY) * ease_->easeInOutCubic(timer[5] / MaxTimer[5]);

		backLeftX = backLeftX + (backLeftFinalX - backLeftX) * ease_->easeInOutCubic(timer[5] / MaxTimer[5]);
		backRightX = backRightX + (backRightFinalX - backRightX) * ease_->easeInOutCubic(timer[5] / MaxTimer[5]);
		backTopY = backTopY + (backTopFinalY - backTopY) * ease_->easeInOutCubic(timer[5] / MaxTimer[5]);
		backDownY = backDownY + (backDownFinalY - backDownY) * ease_->easeInOutCubic(timer[5] / MaxTimer[5]);

		//サウンドバー
		soundBarLeftX = soundBarLeftX + (soundBarLeftFinalX - soundBarLeftX) * ease_->easeInOutCubic(timer[5] / MaxTimer[5]);
		soundBarRightX = soundBarRightX + (soundBarRightFinalX - soundBarRightX) * ease_->easeInOutCubic(timer[5] / MaxTimer[5]);
		soundBarTopY = soundBarTopY + (soundBarTopFinalY - soundBarTopY) * ease_->easeInOutCubic(timer[5] / MaxTimer[5]);
		soundBarDownY = soundBarDownY + (soundBarDownFinalY - soundBarDownY) * ease_->easeInOutCubic(timer[5] / MaxTimer[5]);

		soundChangeLeftX = soundChangeLeftX + (soundChangeLeftFinalX - soundChangeLeftX) * ease_->easeInOutCubic(timer[5] / MaxTimer[5]);
		soundChangeRightX = soundChangeRightX + (soundChangeRightFinalX - soundChangeRightX) * ease_->easeInOutCubic(timer[5] / MaxTimer[5]);
		soundChangeTopY = soundChangeTopY + (soundChangeTopFinalY - soundChangeTopY) * ease_->easeInOutCubic(timer[5] / MaxTimer[5]);
		soundChangeDownY = soundChangeDownY + (soundChangeDownFinalY - soundChangeDownY) * ease_->easeInOutCubic(timer[5] / MaxTimer[5]);

	}

	//ただの初期化調整
	if (isSettingBack == 1) {
		if (timer[5] >= MaxTimer[5]) {
			isSetting = 0;
			isSettingBack = 0;
			isSettingAndEsc = 0;
			isSoundChange = 0;
			pal5 = 0;
		}
	}

	if (isSettingBack == 0) {
		if (isSetting == 1) {
			if (timer[5] >= MaxTimer[5]) {
				isSoundChange = 1;
			}
		}
	}


}

void Pause::MenuSelect() {
	int x, y;
	GetMousePoint(&x, &y);

	//矩形の当たり判定

	if (isPause == 0) {

		if (soundX < x && x < soundX + 178) {
			if (soundY < y && y < soundY + 67) {
				isHit = 1;
				pal = 255; pal2 = 120; pal3 = 120;
				if (soundFlagHit1 == 0) {
					sound_->SelectUpdate();
					soundFlagHit1 = 1;
				}
			}
			else {
				isHit = 0;
				soundFlagHit1 = 0;
			}
		}
		else {
			isHit = 0;
			soundFlagHit1 = 0;
		}

		if (ResetX < x && x < ResetX + 178) {
			if (ResetY - 3 < y && y < ResetY + 67) {
				isHit2 = 1;
				pal = 120; pal2 = 255; pal3 = 120;
				if (soundFlagHit2 == 0) {
					sound_->SelectUpdate();
					soundFlagHit2 = 1;
				}
			}
			else {
				isHit2 = 0;
				soundFlagHit2 = 0;
			}
		}
		else {
			isHit2 = 0;
			soundFlagHit2 = 0;
		}

		if (TitleX < x && x < TitleX + 178) {
			if (TitleY - 3 < y && y < TitleY + 64) {
				isHit3 = 1;
				pal = 120; pal2 = 120; pal3 = 255;
				if (soundFlagHit3 == 0) {
					sound_->SelectUpdate();
					soundFlagHit3 = 1;
				}
			}
			else {
				isHit3 = 0;
				soundFlagHit3 = 0;
			}
		}
		else {
			isHit3 = 0;
			soundFlagHit3 = 0;
		}

		if (GameOutX < x && x < GameOutX + 178) {
			if (GameOutY < y && y < GameOutY + 64) {
				isHit4 = 1;
				if (soundFlagHit4 == 0) {
					sound_->SelectUpdate();
					soundFlagHit4 = 1;
				}
			}
			else {
				isHit4 = 0;
				soundFlagHit4 = 0;
			}
		}
		else {
			isHit4 = 0;
			soundFlagHit4 = 0;
		}
	}
	if (isSetting == 1) {
		if (backLeftX < x && x < backRightX) {
			if (backTopY < y && y < backDownY) {
				isHit5 = 1;
				if (soundFlagHit5 == 0) {
					sound_->SelectUpdate();
					soundFlagHit5 = 1;
				}
			}
			else {
				isHit5 = 0;
				soundFlagHit5 = 0;
			}
		}
		else {
			isHit5 = 0;
			soundFlagHit5 = 0;
		}
		if (soundBarLeftX < x && x < soundBarRightX) {
			if (soundBarTopY - 64 < y && y < soundBarDownY +  64) {
				isHit6 = 1;
				if (soundFlagHit6 == 0) {
					soundFlagHit6 = 1;
				}
			}
			else {
				isHit6 = 0;
			}
		}
		else {
			isHit6 = 0;
		}
	}


	if (isHit == 1) {
		int Mouse = GetMouseInput();
		if (Mouse && MOUSE_INPUT_LEFT) {
			timer[5] = 0;
			isSetting = 1;
			pal5 = 70;
			sound_->DecisionUpdate();
		}
	}
	if (isHit2 == 1) {
		int Mouse = GetMouseInput();
		if (Mouse && MOUSE_INPUT_LEFT) {
			selectSceen = 1;
			sound_->DecisionUpdate();
		}
	}
	if (isHit3 == 1) {
		int Mouse = GetMouseInput();
		if (Mouse && MOUSE_INPUT_LEFT) {
			selectSceen = 2;
			sound_->DecisionUpdate();
		}
	}
	if (isHit4 == 1) {
		int Mouse = GetMouseInput();
		if (Mouse && MOUSE_INPUT_LEFT) {
			isFinish = 1;
		}
	}
	if (isHit5 == 1) {
		int Mouse = GetMouseInput();
		if (mouse.GetCrickTrigger(MOUSE_INPUT_LEFT)) {
			timer[5] = 0;
			isSettingBack = 1;
			sound_->DecisionUpdate();
		}
	}

	if (isHit6 == 1) {
		if (isSoundChange == 1) {
			int Mouse = GetMouseInput();
			if (Mouse && MOUSE_INPUT_LEFT) {
				soundChangeLeftX = x - 16;
				soundChangeRightX = x + 16;

				if (soundChangeLeftX < 590) {
					soundChangeLeftX = 590;
					soundChangeRightX = 590 + 32;
				}
				else if (soundChangeRightX > 1100) {
					soundChangeLeftX = 1100 - 32;
					soundChangeRightX = 1100;
				}
				keepSoundLeft = soundChangeLeftX;
				keepSoundRight = soundChangeRightX;

			}
		}
	}

	if (isSettingAndEsc == 0) {
		if (isPause == 1) {
			isSettingAndEsc = 1;
			timer[5] = 0;
			isSettingBack = 1;
		}
	}


	if (isHit == 0) {
		if (isHit2 == 0) {
			if (isHit3 == 0) {
				if (isHit4 == 0) {
					pal = 255; pal2 = 255; pal3 = 255; pal4 = 255;
				}
			}
		}
	}

}

void Pause::Draw() {
	DrawBox(0, 0, menuX + 200, 800, GetColor(100, 100, 100), true);
	DrawBox(0, 0, GameOutX + 190, 800, GetColor(100, 100, 100), true);
	DrawGraph(menuX, menuY, MenuGh, true);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, pal);
	DrawGraph(soundX, soundY, SoundGh, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, pal2);
	DrawGraph(ResetX, ResetY, ResetGh, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, pal3);
	DrawGraph(TitleX, TitleY, TitleGh, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	if (isHit4 == 0) {
		DrawGraph(GameOutX, GameOutY, GameOutGh, true);
	}
	else {
		DrawGraph(GameOutX, GameOutY, GameOut2Gh, true);
	}

	if (isSetting == 1) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, pal5);
		DrawBox(0, 0, 1280, 800, GetColor(0, 0, 0), true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		DrawExtendGraph(backGroundLeftX, backGroundTopY, backGroundRightX, backGroundDownY, backGroundGh, true);

		DrawExtendGraph(soundBarLeftX, soundBarTopY, soundBarRightX, soundBarDownY, soundBarGh, true);
		DrawExtendGraph(soundChangeLeftX, soundChangeTopY, soundChangeRightX, soundChangeDownY, soundChangeGh, true);
		if (isHit5 == 0) {
			DrawExtendGraph(backLeftX, backTopY, backRightX, backDownY, BackGh, true);
		}
		else {
			DrawExtendGraph(backLeftX, backTopY, backRightX, backDownY, Back2Gh, true);
		}
	}

	
}

void Pause::SetIsEsc(int isEsc) {
	isPause = isEsc;
}

void Pause::TimerReset(int x) {
	for (int i = 0; i < 5; i++) {
		timer[i] = x;
	}
}

int Pause::GetFinish() {

	return isFinish;
}

int Pause::GetSoundVolum()
{
	return soundVolume;
}

int Pause::GetRisetOrTitle()
{
	return selectSceen;
}