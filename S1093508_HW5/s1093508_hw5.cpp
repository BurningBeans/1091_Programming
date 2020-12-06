#include <iostream>
using std::cout;
template <typename T>
void mySwap(T &a, T &b)
{
    auto t = a;
    a = b;
    b = t;
}
/* function overloading
void mySwap(double &a, double &b)
{
    double t = a;
    a = b;
    b = t;
}
void mySwap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}
*/
int main()
{
 int a = 3;
 int b = 6;
 double x = 3.2;
 double y = 3.7;
 mySwap( a, b );
 mySwap( x, y );
 cout << a << ' ' << b << ' '; // 6 3
 cout << x << ' ' << y << '\n'; // 3.7 3.2
}