#include "HitPar.h"
#include "Util.h"
#include <math.h>
#include "DxLib.h"

HitPar::HitPar()
{
	flag = false;
	pos.x = 0;
	pos.y = 0;
	vec.x = 0;
	vec.y = 0;
	max = 5;
	particle = new Particle[max];
}

HitPar::~HitPar()
{
	delete[] particle;
}

void HitPar::Initialize()
{
	flag = false;
	pos.x = 0;
	pos.y = 0;
	for (int i = 0; i < max; i++)
	{
		particle[i].Initialize();
	}
}

void HitPar::Update()
{
	if (flag == false) return;

	int count = 0;
	int angle = 0;
	for (int i = 0; i < max; i++)
	{
		if (particle[i].GetActive() == false && flag == true)
		{
			count++;
			int size = GetRandomRange(2, 6);
			particle[i].SetShape(particle->BOX);
			particle[i].SetSize(size, size);
			particle[i].SetPos(pos);

			// â∫îºâ~ÇÃéû
			if (vec.y >= 0)
			{
				angle = GetRandomRange(Angle(acos(vec.x)) - 90, Angle(acos(vec.x)) + 90);
			}
			// è„îºâ~ÇÃéû
			else if (vec.y < 0)
			{
				angle = GetRandomRange(-Angle(acos(vec.x)) - 90, -Angle(acos(vec.x)) + 90);
			}

			vec.x = cos(Radian(angle));
			vec.y = sin(Radian(angle));

			particle[i].SetVec(vec);
			particle[i].SetSpeed(2.5);
			particle[i].SetActive(true);
			particle[i].SetMaxDisplayTime(15);

			if (count == max)
			{
				count = 0;
				break;
			}
		}
	}

	for (int i = 0; i < max; i++)
	{
		if (particle[i].GetActive() == true)
		{
			particle[i].Update();

			if (particle[i].GetDisPlayTimer() >= 15) flag = false;
		}
	}
}

void HitPar::Draw()
{
	if (flag == false) return;

	for (int i = 0; i < max; i++)
	{
		particle[i].Draw();
	}

	DrawFormatString(0, 20, 0xffffff, "%d", flag);
}

void HitPar::SetFlag(bool flag)
{
	this->flag = flag;
}

bool HitPar::GetFlag()
{
	return flag;
}

void HitPar::SetPos(Vec2 pos)
{
	this->pos = pos;
}

void HitPar::SetVec(Vec2 vec)
{
	this->vec = vec;
}