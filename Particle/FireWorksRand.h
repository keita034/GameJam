#pragma once
#include "Particle.h"

class FireWorksRand
{
private:
	// 位置
	Vec2 pos;

	Vec2 vec;

	// フラグ
	bool isActive = false;

	// パーティクルの数
	int maxParticle;

	// 表示時間
	int displayTime;

	// 表示時間を計測するタイマー
	int displayTimer;

	// 生成のタイマー
	int timer;

	// クラス
	Particle* particle;

public:
	// コンストラクタ
	FireWorksRand();

	// デストラクタ
	~FireWorksRand();

	// 生成関数
	void Generation(int displayTime);

	// 更新処理
	void Update();

	// 描画処理
	void Draw(int graph);

	//-----セッター-----//

	// 位置の設定
	void SetPos(Vec2 pos);

	//-----ゲッター-----//

	// 位置の取得
	float GetPosX();
	float GetPosY();

	//　フラグの取得
	bool GetActive();
};