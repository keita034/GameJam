#pragma once
#include "Util.h"
#include "DxLib.h"
#include"KeyBoardInput.h"
enum Pattern
{
	heightUp,       // �c��
	heightDown,     // �c��
	widthL,         // ����
	widthR,         // ���E
	upperL,         // ���΂ߏ�
	upperR,         // �E�΂ߏ�
	diagonallyDownL,// ���΂߉�
	diagonallyDownR,// �E�΂߉�
	traking         // �ǔ�
};

class Enemy
{
public:
	// �C���X�^���X
	Enemy();
	~Enemy();

	// �����o�[�֐�

	// �������֐�
	void Initialize(Pattern pattern,Vec2 pos,Vec2 speed);

	// �X�V�֐�
	void Update();

	// �`��֐�
	void Draw();
private:
	// �����o�[�ϐ�
	Vec2 pos_;
	Vec2 speed_;
	Vec2 playerPos_;

	// �G�l�~�[�̍s���p�^�[��
	Pattern pattern_;
};

