#include"Pause.h"
#include<math.h>

void Pause::Initialize() {
	// 画像などのリソースデータの変数宣言と読み込み
	MenuGh = LoadGraph("Resources/Menu.png", true);
	SoundGh = LoadGraph("Resources/Sound.png", true);
	BackGh = LoadGraph("Resources/Back.png", true);
	Back2Gh = LoadGraph("Resources/Back2.png", true);
	ResetGh = LoadGraph("Resources/Reset.png", true);
	TitleGh = LoadGraph("Resources/Title.png", true);

	//イージング初期化
	ease_ = new Ease();

	MaxTimer[0] = 100.0f;
	MaxTimer[1] = 90.0f;
	MaxTimer[2] = 100.0f;
	MaxTimer[3] = 105.0f;
	MaxTimer[4] = 120.0f;

}

void Pause::Update() {
	
	Move();
	MenuSelect();
}

void Pause::Move() {


	for (int i = 0; i < 5; i++) {
		if (timer[i] < MaxTimer[i]) {
			timer[i]++;
		}
	}

	if (isPause == 0) {
		menuXFinal = 150; soundXFinal = 30; ResetXFinal = 30; TitleXFinal = 30; backXFinal = 120;
		menuX = menuX + (menuXFinal - menuX) * ease_->easeInOutCubic(timer[0] / MaxTimer[0]);
		soundX = soundX + (soundXFinal - soundX) * ease_->easeInOutCubic(timer[1] / MaxTimer[1]);
		ResetX = ResetX + (ResetXFinal - ResetX) * ease_->easeInOutCubic(timer[2] / MaxTimer[2]);
		TitleX = TitleX + (TitleXFinal - TitleX) * ease_->easeInOutCubic(timer[3] / MaxTimer[3]);
		backX = backX + (backXFinal - backX) * ease_->easeInOutCubic(timer[0] / MaxTimer[0]);
	}
	if (isPause == 1) {
		menuXFinal = -400; soundXFinal = -500; ResetXFinal = -500; TitleXFinal = -500; backXFinal = -300;
		menuX = menuX + (menuXFinal - menuX) * ease_->easeInOutCubic(timer[0] / MaxTimer[0]);
		soundX = soundX + (soundXFinal - soundX) * ease_->easeInOutCubic(timer[1] / MaxTimer[1]);
		ResetX = ResetX + (ResetXFinal - ResetX) * ease_->easeInOutCubic(timer[2] / MaxTimer[2]);
		TitleX = TitleX + (TitleXFinal - TitleX) * ease_->easeInOutCubic(timer[3] / MaxTimer[3]);
		backX = backX + (backXFinal - backX) * ease_->easeInOutCubic(timer[4] / MaxTimer[4]);
	}

	if (timer[0] >= 50.0f) {
		isPause = 3;
	}

}

void Pause::MenuSelect() {
	int x, y;
	GetMousePoint(&x, &y);

	//矩形の当たり判定
	if (soundX < x && x < soundX + 178) {
		if (soundY < y && y < soundY + 64) {
			isHit = 1;
			pal = 255; pal2 = 120; pal3 = 120;
		}
		else {
			isHit = 0;
		}
	}
	else {
		isHit = 0;
	}

	if (ResetX < x && x < ResetX + 178) {
		if (ResetY < y && y < ResetY + 64) {
			isHit2 = 1;
			pal = 120; pal2 = 255; pal3 = 120;
		}
		else {
			isHit2 = 0;
		}
	}
	else {
		isHit2 = 0;
	}

	if (TitleX < x && x < TitleX + 178) {
		if (TitleY < y && y < TitleY + 64) {
			isHit3 = 1;
			pal = 120; pal2 = 120; pal3 = 255;
		}
		else {
			isHit3 = 0;
		}
	}
	else {
		isHit3 = 0;
	}

	if (backX < x && x < backX + 178) {
		if (backY < y && y < backY + 64) {
			isHit4 = 1;
			pal = 120; pal2 = 120; pal3 = 120;
		}
		else {
			isHit4 = 0;
		}
	}
	else {
		isHit4 = 0;
	}

	if (isHit4 == 1) {
		int Mouse = GetMouseInput();
		if (Mouse && MOUSE_INPUT_LEFT) {
			isFinish = 1;
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
	DrawBox(0, 0, backX + 190, 800, GetColor(100, 100, 100), true);
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
		DrawGraph(backX, backY, BackGh, true);
	}
	else {
		DrawGraph(backX, backY, Back2Gh, true);
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