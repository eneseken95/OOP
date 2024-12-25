#include <iostream>
using namespace std;


class A{
    private:
    int x;

    public:
    int getX();
    void setX(int);
    friend ostream& operator << (ostream&,A&);
  
};


int A::getX(){return x;}

void A::setX(int _x){x = _x;}

ostream& operator << (ostream&o, A&a){
    o << a.x;
    return o;
}

int main()
{
   A n;
   n.setX(20);
   cout<<n;

   return 0;
}