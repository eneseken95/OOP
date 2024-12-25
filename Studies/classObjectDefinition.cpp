#include <iostream>
using namespace std;

class Nokta{

    public:
    int x,y;

};


int main()
{
    Nokta n;

    n.x = 5;
    n.y = 2;

    cout << n.x << " , " << n.y << endl;


    return 0;
}