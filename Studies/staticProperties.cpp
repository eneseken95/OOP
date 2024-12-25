#include <iostream>
using namespace std;

class A
{
public:
   static int x; 
   int y;       
   void yaz();  
   void yaz2(){x=8;} 
};

int A::x=0; 

void A::yaz() 
{
    cout<<x<<endl;
}

int main(int argc, char** argv) {
    A bir, iki;
    bir.x = 90; 
    cout << iki.x << endl;
    return 0;
}
