#include <bits/stdc++.h>
using namespace std;
enum status {TH, TL, RT};
void generatePassWd(string &, int &);
void guess(status &, string, string);
int main()
{
    status aGuess;
    string passWd;
    string GpassWd;
    int passLen;
    char play = 'y';
    while(play == 'y'|| play == 'Y')
    {
        generatePassWd(passWd, passLen);
        int guesscount = 1;//total guess count
        cout << "Guess a password having at most 4 lower-case letters. My guess is as follows : " << endl;
        do
        {
            cout << guesscount << "-";
            if(guesscount==1)
            {
                cout << "st ";
            }
            else if(guesscount==2)
            {
                cout << "nd ";
            }
            else if(guesscount==3)
            {
                cout << "rd ";
            }
            else
            {
                cout << "th ";
            }
            cout << "guess = ";
            cin >> GpassWd;
            guess(aGuess, passWd, GpassWd);
            if(aGuess == TL)
            {
                cout << "Too low. Try again." << endl;
            }
            else if(aGuess == TH)
            {
                cout << "Too high. Try again." << endl;
            }
            else
            {
                cout << "Bravo, you guess it right!"<< endl;
                if(guesscount <= ceil(log2(pow(26,passLen))))
                {
                    cout << "You know the secret!" << endl;
                }
                else
                {
                    cout << "You should be able to do better" << endl;
                }
                break;
            }
            guesscount++;
        } while (aGuess!=RT);
        cout << "Play the game again (Y or y for yes): ";
        cin >> play;
    }
}
void generatePassWd(string &passWd, int &passLen)
{
    srand(time(0));
    passLen = rand()%4+1;
    if(passLen==1)
    passWd="0";
    else if(passLen==2)
    passWd="00";
    else if(passLen==3)
    passWd="000";
    else
    passWd="0000";
    for (int i=0; i<passLen; i++)
    passWd[i] = 'a' + rand()% 26;
}
void guess(status &result, string passWd, string GpassWd)
{
    if (passWd.length()>GpassWd.length())
    {
        result = TL;
    }
    else if (passWd.length()<GpassWd.length())
    {
        result = TH;
    }
    else
    {
        for(int i = 0; i < passWd.length() ; i++)
        {
            if (GpassWd[i] < passWd[i])
            {
                result = TL;
                break;
            }
            else if(GpassWd[i] > passWd[i])
            {
                result = TH;
                break;
            }
            else
            {
                result = RT;
            }
        }
    }
}