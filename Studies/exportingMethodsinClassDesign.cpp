#include <iostream>
using namespace std;

class Nokta{

    public:
    int x,y;


    void degerAta(int, int);
    

    void ekranaYaz();
   

    bool baslangictaMi();
   

};

void Nokta::degerAta(int _x, int _y)
{
        x = _x;
        y = _y;
}

void Nokta::ekranaYaz()
{
    cout << x << " , " << y << endl;
}

bool Nokta:: baslangictaMi()
{
 
    return  (x == 0 && y == 0);           
  
}


int main()
{
    Nokta n1,n2;

    Nokta* n3;
    Nokta* n4;

    Nokta array[2];
    Nokta* parray;
    parray = new Nokta[2];
    


    n3 = &n2;

    n4 = new Nokta();

    n1.degerAta(0,0);

    n2.degerAta(3,10);

    n4->degerAta(10,10);
    
    n1.ekranaYaz();

    n2.ekranaYaz();

    cout<<"Pointer ile yazilan degerler: "<< endl;
    n3->ekranaYaz();

    n4->ekranaYaz();

    for (int i = 0; i < 2; i++)
    {
        array[i].degerAta(i,i+2);
        (parray + sizeof(Nokta) * i) ->degerAta(i+5,i+10);
    }

     for (int i = 0; i < 2; i++)
    {
        array[i].ekranaYaz();
        (parray + sizeof(Nokta) * i) ->ekranaYaz();
    }
    
    
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