#include"DxLib.h"
#include"PlayerFootprints.h"

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

}

void PlayerFootprints::Draw() {

	//DrawFormatString(20, 120, GetColor(0, 0, 0), "%d", footFlag[0], true);

	for (int i = 0; i < 30; i++) {

		if (LeftFlag[i] == 1) {
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, pal[i]);
			DrawGraph(x[i], y[i], FootArt[0], true);
			SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 0);
		}
		if (RightFlag[i] == 1) {
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, pal[i]);
			DrawGraph(x[i], y[i], FootArt[1], true);
			SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 0);
		}
	}

}