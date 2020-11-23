#include<iostream>
#include<string>
using namespace std;
int main()
{
    int cases = 0;
    cin >> cases;
    for(int i = 0; i < cases; i++)
    {
        string input;
        string output;
        int length = 0;
        cin >> input;
        for(int i = 0; i < input.length(); i++)
        {
            if(input[i]>=65&&input[i]<=90)
            {
                for(int j = 0; j < input[i+1]-48; j++)
                {
                    
                }
            }
        }
    }
}
//ref:https://onlinejudge.org/external/115/p11541.pdf