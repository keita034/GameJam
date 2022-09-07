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

private:
	// �����o�[�ϐ�
	Vec2 pos_;
	float speed_;
	Vec2 velocity_;
	float radius_;
	Vec2 playerPos_;
	bool isDeath_;
	// �G�l�~�[�̍s���p�^�[��
	Pattern pattern_;
};

