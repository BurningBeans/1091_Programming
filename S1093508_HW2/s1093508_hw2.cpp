#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector <int> nums;
    int input = 0;
    int counter = 0;
    while(cin >> input)
    {
        if(input == -1)
        {
            break;
        }
        nums.push_back(input);
    }
    for(int i = 0; i < nums.size()-1 ; i++)
    {
        if(nums[i] < nums[i+1])
        {
            counter++;
        }
    }
    cout << counter;
}