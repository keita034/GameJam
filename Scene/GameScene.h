#pragma once
#include"DxLib.h"
#include"Player.h"

class GameScene
{
public:
	GameScene();

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
	Player* player_;

};

