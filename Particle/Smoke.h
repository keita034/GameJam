#pragma once
#include <DxLib.h>
#include"Vec2.h"

class Smoke {

public:

	Smoke();

	/// <summary>
	/// ������
	/// </summary>
	void Initialize(int siroGh_);

	/// <summary>
	/// ���t���[������
	/// </summary>
	void Update();

	/// <summary>
	/// �`��
	/// </summary>
	void Draw();

	/// <summary>
	/// �G���G�����܂�鎞�ɏo���X���[�N
	/// </summary>
	void MakeEnemySmoke(int SmokePosX, int SmokePosY);

	/// <summary>
	/// �{�X�����܂�鎞�ɏo���X���[�N
	/// </summary>
	void MakeBossEnemySmoke(int SmokePosX, int SmokePosY);

	/// <summary>
	/// ���񂾂Ƃ��ɏo���X���[�N
	/// </summary>
	void DieSmoke(int SmokePosX,int SmokePosY);

private:

	int siroGh;

	float MakeEnemySmokeX[100];
	float MakeEnemySmokeY[100];

	float MakeBossSmokeX[100];
	float MakeBossSmokeY[100];

	float DieSmokeX[300];
	float DieSmokeY[300];
	int MakeEnemyTimer[300];
	int MakeBossTimer[300];

	float randX[300];
	float randY[300];

	int MakeEnemyPal[300];
	int MakeBossPal[300];

	int MakeEnemyFlag[300];
	int MakeBossFlag[300];
	
	int MakeBossSmokeFlag[300];

	int DiePal[300];

	int frame = 0;
	int maxFrame = 1;

	int DieTimer[300];
	int dieFlag[100];

	int Smokes = 0;

	int NowSmoke = 0;
	int NextSmoke = 0;

	Vec2 randomPos;
	Vec2 movePos;
	Vec2 a;

	Vec2 pos;
	Vec2 vec;

};