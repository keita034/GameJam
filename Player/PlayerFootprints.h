#pragma once


class PlayerFootprints {

public:


	/// <summary>
	/// ‰Šú‰»
	/// </summary>
	void Initialize();

	/// <summary>
	/// –ˆƒtƒŒ[ƒ€ˆ—
	/// </summary>
	void Update(int playerPosX ,int playerPosY);

	/// <summary>
	/// •`‰æ
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
