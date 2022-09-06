#include "Timer.h"

Timer timer;

Timer::Timer()
{
	StartTime = 0;
	NowTime = 0;
}

void Timer::ResetTimer()
{
	int flag = true;
	if (flag == true)
	{
		StartTime = GetNowHiPerformanceCount();
		flag = false;
	}
	else return;
}

LONGLONG Timer::GetSeconds()
{
	return (GetNowHiPerformanceCount() - StartTime) / 1000000;
}

LONGLONG Timer::GetMinutes()
{
	return (GetNowHiPerformanceCount() - StartTime) / 1000000 / 60;
}

LONGLONG Timer::GetHour()
{
	return (GetNowHiPerformanceCount() - StartTime) / 1000000 / 360;
}