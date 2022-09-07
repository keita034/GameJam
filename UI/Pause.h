#pragma once
#include"Ease.h"
#include <DxLib.h>
#include"KeyBoardInput.h"


class Pause
{

public:
	//関数の制作

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

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
	void MenuSelect();

	//Esc押したら0出す1戻す
	void SetIsEsc(int isEsc);
	//xには0を入れる
	void TimerReset(int x);

	int GetPause();

private:
	// 画像などのリソースデータの変数宣言と読み込み
	int MenuGh;
	int SoundGh;
	int BackGh;
	int Back2Gh;
	int ResetGh;
	int TitleGh;

	Ease* ease_ = nullptr;

	//メンバ変数
	float timer[5];
	float MaxTimer[5];

	float menuX = -300;
	float menuY = 20;
	float menuXFinal;

	float soundX = -300;
	float soundY = 170;
	float soundXFinal;

	float ResetX = -300;
	float ResetY = 170 + 64;
	float ResetXFinal;

	float TitleX = -300;
	float TitleY = 170 + 128;
	float TitleXFinal;

	float backX = -300;
	float backY = 500;
	float backXFinal;


	int isPause = 3;
	int isEscTrigger = 0;

	int isHit = 0;
	int isHit2 = 0;
	int isHit3 = 0;
	int isHit4 = 0;

	int pal = 255;
	int pal2 = 255;
	int pal3 = 255;
	int pal4 = 255;
};