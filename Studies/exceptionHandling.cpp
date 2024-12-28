#include <cstdlib>
#include <iostream>
#include <string>
#include <stdexcept>
#include <cmath>

using namespace std;

int main(int argc, char** argv) {
    string s;
    getline(cin, s);
    cout << s << endl;

    for (int i = s.size() - 1; i >= 0; i--)
        cout << s[i];
    cout << endl;
    
    int a;
    try {
        cout << "Sayi giriniz (0-100): " << endl;
        cin >> a;
        
        if (a < 0 || a > 100)
            throw a;
        else if (a == 20)
            throw "dogru veri";
        else
            throw 'c';
        
    } catch (int x) {
        cerr << "Hatalı veri: " << x << endl;
    } catch (const char* a) {
        cout << a << endl;
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    try {
        double x = -1.0;
        if (x < 0)
            throw domain_error("Negatif sayinin karekoku yok");
        cout << "Karekok: " << sqrt(x) << endl;
    } catch (const domain_error& de) {
        cerr << "Domain hata: " << de.what() << endl;
    }

    try {
        int yas = -5;
        if (yas < 0)
            throw invalid_argument("Yas negatif olamaz.");
    } catch (const invalid_argument& ia) {
        cerr << "Gecersiz veri: " << ia.what() << endl;
    }

    try {
        vector<int> sayi(3);
        sayi.at(5);
    } catch (const out_of_range& oor) {
        cerr << "Indis disi: " << oor.what() << endl;
    }

    try {
        short int x = 32767;
        x = x + 1; 
        if (x < 32767)
            throw overflow_error("Degisken boyut asimi");
        cout << x << endl;
    } catch (const overflow_error& of) {
        cerr << "Overflow Error: " << of.what() << endl;
    }

    try {
        throw runtime_error("Beklenmeyen calisma zamani hatasi.");
    } catch (const runtime_error& re) {
        cerr << "Runtime Error: " << re.what() << endl;
    }

    try {
        throw logic_error("Program mantik hatasi");
    } catch (const logic_error& le) {
        cerr << "Logic Error: " << le.what() << endl;
    }

    return 0;
}
