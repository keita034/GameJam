#pragma once
class Score
{
private:
	//ハイスコア
	int hignScore;
	//スコア
	int Score;
	//計算用スコア
	float tmpScore;
	//スコア倍率
	float magnification;

public:

	//初期化
	void Initialize();

	// 更新
	void Update();

	// 描画
	void Draw();
};

