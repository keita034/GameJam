#pragma once
#include"Ease.h"
#include <DxLib.h>
#include"KeyBoardInput.h"


class Pause
{

private:
	//�֐��̐���

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

	/// <summary>
	/// �C�[�W���O������
	/// </summary>
	void Move();

	/// <summary>
	/// ��`�̓����蔻��őI��
	/// </summary>
	void MenuSelect();

public:
	// �摜�Ȃǂ̃��\�[�X�f�[�^�̕ϐ��錾�Ɠǂݍ���
	int MenuGh;
	int SoundGh;
	int BackGh;
	int Back2Gh;

	Ease* ease_ = nullptr;

	//�����o�ϐ�
	int timer[5];
	int MaxTimer[5];

	float menuX = -100;
	float menuY = 20;
	float menuXFinal;

	float backX = -100;
	float backY = 100;

	float soundX = -100;
	float soungY = 300;

	int isPause = 0;

	int isEscTrigger = 0;

};