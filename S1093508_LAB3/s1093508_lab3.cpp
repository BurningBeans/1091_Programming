#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    double weight = 0, height = 0, BMI = 0;
    int headcount = 0, USL = 0, HSUW = 0, SUW = 0, UW = 0, NW = 0, OW = 0, OB = 0, SOB = 0, HSOB = 0, ULL = 0;
    do
    {
        cin >> weight >> height;
        BMI = weight/pow(height,2);
        
        if(weight < 20 || weight > 200 || height < 0.9 || height > 2.5)
        {
            continue;
        }
        else
        {

            if(BMI > 70)
            {
                //cout <<"# Your BMI level is Unreasonably large \n";
                ULL++;
            }
            else if(BMI >= 60)
            {
                //cout << "# Your BMI level is Highly severely obese \n";
                HSOB++;
            }
            else if (BMI >= 50)
            {
                //cout << "# Your BMI level is Severely obese \n";
                SOB++;
            }
            else if (BMI >= 40)
            {
                //cout << "# Your BMI level is Obese \n";
                OB++;
            }
            else if (BMI >= 25)
            {
                //cout << "# Your BMI level is Overweight \n";
                OW++;
            }
            else if (BMI >= 18.5)
            {
                //cout << "# Your BMI level is Normal \n";
                NW++;
            }
            else if (BMI >= 16)
            {
                //cout << "# Your BMI level is Underweight \n";
                UW++;
            }
            else if (BMI >= 15)
            {
                //cout << "# Your BMI level is Severely underweight \n";
                SUW++;
            }
            else if (BMI >= 10)
            {
                //cout << "# Your BMI level is Highly severely underweight \n";
                HSUW++;
            }
            else
            {
                //cout << "# Your BMI level is Unreasonably underweight \n";
                USL++;
            }
            //headcount at end of loop
            headcount++;
        }
    }while (weight > 0 || height > 0);
    cout << "USL\tHSUW\tSUW\tUW\tNW\tOW\tOB\tSOB\tHSOB\tULL\n";
    cout << setw(3) << USL << "\t" << setw(4) << HSUW << "\t" << setw(3) << SUW << "\t" << setw(2) << UW << "\t" << setw(2) << NW << "\t" << setw(2) << OW << "\t" << setw(2) << OB << "\t" << setw(3) << SOB << "\t" << setw(4) << HSOB << "\t" << setw(3) << ULL << "\n";
    cout << "Headcount = " << headcount << "\n";
    system("pause");
    return 0;
}