#include "iostream"
int main(){
    int i, j, k;
    while(std::cin >> i >> j >> k)
    {
        int temp;
        temp = i * j;
        int temp2;
        if(i/j)
        {
            temp2 = i / j;
        }
        else
        {
            std::cout << "Some result are not available!" << std::endl;
            continue;
        }
        int temp3;
        temp3 = j % k;
        std::cout << temp + temp2 + temp3 << std::endl;
    }
}