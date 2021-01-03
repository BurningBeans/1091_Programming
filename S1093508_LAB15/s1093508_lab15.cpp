#include "iostream"
#include "string"
#include "sstream"
#include "vector"
#include "algorithm"
using namespace std;
int main(int argc, char **)
{
    string ans, input;
    vector <string> ansV, inputV, rawinputV, rawansV;
    int runcount = 1;
    while(true)
    {
        //------------------------------
        //doing inputs
        while(getline(cin,input))
        {
            rawinputV.push_back(input);
            input.erase(remove(input.begin(), input.end(), ' '), input.end());
            input.erase(remove(input.begin(), input.end(), '\t'), input.end());
            if(input=="!@#$%")
                break;
            if(input=="")
            {
                rawinputV.pop_back();
                continue;
            }
            inputV.push_back(input);
            input.clear();
        }
        //cout <<"first input end"<<endl;
        while(getline(cin,ans))
        {
            rawansV.push_back(ans);
            ans.erase(remove(ans.begin(), ans.end(), ' '), ans.end());
            ans.erase(remove(ans.begin(), ans.end(), '\t'), ans.end());
            if(ans=="!@#$%")
                break;
            if(ans=="")
            {
                rawansV.pop_back();
                continue;
            }
            ansV.push_back(ans);
            ans.clear();
        }
        //cout <<"end of second input" << endl;
        //------------------------------
        //just debugging lines
        /*
        cout << "Elements of first inputs : \n"; 
        for(auto i : inputV)
        {
            cout << i << endl;
        }
        cout << "Elements of second inputs : \n";
        for(auto i : ansV)
        {
            cout << i << endl;
        }
        */
        //------------------------------
        //check same number of lines first then check each charcter contents
        bool print = false;
        if(inputV.size() == ansV.size())
        {
            for(int i = 0; i < inputV.size(); i++)
            {
                if(inputV[i]!=ansV[i])
                {
                    cout << "Run #" << runcount << ": Wrong Answer." << endl;
                    print = true;
                    break;
                }
                for(int j = 0; j < rawansV[i].size(); j++)
                    if(rawansV[i][j]!=rawinputV[i][j])
                    {
                        cout << "Run #" << runcount << ": Presentation Error." << endl;
                        print = true;
                        break;
                    }
                if(print)
                {
                    break;
                }
            }
            if(!print)
                cout << "Run #" << runcount << ": Accepted." << endl;
        }
        else
        {
            cout << "Run #" << runcount << ": Wrong Answer." << endl;
        }
        //------------------------------
        inputV.clear();
        ansV.clear();
        rawinputV.clear();
        rawansV.clear();
        char Y;
        cout <<"continue ?";
        cin >> Y;
        if(Y=='Y' or Y=='y')
        {
            runcount++;
            continue;
        }
        else
        {
            break;
        }
        
    }
}
/*
15 0 3
!@#$%
1503
!@#$%
y
1 5 0 3

!@#$%
15  	 03
!@#$%
y
2
The answer is: 10

   The answer is: 5
!@#$%
2

The answer is: 10
The answer is: 5

!@#$%
Y
2
The answer is: 10
   	
The answer is: 15
!@#$%
2
The answer is: 10
The answer is: 15
    
!@#$%
Y
2
The answer is: 10
The answer is:  5
!@#$%
2
The answer is: 10
The answer is: 5
!@#$%
y
3
Input Set #1: YES
Input Set #2: NO
Input Set #3: NO
!@#$%
3
Input Set #1: 	YES
Input Set #2: 	NO
Input Set #3: 	NO
!@#$%
Y
1
1 0 1  0 
!@#$%
1
1010
!@#$%
y
1
The judges are mean!
!@#$%
1
The judges are good!
!@#$%
Y
1
For example, there are 850 groups that have 80 to 99 clusters.
!@#$%
1
For Instance, there was groups that has 80 to clustering.
!@#$%
Y
1
For example, there are 850 groups that have 80 to 99 clusters.
!@#$%
1
For example, there are 850 groups that have 80 to99clusters.
!@#$%
y
1
For example, there are 850 groups that have 80 to 99 clusters.
!@#$%
2
For example, there are 8
50 groups that have 80 to 99 clusters.
!@#$%
n
*/