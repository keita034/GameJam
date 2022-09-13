#pragma once
#include "Util.h"

class TitleScene
{
public:
	TitleScene();

	/// <summary>
	/// ‰Šú‰»
	/// </summary>
	void Initialize();

	/// <summary>
	/// –ˆƒtƒŒ[ƒ€ˆ—
	/// </summary>
	void Update();

	/// <summary>
	/// •`‰æ
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

