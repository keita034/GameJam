#pragma once

class ModeChange
{
public:
	// 位置
	float x, y;

	// 半径
	int r;

	// フラグ
	bool isActive;

	// モーションの時間
	int motionTime;

	// モーションし始めてからの時間
	int motionTimer;

	// 画像
	int particleGraph;

public:
	// コンストラクタ
	ModeChange();

	// デストラクタ
	~ModeChange();

	// 更新処理
	void Update();

	// 描画処理
	void Draw();

	// 生成
	void Generate();

	// 画像読み込み
	void Load();

	//-----セッター-----//
	
	// 位置の設定
	void SetPos(float x, float y);
};