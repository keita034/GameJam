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
	void Update();

	/// <summary>
	/// �`��
	/// </summary>
	void Draw();

private:

	int x[30];
	int y[30];

	int pal[30];

	int FootArt[2];

};
