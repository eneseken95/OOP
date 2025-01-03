#include <iostream>
using namespace std;

class Nokta{
    protected:
    int p;

    private:
    int x;

    public:
    int y;
    
};

class Nokta2 : public Nokta {
    public:
     void printP() {        
        p = 20;
        cout << "p: " << p << endl;
    }
};

int main()
{
    Nokta n1;
    Nokta2 n2;
    
    n1.y = 5;
    cout << n1.y << endl;
    
    n2.printP();

    return 0;
}
