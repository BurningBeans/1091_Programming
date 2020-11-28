#include "bits/stdc++.h"
using namespace std;
//void removeDuplicateRecords(fstream , const string );
void createRecord(ofstream , string , string , double );
void displayFile();
int main()
{
    ifstream inclientFile("clientFile.txt");
    if(inclientFile)
    {
        cout << "Existing file content: " << endl;
        displayFile();
    }
    else
    {
        cout << "Creating a new file: " << endl;
    }
    /*
    ofstream outclientFile("clientFile.txt", ios::out);
    //End first step
    cout << "Enter first name, last name, and balance: " ;
    string firstName;
    string lastName;
    double actBalance;
    
    while(cin >> firstName >> lastName >> actBalance)
    {
        createRecord(outclientFile, firstName, lastName, actBalance);
    }
    */
}
/*
void removeDuplicateRecords(fstream &fptr, const string fileN);
{

}
*/
void createRecord(ofstream &fptr, string firstN, string lastN, double actBal)
{
    time_t currentTime;
    fptr << firstN << ' ' << lastN << ' ' << actBal << ' ' << ctime (&currentTime);
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
}