#pragma once
#include <DxLib.h>
#include"Vec2.h"

class Smoke {

public:

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

	int siroGh;
	float x[300];
	float y[300];
	int timer[300];

	float randX[300];
	float randY[300];

	int flag[300];

	int pal[300];

	int frame = 0;
	int maxFrame = 3;

	Vec2 randomPos;
	Vec2 movePos;
	Vec2 a;

	Vec2 pos;
	Vec2 vec;

};