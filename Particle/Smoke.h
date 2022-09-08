#pragma once
#include <DxLib.h>
#include"Vec2.h"

class Smoke {

public:

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
	/// 死んだときに出し続けるかとスモークの数
	/// </summary>
	void MakeSmoke(int SmokePosX,int SmokePosY,int HowManySmokes);

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
	int maxFrame = 1;

	int DieTimer = 0;
	int dieFlag = 0;

	int HowManySmokes = 0;

	Vec2 randomPos;
	Vec2 movePos;
	Vec2 a;

	Vec2 pos;
	Vec2 vec;

};