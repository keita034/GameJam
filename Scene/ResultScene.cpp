#include "ResultScene.h"

void ResultScene::Initialize()
{
	changeGameScene = false;
	changeTitle = false;
	flame1 = 1;
	flame2 = 1;

	flameHandle, resultBackHandle, resultKyaraHandle, resultKyaraFlameHandle;
	flameHandle = LoadGraph("Resources/Flame01.png");
	resultBackHandle = LoadGraph("Resources/ResultBackGround.png");
	resultKyaraHandle = LoadGraph("Resources/player_smile.png");
	resultKyaraFlameHandle = LoadGraph("Resources/player_background.png");
	resultAccessoriesHandle = LoadGraph("Resources/Resultaccessories.png");
	resultMojiFontHandle = LoadGraph("Resources/ResultMojiFont.png");
	resultScoreFontHandle= LoadGraph("Resources/ResultScoreMojiFont.png");
	resultMaxComboFontHandle = LoadGraph("Resources/ResultMaxComboMojiFont.png");

	LoadDivGraph("Resources/ResultButton1.png", 2, 2, 1, 272, 80, resultButtonTitleHandle);
	LoadDivGraph("Resources/ResultButton2.png", 2, 2, 1, 272, 80, resultButtonReplay);
}

void ResultScene::Update()
{
	mouse.Update();

	if (mouse.GetMouseX() >= 260 && mouse.GetMouseX() <= 478
		&& mouse.GetMouseY() >= 488 && mouse.GetMouseY() <= 552)
	{
		flame1 = 0;
		if (mouse.GetCrickTrigger(MOUSE_INPUT_LEFT))
		{
			changeTitle = true;
		}
	}
	else
	{
		flame1 = 1;
	}
	if (mouse.GetMouseX() >= 560 && mouse.GetMouseX() <= 778
		&& mouse.GetMouseY() >= 488 && mouse.GetMouseY() <= 552)
	{
		flame2 = 0;
		if (mouse.GetCrickTrigger(MOUSE_INPUT_LEFT))
		{
			changeGameScene = true;
		}
	}
	else
	{
		flame2 = 1;
	}
}

void ResultScene::Draw()
{
	DrawGraph(58, 58, resultBackHandle, true);
	DrawGraph(58, 58, resultAccessoriesHandle, true);
	DrawRotaGraph(525, 130, 0.8f, 0.0f, resultMojiFontHandle, true);
	DrawRotaGraph(200, 220, 0.7f, 0.0f, resultScoreFontHandle, true);
	DrawRotaGraph(260, 320, 0.7f, 0.0f, resultMaxComboFontHandle, true);
	DrawRotaGraph(370, 520, 0.8f, 0.0f, resultButtonTitleHandle[flame1], true);
	DrawRotaGraph(670, 520, 0.8f, 0.0f, resultButtonReplay[flame2], true);

	DrawGraph(1038, 366, resultKyaraFlameHandle, true);
	DrawRotaGraph(1135, 515, 1.3f, 0.0f, resultKyaraHandle, true);
	DrawGraph(0, 0, flameHandle, true);
}

bool ResultScene::GetChangeTitle()
{
	return changeTitle;
}

bool ResultScene::GetChangeGame()
{
	return changeGameScene;
}
