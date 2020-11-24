#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N1,N2;
    while(cin >> N1 >> N2)
    {
        if(N1==0&&N2==0)
        {
            break;
        }
        cout << N1 + N2 << endl;
    }
}