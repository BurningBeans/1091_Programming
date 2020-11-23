#include <iostream>
using namespace std;

int main()
{
    int cases = 0;
    int sizes = 0;
    
    cin >> cases;
 
    for(int i = 0; i < cases; i++)
    {
        long long matrix[100][100] = {0};//clear array every loop
        bool sym = true;
        cin.ignore(4,'\0') >> sizes ;//there's a '/0' before "N = "
        for(int i = 0; i < sizes; i++)
        {
            for(int j = 0; j < sizes; j++)
            {
                cin >> matrix[i][j];
            }
        }
        for(int i = 0; i < sizes; i++)
        {
            for(int j = 0; j < sizes; j++)
            {
                if(matrix[i][j]!=matrix[(sizes-1)-i][(sizes-1)-j])
                sym = false;
            }
        }
        if(sym)
        {
            cout << "Test #" << i+1 <<" : Symmetric.\n";
        }
        else
        {
            cout << "Test #" << i+1 <<" : Non-symmetric.\n";
        }
        
    }

}

/* Failed at using vector

int main()
{
    int cases = 0;
    int dimension = 0;
    int input = 0;
    std::vector <std::vector<int>> vec;
    std::cin >> cases >> dimension;
    for(int i = 0; i < dimension; i++)
    {
        for(int j = 0; j < dimension; j++)
        {
            std::cin >> input;
            vec[i].push_back(input);
        }
    }
    for(int i = 0; i < dimension; i++)
    {
        for(int j = 0; j < dimension; j++)
        {
            std::cout << vec[i].at(j) << " ";
        }
        std::cout << std::endl;
    }
}
*/
//ref:https://cpe.cse.nsysu.edu.tw/cpe/file/attendance/problemPdf/11349.pdf