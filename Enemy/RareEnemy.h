#pragma once
#include "Enemy.h"
#include "Player.h"
#include "Collision.h"
#include "Util.h"
#include<memory>
#include<list>
#include"Smoke.h"
#include"Sound.h"
#include"Pause.h"

// レア敵の動き
enum situation
{
	MoveLeftRight,           // 上で左右に動く
	TrakingPlayer,           // プレイヤーを追尾
	StopInFrontOfThePlayer,  // プレイヤーの前に止まって回る
	Escape_,                  // 逃げる
};

class RareEnemy
{
public:
	// 初期化
	void RareEnemyInit(Vec2 pos,int siroGh);

	// 更新処理
	void RareEnemyUpdate(Player* player_);

	// 描画処理
	void RareEnemyDraw(Player* player_);

	// 当たり判定
	void RareEnemyCheckCollisions(Player* player_);

	// 死亡フラグの取得
	bool IsDeath();

private:
	Vec2 InitPos = { 0,0 };
	Vec2 velocity;
	Vec2 A = { 0,0 }, B = { 200,0 };
	Vec2 limitVelocity = B - A;
	Vec2 NowVelocity;
	float angle;

	bool StopinitFlag = true;
	Vec2 StopEnemyPos = { 0,0 };
	Vec2 center;
	Vec2 vector;
	Vec2 vector2;

	// スモーク
	Smoke* smoke_ = nullptr;
	bool smokeFlag = false;

	// レア敵
	std::unique_ptr<Enemy> rareEnemy;

	// フェーズ
	situation situation_ = MoveLeftRight;

	// 行動タイマー
	int timer = 0;

	// 敵のスピード
	Vec2 Speed = { 8,8 };

	// 横移動フラグ
	bool MoveLeftRightFlag = false;

	//音ワッカ
	Sound* sound_ = nullptr;
	Pause* pause_ = nullptr;
};

