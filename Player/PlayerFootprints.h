#pragma once


class PlayerFootprints {

public:


	/// <summary>
	/// ������
	/// </summary>
	void Initialize();

	/// <summary>
	/// ���t���[������
	/// </summary>
	void Update(int playerPosX ,int playerPosY);

	/// <summary>
	/// �`��
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
