#include "DxLib.h"
#include "Util.h"
#include <stdlib.h>
#include <math.h>

/// <summary>
/// 最大値を返す関数
/// </summary>
float Max(float a, float b)
{
	if (a > b)return a;
	return b;
}

/// <summary>
/// 最小値を返す関数
/// </summary>
float Min(float a, float b)
{
	if (a < b)return a;
	return b;
}

/// <summary>
/// 符号を返す関数
/// </summary>
int Sign(double a)
{
	if (a > 0)return 1;
	if (a < 0)return -1;

	return 0;
}

/// <summary>
/// 符号反転する関数
/// </summary>
float Sign2(float a)
{
	return -a;
}

/// <summary>
/// ランダム関数
/// </summary>
int GetRandomRange(int min, int max)
{
	return  rand() % ((max - min)) + min;
}

/// <summary>
/// 確率でTRUEを返す関数
/// </summary>
bool GetRandBool(float rate)
{
	int num = GetRandomRange(0, 100);
	if (num < rate) return true;
	return false;
}

/// <summary>
/// 弧度法から度数法に変換する関数
/// </summary>
float Angle(float radian)
{
	return radian * 360 / (2 * PI);
}

/// <summary>
/// 度数法から弧度法に変換する関数
/// </summary>
float Radian(float angle)
{
	return angle * (2 * PI) / 360;
}

/// <summary>
/// 円のオブジェクトと矩形の当たり範囲を描画する関数
/// </summary>
void DrawObject(float x, float y, int r)
{
	int ax = x - r;
	int ay = y - r;
	int bx = x + r;
	int by = y + r;
	DrawBox(ax, ay, bx, by, col.red, false);
	DrawCircle(x, y, r, col.white, true);
}

/// <summary>
/// アニメーションを回す関数
/// </summary>
int Animetion(float& anime_timer, int fream_num, int anime_speed)
{
	float frame = 0;
	anime_timer++;
	frame = anime_timer / anime_speed;
	if (anime_timer >= fream_num * anime_speed - 1)anime_timer = 0;

	return frame;
}