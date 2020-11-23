#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int v = 0;//velocity
    int t = 0;//time
    while(std::cin >> v >> t)
    {
        std::cout << v*(t*2) << "\n";
    }
}

//ref: https://cpe.cse.nsysu.edu.tw/cpe/file/attendance/problemPdf/10071.pdf