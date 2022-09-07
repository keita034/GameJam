#pragma once
#include"Ease.h"
#include <DxLib.h>
#include"KeyBoardInput.h"


class Pause
{

public:
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

	//Esc��������0�o��1�߂�
	void SetIsEsc(int isEsc);
	//x�ɂ�0������
	void TimerReset(int x);

	int GetPause();

private:
	// �摜�Ȃǂ̃��\�[�X�f�[�^�̕ϐ��錾�Ɠǂݍ���
	int MenuGh;
	int SoundGh;
	int BackGh;
	int Back2Gh;
	int ResetGh;
	int TitleGh;

	Ease* ease_ = nullptr;

	//�����o�ϐ�
	float timer[5];
	float MaxTimer[5];

	float menuX = -300;
	float menuY = 20;
	float menuXFinal;

	float soundX = -300;
	float soundY = 170;
	float soundXFinal;

	float ResetX = -300;
	float ResetY = 170 + 64;
	float ResetXFinal;

	float TitleX = -300;
	float TitleY = 170 + 128;
	float TitleXFinal;

	float backX = -300;
	float backY = 500;
	float backXFinal;


	int isPause = 3;
	int isEscTrigger = 0;

	int isHit = 0;
	int isHit2 = 0;
	int isHit3 = 0;
	int isHit4 = 0;

	int pal = 255;
	int pal2 = 255;
	int pal3 = 255;
	int pal4 = 255;
};