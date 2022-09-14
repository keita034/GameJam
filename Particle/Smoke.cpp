#include "Smoke.h"
#include"math.h";
#include <Util.h>

Smoke::Smoke() {

}

void Smoke::Initialize(int siroGh_) {
	siroGh = siroGh_;
	for (int i = 0; i < 100; i++) {
		smokeFlag[i] = 0;
		AllTimer = 0;
		pal = 0;
		damageFlag[i] = 0;
		MakeEnemySmokeX[i] = 0;
		MakeEnemySmokeY[i] = 0;
	}
}

void Smoke::Update(float enemyPosX, float enemyPosY) {

	if (drawTimer > 0) {
		drawTimer--;
	}

	if (drawTimer == 0) {
		for (int i = 0; i < 100; i++) {
			if (MakeEnemyFlag[i] == 1) {
				if (smokeFlag[i] == 0) {
					frame++;

					if (1 < frame) {
						frame = 0;
						break;
					}
					drawTimer = 1;
					smokeFlag[i] = 1;
					// アングルをランダムで指定
					float angle = GetRand_(1, 359);
					vecX[i] = cos(Radian(angle));
					vecY[i] = sin(Radian(angle));
					MakeEnemyFlag[i] = 0;

				}
			}
		}
	}
	if (drawTimer == 0) {
		for (int i = 0; i < 100; i++) {
			if (dieFlag[i] == 1) {
				if (smokeFlag[i] == 0) {
					frame++;

					if (1 < frame) {
						frame = 0;
						break;
					}
					drawTimer = 1;
					smokeFlag[i] = 1;
					// アングルをランダムで指定
					float angle = GetRand_(1, 359);
					
					vecX[i] = cos(Radian(angle));
   					vecY[i] = sin(Radian(angle));

				}
			}
		}
	}
	if (drawTimer == 0) {
		for (int i = 0; i < 100; i++) {
			if (damageFlag[i] == 1) {
				if (smokeFlag[i] == 0) {
					frame++;

					if (1 < frame) {
						frame = 0;
						break;
					}
					drawTimer = 1;
					smokeFlag[i] = 1;
					// アングルをランダムで指定
					float angle = GetRand_(1, 359);
					vecX[i] = cos(Radian(angle));
					vecY[i] = sin(Radian(angle));

				}
			}
		}
	}
	AllTimer--;
	pal = pal - 3;
	for (int i = 0; i < 100; i++) {
		if (smokeFlag[i] == 1) {


			MakeEnemySmokeX[i] = enemyPosX;
			MakeEnemySmokeY[i] = enemyPosY;


			KeepVecX[i] += vecX[i] * 2;
			KeepVecY[i] += vecY[i] * 1.5f;

			y[i] -= 0.8;

			MakeEnemySmokeX[i] += KeepVecX[i];
			MakeEnemySmokeY[i] += KeepVecY[i];
			MakeEnemySmokeY[i] += y[i];


		}
		if (AllTimer < 0) {
			smokeFlag[i] = 0;
			MakeEnemyFlag[i] = 0;
			AllTimer = -1;
		}
	}
	for (int i = 0; i < 100; i++) {
		if (smokeFlag[i] == 1) {
			if (dieFlag[i] == 1) {

				KeepVecX[i] += vecX[i] * 2;
				KeepVecY[i] += vecY[i] * 1.5f;

				y[i] -= 0.8;

				MakeEnemySmokeX[i] += KeepVecX[i];
				MakeEnemySmokeY[i] += KeepVecY[i];
				MakeEnemySmokeY[i] += y[i];

			}
			if (AllTimer < 0) {
				smokeFlag[i] = 0;
				dieFlag[i] = 0;
				AllTimer = -1;
			}
		}
	}
	for (int i = 0; i < 100; i++) {
		if (smokeFlag[i] == 1) {
			if (damageFlag[i] == 1) {

				KeepVecX[i] += vecX[i] * 2;
				KeepVecY[i] += vecY[i] * 1.5f;

				y[i] -= 0.8;

				MakeDamageEnemySmokeX[i] += KeepVecX[i];
				MakeDamageEnemySmokeY[i] += KeepVecY[i];

			}
			if (AllTimer < 0) {
				damageFlag[i] = 0;
				smokeFlag[i] = 0;
				AllTimer = -1;
			}
		}
	}
}

void Smoke::Draw(Vec2 screen) {
	/*for (int i = 0; i < 10; i++) {
		if (dieFlag[i] == 1) {

			SetDrawBright(50, 50, 50);
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, DiePal[i]);
			DrawExtendGraph(DieSmokeX[i] - SmokeRadius, DieSmokeY[i] - SmokeRadius, DieSmokeX[i] + SmokeRadius, DieSmokeY[i] + SmokeRadius, siroGh, true);
			SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 0);
			SetDrawBright(255, 255, 255);

		}
	}*/

	/*for (int i = 0; i < 10; i++) {
		if (MakeBossSmokeFlag[i] == 1) {

			SetDrawBright(50, 50, 50);
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, MakeBossPal[i]);
			DrawExtendGraph(MakeBossSmokeX[i] - SmokeRadius, MakeBossSmokeY[i] - SmokeRadius, MakeBossSmokeX[i] + SmokeRadius, MakeBossSmokeY[i] + SmokeRadius, siroGh, true);
			SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 0);
			SetDrawBright(255, 255, 255);

		}
	}*/

	for (int i = 0; i < 100; i++) {
		if (smokeFlag[i] == 1) {

			if (damageFlag[i] == 1) {
				SetDrawBright(100, 10, 10);
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, pal);
				DrawRotaGraph(MakeEnemySmokeX[i] - screen.x, MakeEnemySmokeY[i] - screen.y, 1.0, 0.0, siroGh, true);
				SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 0);
				SetDrawBright(255, 255, 255);
			}

			if (dieFlag[i] == 1 || MakeEnemyFlag[i] == 1) {
				SetDrawBright(10, 10, 10);
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, pal);
				DrawExtendGraph(MakeEnemySmokeX[i] - SmokeRadius - screen.x, MakeEnemySmokeY[i] - SmokeRadius - screen.y,
					MakeEnemySmokeX[i] + SmokeRadius - screen.x, MakeEnemySmokeY[i] + SmokeRadius - screen.y, siroGh, true);
				SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 0);
				SetDrawBright(255, 255, 255);
			}

		}
	}

}

void Smoke::MakeEnemySmoke() {

	for (int i = 0; i < 100; i++) {

		MakeEnemyFlag[i] = 1;
		MakeEnemyPal[i] = 255;
		AllTimer = 80;

		pal = 255;
		MakeEnemySmokeX[i] = 0;
		MakeEnemySmokeY[i] = 0;

		vecX[i] = 0.0f;
		vecY[i] = 0.0f;

		KeepVecX[i] = 0.0f;
		KeepVecY[i] = 0.0f;
		y[i] = 0;

	}

}


//void Smoke::MakeBossEnemySmoke(int SmokePosX, int SmokePosY) {
//
//	for (int i = 0; i < 10; i++) {
//
//		MakeBossFlag[i] = 1;
//		MakeBossTimer[i] = 5 + i * 5;
//		MakeBossPal[i] = 255;
//
//		
//
//	}
//
//}

void Smoke::DamageSmoke(int SmokePosX, int SmokePosY) {

	for (int i = 0; i < 9; i++) {
		dieFlag[i] = 1;
		damageFlag[i] = dieFlag[i];
		AllTimer = 80;

		pal = 200;
		MakeEnemySmokeX[i] = SmokePosX;
		MakeEnemySmokeY[i] = SmokePosY;

		vecX[i] = 0.0f;
		vecY[i] = 0.0f;

		KeepVecX[i] = 0.0f;
		KeepVecY[i] = 0.0f;
		y[i] = 0;
	}

}

void Smoke::DieSmoke(int SmokePosX, int SmokePosY) {

	for (int i = 0; i < 9; i++) {
		dieFlag[i] = 1;
		AllTimer = 80;

		pal = 200;
		MakeEnemySmokeX[i] = SmokePosX;
		MakeEnemySmokeY[i] = SmokePosY;

		vecX[i] = 0.0f;
		vecY[i] = 0.0f;

		KeepVecX[i] = 0.0f;
		KeepVecY[i] = 0.0f;
		y[i] = 0;
	}


}