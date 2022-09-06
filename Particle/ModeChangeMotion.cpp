#include "DxLib.h"
#include "ModeChangeMotion.h"

// �R���X�g���N�^
ModeChange::ModeChange()
{
	// �ʒu
	x = 0.0f, y = 0.0f;

	// ���a
	r = 48;

	// �t���O
	isActive = false;

	// ���[�V�������n�߂Ă���̎���
	motionTimer = 0;

	// ���[�V�������鎞��
	motionTime = 11;
}

// �f�X�g���N�^
ModeChange::~ModeChange()
{
	DeleteGraph(particleGraph);
}

// �X�V����
void ModeChange::Update()
{
	// �t���O��false�Ȃ炱�̌�̏��������Ȃ�
	if (!isActive) return;

	// �^�C�}�[���Z
	motionTimer++;

	switch (motionTimer)
	{
	case 1:
		r = 16;
		break;
	case 3:
		r = 32;
		break;
	case 5:
		r = 48;
		break;
	case 7:
		r = 32;
		break;
	case 9:
		r = 16;
		break;
	}

	// �w�肵�����ԃ��[�V��������������false�ɂ���
	if (motionTimer >= motionTime)
	{
		isActive = false;
		motionTimer = 0;
	}
}

// �`�揈��
void ModeChange::Draw()
{
	// �t���O��false�Ȃ炱�̌�̏��������Ȃ�
	if (!isActive) return;

	// �摜�`��
	SetDrawBlendMode(DX_BLENDMODE_ADD, 255);
	SetDrawBright(255, 255, 80);
	DrawExtendGraphF(x - r, y - r, x + r, y + r, particleGraph, true);
	DrawExtendGraphF(x - r - 10, y - r - 10, x + r + 10, y + r + 10, particleGraph, true);
	DrawExtendGraphF(x - r - 20, y - r - 20, x + r + 20, y + r + 20, particleGraph, true);
	DrawExtendGraphF(x - r - 30, y - r - 30, x + r + 30, y + r + 30, particleGraph, true);
	DrawExtendGraphF(x - r - 40, y - r - 40, x + r + 40, y + r + 40, particleGraph, true);
	SetDrawBright(255, 255, 255);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void ModeChange::Generate()
{
	this->x = x;
	this->y = y;
	isActive = true;
}

void ModeChange::Load()
{
	// �摜�ǂݍ���
	particleGraph = LoadGraph("Resources/particle.png");
}

void ModeChange::SetPos(float x, float y)
{
	this->x = x;
	this->y = y;
}