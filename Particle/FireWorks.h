#pragma once
#include "Particle.h"

class FireWorks
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

	// クラス
	Particle* particle;

public:
	// コンストラクタ
	FireWorks();

	// デストラクタ
	~FireWorks();

	// 生成関数
	void Generation(int displayTime);

	// 更新処理
	void Update();

	// 描画処理
	void Draw();

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