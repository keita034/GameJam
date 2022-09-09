#pragma once
//�ǉ�
class Ease
{
public:
	static double In(double start, double end, double time, double max_time);

	static double Out(double start, double end, double time, double max_time);

	static double InOut(double start, double end, double time, double max_time);

	static double In_Back(double start, double end, double time, double max_time);

	static double Out_Back(double start, double end, double time, double max_time);

	static double InOut_Back(double start, double end, double time, double max_time);

	static double Out_Bounce(double start, double end, double time, double max_time);

	static double In_Bounce(double start, double end, double time, double max_time);

	static double InOut_Bounce(double start, double end, double time, double max_time);

	//���̂��
	static double easeInOutCubic(double x);
	static double easeInOutQuart(double x);
	static double easeInBack(double x);

};

