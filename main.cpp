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
void bangunFasilitas (int *pSisaInteraksi, char petaKota[6][6]);
void upgradeFasilitas(int* interaksi);
void terapkanKebijakan();
void robohkanFasilitas(int*);
void lihatPeta();
void lihatJumlahFasilitas(int*,int*,int*,int*);
void statistikPopulasi();
void save();
void menuBangunFasilitas(int *pSisaInteraksi, char alias, int biaya, int pekerjaFasilitas,int* total, int &targetKordinatX, int &targetKordinatY);
void statistikHarian ();

int pilihan = 0;
int lebarLayar = 50;
int jatahInteraksi = 3;
int uang = 0, energi = 0, kebahagiaan = 0;
int Jpabrik = 0, Jrumah = 0, JdestinasiWisata = 0, JsumberEnergi = 0;
int JpabrikOn = 0, JsumberEnergiOn = 0;
int hari = 0;
int hariTerkini = 0;
int populasi = 0;
int pekerja = 0;
int energiMasuk = 0;
int energiKeluar = 0;
int tingkatKebahagiaan = 0;
int pendapatan = 0;
int pengeluaran = 0;
int rumahCD = 0;
double lvlBonus = 100; //ini untuk menentukan bonus per level
char petaKota[6][6] = {
    {'O','P','P','P','D','D'},
    {'O','O','O','O','D','D'},
    {'O','R','R','R','D','R'},
    {'E','O','R','O','O','O'},
    {'E','R','R','R','R','R'},
    {'E','O','O','O','O','O'},
};
char petaLvlFasilitas[6][6] = {
    {'O','1','1','1','1','1'},
    {'O','O','O','O','1','1'},
    {'O','1','1','1','1','1'},
    {'1','O','1','O','O','O'},
    {'1','1','2','2','2','1'},
    {'1','O','O','O','O','O'},
};
struct Index
{
    int x;
    int y;
    int level;
};
struct bangunan 
{
    char alias;
    int biaya, populasi, pekerja, energi, pendapatan, kebahagiaan;
    Index index[32];
};

bangunan rumah = {'R', 500, 100, 0, 1, 0, 0}, pabrik = {'P', 3000, 0, 50, 5, 3000, 5}, destinasiWisata = {'D', 1500, 0, 0, 0, 0, 5}, sumberEnergi = {'E', 1500, 0, 50, 10, 500};


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
    Jpabrik = 3;
    JpabrikOn = Jpabrik;
    Jrumah = 10;
    JdestinasiWisata = 5;
    JsumberEnergi = 3;
    JsumberEnergiOn = JsumberEnergi;
    hari = 10;
    hariTerkini = 1;
    populasi = Jrumah*100;
    pekerja = populasi - (JpabrikOn*50) - (JsumberEnergiOn*50);
    energiMasuk = JsumberEnergiOn*10;
    energiKeluar = (JpabrikOn*5) + (Jrumah*1);
    tingkatKebahagiaan = kebahagiaan + (JdestinasiWisata*5) - (JpabrikOn*5);
    pendapatan = JpabrikOn * 3000;
    pengeluaran = JsumberEnergiOn*500;
    rumahCD = 1;
    
    cout << "Pada suatu pagi kamu tiba-tiba terbangun ditempat yang asing \n"
    << "Tempat asing itu adalah kamar tidur walikota!! \n"
    << "Kamu melihat kecermin dan menyadari dirimu sedang berada pada raga walikota \n"
    <<  "Saat sedang kondisi terkejut, kemudian muncullah pesan dari ponselmu yang berisi \n"
    << "-Walikota yang sebenarnya akan kembali dalam waktu 10 hari lagi- \n"
    << "nasib kota ini berada di tanganmu sekarang !!! \n";
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
        
        while (sisaInteraksi > 0 && !kembaliKeMenuUtama)
        {
            setColor(6); cout << string(lebarLayar, '-') << endl;
            cout << "Uang : $" << uang << " | " << plusMinus(pendapatan, pengeluaran)<< "$" << abs(pengeluaran - pendapatan) << "/hari \n";
            cout << "Populasi : " << populasi << endl;
            cout << "Pekerja : " << pekerja << endl;
            cout << "Energi : " << plusMinus(energiMasuk, energiKeluar) << abs(energiKeluar-energiMasuk) << "MW \n";
            cout << "Tingkat Kebahagiaan : " << tingkatKebahagiaan << endl; 
            cout << endl;

            setColor(6); cout << "Interaksi : " << sisaInteraksi << endl;
            tampilanPilihan();
            setColor(1); cout << "Pilihan : "; setColor(7);
            cin >> pilihan;
            switch (pilihan)
            {
            case 1:
                bangunFasilitas(&sisaInteraksi, petaKota);
                break;
            case 2:
                upgradeFasilitas(&sisaInteraksi);
                break;
            case 3:
                terapkanKebijakan();
                sisaInteraksi--;
                break;
            case 4:
                robohkanFasilitas(&sisaInteraksi);
                sisaInteraksi--;
                break;
            case 5:
                lihatPeta();
                break;
            case 6:
                lihatJumlahFasilitas(&Jpabrik, &Jrumah, &JsumberEnergi, &JdestinasiWisata);
                break;
            case 7:
                statistikPopulasi();
                break;
            case 8:
                sisaInteraksi = 0;
                break;
            case 9:
                save();
                break;
            case 10:
                kembaliKeMenuUtama = true;
                break;
            default:
                cout << "Pilihan tidak valid, silahkan coba lagi \n";
                break;
            }
        }
        
        hariTerkini++;
        // code code di bawah ini untuk menghitung sisa resource dan di tambah untuk besok
        // JpabrikOn dan JsumberEnergiOn untuk menentukan apakah mereka aktif atau enggak - zaki
        statistikHarian();
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
    setColor(4); cout << "2. "; setColor(7); cout << "Tingkatkan Fasilitas (interaksi -1) \n";
    setColor(4); cout << "3. "; setColor(7); cout << "Terapkan Kebijakan (interaksi -1) \n";
    setColor(4); cout << "4. "; setColor(7); cout << "Robohkan Fasilitas (interaksi -1) \n";
    setColor(4); cout << "5. "; setColor(7); cout << "Lihat Peta Kota \n";
    setColor(4); cout << "6. "; setColor(7); cout << "Lihat Jumlah Fasilitas \n";
    setColor(4); cout << "7. "; setColor(7); cout << "Statistik Populasi \n";
    setColor(4); cout << "8. "; setColor(7); cout << "Akhiri Hari \n";
    setColor(4); cout << "9. "; setColor(7); cout << "Save \n";
    setColor(4); cout << "10. "; setColor(7); cout << "Kembali Ke Menu Utama \n";
}

void bangunFasilitas (int *pSisaInteraksi, char petaKota[6][6]){
    int pilihan = 0, X = 0, Y = 0;
    cout << "Pilih bangunan yang ingin di bangun:\n";
    setColor(12); cout << "1. Pabrik\n"; setColor(7); cout << "Biaya : $" << pabrik.biaya << "\nEnergi : -" << pabrik.energi << "MW/hari\nUang : +$" << pabrik.pendapatan << "/hari\nPekerja : -" << pabrik.pekerja << "\nKebahagiaan : -" << pabrik.kebahagiaan << "%\n\n";
    setColor(13); cout << "2. Rumah\n"; setColor(7); cout << "Biaya : $" << rumah.biaya << "\nPopulasi : +" << rumah.populasi << "\nEnergi : -" << rumah.energi << "MW/hari\n\n";
    setColor(10); cout << "3. Sumber energi\n"; setColor(7); cout << "Biaya : $" << sumberEnergi.biaya << "\nEnergi : +" << sumberEnergi.energi << "MW/hari\nUang : -$" << sumberEnergi.pendapatan << "/hari\nPekerja : -" << sumberEnergi.pekerja << "\n\n";
    setColor(11); cout << "4. Destinasi wisata\n"; setColor(7); cout << "Biaya : $" << destinasiWisata.biaya << "\nKebahagiaan : +" << destinasiWisata.kebahagiaan << "%\n\n";
    cout << "5. Batal\n\n";
    while (pilihan < 1 || pilihan > 5)
    {
        cout << "\033[43m\033[30mPilihan: \033[0m \n";
        cin >> pilihan;
        switch (pilihan)
        {
            case 1:
                menuBangunFasilitas(pSisaInteraksi, pabrik.alias, pabrik.biaya, pabrik.pekerja, &Jpabrik, pabrik.index[Jpabrik].x, pabrik.index[Jpabrik].y);
                break;
            case 2:
                menuBangunFasilitas(pSisaInteraksi, rumah.alias, rumah.biaya, rumah.pekerja, &Jrumah, rumah.index[Jrumah].x, rumah.index[Jrumah].y);
                break;
            case 3: 
                menuBangunFasilitas(pSisaInteraksi, sumberEnergi.alias, sumberEnergi.biaya, sumberEnergi.pekerja, &JsumberEnergi, sumberEnergi.index[JsumberEnergi].x, sumberEnergi.index[JsumberEnergi].y);
                break;
            case 4: 
                menuBangunFasilitas(pSisaInteraksi, destinasiWisata.alias, destinasiWisata.biaya, destinasiWisata.pekerja, &JdestinasiWisata, destinasiWisata.index[JdestinasiWisata].x, destinasiWisata.index[JdestinasiWisata].y);
                break;
            case 5:
            return;
        } //pusing
        return;
    }
}

void menuBangunFasilitas(int* pSisaInteraksi, char alias, int biaya, int pekerjaFasilitas,int* total, int &targetKordinatX, int &targetKordinatY)
{
    int X = 0, Y = 0;
    if (uang < biaya && pekerja < pekerjaFasilitas)
    {
        setColor(12); cout << "Resource anda tidak cukup\n"; setColor(7);
        pilihan = 0;
    }
    else
    {
        lihatPeta();
    }
    int i = 0;
    while(i == 0){
        cout << "Tentukan kordinat lahan\n";
        cout << "baris: ";
        cin >> X;
        cout << "kolom: ";
        cin >> Y;
        if (petaKota[X-1][Y-1] == 'O')
        {
            petaKota[X-1][Y-1] = alias;
            petaLvlFasilitas[X-1][Y-1] = '1';
            total++;
            targetKordinatX = X-1;
            targetKordinatY = Y-1;
            uang-=biaya;
            setColor(13);
            cout << string(lebarLayar, '-') << endl;
            printTextTengah("BANGUNAN BERHASIL DIBANGUN", lebarLayar);
            cout << string(lebarLayar, '-') << endl;
            setColor(7);
            *pSisaInteraksi = *pSisaInteraksi - 1;
            return;
        }
        else
        {
            setColor(12);
            cout << string(lebarLayar, '-') << endl;
            printTextTengah("LAHAN TERSEBUT MASIH ADA BANGUNAN", lebarLayar);
            cout << string(lebarLayar, '-') << endl;
            setColor(7);
            pilihan = 0;
        }
    }
}

void upgradeFasilitas(int* interaksi)
{
    int pilihFasilitas;
    int konfirmasi;
    int baris = 6;
    int kolom = 6;
    int index = 0;
    cout << "\033[43m\033[30mPilih Fasilitas : \033[0m \n";
    for (int i = 0; i < baris; i++)
    {
        for (int j = 0; j < kolom; j++)
        {
            index=index+1;
            switch (petaKota[i][j])
            {
            case 'P':
                setColor(4); cout << index << ". Pabrik level " << petaLvlFasilitas[i][j] << " (" << i+1 << "," << j <<") \n";
                break;
            case 'R':
                setColor(5); cout << index << ". Rumah level " << petaLvlFasilitas[i][j] << " (" << i+1 << "," << j+1 <<") \n";
                break;
            case 'E':
                setColor(10); cout << index << ". Sumber Energi level " << petaLvlFasilitas[i][j] << " (" << i+1 << "," << j+1 <<") \n";
                break;
            case 'D':
                setColor(11); cout << index << ". Destinasi Wisata level " << petaLvlFasilitas[i][j] << " (" << i+1 << "," << j+1 <<") \n";
                break;
            default:
                index--;
                break;
            }
        }
    }
    setColor(7); cout << index+1 << ". Back" << "\n";
    setColor(1); cout << "Pilihan : "; setColor(7);
    cin >> pilihFasilitas;

    if (pilihFasilitas == index+1)
    {
        *interaksi = *interaksi + 1;
    }else
    {
        setColor(6);cout << string(lebarLayar, '-') << endl;setColor(7);
        index = 0;
        for (int i = 0; i < baris; i++)
        {
            for (int j = 0; j < kolom; j++)
            {
                switch (petaKota[i][j])
                {
                    case 'O':
                    break;
                    default:
                        index=index+1;
                    break;
                }
                if (index == pilihFasilitas)
                {
                    switch (petaKota[i][j])
                    {
                        case 'P':
                            setColor(12); cout << "Pabrik Level " << petaLvlFasilitas[i][j] << " > " << petaLvlFasilitas[i][j]-47 << '\n'; setColor(7);
                            cout << "Biaya : $" << 1500 * (1+(lvlBonus*(petaLvlFasilitas[i][j]-49))) << '\n';
                            cout << "Penghasilan : +$" << pabrik.pendapatan * (1+(lvlBonus*(petaLvlFasilitas[i][j]-49))) << "/hari > +$" << pabrik.pendapatan * (1+(lvlBonus*(petaLvlFasilitas[i][j]-48))) << "/hari\n";
                            cout << "Pekerja : -" << pabrik.pekerja * (1+(lvlBonus*(petaLvlFasilitas[i][j]-49))) << " > -" << pabrik.pekerja * (1+(lvlBonus*(petaLvlFasilitas[i][j]-48))) << "\n\n";

                            setColor(6); cout << "Apakah anda yakin? \n";
                            setColor(10); cout << "1. "; cout << "Ya \n";
                            setColor(7); cout << "2. "; cout << "Tidak \n";
                            setColor(1); cout << "Pilihan : "; setColor(7);
                            cin >> konfirmasi;
                            cout << endl;
                            if (konfirmasi == 1)
                            {
                                petaLvlFasilitas[i][j]++;
                                uang -=1500 * (1+(lvlBonus*(petaLvlFasilitas[i][j]-49)));
                                *interaksi = *interaksi -1;
                                setColor(13);
                                cout << string(lebarLayar, '-') << endl;
                                printTextTengah("BANGUNAN BERHASIL DIPERBARUI", lebarLayar);
                                cout << string(lebarLayar, '-') << endl;
                                setColor(7);
                                break;
                            }
                            else
                            {
                                upgradeFasilitas(interaksi);
                            }
                        break;
                        case 'R':
                            setColor(13); cout << "Rumah Level " << petaLvlFasilitas[i][j] << " > " << petaLvlFasilitas[i][j]-47 << '\n'; setColor(7);
                            cout << "Biaya : $" << 250 * (1+(lvlBonus*(petaLvlFasilitas[i][j]-49))) << '\n';
                            cout << "Populasi : +" << rumah.populasi * (1+(0.5*(petaLvlFasilitas[i][j]-49))) << " > +" << rumah.populasi * (1+(lvlBonus*(petaLvlFasilitas[i][j]-48))) << "\n\n";

                            setColor(6); cout << "Apakah anda yakin? \n";
                            setColor(10); cout << "1. "; cout << "Ya \n";
                            setColor(7); cout << "2. "; cout << "Tidak \n";
                            setColor(1); cout << "Pilihan : "; setColor(7);
                            cin >> konfirmasi;
                            cout << endl;
                            if (konfirmasi == 1)
                            {
                                petaLvlFasilitas[i][j]++;
                                uang -=250 * (1+(lvlBonus*(petaLvlFasilitas[i][j]-49)));
                                *interaksi = *interaksi -1;
                                setColor(13);
                                cout << string(lebarLayar, '-') << endl;
                                printTextTengah("BANGUNAN BERHASIL DIPERBARUI", lebarLayar);
                                cout << string(lebarLayar, '-') << endl;
                                setColor(7);
                                break;
                            }
                            else
                            {
                                upgradeFasilitas(interaksi);
                            }
                        break;
                        case 'E':
                            setColor(10);cout << "Sumber energi Level " << petaLvlFasilitas[i][j] << " > " << petaLvlFasilitas[i][j]-47 << '\n'; setColor(7);
                            cout << "Biaya : $" << 750 * (1+(lvlBonus*(petaLvlFasilitas[i][j]-49))) << '\n';
                            cout << "Energi : +" << sumberEnergi.energi * (1+(lvlBonus*(petaLvlFasilitas[i][j]-49))) << " > +" << sumberEnergi.energi * (1+(lvlBonus*(petaLvlFasilitas[i][j]-48))) << '\n';
                            cout << "Pengeluaran : -" << sumberEnergi.pendapatan * (1+(lvlBonus*(petaLvlFasilitas[i][j]-49))) << " > -" << sumberEnergi.pendapatan * (1+(lvlBonus*(petaLvlFasilitas[i][j]-48))) << '\n';
                            cout << "Pekerja : -" << sumberEnergi.pekerja * (1+(lvlBonus*(petaLvlFasilitas[i][j]-49))) << " > -" << sumberEnergi.pekerja * (1+(lvlBonus*(petaLvlFasilitas[i][j]-48))) << "\n\n";

                            setColor(6); cout << "Apakah anda yakin? \n";
                            setColor(10); cout << "1. "; cout << "Ya \n";
                            setColor(7); cout << "2. "; cout << "Tidak \n";
                            setColor(1); cout << "Pilihan : "; setColor(7);
                            cin >> konfirmasi;
                            cout << endl;
                            if (konfirmasi == 1)
                            {
                                petaLvlFasilitas[i][j]++;
                                uang -=750 * (1+(lvlBonus*(petaLvlFasilitas[i][j]-49)));
                                *interaksi = *interaksi -1;
                                setColor(13);
                                cout << string(lebarLayar, '-') << endl;
                                printTextTengah("BANGUNAN BERHASIL DIPERBARUI", lebarLayar);
                                cout << string(lebarLayar, '-') << endl;
                                setColor(7);
                                break;
                            }
                            else
                            {
                                upgradeFasilitas(interaksi);
                            }
                        break;
                        case 'D':
                            setColor(11); cout << "Pabrik Level " << petaLvlFasilitas[i][j] << " > " << petaLvlFasilitas[i][j]-47 << '\n'; setColor(7);
                            cout << "Biaya : " << 750 * (1+(lvlBonus*(petaLvlFasilitas[i][j]-49))) << '\n';
                            cout << "Kebahagiaan : +" << destinasiWisata.kebahagiaan * (1+(lvlBonus*(petaLvlFasilitas[i][j]-49))) << " > +" << destinasiWisata.kebahagiaan * (1+(lvlBonus*(petaLvlFasilitas[i][j]-48))) << "\n\n";

                            setColor(6); cout << "Apakah anda yakin? \n";
                            setColor(10); cout << "1. "; cout << "Ya \n";
                            setColor(7); cout << "2. "; cout << "Tidak \n";
                            setColor(1); cout << "Pilihan : "; setColor(7);
                            cin >> konfirmasi;
                            if (konfirmasi == 1)
                            {
                                petaLvlFasilitas[i][j]++;
                                uang -=750 * (1+(lvlBonus*(petaLvlFasilitas[i][j]-49)));
                                *interaksi = *interaksi -1;
                                setColor(13);
                                cout << string(lebarLayar, '-') << endl;
                                printTextTengah("BANGUNAN BERHASIL DIPERBARUI", lebarLayar);
                                cout << string(lebarLayar, '-') << endl;
                                setColor(7);
                                break;
                            }
                            else
                            {
                                upgradeFasilitas(interaksi);
                            }
                        break;
                    }
                }
            }
        }
    }
}

void terapkanKebijakan(){
    cout << "Sedang dalam tahap pengembangan \n";
}

void statistikHarian()
{
    populasi = 0;
    JpabrikOn = 0;
    JsumberEnergiOn = 0;
    pendapatan = 0;
    pengeluaran = 0;
    energiKeluar = 0;
    energiMasuk = 0;
    tingkatKebahagiaan = kebahagiaan;
    rumahCD = 1;

    for (int i =0; i < 6;i++)
    {
        for (int j = 0;j < 6;j++)
        {
            if(petaKota[i][j] == 'R')
            {
                populasi+= rumah.populasi * (1+(lvlBonus*(petaLvlFasilitas[i][j]-49)));
                energiKeluar+= rumah.energi;
            }
        }
    }

    pekerja = populasi;

    for(int i = 0; i < 6;i++)
    {
        for (int j = 0;j < 6;j++)
        {
            switch(petaKota[i][j])
            {
                case 'P':
                    if (pekerja > pabrik.pekerja)
                    {
                        pendapatan+= pabrik.pendapatan * (1+(lvlBonus*(petaLvlFasilitas[i][j]-49)));
                        pekerja-= pabrik.pekerja * (1+(lvlBonus*(petaLvlFasilitas[i][j]-49)));
                        tingkatKebahagiaan-=pabrik.kebahagiaan;
                        energiKeluar+= pabrik.energi;
                        JpabrikOn++;
                    }
                break;
                case 'E':
                    if (pekerja > sumberEnergi.pekerja)
                    {
                        pengeluaran+= sumberEnergi.pendapatan * (1+(lvlBonus*(petaLvlFasilitas[i][j]-49)));
                        energiMasuk+= sumberEnergi.energi * (1+(lvlBonus*(petaLvlFasilitas[i][j]-49)));
                        pekerja-= sumberEnergi.pekerja * (1+(lvlBonus*(petaLvlFasilitas[i][j]-49)));
                        JsumberEnergiOn++;
                    }

                break;
                case 'D':
                    tingkatKebahagiaan+=destinasiWisata.kebahagiaan * (1+(lvlBonus*(petaLvlFasilitas[i][j]-49)));
                break;
            }
        }
        uang = uang + pendapatan - pengeluaran;
    }

    if(tingkatKebahagiaan < 50)//untuk menghitung mundur dan menghapus sebuah rumah
    {
        cout << "";
        rumahCD++;
        if(rumahCD%3 == 0)
        {
            rumahCD = 1;
            Jrumah--;
            petaKota[rumah.index[Jrumah].y][rumah.index[Jrumah].x] = 'O';
            petaLvlFasilitas[rumah.index[Jrumah].y][rumah.index[Jrumah].x] = 'O';
        }
    }
    else 
    {
        rumahCD = 1;
    }
}

void robohkanFasilitas (int* interaksi){
    cout << endl;
    int pilihFasilitas;
    int konfirmasi;
    int baris = 6;
    int kolom = 6;
    int index = 0;
    cout << "\033[43m\033[30mPilih Fasilitas : \033[0m \n";
    for (int i = 0; i < baris; i++)
    {
        for (int j = 0; j < kolom; j++)
        {
            index=index+1;
            switch (petaKota[i][j])
            {
            case 'P':
                setColor(4); cout << index << ". Pabrik level " << petaLvlFasilitas[i][j] << " (" << i+1 << "," << j <<") \n";
                break;
            case 'R':
                setColor(5); cout << index << ". Rumah level " << petaLvlFasilitas[i][j] << " (" << i+1 << "," << j+1 <<") \n";
                break;
            case 'E':
                setColor(10); cout << index << ". Sumber Energi level " << petaLvlFasilitas[i][j] << " (" << i+1 << "," << j+1 <<") \n";
                break;
            case 'D':
                setColor(11); cout << index << ". Destinasi Wisata level " << petaLvlFasilitas[i][j] << " (" << i+1 << "," << j+1 <<") \n";
                break;
            default:
                index--;
                break;
            }
        }
    }
    setColor(7); cout << index+1 << ". Back" << "\n";
    setColor(1); cout << "Pilihan : "; setColor(7);
    cin >> pilihFasilitas;
    cout << endl;

    if (pilihFasilitas == index+1)
    {
        *interaksi = *interaksi + 1;
    }else{
        setColor(6); cout << "Apakah anda yakin? \n";
        setColor(4); cout << "1. "; cout << "Ya \n";
        setColor(7); cout << "2. "; cout << "Tidak \n";
        setColor(1); cout << "Pilihan : "; setColor(7);
        cin >> konfirmasi;
        cout << endl;

        if (konfirmasi == 1)
        {
        index = 0;
            for (int i = 0; i < baris; i++)
                {
                    for (int j = 0; j < kolom; j++)
                    {
                        switch (petaKota[i][j])
                        {
                        case 'O':
                            break;
                        default:
                            index=index+1;
                        break;
                        }
                        if (index == pilihFasilitas)
                        {
                            switch (petaKota[i][j])
                            {
                                case 'P':
                                    setColor(4); cout << index << ". Pabrik (" << i+1 << "," << j <<") ";
                                    Jpabrik=Jpabrik-1;
                                    break;
                                case 'R':
                                    setColor(5); cout << index << ". Rumah (" << i+1 << "," << j+1 <<") ";
                                    Jrumah=Jrumah-1;
                                    break;
                                case 'E':
                                    setColor(10); cout << index << ". Sumber Energi (" << i+1 << "," << j+1 <<") ";
                                    JsumberEnergi=JsumberEnergi-1;
                                    break;
                                case 'D':
                                    setColor(11); cout << index << ". Destinasi Wisata (" << i+1 << "," << j+1 <<") ";
                                    JdestinasiWisata=JdestinasiWisata-1;
                                    break;
                            }
                            cout << "berhasil dirobohkan \n";
                            uang=uang-5;
                            petaKota[i][j] = 'O';
                            petaLvlFasilitas[i][j] = 'O';
                        }
                        
                    }
                }
                cout << endl;
        }else
        {
            robohkanFasilitas(interaksi);
        }
    }
   
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
                setColor(13); cout << petaKota[i][j] << petaLvlFasilitas[i][j] << " ";
                break;
            case 'P':
                setColor(12); cout << petaKota[i][j] << petaLvlFasilitas[i][j] << " ";
                break;
            case 'E':
                setColor(10); cout << petaKota[i][j] << petaLvlFasilitas[i][j] << " ";
                break;
            case 'D':
                setColor(11); cout << petaKota[i][j] << petaLvlFasilitas[i][j] << " ";
                break;
            default:
                setColor(7); cout << petaKota[i][j] << petaLvlFasilitas[i][j] << " ";
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
void lihatJumlahFasilitas(int* pPabrik, int* pRumah, int* pSumb_energi, int* pDestinasi){
    setColor(6); cout << string(25, '-') << endl;
    setColor(7);
    cout << "Pabrik : " << *pPabrik << endl;
    cout << "Rumah : " << *pRumah << endl;
    cout << "Sumber Energi : " << *pSumb_energi << endl;
    cout << "Destinasi Wisata : " << *pDestinasi << endl;
    setColor(6); cout << string(25, '-') << endl;
}
void statistikPopulasi(){
    cout << "Sedang dalam tahap pengembangan \n";
}
void save(){
    cout << "Sedang dalam tahap pengembangan \n";
}
