#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

class hesap
{
  public:

  int hesapno;
  string hsismi;
  int bakiye;

  void bilgigoruntule(int hesapno);
  void parayatir(int hesapno, int para);
  void paracek(int hesapno, int para);
};

fstream oku,yaz;

void hesap::bilgigoruntule(int hesapno)
{
  hesap bir;
  bool hesapBulundu = false;
  
  oku.open("banka.txt", ios::in);
  if (!oku) {
      cout << "Dosya acilamadi!" << endl;
      return;
  }

  while(oku >> bir.hesapno >> bir.hsismi >> bir.bakiye) {
    if(hesapno == bir.hesapno) {
      cout << "Hesap No: " << bir.hesapno << endl;
      cout << "Hesap Ismi: " << bir.hsismi << endl;
      cout << "Bakiye: " << bir.bakiye << " TL" << endl;
      hesapBulundu = true;
      break;
    }
  }

  if (!hesapBulundu) {
      cout << "Hesap bulunamadi!" << endl;
  }
  
  oku.close();
}

void hesap::paracek(int hesapno, int para)
{
  hesap bir;
  bool hesapBulundu = false;
  
  oku.open("banka.txt", ios::in);
  if (!oku) {
      cout << "Dosya acilamadi!" << endl;
      return;
  }

  yaz.open("bankakopya.txt", ios::out);
  while(oku >> bir.hesapno >> bir.hsismi >> bir.bakiye) {
    if(hesapno == bir.hesapno) {
      if (bir.bakiye >= para) {
        bir.bakiye -= para;
        cout << "Cekilen miktar: " << para << " TL" << endl;
        cout << "Yeni bakiye: " << bir.bakiye << " TL" << endl;
      } else {
        cout << "Yetersiz bakiye!" << endl;
      }
      hesapBulundu = true;
    }
    yaz << bir.hesapno << " " << bir.hsismi << " " << bir.bakiye << endl;
  }

  if (!hesapBulundu) {
      cout << "Hesap bulunamadi!" << endl;
  }

  oku.close();
  remove("banka.txt");
  rename("bankakopya.txt", "banka.txt");
  yaz.close();
}

void hesap::parayatir(int hesapno, int para)
{
  hesap bir;
  bool hesapBulundu = false;
  
  oku.open("banka.txt", ios::in);
  if (!oku) {
      cout << "Dosya acilamadi!" << endl;
      return;
  }

  yaz.open("bankakopya.txt", ios::out);

  if (para < 0) {
      cout << "Negatif bir miktar yatırmak mümkün değil!" << endl;
      return;
  }
  
  while(oku >> bir.hesapno >> bir.hsismi >> bir.bakiye) {
    if(hesapno == bir.hesapno) {
      bir.bakiye += para;
      cout << "Yatirilan miktar: " << para << " TL" << endl;
      cout << "Yeni bakiye: " << bir.bakiye << " TL" << endl;
      hesapBulundu = true;
    }
    yaz << bir.hesapno << " " << bir.hsismi << " " << bir.bakiye << endl;
  }

  if (!hesapBulundu) {
      cout << "Hesap bulunamadi!" << endl;
  }

  oku.close();
  remove("banka.txt");
  rename("bankakopya.txt", "banka.txt");
  yaz.close();
}

int main(int argc, char** argv) {
  hesap bir;
  float para;
  char c;
  
  while(true) {
    cout << endl;
    cout << "Banka islemlerine hosgeldiniz:" << endl;
    cout << "Lutfen islem yapmak istediginiz secenegi belirleyiniz:" << endl;
    cout << "Para yatirma -> 1" << endl;
    cout << "Para cekme -> 2" << endl;
    cout << "Bakiye goruntuleme -> 3" << endl;
    cout << "Cikis -> 4" << endl;

    cin >> c;

    switch(c) {
      case '1':
        cout << "Yatirilacak miktari giriniz : ";
        cin >> para;
        cout << "Hesap noyu giriniz : ";
        cin >> bir.hesapno;
        bir.parayatir(bir.hesapno, para);
        break;

      case '2':
        cout << "Cekilecek miktari giriniz : ";
        cin >> para;
        cout << "Hesap noyu giriniz : ";
        cin >> bir.hesapno;
        bir.paracek(bir.hesapno, para);
        break;

      case '3':
        cout << "Goruntulemek istediginiz hesap noyu giriniz : ";
        cin >> bir.hesapno;
        bir.bilgigoruntule(bir.hesapno);
        break;

      case '4':
        cout << "Cikis yapiliyor..." << endl;
        return 0;
        break;

      default:
        cout << "Yanlis secim, lutfen tekrar deneyiniz!" << endl;
        break;
    }
  }

  return 0;
}
