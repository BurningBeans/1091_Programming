#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    int count =1;
    while(cin>>n)
    {
        cout <<setw(4)<<setfill(' ')<<count++ <<". ";
        if(n==0)
        {
            cout << '0' << endl;
            continue;
        }
        int t;
        long long int interval;
        if(n >= (long long int)100000000000000)
        {
            t = 3;
            interval = 100000000000000;
        }
        else if (n >= (long long int)10000000)
        {
            t = 2;
            interval = 100000000;
        }
        else
        {
            t = 1;
            interval = 1;
        }
        
        for(int i = 0; i < t ;i++)
        {
            int deal_num = n / interval;
            n %= interval;
            if(deal_num/100000)
            {
                cout <<deal_num/100000 << " lakh";
                deal_num%=100000;
                if(deal_num!=0)
                cout<<" ";
            }
            if(deal_num/1000)
            {
                cout <<deal_num/1000 << " hajar";
                deal_num%=1000;
                if(deal_num!=0)
                cout<<" ";
            }
            if(deal_num/100)
            {
                cout << deal_num/100 << " shata";
                deal_num%=100;
                if(deal_num!=0)
                cout<<" ";
            }
            if(deal_num)
            {
                cout << n;
            }
            interval /= 10000000;
            if(i+1 < t)
            {
                cout << " kuti";
                if(n)
                {
                    cout << " ";
                }
            }
        }
        cout << endl;
    }
}