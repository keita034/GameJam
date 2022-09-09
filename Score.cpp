#include "Score.h"
#include"Player.h"

void Score::Initialize(Player* player)
{
	this->player = player;

	
}

void Score::Update()
{
	maxCombo = max(player->GetCombo(), maxCombo);

	switch (player->GetCombo())
	{
	case 1:
		magnification = 1.1f;
		break;
	case 2:
		magnification = 1.2f;
		break;
	case 3:
		magnification = 1.3f;
		break;
	case 4:
		magnification = 1.4f;
		break;
	case 5:
		magnification = 1.5f;
		break;
	}
}

void Score::Draw()
{

}

void Score::ScoreAdd(int score)
{
	this->score += score * magnification;;
}

void Score::ResultInitialize()
{
	if (score > hignScore)
	{
		hignScore = true;
		hignScore = score;
	}
}

void Score::ResultDraw()
{
	if (hignScoreFlag)
	{

	}
	else
	{

	}
}

void Score::AddEnemydestroy()
{
	maxEnemydestroying++;
}

Score* Score::GetInstance()
{
	static Score instance;
	return &instance;
}

void Score::Reset()
{
	//�X�R�A
	score = 0;
	//�X�R�A�{��
	magnification = 1.0f;
	//�n�C�X�R�A���ǂ���
	hignScoreFlag = false;
	maxCombo = 0;
	maxEnemydestroying = 0;
}
