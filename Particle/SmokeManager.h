#pragma once
#include<memory>
#include<list>
#include"Smoke.h"

class SmokeManager {

public:
	static SmokeManager* GetInstance();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// スモークの更新
	/// </summary>
	void Updata(Vec2 pos);

	/// <summary>
	/// Draw処理
	/// </summary>
	void Draw(Vec2 screen);

	/// <summary>
	/// 生まれた時のスモーク処理
	/// </summary>
	void MakeSmoke();

	/// <summary>
	/// 死んだときのスモーク処理
	/// </summary>
	void deathSmoke(Vec2 pos);

	bool IsDeath();

private:
	SmokeManager();
	~SmokeManager() = default;

	std::list<std::unique_ptr<Smoke>>smokes_;

	int siroGh = 0;

	bool isDeath;
};