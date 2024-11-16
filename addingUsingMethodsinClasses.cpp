#include <iostream>
using namespace std;

class Nokta{

    public:
    int x,y;
    void degerAta(int _x, int _y)
    {
        x = _x;
        y = _y;
    }

    void ekranaYaz()
    {
        cout << x << " , " << y << endl;
    }

    bool baslangictaMi()
    {
        return  (x == 0 && y == 0); 
           
    }

};


int main()
{
    Nokta n1,n2;

    n1.degerAta(0,0);

    n2.degerAta(3,10);

    
    n1.ekranaYaz();

    n2.ekranaYaz();

    
    if (n1.baslangictaMi())
    {
        cout<<"n1 Baslangicta"<<endl;
    }
    

      if (n2.baslangictaMi())
    {
        cout<<"n2 Baslangicta"<<endl;
    }


    return 0;
}