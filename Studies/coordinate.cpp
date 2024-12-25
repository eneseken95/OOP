#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

class nokta
{
public:
    int x,y;
};

int main(int argc, char** argv) {

   fstream fp;
   int p;

   fp.open("nokta.txt",ios::in|ios::out|ios::binary);
    
   if(!fp)
    cout<<"dosy acilamadi"<<endl;

   nokta bir;

   bir.x=10;
   bir.y=20;
   fp.write((char*)(&bir),sizeof(bir));

   bir.x=3;
   bir.y=5;
   fp.write((char*)(&bir),sizeof(bir));

   bir.x=50;
   bir.y=78;
   fp.write((char*)(&bir),sizeof(bir));

   fp.close();
  
   fp.open("nokta.txt",ios::in|ios::binary);

   while(fp.read((char*)(&bir),sizeof(bir)))
    cout<<bir.x<<" "<<bir.y<<endl;

   fp.close();
   
   fp.open("nokta.txt",ios::out|ios::in|ios::binary);

   while(fp.read((char*)(&bir),sizeof(bir)))
   {
       if(bir.x==3)
       {
       bir.y=7;
       p= -1*(int)sizeof(bir);
       fp.seekp(p,ios::cur);
       fp.write((char*)(&bir),sizeof(bir));
       }
      
   }
   fp.close();
   
}
   
