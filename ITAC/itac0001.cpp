#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    while(cin >> str)
    {
        for(int i = 0; i < str.length(); i++)
        {
            str[i]+=13;
            if(str[i] > 'Z')
            {
                str[i]= ('A'- 1) + (str[i] - 'Z');
            }
        }
        cout << str << endl;
    }
}