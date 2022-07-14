#include <iostream>
using namespace std;

float y(float x){
    return 1/(1+x*x);
}
float trapezoidal(float a, float b, float n){
    float h = (b-a)/n;
    float s = y(a)+y(b);

    for(int i = 1 ; i <= n ; i++){
        s = s+2*y(a+i*h);
        cout <<"\nS" <<i << '=' << y(a+i*h) << '\n';
    }
    return (h/2)*s;
}
int main()
{
//    cout << "SHIVAM SINGH\n07313302720\nCSE-4A";
    float x0=0;
    float xn=1;
    int n = 6;
    float result = trapezoidal(x0,xn,n);
    cout << trapezoidal(x0,xn,n);
    cout << "\nthe value of integral is: " << result << '\n'; 
    return 0;
}