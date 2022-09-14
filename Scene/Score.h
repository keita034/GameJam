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
	int combo = 0;
	int maxCombo = 0;
	int maxEnemydestroying = 0;
	Player* player;
	int hpBarImg;
	int scoreImg = 0;
	int scoreNumber[10];
	int comboImg = 0;
	float hpAfterimage = 1.0f;
	int scoreIntegerNum = 0;
	float scoreDecimalNum = 0.0f;
	int scoreMagnificationImg[2];
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

