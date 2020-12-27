#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int main()
{
    int a;
    vector<int>num;
    while(cin>>a)
        num.push_back(a);
    cout <<"*num.begin() is :"<< *num.begin() << endl;
    cout<<"*num.end() is : " <<*num.end() << endl;
    cout <<"last element should be :"<< *num.rbegin()<<endl;
    cout <<"prev of end :" <<*prev(num.end())<<endl;
    reverse(num.begin(), num.end());
    cout << "All the element are : ";
    for(auto i: num)
    {
        cout << i << ' ';
    }
    cout << endl;

    /*
    int n;
    cin >> n;
    while(n!=0)
    {
        map<set<int>,int> classes;
        set <int> courses;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<5; j++)
            {
                int input;
                cin >> input;
                courses.insert(input);
            }
            if(classes.find(courses)==classes.end())
            {
                classes[courses] = 1;
            }
            else
            {
                classes[courses]++;
            }
        }
        int max = -1;
        for(map<set<int>,int>::iterator it = classes.begin(); it != classes.end();)
        {
            if(it-> second > max)
            {
                max = it -> second;
            }
        }
        int sum = 0;
        for(map<set<int>,int>::iterator it = classes.begin(); it != classes.end();)
        {
            if(it-> second == max)
            {
                sum += it -> second;
            }
        }
        cout << sum <<endl;
        cin >> n;
    }
    */
}