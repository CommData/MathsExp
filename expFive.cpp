#include<iostream>
#include<cmath>  
#include<iomanip>
using namespace std;

float f(float(x),float(y))
{
return (y-x);
}

int main()
{
int n,i,j;
float h;
// cout << "SHIVAM SINGH\n07313302720\nCSE-4A\n";
cout<<"Aim : To solve a differential equation by Second Order Runge-Kutta's Method"<< endl;
cout<<"Given Equtaion is dy/dx = y - x "<<endl;

cout<<"Enter the number of solutions "<<endl;
cin>>n;

cout<<"Enter The Value of Step Size "<<endl;
cin>>h;

long double y[n],x[n],k[n][n];

cout<<"Enter the value of x0 "<<endl;
cin>>x[0];
cout<<"Enter The Value of y0 "<<endl;
cin>>y[0];

for(i=1;i<=n;i++)
 {
 x[i]=x[i-1]+h;
 }

cout << "Solution of the given differential equation by Second Order Runga Kutta Method is " << endl;

for(j=1;j<=n;j++)
 {
 k[1][j] = h*f(x[j-1],y[j-1]);
 cout << "K[1] = "<< k[1][j] << "\t";
 k[2][j] = h*f(x[j-1]+h,y[j-1]+k[1][j]);
 cout<< "K[2] = " << k[2][j] << "\n"; 
 y[j] = y[j-1] + ((k[1][j]+k[2][j])/2);
 cout << "y[" << h*j << "] = " << setprecision(5) << y[j] << endl;
 }
 
return 0;
}