#include <bits/stdc++.h>
using namespace std;
//void makefile();
//void read();
void createRecord(ofstream &fptr, string firstN, string lastN, double actBal)
{
    time_t currentTime;
    fptr << firstN << ' ' << lastN << ' ' << actBal << ' ' << currentTime;
}
int main()
{
    ofstream fptr("test.txt",ios::out);
    string f;
    string l;
    double actBal;
    cin >> f >> l >> actBal;
    createRecord(fptr, f , l ,actBal);
}

/*
void makefile()
{
    string name;
    string number;
    ofstream outfile("test.txt", ios::out);
    if(!outfile)
    {
        cerr << "File could not be opened! " << endl;
        exit(1);
    }
    cout << "Enter number :";
    while(cin >> name >> number)
    {
        outfile << name << ' ' << number << endl;
    }
}
void read()
{
    string name;
    string number;
    int lines = 0;
    string fileN = "test.txt";
    ifstream infile;
    infile.open(fileN);
    if ( !infile ) 
    {
        cerr << "File could not be opened" << endl;
        exit( 1 );
    } // end if
    while(infile >> name >> number)
    {
        cout << name << ' ' << number << endl;
        lines++;
    }
    cout << "Total lines : " << lines;
}
*/
/*
    string str1;
    string str2;
    string fileN = "clientFile.txt";
    ifstream fptr;
    fptr.open(fileN);
    double balance;
    int numAct = 0;
    time_t transTime;
    if ( !fptr ) 
    {
        cerr << "File could not be opened" << endl;
        exit( 1 );
    } // end if
    while(fptr >> str1 >> str2 >> balance >> transTime) 
    {
        cout << setw(15) << str1 << ' ' << setw(15) << str2 << ' ' << setw(7) << balance << " " << ctime(&transTime);
        numAct++;
    }
    cout << "Number of records in the file " << fileN << ": " << numAct << endl;
*/