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
	//�p�x
	float angle;
	//���a
	int radius = 30;
	//�X�N���[�����W
	Vec2 screen = { 640.0f,610.0f };
	int attackTime = 40;
	int attackInterval = 0;
	int maxAttackInterval = 50 * 10;
	bool attackFlag = false;


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

private:

	/// <summary>
	/// �U��
	/// </summary>
	void Attack();
};

