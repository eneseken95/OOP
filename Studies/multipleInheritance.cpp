#include <iostream>
using namespace std;


class Yazici {
public:
    string marka;
    Yazici(string marka) : marka(marka){cout <<"Yazici sinifi"<<endl;}
};


class Tarayici {
public:
    string marka;
    Tarayici(string marka) : marka(marka){cout <<"Tarayici sinifi"<<endl;}
};

class TarayiciliYazici:public Yazici, public Tarayici{
    public:
    TarayiciliYazici(string m1, string m2): Yazici(m1), Tarayici(m2){
        cout<<"Tarayicili Yazici sinifi"<<endl;
        cout<<Yazici::marka<<endl;
        cout<<Tarayici::marka<<endl;
    }
};

int main()
{
    TarayiciliYazici("Apple", "Asus");
    return 0;
}