#pragma once
#include "Util.h"
#include "DxLib.h"
#include"KeyBoardInput.h"
enum Pattern
{
	HeightUp,       // �c��
	HeightDown,     // �c��
	WidthL,         // ����
	WidthR,         // ���E
	UpperL,         // ���΂ߏ�
	UpperR,         // �E�΂ߏ�
	DiagonallyDownL,// ���΂߉�
	DiagonallyDownR,// �E�΂߉�
	Traking,        // �ǔ�
	Center,         //���S��ʂ�
};

class Enemy
{
public:
	// �C���X�^���X
	Enemy();
	~Enemy();

	// �����o�[�֐�

	// �������֐�
	void Initialize(Pattern pattern,Vec2 pos,float speed);

	// �X�V�֐�
	void Update(Vec2 playerNpos);

	// �`��֐�
	void Draw(Vec2 screen);

	bool IsDeath();

	Vec2 GetPos();

	int GetRadius();

	void Death();

	void HPSub(int subNum);

	void HPAdd(int addNum);

private:
	// �����o�[�ϐ�
	Vec2 pos_;
	float speed_;
	Vec2 velocity_;
	float radius_;
	Vec2 playerPos_;
	bool isDeath_;
	//�_���[�W�C���^�[�o��
	int damageInterval;
	int maxDamageInterval = 25;
	//�_���[�W�t���O
	bool damageFlag = true;
	// �G�l�~�[�̍s���p�^�[��
	Pattern pattern_;
	//�̗�
	int hp = 3;
};

