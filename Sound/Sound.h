#pragma once


class Sound {

public:

	Sound();

	/// <summary>
	/// ������
	/// </summary>
	void Initialize();

	/// <summary>
	/// ���̍X�V
	/// </summary>
	void Updata();

	/// <summary>
	/// title����
	/// </summary>
	void TitleUpdate();

	/// <summary>
	/// gameScene����
	/// </summary>
	void gameSceneUpdate(int soundVolum);

	/// <summary>
	/// UI����
	/// </summary>
	void SelectUpdate(int soundVolum);
	void DecisionUpdate(int soundVolum);

	/// <summary>
	/// levelUp����
	/// </summary>
	void levelUpdata(int level_,int soundVolum);

	/// <summary>
	/// AttackHit����
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