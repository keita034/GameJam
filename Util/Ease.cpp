#include "Ease.h"
//’Ç‰Á
double Ease::In(double start, double end, double time, double max_time)
{
	time /= max_time;
	double move = end - start;
	return start + (move * time * time);
}

double Ease::Out(double start, double end, double time, double max_time)
{
	time /= max_time;
	double move = end - start;
	return start + (move * (1 - (1 - time) * (1 - time)));
}

double Ease::InOut(double start, double end, double time, double max_time)
{
	time /= max_time;
	double move = end - start;
	if (time < 0.5)
	{
		return start + (move * (2 * time * time));
	}
	else
	{
		return start + move * (1 - (((-2 * time + 2) * (-2 * time + 2)) / 2));
	}
}

double Ease::In_Back(double start, double end, double time, double max_time)
{
	time /= max_time;
	double move = end - start;
	double c1 = 1.70158;
	double c3 = (c1 + 1);
	return start + (move * (c3 * time * time * time - c1 * time * time));
}

double Ease::Out_Back(double start, double end, double time, double max_time)
{
	time /= max_time;
	double move = end - start;
	double c1 = 1.70158;
	double c3 = (c1 + 1);
	return start + (move * (1 + c3 * ((time - 1) * (time - 1) * (time - 1)) + c1 * ((time - 1) * (time - 1))));
}

double Ease::InOut_Back(double start, double end, double time, double max_time)
{
	time /= max_time;
	double move = end - start;
	double c1 = 1.70158;
	double c2 = c1 * 1.525;

	if (time < 0.5)
	{
		return start + move * ((((2 * time) * (2 * time)) * ((c2 + 1) * 2 * time - c2)) / 2);
	}
	else
	{
		return start + move * ((((2 * time - 2) * (2 * time - 2)) * ((c2 + 1) * (time * 2 - 2) + c2) + 2) / 2);
	}
}

double Ease::Out_Bounce(double start, double end, double time, double max_time)
{
	time /= max_time;
	double move = end - start;
	double n1 = 7.5625;
	double d1 = 2.75;
	if (time < 1 / d1) {
		return start + move * (n1 * time * time);
	}
	else if (time < 2 / d1) {
		return start + move * (n1 * (time -= 1.5 / d1) * time + 0.75);
	}
	else if (time < 2.5 / d1) {
		return start + move * (n1 * (time -= 2.25 / d1) * time + 0.9375);
	}
	else {
		return start + move * (n1 * (time -= 2.625 / d1) * time + 0.984375);
	}
}

double Ease::In_Bounce(double start, double end, double time, double max_time)
{
	time /= max_time;
	double move = end - start;
	double n1 = 7.5625;
	double d1 = 2.75;
	time = 1 - time;
	if (time < 1 / d1) {
		return start + move * (1 - (n1 * time * time));
	}
	else if (time < 2 / d1) {
		return start + move * (1 - (n1 * (time -= 1.5 / d1) * time + 0.75));
	}
	else if (time < 2.5 / d1) {
		return start + move * (1 - (n1 * (time -= 2.25 / d1) * time + 0.9375));
	}
	else {
		return start + move * (1 - (n1 * (time -= 2.625 / d1) * time + 0.984375));
	}

}

double Ease::InOut_Bounce(double start, double end, double time, double max_time)
{
	time /= max_time;
	double move = end - start;
	double n1 = 7.5625;
	double d1 = 2.75;
	if (time < 0.5)
	{
		time = 1 - time * 2;
		if (time < 1 / d1) {
			return start + move * ((1 - (n1 * time * time)) / 2);
		}
		else if (time < 2 / d1) {
			return start + move * ((1 - (n1 * (time -= 1.5 / d1) * time + 0.75)) / 2);
		}
		else if (time < 2.5 / d1) {
			return start + move * ((1 - (n1 * (time -= 2.25 / d1) * time + 0.9375)) / 2);
		}
		else {
			return start + move * ((1 - (n1 * (time -= 2.625 / d1) * time + 0.984375)) / 2);
		}
	}
	else
	{
		time = time * 2 - 1;
		if (time < 1 / d1) {
			return start + move * ((n1 * time * time) / 2 + 0.5);
		}
		else if (time < 2 / d1) {
			return start + move * ((n1 * (time -= 1.5 / d1) * time + 0.75) / 2 + 0.5);
		}
		else if (time < 2.5 / d1) {
			return start + move * ((n1 * (time -= 2.25 / d1) * time + 0.9375) / 2 + 0.5);
		}
		else {
			return start + move * ((n1 * (time -= 2.625 / d1) * time + 0.984375) / 2 + 0.5);
		}
	}
}
