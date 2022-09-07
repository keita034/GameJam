#include"Pause.h"
#include<math.h>

void Pause::Initialize() {
	// 画像などのリソースデータの変数宣言と読み込み
	MenuGh = LoadGraph("Menu.png", true);
	SoundGh = LoadGraph("Sound.png", true);
	BackGh = LoadGraph("Back.png", true);
	Back2Gh = LoadGraph("Back2.png", true);

	//イージング初期化
	ease_ = new Ease();


}

void Pause::Update() {

	if (isEscTrigger == 0) {
		if (key.GetKeyTrigger(KEY_INPUT_ESCAPE)) {
			isEscTrigger = 1;
			for (int i = 0; i < 5; i++) {
				timer[i] = 0;
			}
		}
	}
	else if (isEscTrigger == 0) {
		if (key.GetKeyTrigger(KEY_INPUT_ESCAPE)) {
			isEscTrigger = 0;
			for (int i = 0; i < 5; i++) {
				timer[i] = 0;
			}
		}
	}

	Move();

}

void Pause::Move() {


	for (int i = 0; i < 5; i++) {
		if (timer[i] <= MaxTimer[i]) {
			timer[i]++;
		}
	}

	if (isPause == 0) {
		menuXFinal = 20;
		menuX = menuX + (menuXFinal - menuX) * ease_->easeInOutCubic(timer[0] / MaxTimer[0]);
		backX = backX + (menuXFinal - menuX) * ease_->easeInOutCubic(timer[1] / MaxTimer[1]);
		soundX = soundX + (menuXFinal - menuX) * ease_->easeInOutCubic(timer[2] / MaxTimer[2]);
	}
	if (isPause == 1) {
		menuXFinal = -100;
		menuX = menuX + (menuXFinal - menuX) * ease_->easeInOutCubic(timer[0] / MaxTimer[0]);
		backX = backX + (menuXFinal - menuX) * ease_->easeInOutCubic(timer[0] / MaxTimer[0]);
		soundX = soundX + (menuXFinal - menuX) * ease_->easeInOutCubic(timer[0] / MaxTimer[0]);
	}



}

void Pause::MenuSelect() {

}

void Pause::Draw() {

}

