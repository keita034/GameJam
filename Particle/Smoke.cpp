#include "Smoke.h"
#include"math.h";
#include <Util.h>

Smoke::Smoke() {

}

void Smoke::Initialize(int siroGh_) {
	siroGh = siroGh_;


}

void Smoke::Update() {

	//左下に動く
	if (dieFlag[0] == 1) {
		DieSmokeX[0] += 0.5;
		DieSmokeY[0] += 0.8;
	}
	//左に動く
	if (dieFlag[1] == 1) {
		DieSmokeX[1] += 1.2;
		DieSmokeY[1] += 0;
	}
	//左上に動く
	if (dieFlag[2] == 1) {
		DieSmokeX[2] += 0.5;
		DieSmokeY[2] += -0.5;
	}
	//上に動く
	if (dieFlag[3] == 1) {
		DieSmokeX[3] += 0;
		DieSmokeY[3] += -1.3;
	}
	//右上に動く
	if (dieFlag[4] == 1) {
		DieSmokeX[4] += -0.5;
		DieSmokeY[4] += -0.5;
	}
	//右に動く
	if (dieFlag[5] == 1) {
		DieSmokeX[5] += -1.2;
		DieSmokeY[5] += 0;
	}
	//右下に動く
	if (dieFlag[6] == 1) {
		DieSmokeX[6] += -0.5;
		DieSmokeY[6] += 0.8;
	}
	//下に動く
	if (dieFlag[7] == 1) {
		DieSmokeX[7] += 0;
		DieSmokeY[7] += 0.8;
	}

	for (int i = 0; i < 10; i++) {
		DieTimer[i]--;
		DieSmokeY[i] -= 1.0;
		DiePal[i] = DiePal[i] - 4;
		if (DieTimer[i] < 0) {
			dieFlag[i] = false;
			DieTimer[i] = 0;
		}
	}


	for (int i = 0; i < 10; i++) {

		if (MakeBossFlag[i] == 1) {

			MakeBossTimer[i]--;

			if (MakeBossTimer[i] < 0) {
				MakeBossSmokeFlag[i] = true;
				MakeBossFlag[i] = false;
				MakeBossTimer[i] = 0;
			}


		}

	}

	for (int i = 0; i < 10; i++) {

		if (MakeEnemyFlag[i] == 1) {

			MakeEnemyTimer[i]--;
			MakeEnemyPal[i] = MakeEnemyPal[i] - 3;
			MakeEnemySmokeY[i] -= 0.3f;
			if (MakeEnemyTimer[i] < 0) {
				MakeEnemyFlag[i] = false;
				MakeEnemyTimer[i] = 0;
			}


		}

	}



}

void Smoke::Draw() {
	for (int i = 0; i < 10; i++) {
		if (dieFlag[i] == 1) {

			SetDrawBright(50, 50, 50);
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, DiePal[i]);
			DrawExtendGraph(DieSmokeX[i] - SmokeRadius, DieSmokeY[i] - SmokeRadius, DieSmokeX[i] + SmokeRadius, DieSmokeY[i] + SmokeRadius, siroGh, true);
			SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 0);
			SetDrawBright(255, 255, 255);

		}
	}

	for (int i = 0; i < 10; i++) {
		if (MakeBossSmokeFlag[i] == 1) {

			SetDrawBright(50, 50, 50);
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, MakeBossPal[i]);
			DrawExtendGraph(MakeBossSmokeX[i] - SmokeRadius, MakeBossSmokeY[i] - SmokeRadius, MakeBossSmokeX[i] + SmokeRadius, MakeBossSmokeY[i] + SmokeRadius, siroGh, true);
			SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 0);
			SetDrawBright(255, 255, 255);

		}
	}

	for (int i = 0; i < 10; i++) {
		if (MakeEnemyFlag[i] == 1) {

			SetDrawBright(10, 10, 10);
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, MakeEnemyPal[i]);
			DrawExtendGraph(MakeEnemySmokeX[i] - SmokeRadius - 64, MakeEnemySmokeY[i] - SmokeRadius - 64, MakeEnemySmokeX[i] + SmokeRadius + 64, MakeEnemySmokeY[i] + SmokeRadius + 64, siroGh, true);
			SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 0);
			SetDrawBright(255, 255, 255);

		}
	}


	DrawFormatString(20, 120, GetColor(0, 0, 0), "%f", MakeBossSmokeX[0], true);
	DrawFormatString(20, 140, GetColor(0, 0, 0), "%f", MakeBossSmokeY[1], true);
}

void Smoke::MakeEnemySmoke(int SmokePosX, int SmokePosY) {

	for (int i = 0; i < 10; i++) {

		MakeEnemyFlag[i] = 1;
		MakeEnemyTimer[i] = 60;
		MakeEnemyPal[i] = 255;

		//Smokeポジション
		MakeEnemySmokeX[0] = SmokePosX;
		MakeEnemySmokeY[0] = SmokePosY;

	}

}


void Smoke::MakeBossEnemySmoke(int SmokePosX, int SmokePosY) {

	for (int i = 0; i < 10; i++) {

		MakeBossFlag[i] = 1;
		MakeBossTimer[i] = 5 + i * 5;
		MakeBossPal[i] = 255;

		//Smokeポジション
		MakeBossSmokeX[0] = SmokePosX - 60;
		MakeBossSmokeY[0] = SmokePosY + 70;

		MakeBossSmokeX[1] = SmokePosX - 80;
		MakeBossSmokeY[1] = SmokePosY;

		MakeBossSmokeX[2] = SmokePosX - 60;
		MakeBossSmokeY[2] = SmokePosY - 70;

		MakeBossSmokeX[3] = SmokePosX + 60;
		MakeBossSmokeY[3] = SmokePosY - 70;

		MakeBossSmokeX[4] = SmokePosX + 80;
		MakeBossSmokeY[4] = SmokePosY;

		MakeBossSmokeX[5] = SmokePosX + 60;
		MakeBossSmokeY[5] = SmokePosY + 70;


	}

}


void Smoke::DieSmoke(int SmokePosX, int SmokePosY) {

	for (int i = 0; i < 9; i++) {
		DieSmokeX[i] = SmokePosX;
		DieSmokeY[i] = SmokePosY;
		dieFlag[i] = 1;
		DieTimer[i] = 60;
		DiePal[i] = 255;
	}


}