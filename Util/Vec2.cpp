#include "Vec2.h"
#include <math.h>

Vec2::Vec2()
{
	x = 0;
	y = 0;
}

Vec2::Vec2(float x, float y)
{
	this->x = x;
	this->y = y;
}

float Vec2::Length() const // �x�N�g���̒������v�Z���� const �����o�֐�
{
	return sqrt(x * x + y * y);
}
//
//float Vec2::LengthSquare() const // �x�N�g���̒����̓��
//{
//	return x * x + y * y;
//}
//
//float Vec2::Dot(const Vec2& other) const // ��������̃x�N�g���Ƃ̓���
//{
//	return x * other.x + y * other.y;
//}
//
//float Vec2::DistanceFrom(const Vec2& other) const    // ��������̃x�N�g���Ƃ̋���
//{
//	return sqrt((other.x - x) * (other.x - x) + (other.y - y) * (other.y - y));
//}
//
Vec2 Vec2::Normalized() const // ���K���i�������P�ɂ����j�x�N�g��
{
	return{ x / Length() , y / Length() };
}
//
//bool Vec2::isZero() const // �[���x�N�g���ł��邩
//{
//	return x == 0.0 && y == 0.0;
//}