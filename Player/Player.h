#pragma once
#include"DxLib.h"
#include"Vec2.h"
#include"KeyBoardInput.h"
#include<cmath>

class Player
{
private:

	//座標
	Vec2 pos;
	//半径
	int radius = 64;
	//角度
	float angle;
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
	//攻撃フラグ
	bool attackFlag = false;
	//攻撃半径
	int attackRadius = 150;

	int level = 0;

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

private:

	/// <summary>
	/// 攻撃
	/// </summary>
	void Attack();
};

