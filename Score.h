#pragma once

class Player;
class Score
{
private:
	//ハイスコア
	float hignScore = 0;
	//スコア
	float score = 0;
	//スコア倍率
	float magnification = 1.0f;
	//ハイスコアかどうか
	bool hignScoreFlag = false;
	int maxCombo = 0;
	int maxEnemydestroying = 0;
	Player* player;

public:

	//初期化
	void Initialize(Player* player );

	// 更新
	void Update();

	// 描画
	void Draw();

	//スコア加算
	void ScoreAdd(int score);

	void ResultInitialize();

	void ResultDraw();

	void AddEnemydestroy();

	static Score* GetInstance();

	void Reset();

private:
	Score() = default;
	~Score() = default;

};

