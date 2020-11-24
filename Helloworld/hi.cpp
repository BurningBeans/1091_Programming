#include <bits/stdc++.h>
using namespace std;
int main()
{
    int passLen;
    string passWd = "   ";
    srand(time(0));
    passLen = rand()%4+1;

    for (int i=0; i<passLen; i++)
    {
      passWd[i] = 'a' + rand()% 26;
    }
  std::cout << passWd << std::endl;
  for (int i = 0; i < passWd.length(); i++)
  {
     std::cout << passWd[i] << std::endl;
  }
}
