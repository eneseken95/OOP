#include <iostream>
using namespace std;

class Sekil {
public:
    virtual void ciz() = 0;
    virtual double alan() = 0;
};

class Daire : public Sekil {
private:
    double yariCap;

public:
    Daire(double r) : yariCap(r) {}

    void ciz() override 
    {
        cout << "Daire ciziliyor!" << endl;
    }

    double alan() override 
    {
        return 3.14159 * yariCap * yariCap;
    }
};

class Dikdortgen : public Sekil {
private:
    double genislik, yukseklik;
    
public:
    Dikdortgen(double g, double y) : genislik(g), yukseklik(y) {}

    void ciz() override 
    {
        cout << "Dikdörtgen ciziliyor!" << endl;
    }

    double alan() override 
    {
        return genislik * yukseklik;
    }
};

int main() {
    Daire daire(5.0);
    Dikdortgen dikdortgen(4.0, 6.0);

    Sekil* sekilPtr;

    sekilPtr = &daire;
    sekilPtr->ciz();
    cout << "Dairenin alanı: " << sekilPtr->alan() << endl;

    sekilPtr = &dikdortgen;
    sekilPtr->ciz();
    cout << "Dikdörtgenin alanı: " << sekilPtr->alan() << endl;

    return 0;
}
