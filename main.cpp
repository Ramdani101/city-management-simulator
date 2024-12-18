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
void bangunFasilitas (char petaKota[6][6]);
void terapkanKebijakan();
void robohkanFasilitas(int*);
void lihatPeta();
void lihatJumlahFasilitas(int*,int*,int*,int*);
void statistikPopulasi();
void save();

int pilihan = 0;
int lebarLayar = 50;
int jatahInteraksi = 3;
int uang = 0, energi = 0, kebahagiaan = 0, pekerja = 0;
int Jpabrik = 0, Jrumah = 0, JdestinasiWisata = 0, JsumberEnergi = 0;
int JpabrikOn = 0, JsumberEnergiOn = 0;
int hari = 0;
int hariTerkini = 0;
char petaKota[6][6] = {
    {'O','P','P','P','D','D'},
    {'O','O','O','O','D','D'},
    {'O','R','R','R','D','R'},
    {'E','O','R','O','O','O'},
    {'E','R','R','R','R','R'},
    {'E','O','O','O','O','O'},
};
struct Index
{
    bool aktif = true;
    int x, y;
};
struct bangunan 
{
    char alias;
    int biaya, pekerja;
    Index index[32];
};

bangunan rumah = {'R', 500, 0}, pabrik = {'P', 3000, 50}, destinasiWisata = {'D', 1500, 0}, sumberEnergi = {'E', 1500, 50};


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
    int populasi = Jrumah*100;
    int pekerja = populasi - (JpabrikOn*50) - (JsumberEnergiOn*50);
    int energiMasuk = JsumberEnergiOn*10;
    int energiKeluar = (JpabrikOn*5) + (Jrumah*1);
    int tingkatKebahagiaan = kebahagiaan + (JdestinasiWisata*5) - (JpabrikOn*5);
    int pendapatan = JpabrikOn * 3000;
    int pengeluaran = JsumberEnergiOn*500;
    int rumahCD = 1;
    
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
                bangunFasilitas(petaKota);
                sisaInteraksi--;
                break;
            case 2:
                terapkanKebijakan();
                sisaInteraksi--;
                break;
            case 3:
                robohkanFasilitas(&sisaInteraksi);
                sisaInteraksi--;
                break;
            case 4:
                lihatPeta();
                break;
            case 5:
                lihatJumlahFasilitas(&Jpabrik, &Jrumah, &JsumberEnergi, &JdestinasiWisata);
                break;
            case 6:
                statistikPopulasi();
                break;
            case 7:
                sisaInteraksi = 0;
                break;
            case 8:
                save();
                break;
            case 9:
                kembaliKeMenuUtama = true;
                break;
            default:
                cout << "Pilihan tidak valid, silahkan coba lagi \n";
                break;
            }
        }
        
        hariTerkini++;
        // code code di bawah ini untuk menghitung sisa resource dan di tambah untuk besok - zaki
        populasi = Jrumah*100;
        JpabrikOn = 0; // JpabrikOn dan JsumberEnergiOn untuk menentukan apakah mereka aktif atau enggak
        JsumberEnergiOn = 0;
        pekerja = populasi;

        for(int i = 0; i < Jpabrik + JsumberEnergi;i++) //ini untuk menentukan berapa banyak pabrik dan sumber energi yang aktif
        {
            if (pekerja > 100 && i < Jpabrik)
            {
                pekerja -= 100;
                JpabrikOn++;
            }

            if (pekerja > 100 && i < JsumberEnergi)
            {
                pekerja -=100;
                JsumberEnergiOn++;
            }
        }
        uang = uang + (JpabrikOn * 3000) - (JsumberEnergiOn*500);
        pendapatan = JpabrikOn * 3000;
        pengeluaran = JsumberEnergiOn*500;
        energiMasuk = JsumberEnergiOn*10;
        energiKeluar = (JpabrikOn*5) + (Jrumah*1);
        tingkatKebahagiaan = tingkatKebahagiaan + (JdestinasiWisata*5) - (JpabrikOn*5);
        if(tingkatKebahagiaan < 50)//untuk menghitung mundur dan menghapus sebuah rumah
        {
            cout << "";
            rumahCD++;
            if(rumahCD%3 == 0)
            {
                rumahCD = 1;
                Jrumah--;
                petaKota[rumah.index[Jrumah].y][rumah.index[Jrumah].y] = 'O';
            }
        }
        else 
        {
            rumahCD = 1;
        }
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
    setColor(4); cout << "3. "; setColor(7); cout << "Robohkan Fasilitas (interaksi -1) \n";
    setColor(4); cout << "4. "; setColor(7); cout << "Lihat Peta Kota \n";
    setColor(4); cout << "5. "; setColor(7); cout << "Lihat Jumlah Fasilitas \n";
    setColor(4); cout << "6. "; setColor(7); cout << "Statistik Populasi \n";
    setColor(4); cout << "7. "; setColor(7); cout << "Akhiri Hari \n";
    setColor(4); cout << "8. "; setColor(7); cout << "Save \n";
    setColor(4); cout << "9. "; setColor(7); cout << "Kembali Ke Menu Utama \n";
}

void bangunFasilitas (char petaKota[6][6]){
    int pilihan = 0, X = 0, Y = 0;
    cout << "Pilih bangunan yang ingin di bangun:\n";
    setColor(12); cout << "1. Pabrik\n"; setColor(7); cout << "Biaya : $3,000\nEnergi : -5MW/hari\nUang : +$3,000/hari\nPekerja : -100\n";
    setColor(13); cout << "2. Rumah\n"; setColor(7); cout << "Biaya : $500\nPopulasi : +100\nEnergi : -1MW/hari\n";
    setColor(10); cout << "3. Sumber energi\n"; setColor(7); cout << "Biaya : $1,000\nEnergi : +10MW/hari\nUang : -$500/hari\nPekerja : -100\n";
    setColor(11); cout << "4. Destinasi wisata\n"; setColor(7); cout << "Biaya : $1,500\nKebahagiaan : +5%\n";
    while (pilihan < 1 || pilihan > 4)
    {
        setColor(1); cout << "Pilihan : "; setColor(7);
        cin >> pilihan;
        switch (pilihan)
        {
            case 1: if (uang < 3000 && pekerja < 50)
                {
                    setColor(12); cout << "Resource anda tidak cukup\n"; setColor(7);
                    pilihan = 0;
                }
                else
                {
                    lihatPeta();
                    int i = 0;
                    while(i == 0){
                        cout << "Tentukan kordinat lahan\n";
                        cout << "baris: ";
                        cin >> X;
                        cout << "kolom: ";
                        cin >> Y;
                        if (petaKota[X-1][Y-1] == 'O')
                        {
                            petaKota[X-1][Y-1] = pabrik.alias;
                            Jpabrik++;
                            pabrik.index[Jpabrik-1].x = X-1;
                            pabrik.index[Jpabrik-1].y = Y-1;
                            uang-=3000;
                            return;
                        }
                        else
                        {
                            setColor(12); cout << "Lahan masih ada bangunan\n\n"; setColor(7);
                            pilihan = 0;
                        }
                    }
                }
                break;

            case 2: if (uang < 500)
                {
                    setColor(12); cout << "Resource anda tidak cukup\n"; setColor(7);

                    pilihan = 0;
                }
                else
                {
                    lihatPeta();
                    int i = 0;
                    while(i == 0){
                        cout << "Tentukan kordinat\n";
                        cout << "baris: ";
                        cin >> X;
                        cout << "kolom: ";
                        cin >> Y;
                        if (petaKota[X-1][Y-1] == 'O')
                        {
                            petaKota[X-1][Y-1] = rumah.alias;
                            rumah.index[Jrumah-1].x = X-1;
                            rumah.index[Jrumah-1].y = Y-1;
                            Jrumah++;
                            uang-=500;
                            cout << "Berhasil membangun\n";
                            return;
                        }
                        else
                        {
                            setColor(12); cout << "Lahan masih ada bangunan\n\n"; setColor(7);
                            pilihan = 0;
                        }
                    }
                }
                break;

            case 3: if (uang < 1500 && pekerja < 50)
                {
                    setColor(13); cout << "Resource anda tidak cukup\n"; setColor(7);
                    pilihan = 0;
                }
                else
                {
                    lihatPeta();
                    int i = 0;
                    while(i == 0){
                        cout << "Tentukan kordinat lahan\n";
                        cout << "baris: ";
                        cin >> X;
                        cout << "kolom: ";
                        cin >> Y;
                        if (petaKota[X-1][Y-1] = 'O')
                        {
                            petaKota[X-1][Y-1] = sumberEnergi.alias;
                            JsumberEnergi++;
                            sumberEnergi.index[JsumberEnergi-1].x = X-1;
                            sumberEnergi.index[JsumberEnergi-1].y = Y-1;
                            uang-=1500;
                            cout << "Berhasil membangun\n";
                            return;
                        }
                        else
                        {
                            setColor(12); cout << "Lahan masih ada bangunan\n\n"; setColor(7);
                            pilihan = 0;
                        }
                    }
                }
                break;
                case 4: if (uang < 1500)
                {
                    setColor(13); cout << "Resource anda tidak cukup\n"; setColor(7);
                    pilihan = 0;
                }
                else
                {
                    lihatPeta();
                    int i = 0;
                    while(i == 0){
                        cout << "Tentukan kordinat lahan\n";
                        cout << "baris: ";
                        cin >> X;
                        cout << "kolom: ";
                        cin >> Y;
                        if (petaKota[X-1][Y-1] == 'O')
                        {
                            petaKota[X-1][Y-1] = destinasiWisata.alias;
                            JdestinasiWisata++;
                            destinasiWisata.index[JdestinasiWisata-1].x = X-1;
                            destinasiWisata.index[JdestinasiWisata-1].y = Y-1;
                            uang-=1500;
                            cout << "Berhasil membangun\n";
                            return;
                        }
                        else
                        {
                            setColor(12); cout << "Lahan masih ada bangunan\n\n"; setColor(7);
                            pilihan = 0;
                        }
                    }
                }
                break;
        } //pusing
    }
}

void terapkanKebijakan(){
    cout << "Sedang dalam tahap pengembangan \n";
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
                setColor(4); cout << index << ". Pabrik (" << i+1 << "," << j <<") \n";
                break;
            case 'R':
                setColor(5); cout << index << ". Rumah (" << i+1 << "," << j+1 <<") \n";
                break;
            case 'E':
                setColor(10); cout << index << ". Sumber Energi (" << i+1 << "," << j+1 <<") \n";
                break;
            case 'D':
                setColor(11); cout << index << ". Destinasi Wisata (" << i+1 << "," << j+1 <<") \n";
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
                                    pabrik=pabrik-1;
                                    break;
                                case 'R':
                                    setColor(5); cout << index << ". Rumah (" << i+1 << "," << j+1 <<") ";
                                    rumah=rumah-1;
                                    break;
                                case 'E':
                                    setColor(10); cout << index << ". Sumber Energi (" << i+1 << "," << j+1 <<") ";
                                    sumberEnergi=sumberEnergi-1;
                                    break;
                                case 'D':
                                    setColor(11); cout << index << ". Destinasi Wisata (" << i+1 << "," << j+1 <<") ";
                                    destinasiWisata=destinasiWisata-1;
                                    break;
                            }
                            cout << "berhasil dirobohkan \n";
                            uang=uang-5;
                            petaKota[i][j] = 'O';
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
