#pragma once
#include"DxLib.h"
#include"Player.h"

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
	Player* player_;

};

