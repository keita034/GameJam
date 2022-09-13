#include "TitleScene.h"

TitleScene::TitleScene()
{
}

void TitleScene::Initialize()
{
	LoadDivGraph("Resources/TitleLogo-sheet.png", 32, 32, 1, 660, 100, TitleFontHandle);
	TitleBackGrouhdHandle = LoadGraph("Resources/GameSceneBackGround.png");
	pressFontHandle = LoadGraph("Resources/startSpace.png");
}

void TitleScene::Update()
{
	timer++;
	if (timer >= 5)
	{
		TitleFlame++;
		timer = 0;
	}
	if (TitleFlame >= 32)
	{
		TitleFlame = 0;
	}
}

void TitleScene::Draw()
{

	DrawGraph(0, 0, TitleBackGrouhdHandle, true);
	DrawGraph(640 - 330, 150, TitleFontHandle[TitleFlame], true);
	DrawRotaGraph(640, 550, 0.5f, 0.0f, pressFontHandle, true);
}
