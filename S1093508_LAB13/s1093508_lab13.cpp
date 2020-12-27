#include "iostream"
#include "fstream"
#include "string"
#include "iomanip"
#include "vector"
#include "set"
//----------------------------------------------------------------
using std::string;
using std::vector;
using std::set;
using std::cout;
using std::endl;
using std::cin;
using std::setw;
using std::setprecision;
using std::fixed;
using std::ifstream;
//----------------------------------------------------------------
const int maxstudents = 200;
const int maxtests = 10;
//----------------------------------------------------------------
void readGrades(ifstream &, int [][maxtests], int &, int &);
int minimun(const int [] [maxtests], int, int);
int maximun(const int [] [maxtests], int, int);
double arverage(const int [] [maxtests],int, int, string);
void ouptutGrades(const int [] [maxtests], int, int);
void outputBarChart(const int[] [maxtests], int, int);
void outputVertBarChart(const int[] [maxtests], int, int);
//------------------------------
int main(int argc, char *[])
{
    string fileName;
    cout << "Please enter the file name : ";
    cin >> fileName;
    ifstream inStudentGrades(fileName,std::ios::in);
    if(!inStudentGrades)
    {
        std::cerr << "File could not be opened";
        return 1;
    }
    int students, tests;
    int studentsGrades[maxstudents][maxtests];
    readGrades(inStudentGrades,studentsGrades,students,tests);
    inStudentGrades.close();
    ouptutGrades(studentsGrades, students, tests);
    outputBarChart(studentsGrades, students, tests);
    outputVertBarChart(studentsGrades, students, tests);
}
void readGrades(ifstream &inFile, int studentGrades[ ][maxtests], int &numStudents, int &numTests)
{
    cout << "The numbers of students : ";
    inFile >> numStudents;
    cout << numStudents << endl;
    cout << "The number of tests : ";
    inFile >> numTests;
    cout <<  numTests << endl;
    //Create grades table
    int grades;
    for(int i = 0; i < numStudents; i++)
    {
        for(int j = 0; j < numTests;j++)
        {
            inFile >> grades;
            studentGrades[i][j] = grades;
        }
    }
}
int minimun(const int grades[][maxtests], int students, int tests) 
{
    int lowest = 999;
    for(int i = 0; i < students; i++)//each students
    {
        if(grades[i][tests] < lowest)
        lowest = grades[i][tests];
    }
    return lowest;
}
int maximun(const int grades[][maxtests], int students, int tests) 
{
    int highest = 0;
    for(int i = 0; i < students; i++)//each students
    {
        if(grades[i][tests] > highest)
        {
            highest = grades[i][tests];
        }
    }
    return highest;
}
double average(const int grades[][maxtests],int students, int tests, string type)//TODO: This function is not finished yet.
{
    int sum = 0;
    if(type=="students")//average of students score
    {
        for(int i = 0; i < tests; i++)
        {
            sum += grades[students][i];
        }
        return (double)sum/tests;
    }
    else if(type=="tests")//average of tests score
    {
        for(int i = 0; i <students; i++)
        {
            sum += grades[i][tests];
        }
        return (double)sum/students;
    }
    else
    {
        std::cerr << "Error for this function";
        exit(1);
    }
}
void ouptutGrades(const int grades[] [maxtests], int students, int tests)
{
    cout << "The grades are:" << endl;
    cout << "            ";
    for(int i = 0; i < tests; i++)
    {
        cout << "Test" << setw(3) << i+1 << ' ';
        if(i == tests-1)
        {
            cout << "Average" << endl;
        }
    }
    // content of array
    cout << "            ";
    for(int i = 0; i <= tests; i++)
    {
        cout << "-------" <<' ';
    }
    cout << endl;
    set<double>averagescores;// using set because easy to find the largest and smallest value
    for(int i = 0; i < students; i++)
    {
        cout << "Student" << setw(4) << i+1 << ' ';
        for(int j = 0; j < tests; j++)
        {
            cout << setw(7) << grades[i][j] << ' ';
        }
        cout << setw(7) << setprecision(2) << fixed << average(grades, i, tests, "students");// setprecision and fixed to make it print out decimal 2 places
        averagescores.insert(average(grades,i,tests, "students"));//put all averages into set
        cout << endl;
    }
    cout << "            ";
    for(int i = 0; i <= tests; i++)
    {
        cout << "-------" <<' ';
    }
    cout << endl;
    // Average of all tests
    cout << "Average     ";
    vector <double> scores;
    for(int i = 0; i < tests; i++)
    {
        cout << setw(7) << (int)average(grades, students, i, "tests") << ' ';
        scores.push_back(average(grades, students, i, "tests"));
        if(i == tests-1)
        {
            double total = 0;
            for(auto j : scores)//useful in range loop
            {
                total += j;
            }
            cout << setw(7) << setprecision(2) << fixed << (double)total/tests << endl;
        }
    }
    //print minimun
    cout << "minimun     ";
    for(int i = 0; i < tests; i++)
    {
        cout << setw(7) << minimun(grades,students,i) << ' ';
        if(i == tests-1)
        {
            double total = 0;
            cout << setw(7) << setprecision(2) << fixed << *averagescores.begin() << endl;
        }
    }
    //print maximun
    cout << "maximun     ";
    for(int i = 0; i < tests; i++)
    {
        cout << setw(7) << maximun(grades,students,i) << ' ';
        if(i == tests-1)
        {
            double total = 0;
            cout << setw(7) << setprecision(2) << fixed << *averagescores.rbegin() << endl;//or using *std::prev(averagescores.end())
        }
    }
}
void outputBarChart(const int grades[] [maxtests], int students, int tests)
{
    cout << "Overall grades distribution (Horizontal bar chart):" << endl;
    cout << "---------------------------------------------------" << endl;
    int scores[12] = {0};
    for (int i = 0; i < students; i++)
    {
        for(int j = 0; j < tests; j++)
        {
            for(int k = 11; k > 0; k--)
            {
                if(grades[i][j]==0)
                {
                    scores[0]++;
                    break;
                }
                if(grades[i][j]>=((k-1)*10))
                {
                    scores[k]++;
                    break;
                }
            }
            /* stupid way to store counters
            if(grades[i][j] >= 100)
                scores[11]++;
            else if (grades[i][j] >= 90)
                scores[10]++;
            else if (grades[i][j] >= 80)
                scores[9]++;
            else if (grades[i][j] >= 70)
                scores[8]++;
            else if (grades[i][j] >= 60)
                scores[7]++;
            else if (grades[i][j] >= 50)
                scores[6]++;
            else if (grades[i][j] >= 40)
                scores[5]++;
            else if (grades[i][j] >= 30)
                scores[4]++;
            else if (grades[i][j] >= 20)
                scores[3]++;
            else if (grades[i][j] >= 10)
                scores[2]++;
            else if (grades[i][j] > 0)
                scores[1]++;
            else
                scores[0]++;
            */
        }
    }
    //end of the counter loop
    for(int i = 0; i < 12; i++)
    {
        if(i == 0)
            cout << setw(6) << "0:";
        if(i == 1)
            cout << setw(6) << "1-9:";
        if(i == 2)
            cout << setw(6) << "10-19:";
        if(i == 3)
            cout << setw(6) << "20-29:";
        if(i == 4)
            cout << setw(6) << "30-39:";
        if(i == 5)
            cout << setw(6) << "40-49:";
        if(i == 6)
            cout << setw(6) << "50-59:";
        if(i == 7)
            cout << setw(6) << "60-69:";
        if(i == 8)
            cout << setw(6) << "70-79:";
        if(i == 9)
            cout << setw(6) << "80-89:";
        if(i == 10)
            cout << setw(6) << "90-99:";
        if(i == 11)
            cout << setw(6) << "100:";
        //
        cout << ' ';
        if(scores[i]==0)
        {
            cout << endl;
            continue;
        }
        for(int j = 0; j < scores[i]; j++)
        {
            cout << '*';
        }
        cout << scores[i] <<endl;
    }
}
void outputVertBarChart(const int grades[] [maxtests], int students, int tests)
{
    cout << "Overall grade distribution (Vertical bar chart):" << endl;
    cout << "------------------------------------------------" << endl;
    //same thing as the function above
    int scores[12] = {0};
    for (int i = 0; i < students; i++)
    {
        for(int j = 0; j < tests; j++)
        {
            for(int k = 11; k > 0; k--)
            {
                if(grades[i][j]==0)
                {
                    scores[0]++;
                    break;
                }
                if(grades[i][j]>=((k-1)*10))
                {
                    scores[k]++;
                    break;
                }
            }
        }
    }
    /*
    for (int i = 0; i < students; i++)
    {
        for(int j = 0; j < tests; j++)
        {
            if(grades[i][j] >= 100)
                scores[11]++;
            else if (grades[i][j] >= 90)
                scores[10]++;
            else if (grades[i][j] >= 80)
                scores[9]++;
            else if (grades[i][j] >= 70)
                scores[8]++;
            else if (grades[i][j] >= 60)
                scores[7]++;
            else if (grades[i][j] >= 50)
                scores[6]++;
            else if (grades[i][j] >= 40)
                scores[5]++;
            else if (grades[i][j] >= 30)
                scores[4]++;
            else if (grades[i][j] >= 20)
                scores[3]++;
            else if (grades[i][j] >= 10)
                scores[2]++;
            else if (grades[i][j] > 0)
                scores[1]++;
            else
                scores[0]++;
        }
    }
    */
    //end of for loop
    cout << setw(6) << "0" << setw(6) << "1-9" << setw(6) << "10-19" << setw(6) << "20-29" << setw(6) << "30-39" << setw(6) << "40-49" << setw(6) << "50-59" << setw(6) << "60-69" << setw(6) << "70-79" << setw(6) << "80-89" << setw(6) << "90-99"  << setw(6) << "100" << endl;
    cout << "------------------------------------------------------------------------" << endl;
    bool output = true;
    int frequency[12] = {0};
    while(output)
    {
        output = false;
        for(int i = 0; i < 12; i++)
        {
            if(scores[i])
            {
                cout << setw(6) << '*';
                scores[i]--;
                frequency[i]++;
                output = true;
            }
            else
            {
                if(frequency[i])
                {
                    cout << setw(6) << frequency[i];
                    frequency[i] = 0;
                }
                else
                {
                    cout << setw(6) << ' ';
                }
            }
        }
        cout << endl;
    }
}