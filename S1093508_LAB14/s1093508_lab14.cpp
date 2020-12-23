#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
void displayAccount(vector <int> &accNum, vector <string> &fName, vector <string> &lName, vector <double> &actBal,
vector <string> &dateV, vector <string> &timeV, vector <string> &validV, vector <string> &acTV, vector <bool> &kept)
// kept is a bool vector. You should use it to indicate whether an account is being merged and not included
// in the merged file.
{
    ifstream inFile("mergedAcount.txt", ios::in);
    if(!inFile)
    {
        cout << "Error: File does not exit. " << endl;
        exit(1);
    }
    else 
        inFile.close();
    for(int i=0; i<accNum.size() && kept[i]==true; i++)
    {
        cout<<accNum[i]<<" "<<fName[i]<<" "<<lName[i]<<" "<<actBal[i]<<" "<<acTV[i]<<" "<<dateV[i]<<" "<<timeV[i]<<" "<<validV[i]<<endl;
    }
}
int main(int argc, char**argv)
{
    if(argc < 2)
    {
        cout << "Wrong input !";
        exit(1);
    }
    ifstream inFile1(argv[1]);
    if(!inFile1)
    {
        cerr << "Wrong input!";
        exit(1);
    }
    ifstream inFile2(argv[2]);
    if(!inFile2)
    {
        cerr << "Wrong input!";
        exit(1);
    }
    if(inFile1&&inFile2)
        cout << "The files are correctly opened." << endl;
    vector <int> accountNumbers,accountNumbers2;
    int acN;
    vector <string> firstName,firstName2;
    string fN;
    vector <string> lastName,lastName2;
    string lN;
    vector <double> accountBalance,accountBalance2;
    double aB;
    vector <string> date,date2;
    string dt;
    vector <string> time,time2;
    string tm;
    vector <string> validity,validity2;
    string val;
    vector <bool> kept;
    int counter = 0;
    int counter2 = 0;
    while(inFile1 >> acN >> fN >> lN >> aB >> dt >> tm >> val)
    {
        accountNumbers.push_back(acN);
        firstName.push_back(fN);
        lastName.push_back(lN);
        accountBalance.push_back(aB);
        date.push_back(dt);
        time.push_back(tm);
        validity.push_back(val);
        counter++;
    }
    while(inFile2 >> acN >> fN >> lN >> aB >> dt >> tm >> val)
    {
        accountNumbers2.push_back(acN);
        firstName2.push_back(fN);
        lastName2.push_back(lN);
        accountBalance2.push_back(aB);
        date2.push_back(dt);
        time.push_back(tm);
        validity2.push_back(val);
        counter2++;
    }
    if(counter!=counter2)
    {
        cerr << "File size mismatch";
        exit(1);
    }
    for(int i = 0; i < counter; i++)
    {
        for(int j = 0; j < counter; j++)
        {
            
        }
    }
}
