#pragma once
#include "Box.h"
#include "Circle.h"
#include "Color.h"
#include "Vec2.h"
#include "Ease.h"
const char TITLE[] = "DxLib";
const int WIN_WIDTH = 1920;
const int WIN_HEIGHT = 1080;
const double PI = 3.141592653589;

enum Scene
{
	Title,
	Tutorial,
	Game,
	Result
};
extern int scene;

float Max(float a, float b);
float Min(float a, float b);
int Sign(double a);
float Sign2(float a);
int GetRandomRange(int min, int max);
bool GetRandBool(float rate);
float Angle(float radian);
float Radian(float angle);
void DrawObject(float x, float y, int r);
int Animetion(float& anime_timer, int frame, int anime_speed);