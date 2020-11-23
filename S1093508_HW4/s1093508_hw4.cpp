#include <bits/stdc++.h>
using std::cout;
int foo(int);
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
int foo(int num)
{
    int a = 0;
    for(int i = 0; i < num/2; i++)
    {
        for(int j = 0; j < num; j++)
        {
            a+=j;
        }
    }
    return a;
}
