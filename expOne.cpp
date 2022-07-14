#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;
#define EPSILON 0.001

double func(double x)
{
	return x * x * x - 2 * x - 5;
}
double derivFunc(double x)
{
	return 3 * x * x - 2;
}
double newtonRapshon(double x)
{
	double h = func(x) / derivFunc(x);
	while (fabs(h) >= EPSILON)
	{
		h = func(x) / derivFunc(x);
		x = x - h;
	}
	return x;
}
int main()
{
	// cout << "SHIVAM SINGH\nENROLLMENT NO. 07313302720\nCLASS = CSE-4A\n";
	double x0 = 3, x;
	cout << "\nEnter equation is ==> "
		 << "x^3-2x-5\n";
	x = newtonRapshon(x0);
	cout << "\nRoot of the equation is == " << x << '\n';
	return 0;
}
