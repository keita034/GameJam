#include "FireWorks.h"
#include "Util.h"
#include "DxLib.h"
#include <math.h>

FireWorks::FireWorks()
{
	// �ʒu
	pos.x = 0;
	pos.y = 0;

	vec.x = 0;
	vec.y = 0;

	// �t���O
	isActive = false;

	// �p�[�e�B�N���̐�
	maxParticle = 25;

	// �C���X�^���X��
	particle = new Particle[maxParticle];
}

FireWorks::~FireWorks()
{
	delete[] particle;
}

void FireWorks::Generation(int displayTime)
{
	isActive = true;

	for (int i = 0; i < maxParticle; i++)
	{
		if (particle[i].GetActive() == false)
		{
			// �A���O���������_���Ŏw��
			int angle = GetRandomRange(0, 360);

			// �`�̎w��
			particle[i].SetShape(particle->CIRCLE);

			// ���a�������_���Ŏw��
			particle[i].SetRadius(GetRandomRange(8, 16));

			// �ʒu���w��
			particle[i].SetPos(pos);

			vec.x = cos(Radian(angle));
			vec.y = sin(Radian(angle));

			// �x�N�g���̎w��
			particle[i].SetVec(vec);

			// ���x�̎w��
			particle[i].SetSpeed(6);

			// �t���O�̐ݒ�
			particle[i].SetActive(true);

			// �\�����Ԃ̐ݒ�
			particle[i].SetMaxDisplayTime(displayTime);
		}
	}
}

void FireWorks::Update()
{
	// �t���O��false�Ȃ炱�̐���������Ȃ�
	if (isActive == false) return;

	// �p�[�e�B�N���̍X�V����
	for (int i = 0; i < maxParticle; i++)
	{
		if (particle[i].GetActive() == true)
		{
			particle[i].Update();
			if (!particle[i].GetActive()) isActive = false;
		}
	}
}

void FireWorks::Draw()
{
	// �t���O��false�Ȃ炱�̐���������Ȃ�
	if (isActive == false) return;

	for (int i = 0; i < maxParticle; i++)
	{
		particle[i].Draw();
	}
}

bool FireWorks::GetActive()
{
	return isActive;
}

void FireWorks::SetPos(Vec2 pos)
{
	this->pos = pos;
}

float FireWorks::GetPosX()
{
	return pos.x;
}

float FireWorks::GetPosY()
{
	return pos.y;
}