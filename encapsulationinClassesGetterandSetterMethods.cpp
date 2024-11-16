#include <iostream>
using namespace std;

class Nokta{

    private:
    int x;
    int y;

    public:
    int getX();
    int getY();


    void setX(int);
    void setY(int);


};


int Nokta:: getX()
{
    return x;
}

int Nokta:: getY()
{
 
    return y;
}


void Nokta:: setX(int _X)
{
    x = _X;
}

void Nokta:: setY(int _Y)
{

    if (_Y >= 6)
    {
        _Y = 10;
        y = _Y;
    }

    else
    {
        y = _Y;
    }
}



int main()
{

    Nokta n1;

    n1.setX(5);
    n1.setY(6);

    cout<< n1.getX() << " " << n1.getY() << endl;


    return 0;
}