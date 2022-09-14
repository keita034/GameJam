#pragma once

class Player;
class Score
{
private:
	//�n�C�X�R�A
	float hignScore = 0;
	//�X�R�A
	float score = 0;
	//�X�R�A�{��
	float magnification = 1.0f;
	//�n�C�X�R�A���ǂ���
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

	//������
	void Initialize(Player* player );

	// �X�V
	void Update();

	// �`��
	void Draw();

	//�X�R�A���Z
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

