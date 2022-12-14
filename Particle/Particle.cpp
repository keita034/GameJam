#include "DxLib.h"
#include "Particle.h"
#include "Camera.h"
#include <math.h>

Particle::Particle()
{
	// 位置
	box.x = 0.0f, box.y = 0.0f;
	circle.x = 0.0f, circle.y = 0.0f;

	// 速度
	speed = 0.0f;

	// フラグ
	isActive = false;

	// 1Fごとに半径を拡縮する数値
	addRadius = 0.0f;

	// 形
	shape = 0;

	// 表示時間を計測するタイマー
	displayTimer = 0;

	// 表示時間
	MaxDisplayTime = 0;
}

Particle::~Particle()
{

}

void Particle::Initialize()
{
	// 位置
	box.x = 0.0f, box.y = 0.0f;
	circle.x = 0.0f, circle.y = 0.0f;

	// 速度
	speed = 0.0f;

	// フラグ
	isActive = false;

	// 1Fごとに半径を拡縮する数値
	addRadius = 0.0f;

	// 形
	shape = 0;

	// 表示時間を計測するタイマー
	displayTimer = 0;

	// 表示時間
	MaxDisplayTime = 0;
}

void Particle::Update()
{
	if (isActive == false) return;

	// 四角の場合の移動処理
	if (shape == BOX)
	{
		// 加算
		box.x += vec.x * speed;
		box.y += vec.y * speed;

		// 四角形の四点座標の初期化
		box.PointsInitialize();
	}

	// 丸の場合の移動処理
	else if (shape == CIRCLE)
	{
		// 加算
		circle.x += vec.x * speed;
		circle.y += vec.y * speed;

		// 半径の拡縮
		circle.radius += addRadius;
	}

	if (MaxDisplayTime != 0) displayTimer++;
	if (displayTimer > MaxDisplayTime)
	{
		isActive = false;
		displayTimer = 0;
	}
}

void Particle::Draw()
{
	if (isActive == false) return;

	// カメラ計算
	float ax = box.left + vec.x - camera.GetPosX();
	float ay = box.up + vec.y - camera.GetPosY();
	float bx = box.right + vec.x - camera.GetPosX();
	float by = box.down + vec.y - camera.GetPosY();

	float cx = circle.x - camera.GetPosX();
	float cy = circle.y - camera.GetPosY();

	// 種類別の描画
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - (255 / MaxDisplayTime) * displayTimer);
	if (shape == BOX) DrawBox(ax, ay, bx, by, col.white, false);
	if (shape == CIRCLE) DrawCircle(cx, cy, circle.radius, col.white, false);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void Particle::DrawGraphHandle(
	int r, int g, int b,
	int BlendNum, double ExRate,
	double Angle, int GraphHandle, bool FillFlag)
{
	if (isActive == false) return;

	// カメラ計算
	float ax = box.x - camera.GetPosX();
	float ay = box.y - camera.GetPosY();

	float cx = circle.x - camera.GetPosX();
	float cy = circle.y - camera.GetPosY();

	// 種類別の描画
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - (255 / MaxDisplayTime) * displayTimer);
	SetDrawBlendMode(DX_BLENDMODE_ADD, BlendNum);
	SetDrawBright(r, g, b);
	if (shape == BOX) DrawRotaGraph(ax, ay, ExRate, Angle, GraphHandle, FillFlag);
	if (shape == CIRCLE) DrawRotaGraph(cx, cy, ExRate, Angle, GraphHandle, FillFlag);
	SetDrawBright(255, 255, 255);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

}

void Particle::SetPos(Vec2& pos)
{
	if (shape == BOX)
	{
		box.x = pos.x;
		box.y = pos.y;
	}
	else if (shape == CIRCLE)
	{
		circle.x = pos.x;
		circle.y = pos.y;
	}
}

void Particle::SetSize(float width, float height)
{
	box.width = width;
	box.height = height;
}

void Particle::SetRadius(float radius)
{
	circle.radius = radius;
}

void Particle::SetVec(Vec2& vec)
{
	this->vec = vec;
}

void Particle::SetSpeed(float speed)
{
	this->speed = speed;
}

void Particle::SetActive(bool isActive)
{
	this->isActive = isActive;
}

void Particle::SetAddRadius(float addRadius)
{
	this->addRadius = addRadius;
}

void Particle::SetShape(int shape)
{
	this->shape = shape;
}

void Particle::SetMaxDisplayTime(float MaxDisplayTime)
{
	this->MaxDisplayTime = MaxDisplayTime;
}

float Particle::GetPosX()
{
	return circle.x;
}

float Particle::GetPosY()
{
	return circle.y;
}

float Particle::GetRadius()
{
	return circle.radius;
}

bool Particle::GetActive()
{
	return isActive;
}

float Particle::GetDisPlayTimer()
{
	return displayTimer;
}