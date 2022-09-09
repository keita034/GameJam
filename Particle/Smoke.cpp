#include "Smoke.h"
#include"math.h";
#include <Util.h>

void Smoke::Initialize() {
	siroGh = LoadGraph("Resources/haiiroMoku.png", true);

	for (int i = 0; i < 300; i++) {
		x[i] = 740;
		y[i] = 360;
		timer[i] = 0;
		flag[i] = 0;
		pal[i] = 100;
	}

}

void Smoke::Update() {

	for (int i = 0; i < 300; i++) {

		if (flag[i] == 1) {
			if (timer[i] < 50) {
				timer[i]++;
			}

			x[i] += randX[i] * 3;
			y[i] += randY[i] * 3;
			if (timer[i] >= 50) {
				flag[i] = 0;
				pal[i] = 100;
				Smokes--;
			}
		}
		pal[i] = pal[i] - 3;
	}

	DrawFormatString(20, 20, GetColor(0, 0, 0), "%f", x[99], true);
	DrawFormatString(20, 40, GetColor(0, 0, 0), "%f", y[99], true);
	DrawFormatString(20, 60, GetColor(0, 0, 0), "%d", flag[98], true);
	DrawFormatString(20, 80, GetColor(0, 0, 0), "%d", frame, true);

}

void Smoke::Draw() {
	for (int i = 0; i < 300; i++) {
		if (flag[i] == 1) {
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, pal[i]);
			//DrawGraph(x[i], y[i], siroGh, true);
			SetDrawBright(50, 50, 50);
			DrawExtendGraph(x[i], y[i], x[i] + 128, y[i] + 128, siroGh, true);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			SetDrawBright(255, 255, 255);
		}
	}
}


void Smoke::MakeSmoke(int SmokePosX, int SmokePosY, int HowManySmokes_) {

	for (int i = 0; i < 300; i++) {
		if (flag[i] == 0) {
			x[i] = SmokePosX;
			y[i] = SmokePosY;
			timer[i] = 0;
			flag[i] = 1;
			// アングルをランダムで指定
			int angle = GetRandomRange(0, 360);
			randX[i] = cos(Radian(angle));
			randY[i] = sin(Radian(angle));
			Smokes++;
		}
		if (Smokes > HowManySmokes_) {
			break;
		}
	}

}