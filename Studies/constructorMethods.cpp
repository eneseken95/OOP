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

    Nokta();
    Nokta(int, int);
    

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
}

Nokta:: Nokta(int x, int y=8)
{
    this->x = x;
    this->y = y;
}


int main()
{
Nokta dizi[5];
dizi[0] = Nokta(1, 2);
dizi[1] = Nokta(1);
dizi[2] = Nokta(2, 4);
dizi[3] = Nokta(0, 0);
dizi[4] = Nokta(6, 7);
   
   for (int i = 0; i < 5; i++)
   {
    cout << dizi[i].getX() <<" "<<dizi[i].getY()<<endl;
   }
   
    Nokta*  ptr = new Nokta(1);

    return 0;
}