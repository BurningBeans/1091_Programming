#include <bits/stdc++.h>
using namespace std;
string crapsFunc();
int rollDice();
int main()
{
    srand(time(0));
    float input;
    cout << "Input the times you want to roll the dices : ";
    cin >> input;
    char play;
    float best = 0;
    do{
        float wincounter = 0;
        for(int i = 0;i<input;i++)
        {
            if(crapsFunc()=="WON")
            {
                wincounter++;
            }
        }
        cout <<"Times that you won = "<< wincounter << "\t";
        float winrate = wincounter/input;
        cout <<"Your win rate ="<< winrate << endl;
        cout << "Continue to play?(Y/y = yes)";
        cin >> play;
        if(abs(best-0.7)>abs(winrate-0.7))
        {
            best = winrate;
        }
    }while(play=='Y'||play=='y');
    cout << "Your best winrate is : " << best << '\t';
    cout << "The score is " << 100-abs(1.0-best/0.7)*1000; //score converter 
}
int rollDice()
{
    int die1 = 1 + rand() % 6;
    int die2 = 1 + rand() % 6;
    
    int sum = die1 + die2;
    return sum;
}
string crapsFunc()
{
    enum Status{ CONTINUE};
    int myPoint;
    Status gameStatus;
    int sumOfDice = rollDice();
    switch(sumOfDice)
    {
        case 3:
        case 5:
        case 7:
        case 9:
        case 11:
            return "WON";
            break;
        case 12:
            return "LOST";
            break;
        default:
            gameStatus = CONTINUE;
            myPoint = sumOfDice;
            break;
    }
    while(gameStatus == CONTINUE)
    {
        sumOfDice = rollDice();
        if (sumOfDice == myPoint)
        {
            return "WON";
        }
        else
        {
            if(sumOfDice >= 10 )//if(sumOfDice == 7)
            {
                return "LOST";
            }
        }
    }
    return crapsFunc();
}
/*
    switch(sumOfDice)//winrate 0.68
    {
        case 3:
        case 5:
        case 7:
        case 9:
        case 11:
            return "WON";
            break;
        case 12:
            return "LOST";
            break;
        default:
            gameStatus = CONTINUE;
            myPoint = sumOfDice;
            break;
    }
*/