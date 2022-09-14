#pragma once
#include"DxLib.h"
#include"Vec2.h"

class PlayerLevelUp
{
public:

	PlayerLevelUp();

	/// <summary>
	/// ������
	/// </summary>
	void Initialize();

	/// <summary>
	/// ���t���[������
	/// </summary>
	void Update(int playerPosX,int playerPosY);

	/// <summary>
	/// �`��
	/// </summary>
	void Draw(Vec2 screen);

	/// <summary>
	/// Level���オ������
	/// </summary>
	void playerLevelUp(int playerLevel);

	/// <summary>
	/// circle����
	/// </summary>
	void CircleUpdata(int playerPosX, int playerPosY);

private:

	// �ʒu
	float posX[50] = {0};
	float posY[50] = {0};

	float vecX[50];
	float vecY[50];

	float KeepVecX[50];
	float KeepVecY[50];

	float y[50];

	//�����Ă邩����ł邩
	int LevelAlive[50];
	int isPlayerLevelUp[50];
	//�^�C�}�[
	int AllTimer;
	int separatelyTimer[50];
	int frame = 0;

	int radius = 8;

	float pal = 0;

	int playerLevel = 0;
	int miniCircleColor = 0;

	//�~���o��
	int makeCircle = 0;

	int level1Circle[12];
	int level2Circle[12];
	int level3Circle[12];
	int level4Circle[12];
	int level5Circle[12];
	int levelDownCircle[12];

	int circlePosX = 0;
	int circlePosY = 0;
	int circleRadius = 48;

	int circleNumber = 0;
	int levelGh[6];

	int drawTimer = 2;
};