#pragma once

class ModeChange
{
public:
	// �ʒu
	float x, y;

	// ���a
	int r;

	// �t���O
	bool isActive;

	// ���[�V�����̎���
	int motionTime;

	// ���[�V�������n�߂Ă���̎���
	int motionTimer;

	// �摜
	int particleGraph;

public:
	// �R���X�g���N�^
	ModeChange();

	// �f�X�g���N�^
	~ModeChange();

	// �X�V����
	void Update();

	// �`�揈��
	void Draw();

	// ����
	void Generate();

	// �摜�ǂݍ���
	void Load();

	//-----�Z�b�^�[-----//
	
	// �ʒu�̐ݒ�
	void SetPos(float x, float y);
};