#pragma once
#include"Ease.h"
#include <DxLib.h>

class Pause
{

private:
	//関数の制作

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update(char* keys, char* oldkeys);

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	/// <summary>
	/// イージングさせる
	/// </summary>
	void Move();

	/// <summary>
	/// 矩形の当たり判定で選択
	/// </summary>
	void MenuSelect(char* keys, char* oldkeys);

public:
	// 画像などのリソースデータの変数宣言と読み込み
	int nextGh;
	int untiGh;
	int MenuGh;
	int GamePlayGh;
	int GraphicGh;
	int SettingGh;
	int SoundGh;
	int EscGh;
	int ORGh;
	int siroGh;
	int BackGh;
	int Back2Gh;

	//メンバ変数

	int flag[100];
	int randx[100];
	int randy[100];

	int LongX; int LongY;
	int hafuX; int hafuY;
	int LongXL; int LongYL;
	int pxLx; int pyLy;

	int maxCircle = 97; int maxCircle2 = 100;

	int frame = 0; int maxFrame = 1;

	float downSpeed[100];

	int redColor[100] = { 100 }; int lowRedColor[100];
	int greenColor[100] = { 0 }; int lowGreenColor[100];
	int blueColor[100] = { 255 }; int lowBlueColor[100];

	int whatColor[100];
	int pal = 127; int pal2; int pal3; int pal4; int pal5;

	double time; double time2; double time3; double time4; double time5;
	double maxTime = 100; double maxTime2 = 102; double maxTime3 = 104;
	double maxTime4 = 106; double maxTime5 = 108; double waitTimer = 50;
	double nextX; double nextX2; double nextX3;
	double startX = -150; double finalX = 245;

	int nexTimer = 500;

	int isOnly = 0; int fastTimer; int invsrc = 0;

	double x1, x2, x3, x4, x5, x6; int y1, y2, y3, y4, y5, y6;
	int isSelect = 0;
	int playerPosX = 500; int playerPosY = 200; int radius = 10;
	int isHit, isHit2, isHit3, isHit4, isHit5, isHit6;

	int mFlag[20]; int mx[20]; int my[20]; int mr[20]; int mc[20];

	int reFlag = 0; int reFlag2 = 0;

};