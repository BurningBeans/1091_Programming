#include <iostream>
#include <ctime>
using namespace std;
int main()
{
    int max, min, temp;
    int n;
    while(cin >> min >> max)
    {
        int cyclelength, maxlength = 0;
        cout << min << " " << max << " ";
        if(min > max)//switch if min > max
        {
            temp = max;
            max = min;
            min = temp;
        }
        while(max > min)// do 3n+1,too lazy to set another varible for min to compare 
        {
            n = min;
            cyclelength = 1;//remember to reset before caculate other length...
            while(n!=1)
            {
                if(n % 2 == 1)
                {
                    n = n * 3 + 1;
                }
                else
                {
                    n /= 2;
                }
                cyclelength++;
            }
            min++;
            if(maxlength < cyclelength)
            {
                maxlength = cyclelength;
            }
        }
        cout << maxlength << "\n";
    }
}