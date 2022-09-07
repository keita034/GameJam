#pragma once
#include"DxLib.h"
#include"Player.h"
#include"Enemy.h"
#include<memory>
#include<list>

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
	std::unique_ptr<Player> player_;
	std::list<std::unique_ptr<Enemy>>enemys_;

};

