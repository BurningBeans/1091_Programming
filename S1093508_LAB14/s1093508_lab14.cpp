#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
void displayAccount(vector <int> &accNum, vector <string> &fName, vector <string> &lName, vector <double> &actBal, vector <string> &acTV, vector <string> &dateV, vector <string> &timeV, vector <string> &validV,  vector <bool> &kept)
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
//----------------------------------------------------------------
//Do selection sort with all the element
void vectorsort(vector <int> &accNum, vector <string> &fName, vector <string> &lName, vector <double> &actBal, vector <string> &acTV, vector <string> &dateV, vector <string> &timeV, vector <string> &validV)
{
    for(int i = 0; i < accNum.size(); i++)
    {
        int max = i;
        for(int j = i+1; j < accNum.size(); j++)
        {
            if(accNum[max] > accNum[j])//swap '>' with '<' if you desired descending sort
                max = j;
        }
        swap(accNum[i],accNum[max]);
        swap(fName[i],fName[max]);
        swap(lName[i],lName[max]);
        swap(actBal[i],actBal[max]);
        swap(dateV[i],dateV[max]);
        swap(timeV[i],timeV[max]);
        swap(validV[i],validV[max]);
        swap(acTV[i],acTV[max]);
    }
}
//----------------------------------------------------------------
int main(int argc, char**argv)
{
    //-------------------------------
    //opening files
    if(argc < 2)
    {
        cout << "Wrong input !";
        exit(1);
    }
    ifstream inFile1(argv[1], ios::in);
    if(!inFile1)
    {
        cerr << "Wrong input!";
        exit(1);
    }
    ifstream inFile2(argv[2], ios::in);
    if(!inFile2)
    {
        cerr << "Wrong input!";
        exit(1);
    }
    if(inFile1&&inFile2)
        cout << "The files are correctly opened." << endl;
    //end of file openings
    //----------------------------------------------------------------
    vector <int> accountNumbers,accountNumbers2;
    int acN;
    vector <string> firstName,firstName2;
    string fN;
    vector <string> lastName,lastName2;
    string lN;
    vector <double> accountBalance,accountBalance2;
    double aB;
    vector <string> accountType,accountType2;
    string aT;
    vector <string> date,date2;
    string dt;
    vector <string> time,time2;
    string tm;
    vector <string> validity,validity2;
    string val;
    vector <bool> kept;
    int counter = 0;
    int counter2 = 0;
    //----------------------------------------------------------------
    //TODO: check is accountNumber exist, if not then push back all item. if accountNumber exist then compare them.
    while(inFile1 >> acN >> fN >> lN >> aB >> aT >> dt >> tm >> val)
    {
        accountNumbers.push_back(acN);
        firstName.push_back(fN);
        lastName.push_back(lN);
        accountBalance.push_back(aB);
        accountType.push_back(aT);
        date.push_back(dt);
        time.push_back(tm);
        validity.push_back(val);
        counter++;
    }
    while(inFile2 >> acN >> fN >> lN >> aB >> aT >> dt >> tm >> val)
    {
        accountNumbers2.push_back(acN);
        firstName2.push_back(fN);
        lastName2.push_back(lN);
        accountBalance2.push_back(aB);
        accountType2.push_back(aT);
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
    vectorsort(accountNumbers, firstName, lastName, accountBalance, accountType, date, time ,validity);
    //display only, comment out if not used
    /*
    for(int i=0; i<counter; i++)
    {
        cout << accountNumbers[i] << ' ' << firstName[i] << ' ' << lastName[i] << ' ' << accountBalance[i] << ' ' << date[i] << ' ' << time[i] << ' ' << validity[i] << endl; 
    }
    cout << "Total account count: " << counter << endl;
    */
}
