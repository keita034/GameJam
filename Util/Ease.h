#pragma once
//’Ç‰Á
class Ease
{
public:
	double In(double start, double end, double time, double max_time);

	double Out(double start, double end, double time, double max_time);

	double InOut(double start, double end, double time, double max_time);

	double In_Back(double start, double end, double time, double max_time);

	double Out_Back(double start, double end, double time, double max_time);

	double InOut_Back(double start, double end, double time, double max_time);

	double Out_Bounce(double start, double end, double time, double max_time);

	double In_Bounce(double start, double end, double time, double max_time);

	double InOut_Bounce(double start, double end, double time, double max_time);

	//‰´‚Ì‚â‚Â
	double easeInOutCubic(double x);
	double easeInOutQuart(double x)

};

