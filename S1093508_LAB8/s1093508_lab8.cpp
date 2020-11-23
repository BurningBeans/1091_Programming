#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
struct line
{
    float x1;
    float y1;
    float x2;
    float y2;
};
bool intersect(float , float , float , float , float , float , float , float ,float& , float&);
int main()
{
    int Ccount;//case count
    struct line L;//line
    struct line S;//line segment
    float px = 0,py = 0;//intersecting point
    cin >> Ccount;
    for(int i = 0; i < Ccount; i++)
    {
        cin >> L.x1 >> L.y1 >> L.x2 >> L.y2 >> S.x1 >> S.y1 >> S.x2 >> S.y2;
        intersect(L.x1,L.y1,L.x2,L.y2,S.x1,S.y1,S.x2,S.y2,px,py);
        if(min (S.x1, S.x2) <= px && px <= max (S.x1, S.x2) && min (S.y1, S.y2) <= py && py <= max (S.y1, S.y2))//check if point is on the line
        {
            cout << "Yes ";
            if(intersect(L.x1,L.y1,L.x2,L.y2,S.x1,S.y1,S.x2,S.y2,px,py))
            {
                cout << "The line segment is on the line" << endl;
            }
            else
            {
                cout << "(" << px << ","<< py << ")" << endl;
            }
        }
        else
        {
            cout << "No" << endl;
        }
    }
}
bool intersect(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4,float& px, float& py)//get intersect point
{   //用行列式解點X點Y
    //AX+BY=C A=Y2-Y1 B=X1-X2 C=(a1*x1)+(b1*y1)
    float a1 = y2 - y1;
    //cout << a1 << " ";
    float b1 = x1 - x2;
    //cout << b1 << " ";
    float c1 = (a1 * x1) + (b1 * y1);
    //cout << c1 << " ";
    float a2 = y4 - y3;
    //cout << a2 << " ";
    float b2 = x3 - x4;
    //cout << b2 << " ";
    float c2 = (a2 * x3) + (b2 * y3);
    //cout << c2 << " ";
    if ((a1 * b2) - (a2 * b1) == 0)//parallel = true
    {        
       return true;
    }
    else
    {
        px = (b2 * c1 - b1 * c2) / ((a1 * b2) - (a2 * b1));
        py = (a1 * c2 - a2 * c1) / ((a1 * b2) - (a2 * b1));
        return false;
    }
}
/*input 1
0.5 1.5 6 3 0 2 2 2
0.5 5.5 5.5 0.5 1 4 3 4
-2 4 0.5 -0.5 -2 0.5 4.5 3
-2 0.5 -0.5 1.5 -2.5 2 -1 3
-4 -2 5 4 -3 4.5 3.5 -1
-10 -2 6 8 0 4 5 4
-8 4 10 6 2 -4 5 4
-8 -4 2 -6 6 -2 10 0
2 8 14 2 4 6 12 4
4 6 16 8 -8 4 16 8
//input 2
1 6 19 13 20 10 5 8
4 7 14 6 1 20 17 3
14 11 10 6 9 5 12 4
8 16 14 19 3 6 4 20
13 2 19 12 18 3 20 16
2 3 19 5 15 13 14 9
10 5 13 18 12 1 15 14
18 15 9 11 10 7 14 1
8 16 14 5 7 20 18 11
6 10 16 9 20 8 11 5
*/


/* cases
(0.5 1.5) (6 3) (0 2) (2 2) no
(0.5 5.5) (5.5 0.5) (1 4) (3 4) Yes at (2 4)
(-2 4) (0.5 -0.5) (-2 0.5) (4.5 3) Yes at (-0.397887 1.116197)
(-2 0.5) (-0.5 1.5) (-2.5 2) (-1 3) No parallel
(-4 -2) (5 4) (-3 4.5) (3.5 -1) Yes at (0.8559322 1.23728813)
(0 4) (5 4) (-10 -2) (6 8) No
(2 -4) (5 4) (-8 4) (10 6) No
(6 -2) (10 0) (-8 -4) (2 -6) No
(2 8) (14 2) (4 6) (12 4) Yes at (8 5)
(4 6) (16 8) (-8 4) (16 8) Yes it's on the line
det = (a1 * b2) - (a2 * b1)
*/