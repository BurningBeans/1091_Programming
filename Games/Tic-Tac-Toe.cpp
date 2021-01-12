#include "iostream"
#include "iomanip"
#include "vector"
using namespace std;
vector<vector<char>> createboard();
void printboard(vector<vector<char>>);
void game(vector<vector<char>>&);
bool statuscheck(vector<vector<char>>);
int main()
{
    vector<vector<char>> elements(createboard());
    printboard(elements);
    game(elements);
}
//----------------------------------------------------------------
vector<vector<char>> createboard()
{
    vector <vector<char>> board
    {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    return board;
}
//----------------------------------------------------------------
void printboard(vector<vector<char>> board)
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cout << board[i][j];
            if(j<2)
                cout <<'|';
                
        }
        cout << '\n';
        if(i<2)
            cout << "-----\n";
    }
}
//----------------------------------------------------------------
void game(vector<vector<char>> &board)
{
    int x ,y;
    cout << "Please enter the coordinates you want to places (O) on the board.\n";
    cout << "Your coordinates : ";
    while(cin >> x >> y)
    {   
        if(x < 3 && y < 3 && board[x][y]==' ')
            break;
        cin.clear();
        cout <<"Invalid input.\n";
        cout << "Please enter the coordinates you want again : ";
    }
    board[x][y]='O';
    printboard(board);
    if(statuscheck(board))
    {
        exit(0);
    }

    cout << "Please enter the coordinates you want to places (X) on the board.\n";
    cout << "Your coordinates : ";
    while(cin >> x >> y)
    {
        if(x < 3 && y < 3 && board[x][y]==' ')
            break;
        cin.clear();
        cout <<"Invalid input.\n";
        cout << "Please enter the coordinates you want again : ";
    }
    board[x][y]='X';
    printboard(board);
    if(statuscheck(board))
    {
        exit(0);
    }
    return game(board);
}  
//----------------------------------------------------------------
bool statuscheck(vector<vector<char>> board)
{
    if ((board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X') ||
        (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X') ||
        (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X') ||
        (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X') ||
        (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X') ||
        (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X') ||
        (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') ||
        (board[2][0] == 'X' && board[1][1] == 'X' && board[0][2] == 'X'))
        {
            cout << "Player (X) has won!\n";
            return true;
        }

    if ((board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O') ||
        (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O') ||
        (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O') ||
        (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O') ||
        (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O') ||
        (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O') ||
        (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') ||
        (board[2][0] == 'O' && board[1][1] == 'O' && board[0][2] == 'O'))
        {
            cout << "Player (O) has won!\n";
            return true;
        }
    return false;
}