#pragma once
#include"DxLib.h"
#include"Vec2.h"
#include"KeyBoardInput.h"
#include"Ease.h"
#include<cmath>

class Player
{
private:

	//座標
	Vec2 pos;
	//半径
	int radius = 64;
	//角度
	float angle = 0.0f;
	//スピード
	float speed = 5.0f;

	//正面ベクトルの終点
	Vec2 front;
	//正面ベクトル
	Vec2 frontVec;
	//正面ベクトルの正規化
	Vec2 normFrontVec;
	
	//フィールドサイズ
	Vec2 fieldSize = { 2560.0f ,1440.0f };
	Vec2 zero = { 0.0f,0.0f };

	//スクリーン座標
	Vec2 screen = { 640.0f,360.0f };

	//攻撃時間
	int attackTime = 50 * 1;
	//攻撃インターバル
	int attackInterval = 0;
	//最大攻撃インターバル
	int maxAttackInterval = 50 * 2;
	//攻撃距離
	int attackDistance = 64;
	//攻撃フラグ
	bool attackFlag = false;
	//攻撃半径
	int attackRadius = 150;
	//攻撃威力
	int attackPower = 1;
	Vec2 attackBeginPos;
	int level = 0;

	//体力
	int hp = 3;

public:

	Player() = default;
	~Player() = default;

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	Vec2 GetPos();
	int GetRadius();

	Vec2 GetScreen();

	bool GetAttackFlag();

	int GetAttackRadius();

	void HPSub(int subNum);

	void HPAdd(int addNum);

	int GetAttackPower();

private:

	/// <summary>
	/// 攻撃
	/// </summary>
	void Attack();
};

