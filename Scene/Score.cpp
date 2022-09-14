#include "Score.h"
#include"Player.h"
#include<string>

Score::Score()
{
	hpBarImg = LoadGraph("Resources/Hp_Bar.png");
	scoreImg = LoadGraph("Resources/score_mojiFont.png");
	comboImg = LoadGraph("Resources/combo_mojiFont.png");
	LoadDivGraph("Resources/score_Num_font.png", 10, 10, 1, 48, 64, scoreNumber, true);
	LoadDivGraph("Resources/Combo_x.Font.png", 2, 2, 1, 48, 48, scoreMagnificationImg, true);
}


void Score::Initialize(Player* player)
{
	this->player = player;
	
	Reset();
}

void Score::Update(int time)
{
	maxCombo = max(player->GetCombo(), maxCombo);

	combo = player->GetCombo();

	switch (player->GetLevel())
	{
	case 0:
		magnification = 1.00f;
		break;
	case 1:
		magnification = 1.10f;
		break;
	case 2:
		magnification = 1.20f;
		break;
	case 3:
		magnification = 1.30f;
		break;
	case 4:
		magnification = 1.40f;
		break;
	case 5:
		magnification = 1.50f;
		break;
	}

	if (hpAfterimage > player->GetHp())
	{
		hpAfterimage -= 0.02f;
	}
	if (hpAfterimage <= player->GetHp())
	{
		hpAfterimage = player->GetHp();
	}

	gameTime = time / 50;
}

void Score::Draw()
{
	int div = 1;
	
	if (player->GetLevelUpExtensionFlag())
	{
		if (player->GetLevelUpExtensionTime() > 50 * 3.8)
		{
			DrawBox(1133, 221, 1133 + (0.5 * 50 * 3.8), 237, player->GetAttackStanceEffectColor(), true);
		}
		else
		{
			DrawBox(1133, 221, 1133 + (0.5 * player->GetLevelUpExtensionTime()), 237, player->GetAttackStanceEffectColor(), true);
		}
	}

	div = 1;
	for (int i = 0; i < std::to_string(gameTime).length(); i++)
	{
		int index =	gameTime / div % 10;
		DrawRotaGraph(80 + (48 * 0.45) * (5 - 1 - i), 80, 0.45, 0.0, scoreNumber[index], true);
		div = div * 10;
	}

	//スコア
	DrawRotaGraph(1040, 73, 0.35, 0.0, scoreImg, true);

	div = 1;
	for (int i = 0; i < 7; i++)
	{
		int index = (int)score / div % 10;
		DrawRotaGraph(1135 + (48*0.45) * (5 - 1 - i), 70, 0.45, 0.0, scoreNumber[index], true);
		div = div * 10;
	}

	//コンボ
	DrawRotaGraph(1040, 137, 0.35, 0.0, comboImg, true);

	div = 1;
	for (int i = 0; i < 5; i++)
	{
		int index = combo / div % 10;
		DrawRotaGraph(1135 + (48 * 0.45) * (5 - 1 - i), 135, 0.45, 0.0, scoreNumber[index], true);
		div = div * 10;
	}

	DrawBox(1036, 278, 1036 + (20 * hpAfterimage), 309, GetColor(100, 0, 0), true);
	DrawBox(1036, 278, 1036 + (20 * player->GetHp()), 309, 0x3cb53e, true);

	//Hpバーフレーム
	DrawRotaGraph(1135, 293, 1.0, 0.0, hpBarImg, true);

	scoreIntegerNum = (int)magnification;
	scoreDecimalNum = fabs(magnification) - floor(fabs(magnification));

	//コンボ倍率
	DrawRotaGraph(1135, 205, 0.45, 0.0, scoreMagnificationImg[0], true);

	div = 1;
	for (int i = 0; i < 2; i++)
	{
		int index = scoreIntegerNum / div % 10;
		if (i == 1 && index == 0)
		{
			continue;
		}
		DrawRotaGraph(1090 + (48 * 0.45) * (5 - 1 - i), 200, 0.45, 0.0, scoreNumber[index], true);
		div = div * 10;
	}

	DrawRotaGraph(1190, 205, 0.45, 0.0, scoreMagnificationImg[1], true);

	div = 1;
	for (int i = 0; i < 2; i++)
	{
		int index = (int)(scoreDecimalNum * 100.0f) / div % 10;
		DrawRotaGraph(1140 + (48 * 0.45) * (5 - 1 - i), 200, 0.45, 0.0, scoreNumber[index], true);
		div = div * 10;
	}
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
	int div = 1;
	for (int i = 0; i < 7; i++)
	{
		int index = (int)score / div % 10;
		DrawRotaGraph(560 + (48 * 0.45) * (5 - 1 - i), 220, 0.6, 0.0, scoreNumber[index], true);
		div = div * 10;
	}
	div = 1;
	for (int i = 0; i < 5; i++)
	{
		int index = maxCombo / div % 10;
		DrawRotaGraph(560 + (48 * 0.45) * (5 - 1 - i), 320, 0.6, 0.0, scoreNumber[index], true);
		div = div * 10;
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
	combo = 0;
}
