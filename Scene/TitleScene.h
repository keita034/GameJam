#pragma once
#include "Util.h"

class TitleScene
{
public:
	TitleScene();

	/// <summary>
	/// ������
	/// </summary>
	void Initialize();

	/// <summary>
	/// ���t���[������
	/// </summary>
	void Update();

	/// <summary>
	/// �`��
	/// </summary>
	void Draw();
private:
	int TitleFontHandle[32];
	int pressFontHandle;
	int TitleBackGrouhdHandle;

	float timer = 0;
	int TitleFlame = 0;
	Vec2 pos;
	
};

