#include <iostream>
using namespace std;

class Nokta{
    private:
    int x;
    int y;
    public:
    const int c;
    int getX()const;
    int getY();
    void setX(int);
    void setY(int);

    Nokta();
    Nokta(int, int, int);
    

};


int Nokta::getX()const
{
    int x = x*2; 
    return x;
    
}
int Nokta::getY(){return y;}

void Nokta::setX(int _x){this->x = _x;}
void Nokta::setY(int _y){this->y = _y;}

Nokta:: Nokta(): c(0)
{
   cout<<"Parametresiz kurucu"<<endl;
   x=0;
   y=0;
  
}

Nokta:: Nokta(int x, int y=8, int c = 0): c(c)
{
    this->x = x;
    this->y = y;
}

int main()
{
    const Nokta n1(1,10,10);
    Nokta n2(2,25,100);
    cout<<n1.c<<endl;
    cout<<n2.c<<endl;

    cout<<n1.getX()<<endl;
    //n1.setX(500);

    return 0;
}