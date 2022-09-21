#include <iostream>
using namespace std;
int main()
{
    int N1,N2;
    while(true)
    {
        cin >> N1 >> N2;
        if(cin.eof())
        {
            break;
        }
        cout << N1 + N2 << endl;
    }
}