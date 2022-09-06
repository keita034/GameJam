#include "FireWorksRand.h"
#include "Util.h"
#include "DxLib.h"
#include <math.h>

FireWorksRand::FireWorksRand()
{
	// �ʒu
	pos.x = 0;
	pos.y = 0;

	vec.x = 0;
	vec.y = 0;

	// �t���O
	isActive = false;

	// �p�[�e�B�N���̐�
	maxParticle = 100;

	// �C���X�^���X��
	particle = new Particle[maxParticle];

	// �����̃^�C�}�[
	timer = 0;
}

FireWorksRand::~FireWorksRand()
{
	delete[] particle;
}

void FireWorksRand::Generation(int displayTime)
{
	isActive = true;

	// �����̃^�C�}�[���C���N�������g
	timer++;

	if (timer >= 5)
	{
		for (int i = 0; i < maxParticle; i++)
		{
			if (particle[i].GetActive() == false)
			{
				// �A���O���������_���Ŏw��
				int angle = GetRandomRange(0, 360);

				// �`�̎w��
				particle[i].SetShape(particle->CIRCLE);

				// ���a�������_���Ŏw��
				particle[i].SetRadius(20);

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

				break;
			}
		}
	}
}

void FireWorksRand::Update()
{
	// �t���O��false�Ȃ炱�̐���������Ȃ�
	if (isActive == false) return;

	// �p�[�e�B�N���̍X�V����
	for (int i = 0; i < maxParticle; i++)
	{
		if (particle[i].GetActive() == true)
		{
			particle[i].Update();
			//if (!particle[i].GetActive()) isActive = false;
		}
	}
}

int angle = 0;

void FireWorksRand::Draw(int graph)
{
	// �t���O��false�Ȃ炱�̐���������Ȃ�
	if (isActive == false) return;

	angle++;
	if (angle >= 360) angle = 0;

	for (int i = 0; i < maxParticle; i++)
	{
		//particle[i].Draw(col.orange, true);
		particle[i].DrawGraphHandle(251, 164, 23, 96, 0.25, angle/2, graph, true);
	}

	//DrawGraph(pos.x, pos.y, graph, true);
}

bool FireWorksRand::GetActive()
{
	return isActive;
}

void FireWorksRand::SetPos(Vec2 pos)
{
	this->pos = pos;
}

float FireWorksRand::GetPosX()
{
	return pos.x;
}

float FireWorksRand::GetPosY()
{
	return pos.y;
}