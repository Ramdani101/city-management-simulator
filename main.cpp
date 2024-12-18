#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <ctime>
#include <cstdint>
#include <windows.h>
using namespace std;

/*
Sertakan informasi tentang setiap variabel dan fungsi yang dipakai

Varible :
int pilihan : untuk menerima masukan pilihan di halaman utama
int lebarLayar : ini untuk lebar layar permainannya
int jatahInteraksi : ini untuk jatah interaksi pemain
int hari : untuk jatah hari;

fungsi  :

void campaignMode() : Fungsi untuk memulai game utama

void howTo() : untuk menampilkan bagaimana sumber daya didalam game bekerja

void keluar() : untuk memberhentikan program

void menuUtama() : untuk menampilkan menu utama

void printDengan2GarisBawah(string) : untuk print text dengan 2 garis bawah

void setColor(int) : untuk ubah warna text, jadi ketika mau cout suatu teks dengan
warna tertentu tinggal diset dulu, baru di cout. Terus ubah lagi ke putih.
nah ini kode warnanya

void printTengah(const string, int) : ini buat print text di tengah berdasarkan
panjang yang kita masukkan diparameter int

0 = Hitam
1 = Biru Gelap
2 = Hijau Gelap
3 = Aqua Gelap
4 = Merah Gelap
5 = Ungu Gelap
6 = Kuning Gelap
7 = Putih (Default)
8 = Abu-abu
9 = Biru
10 = Hijau
11 = Aqua
12 = Merah
13 = Ungu
14 = Kuning
15 = Putih Cerah

*/

void menuUtama();
void campaignMode();
void load();
void howTo();
int keluar();
void setColor(int);
void printDengan2GarisBawah(const string&);
void printTextTengah(const string&, int);
string plusMinus(int, int);
void tampilanPilihan();
void bangunFasilitas ();
void terapkanKebijakan(int*,int*,int*, int*, int*, int*, int*, int*, int*);
void lihatPeta();
void lihatJumlahFasilitas(int*,int*,int*,int*);
void statistikPopulasi();
void save();
void festivalTermina(int*, int*, int&);



int pilihan = 0;
int lebarLayar = 50;
int jatahInteraksi = 3;
int uang = 0, energi = 0, kebahagiaan = 0, pabrik = 0, rumah = 0, destinasiWisata = 0, sumberEnergi = 0;
int hari = 0, kebahagiaanPemilikPabrik = 0, sumberEnergiTambahan = 0, biayaKerjasama = 0, populasiTambahan = 0;
int kebahagiaanSementara = 0;
int hariTerkini = 0;
int durasiFestival = 3;
bool cekFestivalTermina = false;
char petaKota[6][6] = {
    {'O','P','P','P','D','D'},
    {'O','O','O','O','D','D'},
    {'O','R','R','R','D','R'},
    {'E','O','R','O','O','O'},
    {'E','R','R','R','R','R'},
    {'E','O','O','O','O','O'},
};

int main(){
    menuUtama();
    return 0;
}

void menuUtama(){
    setColor(6);
    string selamatDatang = "Selamat Datang di CITY MANGAMENT SIMULATOR v1.0";
    printDengan2GarisBawah(selamatDatang);
    cout << "1. Start New Game \n" << "2. Load \n" << "3. How to \n" << "4. Exit \n";
    setColor(7);
    cout << endl;
    cout << "Pilihan : ";
    cin >> pilihan;
    switch (pilihan)
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

    uang = 10000;
    energi = 30;
    kebahagiaan = 50;
    pabrik = 3;
    rumah = 10;
    destinasiWisata = 5;
    sumberEnergi = 3;
    hari = 10;
    hariTerkini = 1;
    int pajakPabrik = 0;
    int populasi = (rumah*100) + populasiTambahan;
    int energiMasuk = sumberEnergi*10 + sumberEnergiTambahan;
    int energiKeluar = (pabrik*5) + (rumah*1);
    int tingkatKebahagiaan = kebahagiaan + (destinasiWisata*5) + kebahagiaanPemilikPabrik + kebahagiaanSementara;
    int pendapatan = pabrik * (3000 + pajakPabrik);
    int pengeluaran = (sumberEnergi*500) + biayaKerjasama;
    
    cout << "Pada suatu pagi kamu tiba-tiba terbangun ditempat yang asing \n"
    << "Tempat asing itu adalah kamar tidur walikota!! \n"
    << "Kamu melihat kecermin dan menyadari dirimu sedang berada pada raga walikota \n"
    <<  "Saat sedang kondisi terkejut, kemudian muncullah pesan dari ponselmu yang berisi \n";
    setColor(5); cout << "---Walikota yang sebenarnya akan kembali dalam waktu 10 hari lagi--- \n";
    setColor(7); cout << "nasib kota ini berada di tanganmu sekarang !!! \n";
    cout << endl;

    cout << "Tekan apa saja untuk melanjutkan \n";
    cin.ignore();
    cin.get();

    bool kembaliKeMenuUtama = false;
    while (hariTerkini <= hari && !kembaliKeMenuUtama)
    {
        int sisaInteraksi = jatahInteraksi;
        setColor(6);
        cout << string(lebarLayar, '-') << endl;
        printTextTengah("Hari Ke - " + to_string(hariTerkini), lebarLayar);
        cout << string(lebarLayar, '-') << endl;

        if (hariTerkini != 1)
        {
            uang += (pendapatan-pengeluaran);
        }

        if (cekFestivalTermina)
        {
            festivalTermina(&uang, &kebahagiaanSementara, durasiFestival);
        }else{}
        
        //Untuk update stat
        int populasi = (rumah*100) + populasiTambahan;
        int energiMasuk = sumberEnergi*10 + sumberEnergiTambahan;
        int energiKeluar = (pabrik*5) + (rumah*1);
        int tingkatKebahagiaan = kebahagiaan + (destinasiWisata*5) + kebahagiaanPemilikPabrik + kebahagiaanSementara;
        int pendapatan = pabrik * (3000 + pajakPabrik);
        int pengeluaran = (sumberEnergi*500) + biayaKerjasama;
        
        setColor(6);
        cout << "Uang : $" << uang << " | " << plusMinus(pendapatan, pengeluaran)<< "$" << abs(pengeluaran - pendapatan) << "/hari \n";
        cout << "Populasi : " << populasi << endl;
        cout << "Energi : " << plusMinus(energiMasuk, energiKeluar) << abs(energiKeluar-energiMasuk) << "MW \n";
        cout << "Tingkat Kebahagiaan : " << tingkatKebahagiaan << endl; 
        cout << endl;
        
        while (sisaInteraksi > 0 && !kembaliKeMenuUtama)
        {
            setColor(6); cout << "Interaksi : " << sisaInteraksi << endl;
            tampilanPilihan();
            setColor(1); cout << "Pilihan : "; setColor(7);
            cin >> pilihan;
            switch (pilihan)
            {
            case 1:
                bangunFasilitas();
                sisaInteraksi--;
                break;
            case 2:
                terapkanKebijakan(&sisaInteraksi, &kebahagiaanPemilikPabrik, &pajakPabrik, &sumberEnergiTambahan, &biayaKerjasama, &populasiTambahan, &uang, &kebahagiaanSementara, &hariTerkini);
                sisaInteraksi--;
                break;
            case 3:
                lihatPeta();
                break;
            case 4:
                lihatJumlahFasilitas(&pabrik, &rumah, &sumberEnergi, &destinasiWisata);
                break;
            case 5:
                statistikPopulasi();
                break;
            case 6:
                sisaInteraksi = 0;
                break;
            case 7:
                save();
                break;
            case 8:
                kembaliKeMenuUtama = true;
                break;
            default:
                cout << "Pilihan tidak valid, silahkan coba lagi \n";
                break;
            }
        }
        
        hariTerkini++;
        cout << string(lebarLayar, '-') << endl;
        
    }

        if (kembaliKeMenuUtama)
        {
            menuUtama();
        }

}

void howTo(){
    cout << "Sedang dalam tahap pengembangan \n";
    cout << "Tekan 1 untuk kembali \n";
    cin >> pilihan;
    if (pilihan == 1)
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
    cin >> pilihan;
    if (pilihan == 1)
    {
        menuUtama();
    }
}

void setColor(int color){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void printDengan2GarisBawah(const string& text){
    cout << text << endl;
    for (int i = 0; i < text.length(); i++)
    {
        cout << "=";
    }
    cout << endl;
}

void printTextTengah(const string& text, int lebar){
    int padding  = (lebar - text.length())/2;
    if (padding > 0)
    {
        cout << string(padding, ' ');
    }
    cout << text << endl;
}

string plusMinus(int i, int j){
    return (i > j)? "+" : "-";
}

void tampilanPilihan(){
    cout << "\033[43m\033[30mPilih Tindakan : \033[0m \n";
    setColor(4); cout << "1. "; setColor(7); cout << "Bangun Fasilitas (interaksi -1) \n";
    setColor(4); cout << "2. "; setColor(7); cout << "Terapkan Kebijakan (interaksi -1) \n";
    setColor(4); cout << "3. "; setColor(7); cout << "Lihat Peta Kota \n";
    setColor(4); cout << "4. "; setColor(7); cout << "Lihat Jumlah Fasilitas \n";
    setColor(4); cout << "5. "; setColor(7); cout << "Statistik Populasi \n";
    setColor(4); cout << "6. "; setColor(7); cout << "Akhiri Hari \n";
    setColor(4); cout << "7. "; setColor(7); cout << "Save \n";
    setColor(4); cout << "8. "; setColor(7); cout << "Kembali Ke Menu Utama \n";
}

void bangunFasilitas (){
    cout << "Sedang dalam tahap pengembangan \n";
}

void lihatPeta(){
    int baris =6;
    int kolom =6;
    setColor(6); cout << string(25,'-') << endl;
    for (int i = 0; i < baris; i++)
    {
        for (int j = 0; j < kolom; j++)
        {
            switch (petaKota[i][j])
            {
            case 'R':
                setColor(13); cout << petaKota[i][j] << " ";
                break;
            case 'P':
                setColor(12); cout << petaKota[i][j] << " ";
                break;
            case 'E':
                setColor(10); cout << petaKota[i][j] << " ";
                break;
            case 'D':
                setColor(11); cout << petaKota[i][j] << " ";
                break;
            default:
                setColor(7); cout << petaKota[i][j] << " ";
                break;
            }
        }
        cout << endl;
    }
    setColor(6); cout << string(25,'-') << endl;
    cout << endl;
    cout << "Keterangan : \n";
    setColor(12); cout << "P"; setColor(7); cout <<" = Pabrik \n";
    setColor(13); cout << "R"; setColor(7); cout <<" = Rumah \n";
    setColor(10); cout << "E"; setColor(7); cout <<" = Sumber Energi \n";
    setColor(11); cout << "D"; setColor(7); cout <<" = Destinasi Wisata \n";
    cout << endl;
}
void lihatJumlahFasilitas(int* p, int* r, int* e, int* d){
    setColor(6); cout << string(25, '-') << endl;
    setColor(7);
    cout << "Pabrik : " << *p << endl;
    cout << "Rumah : " << *r << endl;
    cout << "Sumber Energi : " << *e << endl;
    cout << "Destinasi Wisata : " << *d << endl;
    setColor(6); cout << string(25, '-') << endl;
}
void statistikPopulasi(){
    cout << "Sedang dalam tahap pengembangan \n";
}
void save(){
    cout << "Sedang dalam tahap pengembangan \n";
}

void terapkanKebijakan(int* a, int* b, int* c, int* d, int* e, int* f, int* g, int* h, int* i){
    /*
    int a = sisa interaksi, int b = kebahagiaan pemilik pabrik, int c = pajakPabrik, int d = sumberEnergiTambahan, int e = biayaKerjasama
    int f = populasiTambahan, int g = uang, int h = kebahagiaanSementara, int i = hariTerkini
    */ 
    setColor(6);
    printTextTengah("KEBIJAKAN KOTA", lebarLayar);
    cout << string(lebarLayar,'-');
    cout << endl;
    setColor(7); cout << "1. Tingkatkan pajak untuk pabrik \n";
    cout << "   Efek : \n"; 
    setColor(2); cout << "Penghasilan tiap pabrik +$1000/hari \n";
    setColor(4); cout << "Kebahagaian -15% \n";
    cout << endl;
    setColor(7); cout << "2. Mengadakan Festival of Termina selama 3 hari \n";
    cout << "   Efek : \n"; 
    setColor(2); cout << "Kebahagiaan +15% \n";
    setColor(4); cout << "Uang -$5000/hari \n";
    cout << endl;
    setColor(7); cout << "3. Bekerja sama dengan Tony Stark untuk pengadaan sumber energi \n";
    cout << "   Efek : \n"; 
    setColor(2); cout << "Energi +20MW/Hari \n";
    setColor(4); cout << "Uang -$1500/hari \n";
    cout << endl;
    setColor(7); cout << "4. Bagikan sprey gratis ke setiap warga \n";
    cout << "   Efek : \n"; 
    setColor(2); cout << "Populasi +300 \n";
    setColor(4); cout << "Uang -$2000 \n";
    cout << endl;
    setColor(7); cout << "5. Batal\n";
    
     setColor(1); cout << "Pilihan : ";
     cin >> pilihan;
     switch (pilihan)
     {
     case 1:
        *c += 1000;
        *b += -15;
        *a--;
        setColor(13);
        cout << string(lebarLayar, '-') << endl;
        printTextTengah("KEBIJAKAN TELAH DITERAPKAN", lebarLayar);
        cout << string(lebarLayar, '-') << endl;
        setColor(7);
        break;
     case 2:
        *a--;
        cekFestivalTermina = true;
        setColor(13);
        cout << string(lebarLayar, '-') << endl;
        printTextTengah("KEBIJAKAN TELAH DITERAPKAN", lebarLayar);
        cout << string(lebarLayar, '-') << endl;
        setColor(7);
        break;
     case 3:
        *d += 20;
        *e += 1500;
        *a--;
        setColor(13);
        cout << string(lebarLayar, '-') << endl;
        printTextTengah("KEBIJAKAN TELAH DITERAPKAN", lebarLayar);
        cout << string(lebarLayar, '-') << endl;
        setColor(7);
        break;
     case 4:
        *f += 300;
        *g -= 2000;
        setColor(13);
        cout << string(lebarLayar, '-') << endl;
        printTextTengah("KEBIJAKAN TELAH DITERAPKAN", lebarLayar);
        cout << string(lebarLayar, '-') << endl;
        setColor(7);
        break;
     default:
        break;
     }

};

void festivalTermina(int *a, int *b, int &c) {
    *a -= 5000;
    *b = 15;
    c--;
    if (c == 0)
    {
        //setColor(11) = warna aqua
        setColor(11); cout << "Festival Termina sudah Berakhir!!! Terima Kasih Pa Wali Kota \n";
        cekFestivalTermina = false;
        *b = 0;
    }else{
        setColor(11); cout << "Festival Termina sedang berlangsung!! \n";
    }
    
}

