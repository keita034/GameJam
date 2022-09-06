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

float Vec2::Length() const // ベクトルの長さを計算する const メンバ関数
{
	return sqrt(x * x + y * y);
}
//
//float Vec2::LengthSquare() const // ベクトルの長さの二乗
//{
//	return x * x + y * y;
//}
//
//float Vec2::Dot(const Vec2& other) const // もう一方のベクトルとの内積
//{
//	return x * other.x + y * other.y;
//}
//
//float Vec2::DistanceFrom(const Vec2& other) const    // もう一方のベクトルとの距離
//{
//	return sqrt((other.x - x) * (other.x - x) + (other.y - y) * (other.y - y));
//}
//
Vec2 Vec2::Normalized() const // 正規化（長さを１にした）ベクトル
{
	return{ x / Length() , y / Length() };
}
//
//bool Vec2::isZero() const // ゼロベクトルであるか
//{
//	return x == 0.0 && y == 0.0;
//}