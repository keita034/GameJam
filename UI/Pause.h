#pragma once
#include"Ease.h"
#include <DxLib.h>
#include"KeyBoardInput.h"
#include"MouseInput.h"
#include"Sound.h"


class Pause
{
	Pause();

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

	int GetFinish();

	int GetSoundVolum();

	int GetRisetOrTitle();

private:
	// 画像などのリソースデータの変数宣言と読み込み
	int MenuGh;
	int SoundGh;
	int GameOutGh;
	int GameOut2Gh;
	int ResetGh;
	int TitleGh;
	int BackGh;
	int Back2Gh;
	int backGroundGh;
	int soundBarGh;
	int soundChangeGh;

	Ease* ease_ = nullptr;

	Sound* sound_ = nullptr;

	//メンバ変数
	float timer[7];
	float MaxTimer[7];

	float menuX = -300;
	float menuY = 20;
	float menuXFinal;

	float soundX = -300;
	float soundY = 170;
	float soundXFinal;

	float ResetX = -300;
	float ResetY = 175 + 64;
	float ResetXFinal;

	float TitleX = -300;
	float TitleY = 180 + 128;
	float TitleXFinal;

	float GameOutX = -300;
	float GameOutY = 500;
	float GameOutXFinal;

	//sound押したとき出てくる背景
	float backGroundLeftX = 800;
	float backGroundRightX = 800;
	float backGroundTopY = 300;
	float backGroundDownY = 300;

	float backGroundLeftFinalX;
	float backGroundRightFinalX;
	float backGroundTopFinalY;
	float backGroundDownFinalY;

	float backLeftX = 800;
	float backRightX = 800;
	float backTopY = 300;
	float backDownY = 300;

	float backLeftFinalX;
	float backRightFinalX;
	float backTopFinalY;
	float backDownFinalY;




	//サウンドバーたち
	float soundBarLeftX = 800;
	float soundBarRightX = 800;
	float soundBarTopY = 300;
	float soundBarDownY = 300;

	float soundBarLeftFinalX;
	float soundBarRightFinalX;
	float soundBarTopFinalY;
	float soundBarDownFinalY;

	float soundChangeLeftX = 800;
	float soundChangeRightX = 800;
	float soundChangeTopY = 300;
	float soundChangeDownY = 300;
	
	float soundChangeLeftFinalX;
	float soundChangeRightFinalX;
	float soundChangeTopFinalY;
	float soundChangeDownFinalY;

	float keepSoundLeft = 800;
	float keepSoundRight = 800;

	int isPause = 3;
	int isEscTrigger = 0;

	int isHit = 0;
	int isHit2 = 0;
	int isHit3 = 0;
	int isHit4 = 0;
	int isHit5 = 0;
	int isHit6 = 0;

	int pal = 255;
	int pal2 = 255;
	int pal3 = 255;
	int pal4 = 255;
	int pal5 = 255;

	int isSetting = 0;
	int isSettingBack = 0;
	int isSettingAndEsc = 0;
	int isFinish = 0;

	int soundFlagHit1 = 0;
	int soundFlagHit2 = 0;
	int soundFlagHit3 = 0;
	int soundFlagHit4 = 0;
	int soundFlagHit5 = 0;
	int soundFlagHit6 = 0;

	int isSoundChange = 0;
	int soundVolume = 197;

	int selectSceen = 0;
};