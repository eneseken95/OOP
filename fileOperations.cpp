#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

 class ogrenci {
    public:
        int n;
        string is;
    };

int main() {
    ifstream f1;
    ofstream f2;

    f2.open("deneme.txt", ios::out);
    if (!f2) {
        cerr << "Dosya açma hatası!" << endl;
        return 1;
    }
    for (int i = 0; i < 10; i++) {
        f2 << i << endl;
    }
    f2.close();

    f2.open("deneme.txt", ios::app);
    if (!f2) {
        cerr << "Dosya açma hatası!" << endl;
        return 1;
    }
    for (int i = 10; i < 20; i++) {
        f2 << i << endl;
    }
    f2.close();

    int data;
    f1.open("deneme.txt", ios::in);
    if (!f1) {
        cerr << "Dosya açma hatası!" << endl;
        return 1;
    }
    for (int i = 0; i < 10; i++) {
        f1 >> data;
        cout << data << endl;
    }
    f1.close();

    fstream f3;

    ogrenci bir;

    f3.open("deneme.txt", ios::in | ios::out);

    if (!f3) {
    cerr << "Dosya açma hatası!" << endl;
    return 1;
    }

    while (f3 >> bir.n >> bir.is) {
    cout << bir.n << " " << bir.is << endl;
    }

    cout << "No ve isim giriniz: ";
    cin >> bir.n >> bir.is;

    f3.clear();
    f3.seekp(0, ios::end);
    f3 << bir.n << " " << bir.is << endl;

    f3.close();

    return 0;
}
