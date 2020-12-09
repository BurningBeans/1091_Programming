#include <iostream>
int expirence_needed(int , int);
int main()
{
    std::cout << "This program is to calculate the expirence required for levels in Minecraft, input any number less than 0 to exit." << std::endl;
    while(true)
    {
        int currentlevel;
        int targetlevel;
        std::cout << "Please input the current level : ";
        std::cin >> currentlevel;
        if(currentlevel<0)
            break;
        std::cout << "Please input the target level : ";
        std::cin >> targetlevel;
        if(targetlevel<0)
            break;
        if(currentlevel>=targetlevel)
        {
            std::cout << "Illegal input!" << std::endl;
            continue;
        }
        std::cout <<"# You need <" << expirence_needed(currentlevel, targetlevel) << "> expirence." <<std::endl;
    }
}
// ----------------------------------------------------------------
int expirence_needed(int a, int b)
{
    int totalexp = 0;
    while(a<b)
    {
        if(a <= 15)
        {
            totalexp += (2 * a + 7);
        }
        else if(a > 15 && a <= 30 )
        {
            totalexp += (5 * a - 38);
        }
        else
        {
            totalexp += (9 * a - 158);
        }
        a++;
    }
    return totalexp;
}
// ref:https://minecraft.gamepedia.com/Experience