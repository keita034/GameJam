#pragma once
#include"DxLib.h"
#include"Vec2.h"
#include"KeyBoardInput.h"
#include<cmath>

class Player
{
private:
	//���W
	Vec2 pos;

	//���ʃx�N�g��
	//Vec2 front;

	//�X�s�[�h
	float speed = 5.0f;

	//�A�^�b�N�X�s�[�h
	float attackSpeed;

	//�t�B�[���h�T�C�Y
	Vec2 fieldSize = { 2560.0f ,1440.0f };
	Vec2 zero = { 0.0f,0.0f };

	//���ʃx�N�g���̏I�_
	Vec2 front;
	//���ʃx�N�g��
	Vec2 frontVec;
	//���ʃx�N�g���̐��K��
	Vec2 normFrontVec;

	float angle;

public:

	Player() = default;
	~Player() = default;

	/// <summary>
	/// ������
	/// </summary>
	void Initialize();

	/// <summary>
	/// �X�V����
	/// </summary>
	void Update();

	/// <summary>
	/// �`��
	/// </summary>
	void Draw();
};

