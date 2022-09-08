#pragma once
#include <DxLib.h>
#include"Vec2.h"

class Smoke {

public:

	/// <summary>
	/// ������
	/// </summary>
	void Initialize();

	/// <summary>
	/// ���t���[������
	/// </summary>
	void Update();

	/// <summary>
	/// �`��
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