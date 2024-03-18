#include <iostream>
using namespace std;

void login(int kesempatan = 0){
    string username, password;

    if(kesempatan < 3){
    cout << "==========================" << endl;
    cout << "##         LOGIN        ##" << endl;
    cout << "==========================" << endl;
    cout << "USERNAME: ";
    cin >> username;
    cout << "PASSWORD: ";
    cin >> password;
    

    if(username == "Faiz" && password == "2309106024"){
        cout << "Login berhasil" << endl;
        cout << endl;
    }
    else{
        cout << "Username atau password anda  salah. (" << kesempatan + 1 << ")x" << endl;
        login(kesempatan + 1);
        }
    }    
    
    else{
    cout << "Anda telah mencapai batas kesempatan untuk login.\nCoba lagi nanti" << endl;
    exit(0);
}
}

bool create(string daftar_belanja[], string jumlah_item[], int& n) {
    string item;
    string jumlah;
    
    cout << "Tambah item: ";
    cin.ignore();
    getline(cin, item);
    cout << item << " berhasil ditambahkan" << endl;
    cout << "Jumlah: ";
    cin >> jumlah;
    cout << "Jumlah " << item << " = " << jumlah << endl;

    daftar_belanja[n] = item;
    jumlah_item[n] = jumlah;
    n++;

    return true;
}

bool read(string daftar_belanja[], string jumlah_item[], int n) {
    if (n == 0) {
        cout << "\nWah, daftar belanja kamu kosong nih." << endl;
        cout << "Ayo tambahkan itemnya terlebih dahulu." << endl;
        cout << "\nTekan Enter untuk melanjutkan";
        cout << endl;
        cin.ignore(); 
        cin.get();
        return false;
    } 
    else {
        cout << "===================================" << endl;
        cout << "##        DAFTAR   ITEM          ##" << endl;
        cout << "===================================" << endl;
        for (int i = 0; i < n; i++) {
            cout << i + 1 << ". " << daftar_belanja[i] << " (" << jumlah_item[i] << ") " << "Unit" << endl;
        }
        cout << "\nTekan Enter untuk melanjutkan";
        cout << endl;
        cin.ignore(); 
        cin.get();
        return true;
    }
}

bool update(string daftar_belanja[], string jumlah_item[], int& n) {
    if (n == 0) {
        cout << "\nWah, daftar belanja kamu kosong nih." << endl;
        cout << "Ayo tambahkan itemnya terlebih dahulu." << endl;
        cout << "\nTekan Enter untuk melanjutkan";
        cout << endl;
        cin.ignore(); 
        cin.get();
        return false;
    } 
    else {
        cout << "===================================" << endl;
        cout << "##        DAFTAR   ITEM          ##" << endl;
        cout << "===================================" << endl;
        for (int i = 0; i < n; i++) {
            cout << i + 1 << ". " << daftar_belanja[i] << " (" << jumlah_item[i] << ") " << "Unit" << endl;
        }
        cout << "Pilih nomor item yang ingin kamu ubah" << endl;
        cout << "Nomor item: ";
        int ubah;
        cin >> ubah;
        ubah -= 1;
        if (ubah >= 0 && ubah < n) {
            cout << "Ganti nama item: ";
            cin.ignore();
            getline(cin, daftar_belanja[ubah]);
            cout << "Ganti jumlah item: ";
            cin >> jumlah_item[ubah];
            cout << "Item nomor " << ubah + 1 << " berhasil diupdate!" << endl;
            return true;
        } 
        else {
            cout << "Nomor item yang kamu pilih tidak ada." << endl;
            return false;
        }
    }
}

bool hapus(string daftar_belanja[], string jumlah_item[], int& n) {
    if (n == 0) {
        cout << "\nWah, daftar belanja kamu kosong nih." << endl;
        cout << "Ayo tambahkan itemnya terlebih dahulu." << endl;
        cout << "\nTekan Enter untuk melanjutkan";
        cout << endl;
        cin.ignore(); 
        cin.get();
        return false;
    } 
    else {
        cout << "===================================" << endl;
        cout << "##        DAFTAR   ITEM          ##" << endl;
        cout << "===================================" << endl;
        for (int i = 0; i < n; i++) {
            cout << i + 1 << ". " << daftar_belanja[i] << " (" << jumlah_item[i] << ") " << "Unit" << endl;
        }
        cout << "Pilih nomor item yang ingin kamu hapus" << endl;
        cout << "Nomor item: ";
        int hapus;
        cin >> hapus;
        hapus -= 1;
        if (hapus >= 0 && hapus < n) {
            char konfirmasi;
            cout << "Yakin ingin hapus item nomor " << hapus+1 << "? [Y/N]";
            cin >> konfirmasi;
            if(konfirmasi == 'Y' || konfirmasi == 'y'){
            for (int i = hapus; i < n - 1; i++) {
                daftar_belanja[i] = daftar_belanja[i + 1];
                jumlah_item[i] = jumlah_item[i + 1];
            }
            cout << "Item nomor " << hapus + 1 << " berhasil dihapus" << endl;
            cout << endl;
            n--;
            return true;
            }
            else if(konfirmasi == 'n' || konfirmasi == 'N'){
                cout << "Item nomor " << hapus+1 << " tidak dihapus" << endl;
                cout << endl;
                return true;
            }
            else{
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

void crud() {
    string daftar_belanja[100];
    string jumlah_item[100];
    int n = 0;
    char pilihan;
    char ulang;

    cout << "\nSelamat datang! Kamu bisa kelola daftar belanja kamu melalui menu ini" << endl;
    while (ulang != 't') {
        cout << "Ayo, pilih salah satu dari menu ini!" << endl;
        cout << "===================================" << endl;
        cout << "##        DAFTAR   BELANJA       ##" << endl;
        cout << "===================================" << endl;
        cout << "1. Buat Daftar Belanja" << endl;
        cout << "2. Lihat Daftar Belanja" << endl;
        cout << "3. Ganti Item" << endl;
        cout << "4. Hapus Item" << endl;
        cout << "5. EXIT" << endl;
        cout << "\nPilihan kamu: ";
        cin >> pilihan;

        if(pilihan == '1'){
            create(daftar_belanja, jumlah_item, n);
        }
        else if(pilihan == '2'){
            read(daftar_belanja, jumlah_item, n);
        }
        else if(pilihan == '3'){
            update(daftar_belanja, jumlah_item, n);
        }
        else if(pilihan == '4'){
            hapus(daftar_belanja, jumlah_item, n);
        }
        else if(pilihan == '5'){
            cout << "Keluar dari program" << endl;
            ulang = 't';
        }
        else{
            cout << endl;
            cout <<"Pilihan kamu tidak valid!" << endl;
            cout << endl;
        }
        
    }
}

int main(){
    login();
    crud();
    return 0;
}
