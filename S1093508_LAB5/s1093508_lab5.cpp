#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    string input;
    char temp;
    while(cin >> input)
    {
        if (input.length() == 1)
        {
            break;
        }
        for(int i = 0; i < input.length(); i++)
        {
            for(int j = i ; j < input.length(); j++)
            {
                if(input.at(i) < input.at(j))
                {
                    temp = input.at(j);
                    input.at(j) = input.at(i);
                    input.at(i) = temp;
                }
            }
        }
        cout << input << '\n';
    }
}