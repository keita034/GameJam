#pragma once
#include"DxLib.h"
#include"Vec2.h"
#include"KeyBoardInput.h"
#include"Ease.h"
#include<cmath>

class Player
{
private:

	//���W
	Vec2 pos;
	//���a
	int radius = 64;
	//�p�x
	float angle = 0.0f;
	//�X�s�[�h
	float speed = 5.0f;

	//���ʃx�N�g���̏I�_
	Vec2 front;
	//���ʃx�N�g��
	Vec2 frontVec;
	//���ʃx�N�g���̐��K��
	Vec2 normFrontVec;
	
	//�t�B�[���h�T�C�Y
	Vec2 fieldSize = { 2560.0f ,1440.0f };
	Vec2 zero = { 0.0f,0.0f };

	//�X�N���[�����W
	Vec2 screen = { 640.0f,360.0f };

	//�U������
	int attackTime = 50 * 1;
	//�U���C���^�[�o��
	int attackInterval = 0;
	//�ő�U���C���^�[�o��
	int maxAttackInterval = 50 * 2;
	//�U������
	int attackDistance = 64;
	//�U���t���O
	bool attackFlag = false;
	//�U�����a
	int attackRadius = 150;
	//�U���З�
	int attackPower = 1;
	Vec2 attackBeginPos;
	int level = 0;

	//�̗�
	int hp = 3;

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

	Vec2 GetPos();
	int GetRadius();

	Vec2 GetScreen();

	bool GetAttackFlag();

	int GetAttackRadius();

	void HPSub(int subNum);

	void HPAdd(int addNum);

	int GetAttackPower();

private:

	/// <summary>
	/// �U��
	/// </summary>
	void Attack();
};

