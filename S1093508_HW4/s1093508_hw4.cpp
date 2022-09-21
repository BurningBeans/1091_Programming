#include <bits/stdc++.h>
using std::cout;
double foo(int);
int main()
{
    cout << foo( 4 ) << '\n'; // 6
    cout << foo( 6 ) << '\n'; // 20
    cout << foo( 8 ) << '\n'; // 70
    cout << foo( 10 ) << '\n'; // 252
    cout << foo( 12 ) << '\n'; // 924
    cout << foo( 14 ) << '\n'; // 3432
    cout << foo( 16 ) << '\n'; // 12870
    cout << foo( 18 ) << '\n'; // 48620
    cout << foo( 20 ) << '\n'; // 184756
}

double foo(int num)
{
    double a = 1;
    double b;
    for(int i = 1; i <= num; i++)
    {
        a*=i;
        if(i == num/2)
        {
            b = a;
        }
    }
    return a/(b*b);
}
//https://cdn.discordapp.com/attachments/775313732641357841/780271149199130674/unknown.png