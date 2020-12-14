#include "iostream"
#include "fstream"
#include "string"
#include "iomanip"
//----------------------------------------------------------------
using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::setw;
using std::ofstream;
using std::ifstream;
using std::fstream;
//----------------------------------------------------------------
const int maxstudents = 200;
const int maxtests = 10;
//----------------------------------------------------------------
int minimun(const int [] [maxtests], int, int);
int maximun(const int [] [maxtests], int, int);
double arverage(const int [] [maxtests],int, int);
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
    cout << "Input the numbers of students : ";
    inStudentGrades >> students;
    cout << students << endl;
    cout << "Input the number of tests : ";
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
double average(const int grades[][maxtests],int students, int tests)//TODO: This function is not finished yet.
{
    int sum = 0;
    for(int i = 0; i < students; i++)
    {
        sum += grades[i][tests];
    }
    return (double)sum/tests;
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
    cout << "            ";
    for(int i = 0; i <= tests; i++)
    {
        cout << "-------" <<' ';
    }
    cout << endl;
    //
    for(int i = 0; i < students; i++)
    {
        cout << "Student" << setw(4) << i+1 << ' ';
        for(int j = 0; j < tests; j++)
        {
            cout << setw(7) << grades[i][j] << ' ';
        }
        cout << setw(7) << average(grades,i,tests) << endl;
    }
    //
    cout << "            ";
    for(int i = 0; i <= tests; i++)
    {
        cout << "-------" <<' ';
    }
    cout << endl;
}