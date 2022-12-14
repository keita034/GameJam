#pragma once


class Sound {

public:

	static Sound* GetInstance();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 音の更新
	/// </summary>
	void Updata(int x);

	/// <summary>
	/// title処理
	/// </summary>
	void TitleUpdate();

	/// <summary>
	/// gameScene処理
	/// </summary>
	void gameSceneUpdate();

	/// <summary>
	/// resultScene処理
	/// </summary>
	void resultSceneUpdate();

	/// <summary>
	/// UI処理
	/// </summary>
	void SelectUpdate();
	void DecisionUpdate();

	/// <summary>
	/// levelUp処理
	/// </summary>
	void levelUpdata(int level_);

	/// <summary>
	/// AttackHit処理
	/// </summary>
	void AttackHitUpdata();

	/// <summary>
	/// damage
	/// </summary>
	void Damage();

	void Swing();


	void SetSound(int soundVolum);

private:

	Sound();
	~Sound() = default;

	int titleBGM = 0;
	int gameBGM = 0;
	int gameBGM2 = 0;
	int resultBGM = 0;
	int level1 = 0;
	int level2 = 0;
	int level3 = 0;
	int level4 = 0;
	int level5 = 0;

	int damage = 0;

	int attackHit = 0;

	int slsectSound = 0;
	int UIDecision = 0;

	int level = 0;

	int swing = 0;

	int volum = 200;
	int volum3 = 0;
	int volume = 0;
};