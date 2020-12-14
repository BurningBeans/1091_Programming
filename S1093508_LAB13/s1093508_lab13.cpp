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
using std::ofstream;
using std::ifstream;
using std::fstream;
//----------------------------------------------------------------
const int maxstudents = 200;
const int maxtests = 10;
//----------------------------------------------------------------
int minimun(const int [] [maxtests], int, int);
int maximun(const int [] [maxtests], int, int);
double arverage(const int [] [maxtests],int, int, string);
void ouptutGrades(const int [] [maxtests], int, int);
//void outputBarChart(const int[] [maxtests], int, int);
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
    cout << "The numbers of students : ";
    inStudentGrades >> students;
    cout << students << endl;
    cout << "The number of tests : ";
    inStudentGrades >> tests;
    cout <<  tests << endl;
    //Create grades table
    int studentsGrades[maxstudents][maxtests];
    int grades;
    for(int i = 0; i < students; i++)
    {
        for(int j = 0; j < tests;j++)
        {
            inStudentGrades >> grades;
            studentsGrades[i][j] = grades;
        }
    }
    ouptutGrades(studentsGrades, students, tests);
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
            cout << setw(7) << setprecision(2) << fixed << *averagescores.rbegin() << endl;//reverse begin because .end() won't get the last element
        }
    }
}