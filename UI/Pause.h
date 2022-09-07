#pragma once
#include"Ease.h"
#include <DxLib.h>
#include"KeyBoardInput.h"


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

public:
	// 画像などのリソースデータの変数宣言と読み込み
	int MenuGh;
	int SoundGh;
	int BackGh;
	int Back2Gh;

	Ease* ease_ = nullptr;

	//メンバ変数
	int timer[5];
	int MaxTimer[5];

	float menuX = -100;
	float menuY = 20;
	float menuXFinal;

	float backX = -100;
	float backY = 100;

	float soundX = -100;
	float soungY = 300;

	int isPause = 0;

	int isEscTrigger = 0;

};