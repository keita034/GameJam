#include "FireWorksRand.h"
#include "Util.h"
#include "DxLib.h"
#include <math.h>

FireWorksRand::FireWorksRand()
{
	// 位置
	pos.x = 0;
	pos.y = 0;

	vec.x = 0;
	vec.y = 0;

	// フラグ
	isActive = false;

	// パーティクルの数
	maxParticle = 100;

	// インスタンス化
	particle = new Particle[maxParticle];

	// 生成のタイマー
	timer = 0;
}

FireWorksRand::~FireWorksRand()
{
	delete[] particle;
}

void FireWorksRand::Generation(int displayTime)
{
	isActive = true;

	// 生成のタイマーをインクリメント
	timer++;

	if (timer >= 5)
	{
		for (int i = 0; i < maxParticle; i++)
		{
			if (particle[i].GetActive() == false)
			{
				// アングルをランダムで指定
				int angle = GetRandomRange(0, 360);

				// 形の指定
				particle[i].SetShape(particle->CIRCLE);

				// 半径をランダムで指定
				particle[i].SetRadius(20);

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

				break;
			}
		}
	}
}

void FireWorksRand::Update()
{
	// フラグがfalseならこの先を処理しない
	if (isActive == false) return;

	// パーティクルの更新処理
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
	// フラグがfalseならこの先を処理しない
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