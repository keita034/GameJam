#pragma once
#include"DxLib.h"
#include"Vec2.h"
#include"KeyBoardInput.h"
#include"Ease.h"
#include<cmath>

class Enemy;

class Player
{
private:

	//���W
	Vec2 pos;
	//1�t���[���O�̍��W
	Vec2 oldPos;
	//���a
	int radius = 32;
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
	int attackTime = 0;
	float attackFrameTime = 0;
	int maxAttackTime = 50 * 1;
	//�U���C���^�[�o��
	int attackInterval = 0;
	//�ő�U���C���^�[�o��
	int maxAttackInterval = 50 * 2;
	//�U������
	int attackDistance = 200;
	//�U���t���O
	bool attackFlag = false;
	//1�t���[���O�̍U���t���O
	bool oldAttackFlag = false;
	//�U�����a
	int attackRadius = 128;
	//�U���З�
	int attackPower = 1;
	//�U�����悤�Ƃ������W
	Vec2 attackBeginPos;
	//�U���̃��x��
	int level = 0;
	//�U���������Ɉ�ԋ߂��G�Ƃ̃x�N�g��
	Vec2 attackEnemyToPlayerVec;
	//�U�����x�����オ�鋗��
	float levelUpDistance = 96;
	//�U���̕����x�N�g��
	Vec2 attackDirectionVec;
	bool finalLevel = false;
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

	/// <summary>
	/// �U��
	/// </summary>
	void AttackUpdate(Vec2 vec);

	bool AttackTriggerFlag();
	void Attack();

private:

};

