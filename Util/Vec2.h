#pragma once
struct Vec2
{
public:
	float x;
	float y;
public:
	Vec2();
	Vec2(float x, float y);
	float Length() const; // ベクトルの長さを計算する const メンバ関数
	//float LengthSquare()const; // ベクトルの長さの二乗
	//float Dot(const Vec2& other) const; // もう一方のベクトルとの内積
	//float DistanceFrom(const Vec2& other) const;    // もう一方のベクトルとの距離
	Vec2 Normalized() const; // 正規化（長さを１にした）ベクトル
	//bool isZero() const; // ゼロベクトルであるか
};