#include <iostream>
#include <map>
#include <vector>
#include <string>


int main()
{
    long long input = 0;
    while(std::cin >> input)
    {
        if(input == 0)
        break;
        if(input%11)
        {
            std::cout << input << " is not a multiple of 11.\n";
        }
        else
        {
            std::cout << input << " is a multiple of 11.\n";
        }
    }
}

//ref:https://onlinejudge.org/external/109/10929.pdf