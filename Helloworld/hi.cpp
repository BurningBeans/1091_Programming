#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main()
{
    //string a ;
    //cin >> a;
    //cout << a.length();
    int a = 0;
    cin >> a;
    switch (a)
    {
    case 1:case 2:case 3:
        cout << "Hello";
        break;
    
    default:
        cout << "Nope";
        break;
    }

    /*
    while(cin >> a)
    {   
        if(a.length()==1)
        counter++;
        if(a.back()=='.')
        cout << a.length()-1 << " ";
        else
        cout << a.length() << " ";
    }
    cout << "\nCounter: " << counter;
    */
}
