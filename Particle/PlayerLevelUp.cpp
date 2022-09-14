#include "playerLevelUp.h"
#include <Util.h>
#include "math.h"

PlayerLevelUp::PlayerLevelUp()
{
	LoadDivGraph("Resources/levelUpDown.png", 6, 6, 1, 8, 8, levelGh);
	LoadDivGraph("Resources/Leval1Circle.png", 12, 12, 1, 96, 96, level1Circle);
	LoadDivGraph("Resources/Leval2Circle.png", 12, 12, 1, 96, 96, level2Circle);
	LoadDivGraph("Resources/Leval3Circle.png", 12, 12, 1, 96, 96, level3Circle);
	LoadDivGraph("Resources/Leval4Circle.png", 12, 12, 1, 96, 96, level4Circle);
	LoadDivGraph("Resources/Leval5Circle.png", 12, 12, 1, 96, 96, level5Circle);
	LoadDivGraph("Resources/LevalDownCircle.png", 12, 12, 1, 96, 96, levelDownCircle);
}

void PlayerLevelUp::Initialize()
{




	for (int i = 0; i < 50; i++)
	{

// 位置
		posX[i] = 0;
		posY[i] = 0.0f;
		//位置ランダム
		vecX[i] = 0.0f;
		vecY[i] = 0.0f;

		KeepVecX[i] = 0.0f;
		KeepVecY[i] = 0.0f;

		//タイマーとか
		AllTimer = 0;
		LevelAlive[i] = 0;
		isPlayerLevelUp[i] = 0;
		y[i] = 0;

	}

}

void PlayerLevelUp::Update(int playerPosX, int playerPosY)
{

	for (int i = 0; i < 50; i++)
	{
		if (isPlayerLevelUp[i] == 1)
		{
			if (LevelAlive[i] == 0)
			{
				frame++;

				if (1 < frame)
				{
					frame = 0;
					break;
				}

				if (AllTimer < 0)
				{
					AllTimer = 50;
				}
				LevelAlive[i] = 1;
				y[i] = 0;

				// アングルをランダムで指定
				int angle = GetRandomRange(0, 360);
				vecX[i] = cos(Radian(angle));
				vecY[i] = sin(Radian(angle));
				isPlayerLevelUp[i] = 0;
			}
		}
	}
	AllTimer--;
	pal = pal - 2.5;
	for (int i = 0; i < 50; i++)
	{
		if (LevelAlive[i] == 1)
		{


			posX[i] = playerPosX;
			posY[i] = playerPosY + 5;


			KeepVecX[i] += vecX[i] * 1.5;
			KeepVecY[i] += vecY[i] * 1.0f;

			y[i] -= 0.8;

			posX[i] += KeepVecX[i];
			posY[i] += KeepVecY[i];
			posY[i] += y[i];


		}
		if (AllTimer < 0)
		{
			LevelAlive[i] = 0;
			isPlayerLevelUp[i] = 0;
			AllTimer = -1;
			makeCircle = 0;
		}
	}
	CircleUpdata(playerPosX, playerPosY);

}

void PlayerLevelUp::Draw(Vec2 screen)
{
	for (int i = 0; i < 50; i++)
	{
		if (LevelAlive[i] == 1)
		{
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, pal);
			DrawGraph(posX[i] - radius - screen.x, posY[i] - radius - screen.y, levelGh[miniCircleColor], true);
			SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 0);

			if (makeCircle == 1)
			{

				if (playerLevel == 1)
				{
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
					DrawGraph(circlePosX - circleRadius - screen.x, circlePosY - circleRadius - screen.y, level1Circle[circleNumber], true);
					SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 0);
				}
				else if (playerLevel == 2)
				{
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
					DrawGraph(circlePosX - circleRadius - screen.x, circlePosY - circleRadius - screen.y, level2Circle[circleNumber], true);
					SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 0);
				}
				else if (playerLevel == 3)
				{
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
					DrawGraph(circlePosX - circleRadius - screen.x, circlePosY - circleRadius - screen.y, level3Circle[circleNumber], true);
					SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 0);
				}
				else if (playerLevel == 4)
				{
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
					DrawGraph(circlePosX - circleRadius - screen.x, circlePosY - circleRadius - screen.y, level4Circle[circleNumber], true);
					SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 0);
				}
				else if (playerLevel == 5)
				{
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
					DrawGraph(circlePosX - circleRadius - screen.x, circlePosY - circleRadius - screen.y, level5Circle[circleNumber], true);
					SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 0);
				}
				else if (playerLevel == 6)
				{
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
					DrawGraph(circlePosX - circleRadius - screen.x, circlePosY - circleRadius - screen.y, levelDownCircle[circleNumber], true);
					SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 0);
				}
			}
		}
	}
}

void PlayerLevelUp::playerLevelUp(int Level_)
{
	playerLevel = Level_;
	miniCircleColor = Level_ - 1;
	for (int i = 0; i < 20; i++)
	{

		isPlayerLevelUp[i] = 1;
		LevelAlive[i] = 0;
		AllTimer = 75;
		circleNumber = 0;
		//位置ランダム
		vecX[i] = 0.0f;
		vecY[i] = 0.0f;

		KeepVecX[i] = 0.0f;
		KeepVecY[i] = 0.0f;


		pal = 255;
		makeCircle = 1;

	}
}

void PlayerLevelUp::CircleUpdata(int playerPosX, int playerPosY)
{

	if (makeCircle == 1)
	{

		circlePosX = playerPosX;
		circlePosY = playerPosY;

		if (AllTimer < 53)
		{
			circleNumber = 0;
		}
		if (AllTimer < 52)
		{
			circleNumber = 1;
		}
		if (AllTimer < 51)
		{
			circleNumber = 2;
		}
		if (AllTimer < 50)
		{
			circleNumber = 3;
		}
		if (AllTimer < 49)
		{
			circleNumber = 4;
		}
		if (AllTimer < 47)
		{
			circleNumber = 5;
		}
		if (AllTimer < 45)
		{
			circleNumber = 6;
		}
		if (AllTimer < 43)
		{
			circleNumber = 7;
		}
		if (AllTimer < 41)
		{
			circleNumber = 8;
		}
		if (AllTimer < 40)
		{
			circleNumber = 9;
		}
		if (AllTimer < 33)
		{
			circleNumber = 10;
		}
		if (AllTimer < 38)
		{
			circleNumber = 11;
		}
		if (AllTimer < 37)
		{
			makeCircle = 0;
		}
	}

}