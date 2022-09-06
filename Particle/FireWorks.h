#pragma once
#include "Particle.h"

class FireWorks
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

	// �N���X
	Particle* particle;

public:
	// �R���X�g���N�^
	FireWorks();

	// �f�X�g���N�^
	~FireWorks();

	// �����֐�
	void Generation(int displayTime);

	// �X�V����
	void Update();

	// �`�揈��
	void Draw();

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