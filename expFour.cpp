#include <iostream>
using namespace std;

float dydx(float x, float y){
    return ((x-y));
}
void rungekutta(float x0, float y0, float xn, float h){
    int n = (int)((xn-x0)/h);
    float k1, k2, k3, k4;
    for(int i = 0 ; i <= n ; i++){
        k1 = h*dydx(x0,y0);
        k2 = h*dydx(x0+0.5*h, y0+0.5*k1);
        k3 = h*dydx(x0+0.5*h, y0+0.5*k2);
        k4 = h*dydx(x0+h, y0+k3);
        y0 = y0+(1.0/6.0)*(k1+2*k2+2*k3+k4);
        x0 = x0+h;
        if((int)x0 == 1 || (int)x0 == 2){
            cout << "\nAt x = " << x0;
            cout << "\nk1 = " << k1 << "\nk2 = " << k2 << "\nk3 = " << k3 << "\nk4 = " << k4;
            cout << "\ny("<< x0 <<") = " << y0 << '\n';
        }
    }
}
int main()
{
    // cout << "SHIVAM SINGH\n07313302720\nCSE-4A\n";
    float x0{0}, y0{1}, xn{2}, h{0.2};
    rungekutta(x0,y0,xn,h);
    return 0;
}