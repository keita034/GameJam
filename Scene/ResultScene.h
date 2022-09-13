#pragma once
#include "Util.h"
#include "MouseInput.h"

class ResultScene
{
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

	bool GetChangeTitle();

	bool GetChangeGame();

private:
	// �`��̃O���t�n���h��
	int flameHandle, resultBackHandle, resultKyaraHandle, resultKyaraFlameHandle;
	int resultAccessoriesHandle,resultMojiFontHandle,resultScoreFontHandle,resultMaxComboFontHandle;
	int resultButtonTitleHandle[2], flame1 = 1;
	int resultButtonReplay[2], flame2 = 1;

	bool changeTitle = false, changeGameScene = false;
};

