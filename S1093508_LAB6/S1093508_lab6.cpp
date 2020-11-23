#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
    string input;
    int wordCount = 0;//Word count
    int wordWithVow = 0;//Word start with Vowel
    int wordNotVow = 0;//Word not vowel but is alphabet
    int wordWithAlp = 0;//Word start with alphabet
    int wordWithDigit = 0;//Word with Digit
    int wordLength[16] = {0};//0 to >=15
    int alpCount[28] = {0};//word at start of the letter
    int sameL[26] = {0};//start and end with same letter
    while (cin>>input)
    {
        //Word counting
        switch (input.front())
        {
        case 'A': case 'a': case 'E': case 'e': case 'I': case 'i': case 'O': case 'o': case 'U': case 'u':
            wordWithVow++;
            wordWithAlp++;
            wordCount++;
            break;
        case 'B': case 'b': case 'C': case 'c': case 'D': case 'd': case 'F': case 'f': case 'G': case 'g': case 'H': case 'h': case 'J': case 'j': case 'K': case 'k': case 'L': case 'l': case 'M': case 'm': case 'N': case 'n': case 'P': case 'p': case 'Q': case 'q': case 'R': case 'r': case 'S': case 's': case 'T': case 't': case 'V': case 'v': case 'W': case 'w': case 'X': case 'x': case 'Y': case 'y': case 'Z': case 'z':
            wordNotVow++;
            wordWithAlp++;
            wordCount++;
            break;
        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
            wordWithDigit++;
            wordCount++;
            break;
        default:
            wordCount++;
            break;
        }
        //Word length
        if(input.back()==','||input.back()=='.'||input.back()==':')//if end with these symbols length--
        {
            wordLength[input.length()-1]++;
        }
        else if(input.length()>15)
        {
            wordLength[15]++;
        }
        else
        {
            wordLength[input.length()]++;
        }
        //First Letter Counter
        if(input.front()>='0'&&input.front()<='9')//do first latter num
        {
            alpCount[26]++;
        }
        else if (input.front()>='A'&&input.front()<='Z'||input.front()>='a'&&input.front()<='z')
        {
            for(int i = 0; i < 26; i++)//do alphabet
            {
                if(input.front()-97==i||input.front()-65==i)
                alpCount[i]++;
            }
        }
        else
        {
            alpCount[27]++;
        }

        //Same letter counter
        if(input.back()==':'||input.back()==','||input.back()=='.')
        input.pop_back();//there are better way but I'm lazy
        if(input.length()>1&&input.front()==input.back()||input.back()-input.front()==32||input.front()-input.back()==32)//Do string longer than 1 and check capital letters
        {
            for(int i = 0; i < 26; i++)//do alphabet
            {
                if(input.front()-97==i||input.front()-65==i)
                sameL[i]++;
            }
        }
    }
    //outputs
    cout << "Total number of words: " << wordCount << '\n';
    cout << "Total number of words starting with a vowel: " << wordWithVow << '\n';
    cout << "Total number of words not starting with a vowel, but with an alphabet: " << wordNotVow << '\n';
    cout << "Total number of words started with an alphabet: " << wordWithAlp << '\n';
    cout << "Total number of words started with a digit: " << wordWithDigit << '\n';
    cout << "Distribution of words by word length: \n";
    for(int i = 0; i < 16; i++)
    {
        cout << "L=" << i << " " << wordLength[i] << endl;
    }
    cout << "Distribution of words by first letter: \n";
    for(int i = 0; i < 26; i++)
    {
        cout << char (i + 65) << "/" << char (i + 97) << ": " << alpCount[i] <<"\n";
    }
    cout << "0~9: " << alpCount[26] << '\n';
    cout << "Other: " << alpCount[27] << '\n';
    cout << "Distribution of words whose first and last letters are the same: \n";
    for(int i = 0; i < 26; i++)
    {
        cout << char (i + 65) << "/" << char (i + 97) << ": " << sameL[i] << "\n";
    }
}