#include <bits/stdc++.h>
void removeDuplicateRecords(std::fstream  &, const std::string );
void createRecord(std::ofstream &, std::string , std::string , double );
void displayFile();
int main()
{
    std::ifstream inclientFile("clientFile.txt");
    std::ofstream outclientFile;
    std::fstream clientFile;
    std::string fileName = "clientFile.txt";
    std::string firstName;
    std::string lastName;
    double actBalance;
    if(inclientFile)//if there is existing file do...
    {
        std::cout << "Existing file content: " << std::endl;
        displayFile();
        outclientFile.open("clientFile.txt", std::ios::app);//Add to existing file
    }
    else
    {
        std::cout << "Creating a new file: " << std::endl;
        outclientFile.open("clientFile.txt", std::ios::out);//Creating new file
    }
    //End first step
    std::cout << "Enter first name, last name, and balance: " ;
    while(std::cin >> firstName >> lastName >> actBalance)
    {
        createRecord(outclientFile, firstName, lastName, actBalance);
    }
    outclientFile.close();//close after writing

    removeDuplicateRecords(clientFile, fileName);
    
    displayFile();
}
void removeDuplicateRecords(std::fstream &fptr, const std::string fileN)
{
    std::string str1;
    std::vector <std::string> strV1;  
    std::string str2;
    std::vector <std::string> strV2;
    double balance;
    std::vector <double> balances;
    std::string line;//read whole line
    time_t currentTime;
    time (&currentTime);
    std::vector <time_t> times;
    std::vector <int> dupLine;//store the number of lines that are duplicate
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
        for(int j = i+1; j < strV1.size(); j++)
        {
            if(strV1[i] == strV1[j] && strV2[i] == strV2[j])
            {
                dupLine.push_back(i);
                //cout << endl << j << endl;//debug line
            }
        }
    }
    fptr.close();
    //write to file
    std::ofstream outputFile(fileN);
    for(int i = 0 ; i < strV1.size(); i++)
    {
        bool skip = false;
        for(int j = 0; j < dupLine.size(); j++)
        {
            if(i == dupLine[j])//if printing line == any dupilcate line skip
            {
                skip = true;
                break;
            }
        }
        if(skip)
        {
            continue;
        }
        else
        outputFile << strV1[i] << ' ' << strV2[i] << ' ' << balances[i] << ' ' << times[i] << std::endl;
    }
    outputFile.close();
}
void createRecord(std::ofstream &fptr, std::string firstN, std::string lastN, double actBal)
{
    time_t currentTime;
    time (&currentTime);
    fptr << firstN << ' ' << lastN << ' ' << actBal << ' ' << currentTime << std::endl;
}
void displayFile()
{
    std::string str1;
    std::string str2;
    std::string fileN = "clientFile.txt";
    std::ifstream fptr;
    fptr.open(fileN);
    double balance;
    int numAct = 0;
    time_t transTime;
    if ( !fptr ) 
    {
        std::cerr << "File could not be opened" << std::endl;
        exit( 1 );
    } // end if
    while(fptr >> str1 >> str2 >> balance >> transTime) 
    {
        std::cout << std::setw(15) << str1 << ' ' << std::setw(15) << str2 << ' ' << std::setw(7) << balance << " " << ctime(&transTime);
        numAct++;
    }
    std::cout << "Number of records in the file " << fileN << ": " << numAct << std::endl;
    fptr.close();// I added to close the file after display
}