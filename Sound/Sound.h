#pragma once


class Sound {

public:

	Sound();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 音の更新
	/// </summary>
	void Updata();

	/// <summary>
	/// title処理
	/// </summary>
	void TitleUpdate();

	/// <summary>
	/// gameScene処理
	/// </summary>
	void gameSceneUpdate(int soundVolum);

	/// <summary>
	/// UI処理
	/// </summary>
	void SelectUpdate(int soundVolum);
	void DecisionUpdate(int soundVolum);

	/// <summary>
	/// levelUp処理
	/// </summary>
	void levelUpdata(int level_,int soundVolum);

	/// <summary>
	/// AttackHit処理
	/// </summary>
	void AttackHitUpdata(int soundVolum);

	void SetSound(int soundVolum);

private:

	int titleBGM = 0;
	int gameBGM = 0;
	int gameBGM2 = 0;
	int level1 = 0;
	int level2 = 0;
	int level3 = 0;
	int level4 = 0;
	int level5 = 0;

	int attackHit = 0;

	int slsectSound = 0;
	int UIDecision = 0;

	int level = 0;

	int swing = 0;

	int volum = 200;
	int volume = 0;
};