#include <iostream>
#include <string>
using namespace std;
int main()
{
    string input;
    char key[]={'q','w','e','r','t','y','u','i','o','p','[',']','a','s','d','f','g','h','j','k','l',';',/*''',*/'z','x','c','v','b','n','m',',','.','/'};
    while(cin >> input)
    {
        for (int i = 0; i < input.size(); i++)//uppercase to lowercase
        {
            if(input.at(i)>='A'&&input.at(i)<='Z')
            {
                input.at(i)+=32;
            }
            for(int j = 0; j < 32; j++)//exchange key
            {
                if(input.at(i) == key[j])
                {
                    input.at(i) = key[j-2];
                }
            }
            cout << input.at(i);
        }
    }
}
//ref:https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=14&page=show_problem&problem=1163