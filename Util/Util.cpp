#include "DxLib.h"
#include "Util.h"
#include <stdlib.h>
#include <math.h>

/// <summary>
/// �ő�l��Ԃ��֐�
/// </summary>
float Max(float a, float b)
{
	if (a > b)return a;
	return b;
}

/// <summary>
/// �ŏ��l��Ԃ��֐�
/// </summary>
float Min(float a, float b)
{
	if (a < b)return a;
	return b;
}

/// <summary>
/// ������Ԃ��֐�
/// </summary>
int Sign(double a)
{
	if (a > 0)return 1;
	if (a < 0)return -1;

	return 0;
}

/// <summary>
/// �������]����֐�
/// </summary>
float Sign2(float a)
{
	return -a;
}

/// <summary>
/// �����_���֐�
/// </summary>
int GetRandomRange(int min, int max)
{
	return  rand() % ((max - min)) + min;
}

/// <summary>
/// �m����TRUE��Ԃ��֐�
/// </summary>
bool GetRandBool(float rate)
{
	int num = GetRandomRange(0, 100);
	if (num < rate) return true;
	return false;
}

/// <summary>
/// �ʓx�@����x���@�ɕϊ�����֐�
/// </summary>
float Angle(float radian)
{
	return radian * 360 / (2 * PI);
}

/// <summary>
/// �x���@����ʓx�@�ɕϊ�����֐�
/// </summary>
float Radian(float angle)
{
	return angle * (2 * PI) / 360;
}

/// <summary>
/// �~�̃I�u�W�F�N�g�Ƌ�`�̓�����͈͂�`�悷��֐�
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
/// �A�j���[�V�������񂷊֐�
/// </summary>
int Animetion(float& anime_timer, int fream_num, int anime_speed)
{
	float frame = 0;
	anime_timer++;
	frame = anime_timer / anime_speed;
	if (anime_timer >= fream_num * anime_speed - 1)anime_timer = 0;

	return frame;
}