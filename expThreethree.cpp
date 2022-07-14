#include <iostream>
using namespace std;

float y(float x)
{
    return 1/(1+x*x);
}
float simpsons(float a, float b, float n){
    float h = (b-a)/n;
    float s = 0;

    for(int i = 0 ; i <= n ; i++){
        if(i == 0 || i == n) s = s+y(a+i*h);
        else if(i%3 == 0) s = s+2*y(a+i*h);
        else s = s+3*y(a+i*h);
        cout << "\nS" << i << '=' << y(a+i*h) << '\n';
    }
    return (3*h/8)*s;
}
int main(){
    cout << "SHIVAM SINGH\n07313302720\nCSE-4A\n";
    float x0{0}, xn{1};
    int n{6};
    cout <<"\nValue of integral is: " << simpsons(x0,xn,n); 
    return 0;
}