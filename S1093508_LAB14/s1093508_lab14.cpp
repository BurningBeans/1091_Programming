#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
void displayAccount(vector <int> &accNum, vector <string> &fName, vector <string> &lName, vector <double> &actBal, vector <string> &dateV, vector <string> &timeV, vector <string> &validV, vector <string> &acTV, vector <bool> &kept) 
// You must use the above vectors
// to store the sorted accounts. kept is a bool vector which indicates whether an account is merged and not included in the merged file.
{
    ifstream inFile("mergedAcount.txt", ios::in);
    if(!inFile)
    {
        cout << "Error: File does not exit. " << endl;
        exit(1);
    }
    else 
        inFile.close();

    int numActualAct=0;
    for(int i=0; i<accNum.size(); i++)
        if(kept[i]==true)
        {
            cout<<setw(8) << setfill('0') <<accNum[i]<< setfill(' ')<<setw(10)<<fName[i]<<setw(10)<<lName[i]<<" "<<setw(8)<<actBal[i]<< " "<<setw(10) << acTV[i]<<" "<<dateV[i]<<" " <<timeV[i]<<" "<<setw(8)<<validV[i]<<endl;
            numActualAct++;
        }
    cout << "Number of accounts: " << numActualAct << endl;
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
        accountNumbers.push_back(acN);
        firstName.push_back(fN);
        lastName.push_back(lN);
        accountBalance.push_back(aB);
        accountType.push_back(aT);
        date.push_back(dt);
        time.push_back(tm);
        validity.push_back(val);
        counter++;
        /*if read into different vector do below
        accountNumbers2.push_back(acN);
        firstName2.push_back(fN);
        lastName2.push_back(lN);
        accountBalance2.push_back(aB);
        accountType2.push_back(aT);
        date2.push_back(dt);
        time.push_back(tm);
        validity2.push_back(val);
        counter2++;
        */
    }
    /*
    if(counter!=counter2)
    {
        cerr << "File size mismatch";
        exit(1);
    }
    */
    vectorsort(accountNumbers, firstName, lastName, accountBalance, accountType, date, time ,validity);
    //display only, comment out if not used
    /*
    for(int i=0; i<counter; i++)
    {
        cout << accountNumbers[i] << ' ' << firstName[i] << ' ' << lastName[i] << ' ' << accountBalance[i] << ' ' << accountType[i] << ' ' << date[i] << ' ' << time[i] << ' ' << validity[i] << endl; 
    }
    cout << "Total account count: " << counter << endl;
    */
    vector<int>mergedacN;
    vector<string>mergedfN;
    vector<string>mergedlN;
    vector<double>mergedaB;
    vector<string>mergedaT;
    vector<string>mergeddt;
    vector<string>mergedtm;
    vector<string>mergedval;
    vector<bool>kept;
    bool duplicate;
    for(int i = 0; i < counter; i++)
    {
        duplicate = false;
        double sum = accountBalance[i];
        for(int j = 0; j < mergedacN.size(); j++)
        {
            
            if(accountNumbers[i]==mergedacN[j])
            {
                if(firstName[i]==mergedfN[j]&&lastName[i]==mergedlN[j]&&accountType[i]==mergedaT[j]&&validity[i]=="true"&&mergedval[j]=="true")
                {
                    //TODO: THIS IS BUGGED
                    //mergedaB[i]+=accountBalance[j];
                    sum = accountBalance[i]+mergedaB[j];
                    mergedaB[j]=sum;
                    if(date[i]>=mergeddt[j])
                    {
                        mergeddt[j]=date[i];
                        if(time[i]>=mergedtm[j])
                        {
                            mergedtm[j]=time[i];
                        }
                    }
                    duplicate = true;
                }
                else
                {
                    cout << "Inconsistent information found for account number: " << accountNumbers[i] << endl;
                }
                
            }
            
        }
        if(duplicate)
        {
            continue;
        }
        mergedacN.push_back(accountNumbers[i]);
        mergedfN.push_back(firstName[i]);
        mergedlN.push_back(lastName[i]);
        mergedaT.push_back(accountType[i]);
        mergedaB.push_back(sum);
        mergeddt.push_back(date[i]);
        mergedtm.push_back(time[i]);
        mergedval.push_back(validity[i]);
        kept.push_back(true);

    }
    /*
    for(int i=0; i<mergedacN.size(); i++)
    {
        cout << mergedacN[i] << ' ' << mergedfN[i] << ' ' << mergedlN[i] << ' ' << mergedaB[i] << ' ' << mergedaT[i] << ' ' << mergeddt[i] << ' ' << mergedtm[i] << ' ' << mergedval[i] << endl; 
    }
    cout << mergedacN.size() << endl;
    */
   ofstream outfile("mergedAcount.txt", ios::out);
   for(int i = 0; i < mergedacN.size(); i++)
   {
       outfile << mergedacN[i] << ' ' << mergedfN[i] << ' ' << mergedlN[i] << ' ' << mergedaT[i] << ' ' << mergedaB[i] << ' ' << mergeddt[i] << ' ' << mergedtm[i] << ' ' << mergedval[i] << ' ' << kept[i] << endl;
   }
   displayAccount(mergedacN,mergedfN,mergedlN,mergedaB,mergeddt,mergedtm,mergedval,mergedaT,kept);
}
