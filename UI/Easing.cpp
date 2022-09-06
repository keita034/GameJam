#include"Easing.h"
#include<math.h>








double Easing::easeInOutCubic(double x) {
	return x < 0.5 ? 4 * x * x * x : 1 - pow(-2 * x + 2, 3) / 2;
}

double Easing::easeInBack(double x) {
	const float c1 = 1.70158;
	const float c3 = c1 + 1;

	return c3 * x * x * x - c1 * x * x;
}

double Easing::easeInOutBack(double x) {
	const int c1 = 1.70158;
	const int c2 = c1 * 1.525;

	return x < 0.5
		? (pow(2 * x, 2) * ((c2 + 1) * 2 * x - c2)) / 2
		: (pow(2 * x - 2, 2) * ((c2 + 1) * (x * 2 - 2) + c2) + 2) / 2;
}

double Easing::easeInOutCirc(double x) {
	return x < 0.5
		? (1 - sqrt(1 - pow(2 * x, 2))) / 2
		: (sqrt(1 - pow(-2 * x + 2, 2)) + 1) / 2;
}