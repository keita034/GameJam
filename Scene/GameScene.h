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
	/// ‰Šú‰»
	/// </summary>
	void Initialize();

	/// <summary>
	/// –ˆƒtƒŒ[ƒ€ˆ—
	/// </summary>
	void Update();

	/// <summary>
	/// •`‰æ
	/// </summary>
	void Draw();

private:
	std::unique_ptr<Player> player_;
	std::list<std::unique_ptr<Enemy>>enemys_;

};

