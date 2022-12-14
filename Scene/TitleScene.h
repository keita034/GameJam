#pragma once
#include "Util.h"

class TitleScene
{
public:
	TitleScene();

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
private:
	int TitleFontHandle[32];
	int pressFontHandle;
	int TitleBackGrouhdHandle;

	float timer = 0;
	int TitleFlame = 0;
	Vec2 pos;
	
};

