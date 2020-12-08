#include <bits/stdc++.h>
using namespace std;
int main()
{
	string str("Hello World!");
    for(auto i : str)
    cout << i << ' ';


	
  /*
    ofstream outCilentFile( "clientFile.txt", ios::out);
    if(!outCilentFile)
    {
        cerr << "File could not be opened! " << endl;
        exit(1);
    }
    cout << "Enter Student ID, name and score." << endl;
    cout << "Enter end-of-file to end input. \n";
	time_t currentTime;
	time (&currentTime);
    string firstName;
    string lastName;
    double actBalance;
    while (cin >> firstName >> lastName >> actBalance)
    {
        outCilentFile << firstName << ' ' << lastName << ' ' << actBalance << ' ' << currentTime << endl;
        cout << "Next : " << endl;
    }
  */
  /*
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
  */
}
