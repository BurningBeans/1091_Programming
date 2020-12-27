#include <iostream>
using namespace std;
void mySwap( int *a, int *b )//Swap using XOR
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}
int main()
{
    int a = 5;
    int b = 7;
    mySwap(&a,&b);
    cout << a << '\n' << b << '\n';
}