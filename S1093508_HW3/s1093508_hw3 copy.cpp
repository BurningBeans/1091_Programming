#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void swap(vector<int> &num)
{
    int temp;
    temp = num.back();
    num.back() = num.front();
    num.front() = temp;
}
bool reshape(vector<int> &num)
{
    int temp;
    for(int i = 0; i < num.size(); i++)
    {
        for(int j = i; j < num.size(); j++)
        {
            if(num[j]>num[i])
            {
                temp = num[i];
                num[i] = num[j];
                num[j] = temp;
                return true;
            }
        }
    }
    return false;

}
int main()
{
    vector<int> nums;
    int cases = 0;
    int input = 0;
    bool output = false;
    cin >> cases;
    for(int i = 0; i < cases; i++)
    {
        cin >> input;
        nums.push_back(input);
    }
    sort(nums.begin(),nums.end());
    while(reshape(nums))
    {
        int is1000 = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(is1000+nums[i] <= 1000)
            {
                is1000+=nums[i];
            }
        }
        if(is1000==1000)
        {
            output = true;
            break;
        }
    }
    if(output)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }


    /*
    while(next_permutation(nums.begin(),nums.end()))
    {
        int is1000 = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(is1000+nums[i] <= 1000)
            {
                is1000+=nums[i];
            }
        }
        if(is1000==1000)
        {
            output = true;
            break;
        }
    }
    if(output)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    */
}