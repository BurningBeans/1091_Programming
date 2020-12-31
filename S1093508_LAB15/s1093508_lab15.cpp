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
        cout <<"first input end"<<endl;
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
        cout <<"end of second input" << endl;
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
                    cout << "Run #" << runcount << " : Wrong Answer." << endl;
                    print = true;
                    break;
                }
                if(rawinputV[i]!=rawansV[i])
                {
                    cout << "Run #" << runcount << " : Presentation Error." << endl;
                    print = true;
                    break;
                }
            }
            if(!print)
                cout << "Run #" << runcount << " : Right Answer." << endl;
        }
        else
        {
            cout << "Run #" << runcount << " : Wrong Answer." << endl;
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