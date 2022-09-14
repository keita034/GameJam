#pragma once
#include"DxLib.h"
#include"Player.h"
#include"Enemy.h"
#include"Collision.h"
#include<memory>
#include<list>
#include"EnemyPop.h"
#include"Score.h"
#include"Smoke.h"
#include"PlayerFootprints.h"
#include"playerLevelUp.h"

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

	// ���\�[�X�n���h��
	static int Siratama1Handle[4], Siratama2Handle[4], Siratama3Handle[4];
	static int Yubi1Handle[9], Yubi2Handle[9], Yubi3Handle[9];
	static int RareEnemy1Handle[5], RareEnemy2Handle[5], RareEnemy3Handle[5];
	static int SnakeEnemyHandle[2];

private:
	std::unique_ptr<Player> player_;
	//std::list<std::unique_ptr<Enemy>>enemys_;
	std::unique_ptr<EnemyPop> enemypop_;

	PlayerFootprints* playerFootprints_ = nullptr;
	PlayerLevelUp* playerLevelUp_ = nullptr;

	int frameImg;
	int frameYRadius = 410;
	int frameXRadius = 690;

	int playerBackImg;
	int playerBackYRadius = 160;
	int playerBackXRadius = 102;

	int backScreenImg;
	int backScreenYRadius = 720;
	int backScreenXRadius = 1280;

	int backScreenGrandImg = 0;

	// ������@�̃��\�[�X�n���h��
	int operationAttackImg;
	int operationDirectionImg;

	Score* score = nullptr;

	int siroGh;

};

