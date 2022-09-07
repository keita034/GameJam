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
	//スピード
	float speed = 5.0f;
	//アタックスピード
	float attackSpeed;
	//フィールドサイズ
	Vec2 fieldSize = { 2560.0f ,1440.0f };
	Vec2 zero = { 0.0f,0.0f };
	//正面ベクトルの終点
	Vec2 front;
	//正面ベクトル
	Vec2 frontVec;
	//正面ベクトルの正規化
	Vec2 normFrontVec;
	//角度
	float angle;
	//半径
	int radius = 30;
	//スクリーン座標
	Vec2 screen = { 640.0f,610.0f };
	int attackTime = 40;
	int attackInterval = 0;
	int maxAttackInterval = 50 * 10;
	bool attackFlag = false;


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

