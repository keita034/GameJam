#include "DxLib.h"
#include "ModeChangeMotion.h"

// コンストラクタ
ModeChange::ModeChange()
{
	// 位置
	x = 0.0f, y = 0.0f;

	// 半径
	r = 48;

	// フラグ
	isActive = false;

	// モーションし始めてからの時間
	motionTimer = 0;

	// モーションする時間
	motionTime = 11;
}

// デストラクタ
ModeChange::~ModeChange()
{
	DeleteGraph(particleGraph);
}

// 更新処理
void ModeChange::Update()
{
	// フラグがfalseならこの後の処理をしない
	if (!isActive) return;

	// タイマー加算
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

	// 指定した時間モーションが動いたらfalseにする
	if (motionTimer >= motionTime)
	{
		isActive = false;
		motionTimer = 0;
	}
}

// 描画処理
void ModeChange::Draw()
{
	// フラグがfalseならこの後の処理をしない
	if (!isActive) return;

	// 画像描写
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
	// 画像読み込み
	particleGraph = LoadGraph("Resources/particle.png");
}

void ModeChange::SetPos(float x, float y)
{
	this->x = x;
	this->y = y;
}