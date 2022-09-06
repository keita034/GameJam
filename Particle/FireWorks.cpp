#include "FireWorks.h"
#include "Util.h"
#include "DxLib.h"
#include <math.h>

FireWorks::FireWorks()
{
	// 位置
	pos.x = 0;
	pos.y = 0;

	vec.x = 0;
	vec.y = 0;

	// フラグ
	isActive = false;

	// パーティクルの数
	maxParticle = 25;

	// インスタンス化
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
			// アングルをランダムで指定
			int angle = GetRandomRange(0, 360);

			// 形の指定
			particle[i].SetShape(particle->CIRCLE);

			// 半径をランダムで指定
			particle[i].SetRadius(GetRandomRange(8, 16));

			// 位置を指定
			particle[i].SetPos(pos);

			vec.x = cos(Radian(angle));
			vec.y = sin(Radian(angle));

			// ベクトルの指定
			particle[i].SetVec(vec);

			// 速度の指定
			particle[i].SetSpeed(6);

			// フラグの設定
			particle[i].SetActive(true);

			// 表示時間の設定
			particle[i].SetMaxDisplayTime(displayTime);
		}
	}
}

void FireWorks::Update()
{
	// フラグがfalseならこの先を処理しない
	if (isActive == false) return;

	// パーティクルの更新処理
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
	// フラグがfalseならこの先を処理しない
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