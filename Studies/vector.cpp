#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ogrenci
{
public:
    string isim;
    int num;
    double nott;
    
    ogrenci(string x, int y, double z) : isim(x), num(y), nott(z) {}
};

int main(int argc, char** argv) {

    ogrenci bir("Ahmet Kurtuluş", 100, 90);
    
    vector<ogrenci> v;
    
    v.push_back(bir);

    cout << "Öğrenciler:" << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << "İsim: " << v[i].isim << ", Numara: " << v[i].num << ", Not: " << v[i].nott << endl;
    }
    
    vector<int> v2(10, 20);  
    
    v2.push_back(1); 
    
    cout << "\nInteger Vektör Elemanları:" << endl;
    for (int i = 0; i < v2.size(); i++) {
        cout << v2[i] << endl;
    }

    return 0;
}
