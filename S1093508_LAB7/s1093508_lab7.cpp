#include <iostream>
#include <cmath>
using namespace std;
struct cord
{
    int x;
    int y;
};
bool verticesinside(int x1, int y1, int x2, int y2, int px, int py)//if a point inside rectangle or not
{
    if (px >= x1 && px <= x2 && py >= y1 && py <= y2)
    {
        return true; 
    }   
    return false; 
}
int main()
{
    struct cord rec1BL,rec1TR;//rectangle 1
    struct cord rec2BL,rec2TR;//rectangle 2
    struct cord rec3BL,rec3TR;//rectangle 3 *draw by intercepting point
    int cases;
    cin >> cases;
    for(int i = 0; i < cases; i++)
    {
        int vert1in2 = 0;//vertices of rec1 inside 2
        int vert2in1 = 0;//vertices of rec2 inside 1
        cin >> rec1BL.x >> rec1BL.y >> rec1TR.x >> rec1TR.y >> rec2BL.x >> rec2BL.y >> rec2TR.x >> rec2TR.y;

        rec3BL.x = max(rec1BL.x,rec2BL.x);//get the bot left of rec3
        rec3BL.y = max(rec1BL.y,rec2BL.y);
        rec3TR.x = min(rec1TR.x,rec2TR.x);//get top right of rec3
        rec3TR.y = min(rec1TR.y,rec2TR.y);
        if(rec3BL.x>rec3TR.x||rec3BL.y>rec3TR.y)//if the rectangle is backward then there's no intersection
        {
            cout << "no\n";
            continue;//end if print out no
        }
        else//keep running
        {
            cout << "Yes ";
        }
        //do first rectangle's vertices
        if(verticesinside(rec2BL.x,rec2BL.y,rec2TR.x,rec2TR.y,rec1BL.x,rec1BL.y))//check bot left of rec1
            vert1in2++;
        if(verticesinside(rec2BL.x,rec2BL.y,rec2TR.x,rec2TR.y,rec1TR.x,rec1BL.y))//check bot right
            vert1in2++;
        if(verticesinside(rec2BL.x,rec2BL.y,rec2TR.x,rec2TR.y,rec1TR.x,rec1TR.y))//check top right
            vert1in2++;
        if(verticesinside(rec2BL.x,rec2BL.y,rec2TR.x,rec2TR.y,rec1BL.x,rec1TR.y))//check top left
            vert1in2++;
        //do second rectangle's vertices
        if(verticesinside(rec1BL.x,rec1BL.y,rec1TR.x,rec1TR.y,rec2BL.x,rec2BL.y))//check bot left of rec2
            vert2in1++;
        if(verticesinside(rec1BL.x,rec1BL.y,rec1TR.x,rec1TR.y,rec2TR.x,rec2BL.y))//check bot right
            vert2in1++;
        if(verticesinside(rec1BL.x,rec1BL.y,rec1TR.x,rec1TR.y,rec2TR.x,rec2TR.y))//check top right
            vert2in1++;
        if(verticesinside(rec1BL.x,rec1BL.y,rec1TR.x,rec1TR.y,rec2BL.x,rec2TR.y))//check top left
            vert2in1++;
        cout << vert1in2 << " " << vert2in1 << " \n";
    }
}