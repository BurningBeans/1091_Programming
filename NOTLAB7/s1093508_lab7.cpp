#include <iostream>
using namespace std;
struct cord
{
    int x;
    int y;
    cord():x(0),y(0){};
};
struct rectangle
{
    cord TR;
    cord BL;
};
int main()
{
    int cases;
    int ArecX1,ArecY1,ArecX2,ArecY2;
    int BrecX1,BrecY1,BrecX2,BrecY2;
    cin >> cases;
    for(int i = 0;i < cases; i++){
        cin >> ArecX1 >> ArecY1 >> ArecX2 >> ArecY2;
        cin >> BrecX1 >> BrecY1 >> BrecX2 >> BrecY2;
        ArecX1,ArecY1;//bot left
        ArecX1,ArecY2;//top left
        ArecX2,ArecY1;//bot right
        ArecX2,ArecY2;//top right
    }
}
/*
bool intersect(cord BL1, cord TR1, cord BL2, cord TR2)
{
    if(BL1.x>BL2.x||BL1.x>TR2.x)//if the left most of x is smaller then both x of second rectangle than there's no intersect 
    {
        return false;
    }
    if(BL1.y>BL2.y||BL1.y>TR2.y)
    {
        return false;
    }
    return true;
}
*/