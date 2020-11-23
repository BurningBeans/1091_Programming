#include <iostream>
#include <cmath>
using namespace std;
int main()
{    
    long long n = 0, temp = 0;
    long long kuti = 10000000, lakh = 100000, hajar = 1000, shata = 100;
    int digits = 1;
    while(cin >> n)
    {
        temp = n;
        while(temp/10)//digits counter
        {
            temp/=10;
            digits++;
        }
        if(n==0)
        {
            cout << n << endl;
            continue;
        }
        if(n/(kuti*kuti))
        {
            cout << n/(kuti*kuti) << " kuti ";
            n%=(kuti*kuti);
        }
        if(n/(kuti*lakh))
        {
            cout << n/(kuti*lakh) << " lakh ";
            n%=(kuti*lakh);
        }
        if(n/(kuti*hajar))
        {
            cout << n/(kuti*hajar) << " hajar ";
            n%=(kuti*hajar);
        }
        if(n/(kuti*shata))
        {
            cout << n/(kuti*shata) << " shata ";
            n%=(kuti*shata);
        }
        if(n/kuti)
        {
            cout << n/kuti << " kuti ";
            n%=kuti;
        }
        else if(digits>8)//always print kuti if digits larger than 8
        {
            cout << " kuti ";
        }
        if(n/lakh)
        {
            cout << n/lakh << " lakh ";
            n%=lakh;
        }
        if(n/hajar)
        {
            cout << n/hajar << " hajar ";
            n%=hajar;
        }
        if(n/shata)
        {
            cout << n/shata << " shata ";
            n%=shata;
        }
        if(n!=0)//print last two digit if not 0
        {
            cout << n << " ";
        }
        cout << endl;
    }
}