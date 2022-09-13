#pragma once
#include"DxLib.h"
#include"Player.h"
#include"Enemy.h"
#include"Collision.h"
#include<memory>
#include<list>
#include"EnemyPop.h"

class GameScene
{
public:
	GameScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	

private:
	std::unique_ptr<Player> player_;
	//std::list<std::unique_ptr<Enemy>>enemys_;
	std::unique_ptr<EnemyPop> enemypop_;

	int frameImg;
	int frameYRadius = 410;
	int frameXRadius = 690;

	int playerBackImg;
	int playerBackYRadius = 160;
	int playerBackXRadius = 102;

	int backScreenImg;
	int backScreenYRadius = 720;
	int backScreenXRadius = 1280;

};

