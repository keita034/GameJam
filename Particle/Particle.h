#pragma once
#include "Util.h"

class Particle
{
private:
	// 形ごとの位置
	Box box;
	Circle circle;

	// 方向
	Vec2 vec;

	// 速度
	float speed;

	// フラグ
	bool isActive;

	// 1Fごとに半径を拡縮する数値
	float addRadius;

	// 形
	int shape;

	// 表示時間を計測するタイマー
	float displayTimer;

	// 表示時間
	float MaxDisplayTime;

public:
	// 形の列挙型
	enum Shape
	{
		BOX = 1,
		CIRCLE
	};

public:
	// コンストラクタ
	Particle();

	// デストラクタ
	~Particle();

	// 初期化
	void Initialize();

	// 更新処理
	void Update();

	// 描画処理
	void Draw();

	void DrawGraphHandle(int r, int g, int b, int BlendNum, double ExRate, double Angle, int GraphhHandle, bool FillFlag);

	//-----セッター-----//

	// 位置の設定
	void SetPos(Vec2& pos);

	// 大きさの設定
	void SetSize(float width, float height);

	// 半径の設定
	void SetRadius(float radius);

	// 方向の設定
	void SetVec(Vec2& vec);

	// 速度の設定
	void SetSpeed(float speed);

	// フラグの設定
	void SetActive(bool isActive);

	// 拡縮数値の設定
	void SetAddRadius(float addRadius);

	// 形の設定
	void SetShape(int shape);

	// 表示時間の設定
	void SetMaxDisplayTime(float MaxDisplayTime);

	//-----ゲッター-----//

	// 位置の取得
	float GetPosX();
	float GetPosY();

	// 半径の取得
	float GetRadius();

	// フラグの取得
	bool GetActive();

	// 表示時間を取得する
	float GetDisPlayTimer();
};