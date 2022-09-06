#pragma once
struct Box
{
public:
	float x;
	float y;
	float width;
	float height;
	float left;
	float right;
	float up;
	float down;
public:
	Box();
	Box(float x, float y);
	Box(float x, float y, float width, float height);
	void PointsInitialize(); // 四点の座標の初期化
	void PointsUpdate(); // 四点の座標の更新
};