#pragma once
#include "DxLib.h"
class Timer
{
private:
	LONGLONG StartTime;
	LONGLONG NowTime;
public:
	Timer();
	void ResetTimer();
	LONGLONG GetSeconds();
	LONGLONG GetMinutes();
	LONGLONG GetHour();
};
extern Timer timer;