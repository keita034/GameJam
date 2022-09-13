#include"DxLib.h"
#include"PlayerFootprints.h"
#include"math.h"

void PlayerFootprints::Initialize() {
	LoadDivGraph("Resources/asiatoAkarui.png", 2, 2, 1, 32, 32, FootArt);
	footTimer = 25;
	for (int i = 0; i < 30; i++) {
		LeftFlag[i] = 0;
		RightFlag[i] = 0;
		FootFlag[i] = 0;
	}

}

void PlayerFootprints::Update(int playerPosX, int playerPosY) {

	footTimer--;

	if (footTimer < 0) {
		
		for (int i = 0; i < 30; i++) {
			if (LeftORright == 0) {
				if (LeftFlag[i] == 0) {
					if (FootFlag[i] == 0) {
						x[i] = playerPosX - 10;
						y[i] = playerPosY;

						LeftFlag[i] = 1;
						FootFlag[i] = 1;
						pal[i] = 295;
						footTimer = 25;
						LeftORright = 1;
						break;
					}
				}
			}
			else if(LeftORright == 1) {
				if (RightFlag[i] == 0) {
					if (FootFlag[i] == 0) {
						x[i] = playerPosX + 10;
						y[i] = playerPosY;

						RightFlag[i] = 1;
						FootFlag[i] = 1;
						pal[i] = 295;
						footTimer = 25;
						LeftORright = 0;
						break;
					}
				}
			}

		}
	}
	for (int i = 0; i < 30; i++) {

		if (LeftFlag[i] == 1 || RightFlag[i] == 1) {
			pal[i] -= 3;

			if (pal[i] < 0) {
				LeftFlag[i] = 0;
				RightFlag[i] = 0;
				FootFlag[i] = 0;
			}

		}

	}

	int mosePosX = 0;
	int mosePosY = 0;

	GetMousePoint(&mosePosX, &mosePosY);
	Vec2 mosePos = { (float)mosePosX ,(float)mosePosY };

	angle = atan2(double(mosePos.y - screenCentral.y), double(mosePos.x - screenCentral.x));
	angle += 1.5708;


}

void PlayerFootprints::Draw(Vec2 screen) {

	DrawFormatString(20, 120, GetColor(0, 0, 0), "%lf", angle, true);

	for (int i = 0; i < 30; i++) {

		if (LeftFlag[i] == 1) {
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, pal[i]);
			DrawRotaGraph(x[i], y[i], 1, angle, FootArt[0], true);
			SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 0);
		}
		if (RightFlag[i] == 1) {
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, pal[i]);
			DrawRotaGraph(x[i], y[i], 1, angle, FootArt[1], true);
			SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 0);
		}
	}

}