#include <iostream>
#include <cmath>

using namespace std;

class Nokta {
private:
    int x;
    int y;

public:
   
    Nokta(int _x, int _y) : x(_x), y(_y) {}


    int getX() const { return x; }
    int getY() const { return y; }

    
    double uzaklikHesapla(const Nokta& n) const {
        
        int xU = pow(n.getX() - getX(), 2); 
        int yU = pow(n.getY() - getY(), 2); 
        return sqrt(xU + yU);
    }
};

int main() {

    Nokta n1(3, 4);
    Nokta n2(5, 6);

    cout << "Mesafe: " << n1.uzaklikHesapla(n2) << endl;

    return 0;
}
