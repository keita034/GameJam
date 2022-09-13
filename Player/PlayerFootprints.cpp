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
		angle[i] = 0;
		redDown[i] = 0;
		red[i] = 0;
	}

}

void PlayerFootprints::Update(int playerPosX, int playerPosY,float angle_) {

	footTimer--;

	GetMousePoint(&mousePosX, &mousePosY);
	Vec2 mosePos = { (float)mousePosX ,(float)mousePosY };

	if (footTimer < 0) {
		
		for (int i = 0; i < 30; i++) {
			if (LeftORright == 0) {
				if (LeftFlag[i] == 0) {
					if (FootFlag[i] == 0) {
						x[i] = playerPosX - 4;
						y[i] = playerPosY;

						LeftFlag[i] = 1;
						FootFlag[i] = 1;
						pal[i] = 295;
						footTimer = 10;
						LeftORright = 1;
						red[i] = 255;

						angle[i] = angle_;
						angle[i] -= 1.5708;
						break;
					}
				}
			}
			else if(LeftORright == 1) {
				if (RightFlag[i] == 0) {
					if (FootFlag[i] == 0) {
						x[i] = playerPosX + 4;
						y[i] = playerPosY;

						RightFlag[i] = 1;
						FootFlag[i] = 1;
						pal[i] = 295;
						footTimer = 10;
						LeftORright = 0;
						red[i] = 255;

						angle[i] = angle_;
						angle[i] -= 1.5708;
						break;
					}
				}
			}

		}
	}
	for (int i = 0; i < 30; i++) {

		if (LeftFlag[i] == 1 || RightFlag[i] == 1) {
			pal[i] -= 3;
			redDown[i] += 2.3;
			if (pal[i] < 0) {
				LeftFlag[i] = 0;
				RightFlag[i] = 0;
				FootFlag[i] = 0;
				redDown[i] = 0;
			}

		}

	}


}

void PlayerFootprints::Draw(Vec2 screen) {


	for (int i = 0; i < 30; i++) {

		if (LeftFlag[i] == 1) {
			SetDrawBright(red[i] - redDown[i], 50, 50);
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, pal[i]);
			DrawRotaGraph(x[i] - screen.x, y[i] - screen.y, 1, angle[i], FootArt[0], true);
			SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 0);
			SetDrawBright(255, 255, 255);
		}
		if (RightFlag[i] == 1) {
			SetDrawBright(red[i] - redDown[i], 50, 50);
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, pal[i]);
			DrawRotaGraph(x[i] - screen.x, y[i]- screen.y, 1, angle[i], FootArt[1], true);
			SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 0);
			SetDrawBright(255, 255, 255);
		}
	}

}