#include "iostream"
#include "string"
#include "vector"
using namespace std;
int main(int argc, char**)
{
    vector<int> nums;
    for(int i = 0; i < 10; i++)
    {
        nums.push_back(i);
    }
    for(auto i: nums)
        cout << i << " ";
    cout << endl;
    string str("Just testing auto.");
    for(auto i: str)
        cout << i ;
}