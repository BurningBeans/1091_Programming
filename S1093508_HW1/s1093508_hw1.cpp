#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int cases = 0;
    int num[100] = {0};
    int output[100] = {0};
    cin >> cases;
    for(int i = 0; i < cases; i++)
    {
        cin >> num[i];
        int POT = 2;//power of two
        while(num[i] >= POT)
        {
            output[i] = POT *= 2;
        }
    }
    for(int j = 0; j < cases; j++)
    cout << output[j] << "\n";
   /* EZ version
   int cases = 0;
   int n = 0;
   cin >> cases;
   for(int i = 0;cases > i; i++)
   {
       cin >> n;
       int j = 2;
       while(n>=j)
       {
           j*=2;
       }
       cout << j << "\n";
   }
   */
}
