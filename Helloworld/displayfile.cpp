#include <bits/stdc++.h>
using namespace std;
template<typename T>
void secondLargest(vector <T> vec, T &sLargest)
{
    T largest = *vec.begin();
    sLargest = -1;
    for(auto i : vec)
    {
        T temp;
        if(sLargest < i)
        {
            if(largest < i)
            {
                sLargest = largest;
                largest = i;
            }
            else
            {
                sLargest = i;
            }
        }
        
    }
}
int main(int argc, char**)
{
    int input;
    int secondL;
    vector<int> nums;
    while(cin>> input)
        nums.push_back(input);
    secondLargest(nums, secondL);
    cout << secondL;
}
