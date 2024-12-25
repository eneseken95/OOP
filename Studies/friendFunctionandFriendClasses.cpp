#include <iostream>
using namespace std;
class B;

class A{
    private:
    int x;

    public:
    int getX();
    void setX(int);
    friend void Foo(A&);
    void setY(B&);
};

class B{
    private:
    int y;

    public:
    int getY();
    void setY(int);
    friend class A;
};


int A::getX(){return x;}

void A::setX(int _x){this->x = _x;}

void Foo(A&a){a.x = 0;}

int B::getY(){return y;}

void B::setY(int _y){this->y = _y;}

void A::setY(B&n2){n2.y = 100;}

int main()
{
    A n;
    n.setX(5);
    cout<<n.getX()<<endl;
    Foo(n);
    cout<<n.getX()<<endl;

    B b;

    b.setY(50);
    cout<<b.getY()<<endl;

    n.setY(b);
    cout<<b.getY()<<endl;

    return 0;
}