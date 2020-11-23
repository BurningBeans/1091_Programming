//#include <iostream>
//#include <cmath>
//#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
struct line
{
    int x1;
    int y1;
    int x2;
    int y2;
};
double slope(int x1, int y1, int x2, int y2)//get slope
{
    if(y2-y1==0)//Divisor cannot be zero
    return (double) x2-x1;
    else
    return (double) (x2-x1)/(y2-y1);
}
double getc(int x1, int y1, int x2, int y2)//get c
{
    double a = y2 - y1;
    double b = x2 - x1;
    double c = a*x1+b*y1;
    return c;
}
bool inrange(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)//find out the line is within range of each other
{//is there bug in this function maybe
    if(x1>=x3&&y1>=y3&&x2>=x4&&y2>=y4)
    return true;
    else
    return false;
}
void intersect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4,double &px, double &py)//get intersect point
{
    //AX+BY=C
    //MX+B=Y //Y-MX=B //(Y-B)/M=X
    double b1 = y1-(slope(x1,y1,x2,y2)*x1);
    double b2 = y3-(slope(x3,y3,x4,y4)*x3);
    px=(y3-b1)/slope(x1,y1,x2,y2);//fix this
    py=(slope(x1,y1,x2,y2)*x3)+b1;//and this
}
int main()
{
    int Ccount;//case count
    struct line L;//line
    struct line S;//line segment
    double px = 0,py = 0;//intersecting point
    cin >> Ccount;
    for(int i = 0; i < Ccount; i++)
    {
        cin >> L.x1 >> L.y1 >> L.x2 >> L.y2 >> S.x1 >> S.y1 >> S.x2 >> S.y2;
        //find out intersect or not
        if(slope(L.x1,L.y1,L.x2,L.y2)==slope(S.x1,S.y1,S.x2,S.y2))
        {
            cout << "Is the same line";
        }
        else
        {
            intersect(L.x1,L.y1,L.x2,L.y2,S.x1,S.y1,S.x2,S.y2,px,py);
            cout << "(" << px << ","<< py << ")" << endl;
        }
        
    }
}
/*test
1 0 3 5 0 3 5 4 Yes
-2 0 3 2 -3 1 1 2 No
*/