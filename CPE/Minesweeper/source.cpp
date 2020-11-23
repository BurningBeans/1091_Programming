#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    int row = 1;
    int column = 1;
    int fCount = 1;//field count
    string input;
    //vector <string> str;
    while (cin >> column >> row)
    {
        vector <string> str;
        if(row == 0 || column == 0)
        {
            break;
        }
        for(int i = 0; i < column; i++)//input string[i]
        {
            cin >> input;
            str.push_back(input);
            for(int j = 0; j < input.length(); j++)//exchange
            {
                if(str[i].at(j) == '.')
                {
                    str[i].at(j) = '0';
                }
            }
        }
        for(int i = 0; i < str.size(); i++)
        {
            for(int j = 0; j < str[i].length(); j++)
            {
                if(str[i].at(j) == '*')
                {
                    if(i > 0)//do up column
                    {
                        if(j>0&&str[i-1].at(j-1)!='*')
                        str[i-1].at(j-1)++;
                        if(str[i-1].at(j)!='*')
                        str[i-1].at(j)++;
                        if(j<str[i].length()&&str[i-1].at(j)!='*')
                        str[i-1].at(j+1)++;
                    }
                    if(j>0&&str[i].at(j-1)!='*')//mid
                    str[i].at(j-1)++;
                    //str[i].at(j)++; //DON'T DO THIS
                    if(j<str[i].length()&&str[i].at(j+1)!='*')
                    str[i].at(j+1)++;
                    if(i+1<str.size())//bot
                    {
                        if(j>0&&str[i+1].at(j-1)!='*')
                        str[i+1].at(j-1)++;
                        if(str[i+1].at(j)!='*')
                        str[i+1].at(j)++;
                        if(j<str[i].length()&&str[i+1].at(j+1)!='*')
                        str[i+1].at(j+1)++;
                    }
                }
            }
        }
        for(int i = 0; i < str.size(); i++)//put * back because I am an idiot
        {
            for(int j = 0; j < str[i].length(); j++)
            {
                if(str[i].at(j) < 47)
                {
                    str[i].at(j)='*';
                }
            }
        }
        //final output
        cout << "Field #" << fCount << ":" << endl;
        fCount++;
        for(int i = 0; i < str.size();i++)
        {
            cout << str[i] << endl;
        }
        //str.clear();//clear vector
    }
}
//ref: https://cpe.cse.nsysu.edu.tw/cpe/file/attendance/problemPdf/10189.pdf