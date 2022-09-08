#pragma once
#include "Util.h"
#include "DxLib.h"
#include"KeyBoardInput.h"
enum Pattern
{
	HeightUp,       // 縦上
	HeightDown,     // 縦下
	WidthL,         // 横左
	WidthR,         // 横右
	UpperL,         // 左斜め上
	UpperR,         // 右斜め上
	DiagonallyDownL,// 左斜め下
	DiagonallyDownR,// 右斜め下
	Traking,        // 追尾
	Center,         // 中心を通る
	TrakingEnemy,   // 前にいる敵の後ろを追尾
};

class Enemy
{
public:
	// インスタンス
	Enemy();
	~Enemy();

	// メンバー関数

	// 初期化関数
	void Initialize(Pattern pattern,Vec2 pos,float speed);

	// 更新関数
	void Update(Vec2 playerNpos);

	// 描画関数
	void Draw(Vec2 screen);

	bool IsDeath();

	Vec2 GetPos();

	int GetRadius();

	void Death();

	void HPSub(int subNum);

	void HPAdd(int addNum);

	void SetTrakingEnemyPos(Vec2 &enemyPos);

private:
	// メンバー変数
	Vec2 zeroVec = { 0.0f,0.0f };
	Vec2 MaxPos = { 700.0f,400.0f };
	Vec2 fieldSize = { 2560.0f ,1440.0f };
	Vec2 pos_;
	float speed_;
	Vec2 velocity_;
	float radius_;
	Vec2 playerPos_;
	bool isDeath_;
	//ダメージインターバル
	int damageInterval = 0;
	int maxDamageInterval = 25;
	//ダメージフラグ
	bool damageFlag = true;
	// エネミーの行動パターン
	Pattern pattern_;
	//体力
	int hp = 3;

	// ひとつ前にいる敵の位置
	Vec2 tarkingEnemyPos = { 0,0 };

	// ひとつ前にいる敵とのベクトルの長さ
	//Vec2 tarkingEnemyPosLength = { 0,0 };
};

