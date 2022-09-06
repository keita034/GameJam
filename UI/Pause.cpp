#include"Pause.h"
#include<math.h>




double Pause::easeInOutCubic(double x) {
	return x < 0.5 ? 4 * x * x * x : 1 - pow(-2 * x + 2, 3) / 2;
}

double Pause::easeInBack(double x) {
	const float c1 = 1.70158;
	const float c3 = c1 + 1;

	return c3 * x * x * x - c1 * x * x;
}

double Pause::easeInOutBack(double x) {
	const int c1 = 1.70158;
	const int c2 = c1 * 1.525;

	return x < 0.5
		? (pow(2 * x, 2) * ((c2 + 1) * 2 * x - c2)) / 2
		: (pow(2 * x - 2, 2) * ((c2 + 1) * (x * 2 - 2) + c2) + 2) / 2;
}

double Pause::easeInOutCirc(double x) {
	return x < 0.5
		? (1 - sqrt(1 - pow(2 * x, 2))) / 2
		: (sqrt(1 - pow(-2 * x + 2, 2)) + 1) / 2;
}