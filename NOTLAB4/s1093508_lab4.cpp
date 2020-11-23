#include <iostream>
#include <ctime>
using namespace std;
int main()
{
    clock_t t1,t2;
    t1=clock();

    int min = 1, max = 0, cyclelength = 0;
    int maxlength = 0;
    int dist[25]={0};
    cout << "Input a number (>0): ";
    cin >> max;
    //cout << min << " " << max << " ";
    int temp = min;
    int n;
    while(max > temp)
    {
        n = temp;
        cyclelength = 1;//reset length before every loop
        while(n > 0)
        {
            if(n == 1)
            {
                break;
            }
            else if(n % 2 == 1)
            {
                n = n*3+1;
            }
            else
            {
                n/=2;
            }
            cyclelength++;
        }
        

        if(cyclelength > maxlength)//get max cycle length
        {
            maxlength = cyclelength;
        }

        for(int i = 0; i < 26; i++)//TODO cycle distribution
        {
            if((i+1)*10-cyclelength < 10)//TODO PUT cyclelength inside array FIX THIS
            {
                dist[i]++;
            }
        }//TODO end

        temp++;
    }
    for(int i = 0; i < 26; i++)
    {
        cout << "Num " << (i*10)+1 << " to "<< (i+1)*10 << " is : " << dist[i] << "\n";//first one 0
    }//TODO Print result
    cout << "Maximum cycle length : " << maxlength << "\n";

    t2=clock();
    float diff=(float)t2-(float)t1;
    cout << "The runtime of my program = " << diff/CLOCKS_PER_SEC << endl;
}