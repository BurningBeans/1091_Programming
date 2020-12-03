#include <bits/stdc++.h>
int main()
{
    int input;
    while(std::cin >> input)
    {
        int counter = 1;
        while(input != 1)
        {
            if(input%2)
            {
                input = (input * 3) + 1;
            }
            else
            {
                input/=2;
            }
            counter++;
        }
        std::cout << counter << std::endl;
    }
}