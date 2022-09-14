#pragma once


class Sound {

public:

	static Sound* GetInstance();

	/// <summary>
	/// ‰Šú‰»
	/// </summary>
	void Initialize();

	/// <summary>
	/// ‰¹‚ÌXV
	/// </summary>
	void Updata();

	/// <summary>
	/// titleˆ—
	/// </summary>
	void TitleUpdate();

	/// <summary>
	/// gameSceneˆ—
	/// </summary>
	void gameSceneUpdate();

	/// <summary>
	/// resultSceneˆ—
	/// </summary>
	void resultSceneUpdate();

	/// <summary>
	/// UIˆ—
	/// </summary>
	void SelectUpdate();
	void DecisionUpdate();

	/// <summary>
	/// levelUpˆ—
	/// </summary>
	void levelUpdata(int level_);

	/// <summary>
	/// AttackHitˆ—
	/// </summary>
	void AttackHitUpdata();

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

	int attackHit = 0;

	int slsectSound = 0;
	int UIDecision = 0;

	int level = 0;

	int swing = 0;

	int volum = 200;
	int volum3 = 0;
	int volume = 0;
};