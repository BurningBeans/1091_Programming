#include <iostream>
#include <string>
template <typename T>
void findSecondLargest(T [], int, T &, int &);
int main()
{
    int casecount;
    std::cin >> casecount;
    std::string datatype;
    while(casecount--)
    {
        int casecount2;
        std::cin >> datatype;
        if(datatype == "int")
        {
            int anAry[10000];
            int secondLargest = 0;
            int loc;
            std::cin >> casecount2;
            for(int i = 0; i < casecount2; i++)
            {
                std::cin >> anAry[i];
            }
            findSecondLargest(anAry, casecount2, secondLargest, loc);
            if(loc == -1)
            std::cout << '#' << loc << std::endl;
            else
            std::cout << secondLargest << '\t' << loc << std::endl;
        }
        else if(datatype == "double")
        {
            double anAry[10000];
            double secondLargest = 0;
            int loc;
            std::cin >> casecount2;
            for(int i = 0; i < casecount2; i++)
            {
                std::cin >> anAry[i];
            }
            findSecondLargest(anAry, casecount2, secondLargest, loc);
            if(loc == -1)
            std::cout << '#' << loc << std::endl;
            else
            std::cout << secondLargest << '\t' << loc << std::endl;
        }
        else if(datatype == "string")
        {
            std::string anAry[10000];
            std::string secondLargest;
            int loc;
            std::cin >> casecount2;
            for(int i = 0; i < casecount2; i++)
            {
                std::cin >> anAry[i];
            }
            findSecondLargest(anAry, casecount2, secondLargest, loc);
            if(loc == -1)
            std::cout << '#' << loc << std::endl;
            else
            std::cout << secondLargest << '\t' << loc << std::endl;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}
template <typename T>
void findSecondLargest(T anAry[], int numElm, T &secondLargest, int &loc)
{
    T largest = anAry[0];
    bool found = false;
    for(int i = 0; i < numElm; i++)
    {
        if(anAry[i] > largest)
        {
            largest = anAry[i];
        }
    }
    for(int i = 0; i < numElm; i++)
    {
        if(largest == anAry[i])
        {
            continue;
        }
        if(anAry[i]>=secondLargest)// use >= because find it's last occurrence
        {
            secondLargest = anAry[i];
            loc = i;
            found = true;// if no second largest found = false;
        }
    }
    if(!found)
    {
        loc = -1;//set loc to -1
    }
}