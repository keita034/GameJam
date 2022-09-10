#pragma once


class PlayerFootprints {

public:


	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update(int playerPosX ,int playerPosY);

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

private:

	int x[30];
	int y[30];

	int LeftFlag[30];
	int RightFlag[30];
	int FootFlag[30];
	int footTimer;

	int pal[30];

	int FootArt[2];

	int LeftORright = 0;

};
