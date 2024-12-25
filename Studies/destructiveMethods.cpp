#include <iostream>
using namespace std;

class Nokta{
    private:
    int x;
    int y;
    public:
    int* z;
    int getX();
    int getY();
    void setX(int);
    void setY(int);

    Nokta();
    Nokta(int, int);
    ~Nokta();
    

};


int Nokta::getX(){return x;}
int Nokta::getY(){return y;}

void Nokta::setX(int _x){this->x = _x;}
void Nokta::setY(int _y){this->y = _y;}

Nokta:: Nokta()
{
   cout<<"Parametresiz kurucu"<<endl;
   x=0;
   y=0;
   z = new int(2);
}

Nokta:: Nokta(int x, int y=8)
{
    this->x = x;
    this->y = y;
}

Nokta::~ Nokta()
{
    cout<<"Yikici fonksiyon calisti"<<endl;
  //  delete z;
}


int main()
{
    Nokta n1(1,10);
    Nokta n2(2,25);

    return 0;
}