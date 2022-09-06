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
	void PointsInitialize(); // �l�_�̍��W�̏�����
	void PointsUpdate(); // �l�_�̍��W�̍X�V
};