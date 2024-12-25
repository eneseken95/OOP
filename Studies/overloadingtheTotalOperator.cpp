#include <iostream>
using namespace std;

class nokta {
private:
    int x, y;  

public:
   
    nokta(int x = 0, int y = 0) : x(x), y(y) {}

    friend nokta operator+(nokta a, nokta b);

    friend nokta operator+(int, nokta);

    void yaz() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};


nokta operator+(nokta a, nokta b) {
    a.x = a.x + b.x;  
    a.y = a.y + b.y; 
    return a;         
}
nokta operator+(int d, nokta s) {
        s.x = s.x + d;  
        s.y = s.y + d;  
        return s;   
    }

int main() {
    nokta bir(5, 5), iki(4, 4), uc;

    bir.yaz(); 
    iki.yaz(); 

    uc = bir + iki;  
    uc.yaz();  

    iki = 8 + iki;  
    iki.yaz();  

    uc.yaz(); 
    
    return 0;
}
