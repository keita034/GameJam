#pragma once
struct Vec2
{
public:
	float x;
	float y;
public:
	Vec2();
	Vec2(float x, float y);
	float Length() const; // �x�N�g���̒������v�Z���� const �����o�֐�
	//float LengthSquare()const; // �x�N�g���̒����̓��
	//float Dot(const Vec2& other) const; // ��������̃x�N�g���Ƃ̓���
	//float DistanceFrom(const Vec2& other) const;    // ��������̃x�N�g���Ƃ̋���
	Vec2 Normalized() const; // ���K���i�������P�ɂ����j�x�N�g��
	//bool isZero() const; // �[���x�N�g���ł��邩
};