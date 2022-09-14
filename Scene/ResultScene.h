#pragma once
#include "Util.h"
#include "MouseInput.h"
#include"Sound.h"

class ResultScene
{
public:
	ResultScene();
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

	bool GetChangeTitle();

	bool GetChangeGame();

private:
	// 描画のグラフハンドル
	int flameHandle, resultBackHandle, resultKyaraHandle, resultKyaraFlameHandle;
	int resultAccessoriesHandle,resultMojiFontHandle,resultScoreFontHandle,resultMaxComboFontHandle;
	int resultButtonTitleHandle[2], flame1 = 1;
	int resultButtonReplay[2], flame2 = 1;

	bool changeTitle = false, changeGameScene = false;

	Sound* sound_ = nullptr;

	int hit1 = 0;
	int hit2 = 0;

};

