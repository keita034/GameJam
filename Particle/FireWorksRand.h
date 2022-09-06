#pragma once
#include "Particle.h"

class FireWorksRand
{
private:
	// �ʒu
	Vec2 pos;

	Vec2 vec;

	// �t���O
	bool isActive = false;

	// �p�[�e�B�N���̐�
	int maxParticle;

	// �\������
	int displayTime;

	// �\�����Ԃ��v������^�C�}�[
	int displayTimer;

	// �����̃^�C�}�[
	int timer;

	// �N���X
	Particle* particle;

public:
	// �R���X�g���N�^
	FireWorksRand();

	// �f�X�g���N�^
	~FireWorksRand();

	// �����֐�
	void Generation(int displayTime);

	// �X�V����
	void Update();

	// �`�揈��
	void Draw(int graph);

	//-----�Z�b�^�[-----//

	// �ʒu�̐ݒ�
	void SetPos(Vec2 pos);

	//-----�Q�b�^�[-----//

	// �ʒu�̎擾
	float GetPosX();
	float GetPosY();

	//�@�t���O�̎擾
	bool GetActive();
};