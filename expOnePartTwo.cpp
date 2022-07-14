#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;
#define EPSILON 0.001

double func(double x){
    return x+cos(x);
}
double derivFunc(double x){
    return 1-sin(x);
}
double newtonRapshon(double x){
    double h = func(x)/derivFunc(x);
    while(fabs(h)>=EPSILON){
        h = func(x)/derivFunc(x);
        x = x-h;
    }
    return x;
}
int main()
{
    cout << "SHIVAM SINGH\nENROLLMENT NO. 07313302720\nCLASS = CSE-4A\n";
    double x0 = 1,x;
    cout << "\nEnter equation is ==> " << "x+cos(x)\n";
    x = newtonRapshon(x0);
    cout << "\nRoot of the equation is == " << x << '\n' ;
    return 0;
}