#include <iostream>
#include <map>
#include <set>
using namespace std;
int main()
{
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
}