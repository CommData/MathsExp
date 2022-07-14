#include <iostream>
#include <iomanip>
using std::cout, std::cin, std::setprecision;

float fun(float x, float y){
    float f;
    f = x+y;
    return f;
}
int main()
{
//    cout << "SHIVAM SINGH\n07313302720\nCSE-4A\n";
    float a,b,x,y,h,t,k;
    cout << "\nEnter x0, y0, h, xn: ";
    cin >> a >> b >> h >> t;
    x = a;
    y = b;
    cout << "\n x \t y \n";
    while(x <= t){
        k = h*fun(x,y);
        y = y+k;
        x = x+h;
        cout << setprecision(3) << x << '\t' << setprecision(3) << y << '\n';
    }
    return 0;
}