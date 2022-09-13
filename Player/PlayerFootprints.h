#pragma once
#include"Vec2.h"

class PlayerFootprints {

public:


	/// <summary>
	/// ������
	/// </summary>
	void Initialize();

	/// <summary>
	/// ���t���[������
	/// </summary>
	void Update(int playerPosX ,int playerPosY);

	/// <summary>
	/// �`��
	/// </summary>
	void Draw(Vec2 screen);

private:

	int x[30];
	int y[30];

	int LeftFlag[30];
	int RightFlag[30];
	int FootFlag[30];
	int footTimer;

	int pal[30];

	int FootArt[2];
	int LeftORright = 0;

	Vec2 frontVec{ 0,0 };
	Vec2 screenCentral = { 640.0f,360.0f };
	double angle = 0;

};
