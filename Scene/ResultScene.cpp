#include "ResultScene.h"
#include "Score.h"
ResultScene::ResultScene()
{
	flameHandle, resultBackHandle, resultKyaraHandle, resultKyaraFlameHandle;
	flameHandle = LoadGraph("Resources/Flame01.png");
	resultBackHandle = LoadGraph("Resources/ResultBackGround.png");
	resultKyaraHandle = LoadGraph("Resources/player_smile.png");
	resultKyaraFlameHandle = LoadGraph("Resources/player_background.png");
	resultAccessoriesHandle = LoadGraph("Resources/Resultaccessories.png");
	resultMojiFontHandle = LoadGraph("Resources/ResultMojiFont.png");
	resultScoreFontHandle = LoadGraph("Resources/ResultScoreMojiFont.png");
	resultMaxComboFontHandle = LoadGraph("Resources/ResultMaxComboMojiFont.png");

	LoadDivGraph("Resources/ResultButton1.png", 2, 2, 1, 272, 80, resultButtonTitleHandle);
	LoadDivGraph("Resources/ResultButton2.png", 2, 2, 1, 272, 80, resultButtonReplay);
}

void ResultScene::Initialize()
{
	changeGameScene = false;
	changeTitle = false;
	flame1 = 1;
	flame2 = 1;

	sound_ = Sound::GetInstance();
	sound_->Initialize();


}

void ResultScene::Update()
{
	mouse.Update();
	changeTitle = false;
	changeGameScene = false;
	if (mouse.GetMouseX() >= 260 && mouse.GetMouseX() <= 478
		&& mouse.GetMouseY() >= 488 && mouse.GetMouseY() <= 552)
	{
		if (hit1 == 0) {
			hit1 = 1;
			sound_->SelectUpdate();
		}
		flame1 = 0;
		int Mouse = GetMouseInput();
		if (Mouse && MOUSE_INPUT_LEFT) {
			changeTitle = true;
		}
	}
	else
	{
		hit1 = 0;
		flame1 = 1;
	}
	if (mouse.GetMouseX() >= 560 && mouse.GetMouseX() <= 778
		&& mouse.GetMouseY() >= 488 && mouse.GetMouseY() <= 552)
	{
		if (hit2 == 0) {
			hit2 = 1;
			sound_->SelectUpdate();
		}
		flame2 = 0;
		int Mouse = GetMouseInput();
		if (Mouse && MOUSE_INPUT_LEFT) {
			changeGameScene = true;
		}
	}
	else
	{
		hit2 = 0;
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
	Score::GetInstance()->ResultDraw();
	

	DrawGraph(1038, 366, resultKyaraFlameHandle, true);
	DrawRotaGraph(1135, 515, 1.3f, 0.0f, resultKyaraHandle, true);
	DrawGraph(-50, -50, flameHandle, true);
}

bool ResultScene::GetChangeTitle()
{
	return changeTitle;
}

bool ResultScene::GetChangeGame()
{
	return changeGameScene;
}
