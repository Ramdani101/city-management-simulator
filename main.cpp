#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>
#include <cstdint>
using namespace std;

/*
Sertakan informasi tentang setiap variabel dan fungsi yang dipakai

Varible :
int pilihanMenuUtama : untuk menerima masukan pilihan di halaman utama

fungsi  :

void campaignMode() : Fungsi untuk memulai game utama
void howTo() : untuk menampilkan bagaimana sumber daya didalam game bekerja
void keluar() : untuk memberhentikan program

*/

void menuUtama();
void campaignMode();
void load();
void howTo();
int keluar();

int pilihanMenuUtama = 0;

int main(){
    menuUtama();
    return 0;
}

void menuUtama(){
    cout << "Selamat Datang di CITY MANGAMENT SIMULATOR v1.0 \n"
    << "--------------------------------- \n"
    << "1. Start New Game \n" << "2. Load \n" << "3. How to \n" << "4. Exit \n";
    cout << "Pilihan : ";
    cin >> pilihanMenuUtama;
    switch (pilihanMenuUtama)
    {
    case 1 :
        campaignMode();
        break;
    case 2 :
        load();
        break;
    case 3 :
        howTo();
        break;
    case 4 :
        keluar();
    default:
        keluar();
        break;
    }
}

void campaignMode(){
    cout << "Sedang dalam tahap pengembangan \n";
    cout << "Tekan 1 untuk kembali \n";
    cin >> pilihanMenuUtama;
    if (pilihanMenuUtama == 1)
    {
        menuUtama();
    }
    

}

void howTo(){
    cout << "Sedang dalam tahap pengembangan \n";
    cout << "Tekan 1 untuk kembali \n";
    cin >> pilihanMenuUtama;
    if (pilihanMenuUtama == 1)
    {
        menuUtama();
    }
}

int keluar(){
    cout << "Terima kasih telah bermain!!! \n";
    return 0;
}

void load(){
    cout << "Sedang dalam tahap pengembangan \n";
    cout << "Tekan 1 untuk kembali \n";
    cin >> pilihanMenuUtama;
    if (pilihanMenuUtama == 1)
    {
        menuUtama();
    }
}
