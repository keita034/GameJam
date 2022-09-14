#pragma once
#include <DxLib.h>
#include"Vec2.h"

class Smoke {

public:

	Smoke();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(int siroGh_);

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update(float enemyPosX, float enemyPosY);

	/// <summary>
	/// 描画
	/// </summary>
	void Draw(Vec2 screen);

	/// <summary>
	/// 雑魚敵が生まれる時に出すスモーク
	/// </summary>
	void MakeEnemySmoke();

	/// <summary>
	/// ボスが生まれる時に出すスモーク
	/// </summary>
	void MakeBossEnemySmoke();

	/// <summary>
	/// 死んだときに出すスモーク
	/// </summary>
	void DieSmoke(int SmokePosX,int SmokePosY);

private:

	int siroGh;
	int AllTimer;
	float pal = 0;
	float MakeEnemySmokeX[100];
	float MakeEnemySmokeY[100];
	float y[100];
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

	int SmokeRadius = 48;

	int frame = 0;
	int maxFrame = 1;

	int DieTimer[300];
	int dieFlag[100];

	int Smokes = 0;

	int NowSmoke = 0;
	int NextSmoke = 0;

	float vecX[300];
	float vecY[300];
	float KeepVecX[100];
	float KeepVecY[100];
	int smokeFlag[300];
	int drawTimer = 2;
	Vec2 randomPos;
	Vec2 movePos;
	Vec2 a;

	Vec2 pos;
	Vec2 vec;

};