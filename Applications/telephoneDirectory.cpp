#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class kisi {
public:
    string ad;
    string telefon;
    
    kisi(string a, string t) : ad(a), telefon(t) {}
    
    void yazdir() const {
        cout << "Ad: " << ad << ", Telefon: " << telefon << endl;
    }
};

class rehber {
private:
    vector<kisi> liste; 
    fstream f; 

public:
    void ekle() {
        string ad, telefon;
        cout << "Ad girin: ";
        cin >> ad;
        cout << "Telefon girin: ";
        cin >> telefon;
        
        kisi yeniKisi(ad, telefon);
        liste.push_back(yeniKisi); 
        
        f.open("rehber.txt", ios::out | ios::app);
        if (f.is_open()) {
            f << ad << " " << telefon << endl;
            f.close();
        } else {
            cout << "Dosya açılamadı!" << endl;
        }
    }

   void listele() {
        if (liste.empty()) {
            cout << "Kişi listesi boş!" << endl;
        } else {
        for (int i = 0; i < liste.size(); i++) {
            liste[i].yazdir();  
        }
      }
    }

    void oku() {
        string ad, telefon;
        f.open("rehber.txt", ios::in);
        if (f.is_open()) {
            while (f >> ad >> telefon) {
                kisi k(ad, telefon);
                liste.push_back(k);  
            }
            f.close();
        } else {
            cout << "Dosya açılamadı!" << endl;
        }
    }
};

int main(int argc, char** argv) {
    rehber birRehber;

    birRehber.oku();

    int secim;
    do {
        cout << "\n1. Kisi Ekle\n";
        cout << "2. Kisi Listele\n";
        cout << "3. Çıkış\n";
        cout << "Seçiminizi yapın: ";
        cin >> secim;

        switch (secim) {
            case 1:
                birRehber.ekle(); 
                break;
            case 2:
                birRehber.listele(); 
                break;
            case 3:
                cout << "Çıkılıyor..." << endl;
                break;
            default:
                cout << "Geçersiz seçenek!" << endl;
        }
    } while (secim != 3); 

    return 0;
}
