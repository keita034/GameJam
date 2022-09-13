#include "Score.h"
#include"Player.h"

void Score::Initialize(Player* player)
{
	this->player = player;
	hpBarImg = LoadGraph("Resources/Hp_Bar.png");
	scoreImg = LoadGraph("Resources/score_mojiFont.png");
	comboImg = LoadGraph("Resources/combo_mojiFont.png");
	LoadDivGraph("Resources/score_Num_font.png",10,10,1,48,64,scoreNumber,true);
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

	combo = player->GetCombo();
}

void Score::Draw()
{

	DrawRotaGraph(1075, 73, 0.35, 0.0, scoreImg, true);
	
	int div = 1;
	for (int i = 0; i < 5; i++)
	{
		int index = (int)score / div % 10;
		DrawRotaGraph(1135 + (48*0.45) * (5 - 1 - i), 70, 0.45, 0.0, scoreNumber[index], true);
		div = div * 10;

	}

	DrawRotaGraph(1075, 137, 0.35, 0.0, comboImg, true);
	
	div = 1;
	for (int i = 0; i < 5; i++)
	{
		int index = combo / div % 10;
		DrawRotaGraph(1135 + (48 * 0.45) * (5 - 1 - i), 135, 0.45, 0.0, scoreNumber[index], true);
		div = div * 10;
	}

	DrawRotaGraph(1135, 293, 1.0, 0.0, hpBarImg, true);


	for (size_t i = 0; i < player->GetHp(); i++)
	{
		DrawBox(1036 + (20 * i), 278, 1056 + (20 * i), 309, GetColor(255, 0, 0), true);
	}

	//Hpバーフレーム
	DrawRotaGraph(1135, 293, 1.0, 0.0, hpBarImg, true);
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
	//スコア
	score = 0;
	//スコア倍率
	magnification = 1.0f;
	//ハイスコアかどうか
	hignScoreFlag = false;
	maxCombo = 0;
	maxEnemydestroying = 0;
}
