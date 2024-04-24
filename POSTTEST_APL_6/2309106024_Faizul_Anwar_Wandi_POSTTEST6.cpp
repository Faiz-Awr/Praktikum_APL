#include <iostream>
#include <limits>
using namespace std;

void clearinputbuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

struct detail {
    string detail;
};

struct item {
    string nama;
    int jumlah;
    detail* dtl;
};

item itm[100];
detail dtl[100];

void login(int kesempatan = 0) {
    string username, password;

    if (kesempatan < 3) {
        cout << "==========================" << endl;
        cout << "##         LOGIN        ##" << endl;
        cout << "==========================" << endl;
        cout << "USERNAME: ";
        cin >> username;
        cout << "PASSWORD: ";
        cin >> password;

        if (username == "Faiz" && password == "2309106024") {
            cout << "Login berhasil" << endl;
            cout << endl;
        }
        else {
            cout << "Username atau password kamu salah. (" << kesempatan + 1 << ")x" << endl;
            login(kesempatan + 1);
        }
    }
    else {
        cout << "Kamu telah mencapai batas kesempatan untuk login.\nCoba lagi nanti" << endl;
        exit(0);
    }
}

bool create(item *itm, detail *dtl, int &n) {
    cout << "Tambah item: ";
    cin.ignore();
    getline(cin, itm[n].nama);
    if (itm[n].nama.empty()) {
        cout << "Nama item tidak boleh kosong." << endl;
        cout << endl;
        return false;
    }
    cout << itm[n].nama << " berhasil ditambahkan" << endl;

    while (true) {
        cout << endl;
        cout << "Jumlah (max 10 digit): ";
        if (!(cin >> itm[n].jumlah)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Inputan kamu salah. Pastikan kamu input angka dan maksimal 10 digit." << endl;
            cout << "Tekan ENTER" << endl;
            clearinputbuffer();
        }
        else {
            cout << "Jumlah " << itm[n].nama << " = " << itm[n].jumlah << endl;
            break;
        }
    }
    cout << endl;
    cout << "Detail item (merk/varian) atau tekan ENTER jika tidak ada" << endl;
    cout << "Detail: ";
    cin.ignore();
    getline(cin, dtl[n].detail);
    if (dtl[n].detail.empty()) {
        dtl[n].detail = '-';
    }
    itm[n].dtl = &dtl[n];
    n++;

    return true;
}

bool read(item *itm, detail *dtl, int n) {
    if (n == 0) {
        cout << "\nWah, daftar belanja kamu kosong nih." << endl;
        cout << "Ayo tambahkan itemnya terlebih dahulu." << endl;
        cout << "\nTekan Enter untuk melanjutkan";
        cout << endl;
        cin.get();
        clearinputbuffer();
        return false;
    }
    else {
        cout << "===================================" << endl;
        cout << "##        DAFTAR   ITEM          ##" << endl;
        cout << "===================================" << endl;
        for (int i = 0; i < n; i++) {
            cout << i + 1 << ". " << itm[i].nama << " (" << itm[i].jumlah << ") " << "Unit" << endl;
            cout << "Catatan: " << dtl[i].detail << endl;
            cout << endl;
        }
        cout << "\nTekan Enter untuk melanjutkan";
        cin.get();
        clearinputbuffer();
        cout << endl;
        return true;
    }
}

bool update(item *itm, detail *dtl, int &n) {
    if (n == 0) {
        cout << "\nWah, daftar belanja kamu kosong nih." << endl;
        cout << "Ayo tambahkan itemnya terlebih dahulu." << endl;
        cout << "\nTekan Enter untuk melanjutkan";
        cout << endl;
        cin.get();
        clearinputbuffer();
        return false;
    }
    read(itm, dtl, n);
    while (true) {
        cout << endl;
        cout << "Pilih nomor item yang ingin kamu ubah " << endl;
        cout << "Nomor item: ";
        int ubah;
        if (!(cin >> ubah)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Inputan kamu salah. Pastikan kamu input angka dan maksimal 10 digit." << endl;
            cout << "Tekan ENTER" << endl;
            clearinputbuffer();
        }
        else {
            ubah -= 1;
            if (ubah >= 0 && ubah < n) {
                string nama_baru;
                cout << endl;
                cout << "Ganti nama item " << endl;
                cout << "Nama item: ";
                cin.ignore();
                getline(cin, nama_baru);
                if (nama_baru.empty()) {
                    cout << "Nama item tidak boleh kosong." << endl;
                    cout << endl;
                    return false;
                }
                while (true) {
                    itm[ubah].nama = nama_baru;
                    cout << endl;
                    cout << "Jumlah (max 10 digit): ";
                    if (!(cin >> itm[ubah].jumlah)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Inputan kamu salah. Pastikan kamu input angka dan maksimal 10 digit." << endl;
                        cout << "Tekan ENTER" << endl;
                        clearinputbuffer();
                    }
                    else {
                        cout << endl;
                        cout << "Ganti detail item atau tekan ENTER jika tidak ada" << endl;
                        cout << "Detail item: ";
                        cin.ignore();
                        getline(cin, dtl[ubah].detail);
                        if (dtl[ubah].detail.empty()) {
                            dtl[ubah].detail = '-';
                        }
                        cout << "Item nomor " << ubah + 1 << " Berhasil diupdate!" << endl;

                        return true;
                        break;
                    }
                }
            }
            else {
                cout << "Nomor item yang kamu pilih tidak ada." << endl;
                return false;
            }

        }
    }
}

bool hapus(item *itm, detail *dtl, int &n) {
    if (n == 0) {
        cout << "\nWah, daftar belanja kamu kosong nih." << endl;
        cout << "Ayo tambahkan itemnya terlebih dahulu." << endl;
        cout << "\nTekan Enter untuk melanjutkan";
        cout << endl;
        cin.get();
        clearinputbuffer();
        return false;
    }
    read(itm, dtl, n);
    while (true) {
        cout << endl;
        cout << "Pilih nomor item yang ingin kamu hapus" << endl;
        cout << "Nomor item: ";
        int hapus;
        if (!(cin >> hapus)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Inputan kamu salah. Pastikan kamu input angka dan maksimal 10 digit." << endl;
            cout << "Tekan ENTER" << endl;
            cin.get();
            clearinputbuffer();
        }
        else {
            hapus -= 1;
            if (hapus >= 0 && hapus < n) {
                string konfirmasi;
                cout << "Yakin ingin hapus item nomor " << hapus + 1 << "? [Y/N] ";
                cin.ignore();
                cin >> konfirmasi;
                if (konfirmasi == "Y" || konfirmasi == "y") {
                    for (int i = hapus; i < n - 1; i++) {
                        itm[i].nama = itm[i + 1].nama;
                        itm[i].jumlah = itm[i + 1].jumlah;
                        dtl[i].detail = dtl[i + 1].detail;
                    }
                    cout << "Item nomor " << hapus + 1 << " berhasil dihapus" << endl;
                    cout << endl;
                    n--;
                    return true;
                    break;
                }
                else if (konfirmasi == "n" || konfirmasi == "N") {
                    cout << "Item nomor " << hapus + 1 << " tidak dihapus" << endl;
                    cout << endl;
                    return true;
                }
                else {
                    cout << "Pilihan kamu tidak valid" << endl;
                    cout << endl;
                    return true;
                }
            }
            else {
                cout << "Nomor item yang kamu pilih tidak ada." << endl;
                cout << endl;
                return false;
            }
        }
    }
}

void bubbleSort(item *itm, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (itm[j].jumlah > itm[j + 1].jumlah) {
                item temp = itm[j];
                itm[j] = itm[j + 1];
                itm[j + 1] = temp;
            }
        }
    }
}

void insertionSort(item *itm, int n) {
    for (int i = 1; i < n; i++) {
        item key = itm[i];
        int j = i - 1;
        while (j >= 0 && itm[j].jumlah < key.jumlah) {
            itm[j + 1] = itm[j];
            j = j - 1;
        }
        itm[j + 1] = key;
    }
}
string uppercase(string x) {
    for (int i = 0; i < x.size(); i++) {
        x[i] = toupper(x[i]);
    }
    return x;
}
void selectionSort(item *itm, int n) {
    for (int i = 0; i < n - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (uppercase(itm[j].nama) > uppercase(itm[max_idx].nama)) {
                max_idx = j;
            }
        }
        if (max_idx != i) {
            item temp = itm[i];
            itm[i] = itm[max_idx];
            itm[max_idx] = temp;
        }
    }
}
void selectionSortAscending(item *itm, int n) {
    for (int i = 0; i < n - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (uppercase(itm[j].nama) < uppercase(itm[max_idx].nama)) {
                max_idx = j;
            }
        }
        if (max_idx != i) {
            item temp = itm[i];
            itm[i] = itm[max_idx];
            itm[max_idx] = temp;
        }
    }
}
void binarySearch(item *itm, int n, string nama) {
    int awal = 0;
    int akhir = n - 1;
    while (awal <= akhir) {
        int tengah = (awal + akhir) / 2;
        if (itm[tengah].nama == nama) {
            cout << "Item " << nama << " ditemukan pada indeks " << tengah << endl;
            return;
        }
        else if (itm[tengah].nama < nama) {
            awal = tengah + 1;
        }
        else {
            akhir = tengah - 1;
        }
    }
    cout << "Item " << nama << " tidak ditemukan" << endl;
}
void sequentialSearch(item *itm, int n, string nama) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (itm[i].nama == nama) {
            cout << "Item " << nama << " ditemukan pada indeks " << i << endl;
            found = true;
            break;
        }
    }
    if (found != true) {
        cout << "Item " << nama << " tidak ditemukan" << endl;
    }
}
void crud() {
    int n = 0;
    string pilihan;
    char ulang;

    cout << "\nSelamat datang! Kamu bisa kelola daftar belanja kamu melalui menu ini" << endl;
    while (ulang != 't') {
        cout << endl;
        cout << "Ayo, pilih salah satu dari menu ini!" << endl;
        cout << "===================================" << endl;
        cout << "##        DAFTAR   BELANJA       ##" << endl;
        cout << "===================================" << endl;
        cout << "1. Buat Daftar Belanja" << endl;
        cout << "2. Lihat Daftar Belanja" << endl;
        cout << "3. Ganti Item" << endl;
        cout << "4. Hapus Item" << endl;
        cout << "5. Sorting Daftar Belanja" << endl;
        cout << "6. Search Daftar Belanja" << endl;
        cout << "7. EXIT" << endl;
        cout << "\nPilihan kamu: ";
        cin >> pilihan;

        if (pilihan == "1") {
            create(itm, dtl, n);
        }
        else if (pilihan == "2") {
            read(itm, dtl, n);
        }
        else if (pilihan == "3") {
            update(itm, dtl, n);
        }
        else if (pilihan == "4") {
            hapus(itm, dtl, n);
        }
        else if (pilihan == "5") {
            cout << "===================================" << endl;
            cout << "##     SORTING DAFTAR BELANJA    ##" << endl;
            cout << "===================================" << endl;
            cout << "1. Sort Berdasarkan Jumlah (Ascending)" << endl;
            cout << "2. Sort Berdasarkan Jumlah (Descending)" << endl;
            cout << "3. Sort Berdasarkan Nama item (Z-A)" << endl;
            cout << "4. Sort Berdasarkan Nama item (A-Z)" << endl;
            cout << "\nPilihan kamu: ";
            string pilihsort;
            cin >> pilihsort;
            if (pilihsort == "1"){
                bubbleSort(itm, n);
                read(itm, dtl, n);
            }
            else if (pilihsort == "2"){
                insertionSort(itm, n);
                read(itm, dtl, n);
            }
            else if (pilihsort == "3"){
                selectionSort(itm, n);
                read(itm, dtl, n);
            }
            else if (pilihsort == "4"){
                selectionSortAscending(itm, n);
                read(itm, dtl, n);
            }
            else{
                cout << "Pilihan kamu tidak valid" << endl;
            }
        }
        else if (pilihan == "6"){
            string pilihsearch;
            cout << "===================================" << endl;
            cout << "##     SEARCH DAFTAR BELANJA     ##" << endl;
            cout << "===================================" << endl;
            cout << "1. Search Berdasarkan Data Ascending" << endl;
            cout << "2. Search Berdasarkan Data Descending" << endl;
            cout << "\nPilihan kamu: ";
            cin >> pilihsearch;
            if (pilihsearch == "1"){
                selectionSortAscending(itm, n);
                string nama_cari;
                cout << "Masukkan nama item yang ingin dicari: ";
                cin >> nama_cari;
                binarySearch(itm, n, nama_cari);
            }
            else if(pilihsearch == "2"){
                selectionSort(itm, n);
                string nama_cari;
                cout << "Masukkan nama item yang ingin dicari: ";
                cin >> nama_cari;
                sequentialSearch(itm, n, nama_cari);
        }
            }
        else if (pilihan == "7"){
            cout << "Keluar dari program" << endl;
            ulang = 't';
        }
        else {
            cout << endl;
            cout << "Pilihan kamu tidak valid!" << endl;
            cout << endl;
        }

    }
}

int main() {
    login();
    crud();
    return 0;
}