#include <bits/stdc++.h>
using namespace std;
void removeDuplicateRecords(fstream  &, const string );
void createRecord(ofstream &, string , string , double );
void displayFile();
int main()
{
    ifstream inclientFile("clientFile.txt");
    ofstream outclientFile;
    fstream clientFile;
    string fileName = "clientFile.txt";
    string firstName;
    string lastName;
    double actBalance;
    if(inclientFile)//if there is existing file do...
    {
        cout << "Existing file content: " << endl;
        displayFile();
        outclientFile.open("clientFile.txt", ios::app);//Add to existing file
    }
    else
    {
        cout << "Creating a new file: " << endl;
        outclientFile.open("clientFile.txt", ios::out);//Creating new file
    }
    //End first step
    cout << "Enter first name, last name, and balance: " ;
    while(cin >> firstName >> lastName >> actBalance)
    {
        createRecord(outclientFile, firstName, lastName, actBalance);
    }
    outclientFile.close();//close after writing

    removeDuplicateRecords(clientFile, fileName);
    
    displayFile();
}
void removeDuplicateRecords(fstream &fptr, const string fileN)
{
    string str1;
    vector <string> strV1;  
    string str2;
    vector <string> strV2;
    double balance;
    vector <double> balances;
    string line;//read whole line
    time_t currentTime;
    time (&currentTime);
    vector <time_t> times;
    vector <int> dupLine;//store line that are duplicate
    fptr.open(fileN);
    while(fptr >> str1 >> str2 >> balance >> currentTime)//read line and compare
    {
        strV1.push_back(str1);
        strV2.push_back(str2);
        balances.push_back(balance);
        times.push_back(currentTime);
    }
    //find the duplicate line
    for(int i = 0; i < strV1.size(); i++)
    {
        for(int j = i; j < strV1.size(); j++)
        {
            if (j==i)
            {
                continue;
            }
            if(strV1[i] == strV1[j] && strV2[i] == strV2[j])
            {
                dupLine.push_back(j);
                //cout << endl << j << endl;//debug line
            }
        }
    }
    fptr.close();
    fptr.open(fileN,ios::in);
    for(int i = 0; i < strV1.size(); i++)
    {
        bool skip = false;
        for(int j = 0; j < dupLine.size();j++)
        {
            if(i==dupLine[j])
            {
                skip = true;
                break;
            }
        }
        if(skip)
        {
            continue;
        }
        fptr << strV1[i] << ' ' << strV2[i] << ' ' << balances[i] << ' ' << times[i] << endl;
    }
}
void createRecord(ofstream &fptr, string firstN, string lastN, double actBal)
{
    time_t currentTime;
    time (&currentTime);
    fptr << firstN << ' ' << lastN << ' ' << actBal << ' ' << currentTime << endl;
}
void displayFile()
{
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
    fptr.close();// I added to close the file
}