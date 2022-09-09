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

	/// <summary>
	/// ���񂾂Ƃ��ɏo�������邩�ƃX���[�N�̐�
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