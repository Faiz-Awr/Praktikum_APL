#include <iostream>
using namespace std;

void login(){
    int i;
    string username, password;

    for(i = 1; i < 4; i++){
        cout << "==========================" << endl;
        cout << "##         LOGIN        ##" << endl;
        cout << "==========================" << endl;
        cout << "USERNAME: ";
        cin >> username;
        cout << "PASSWORD: ";
        cin >> password;
        
        if(username == "Faiz" && password == "2309106024"){
            cout << "Login berhasil" << endl;
            break;
        }
        else{
            cout << "Username atau password anda  salah. (" << i << ")x" << endl;
            }
        }
    if(username != "Faiz" && password != "2309106024"){
        cout << "Anda telah mencapai batas kesempatan untuk login.\nCoba lagi nanti" << endl;
        exit(0);
    }
}

void crud(){
    string daftar_belanja[100];
    string jumlah_item[100];
    int n = 0;
    char pilihan;
    char ulang;
    int i, j;
    bool kosong = true;
    bool no_item;
    int ubah;

    cout << "\nSelamat datang! Kamu bisa kelola daftar belanja kamu melalui menu ini" << endl;
    while(ulang != 't'){
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
        cout << "Di sini, kamu bisa membuat daftar belanja." << endl;
        cout << "Tambah item: ";
        cin.ignore();
        getline(cin, daftar_belanja[n]);
        cout << daftar_belanja[n] << " Berhasil ditambahkan" << endl;
        cout << "Jumlah: ";
        cin >> jumlah_item[n];
        cout << "Jumlah  " << daftar_belanja[n] << " = " << jumlah_item[n] << endl;
        n++;
        kosong = false;
        
    }
    else if(pilihan == '2'){
        if(kosong == false){
        cout << "===================================" << endl;
        cout << "##        DAFTAR   ITEM          ##" << endl;
        cout << "===================================" << endl;
        for(i = 0; i < n; i++){
            cout << i + 1 << ". " << daftar_belanja[i] << " (" <<jumlah_item[i] << ") " << "Unit" << endl;
        }
        cout << "\nTekan Enter untuk melanjutkan";
        cout << endl;
        cin.ignore(); 
        cin.get();
        }   
        else{
            cout << "\nWah, daftar belanja kamu kosong nih." << endl;
            cout << "Ayo tambahkan itemnya terlebih dahulu." << endl;
            cout << "\nTekan Enter untuk melanjutkan";
            cout << endl;
            cin.ignore(); 
            cin.get();
        }
    }
    else if(pilihan == '3'){
        if(kosong == false){
            cout << "===================================" << endl;
            cout << "##        DAFTAR   ITEM          ##" << endl;
            cout << "===================================" << endl;
            for(i = 0; i < n; i++){
                cout << i + 1 << ". " << daftar_belanja[i] << " (" <<jumlah_item[i] << ") " << "Unit" << endl;
        }
            cout << "Pilih nomor item yang ingin kamu ubah" << endl;
            cout << "Nomor item: ";
            cin >> ubah;
            ubah -= 1;
            no_item = false;
            for(i = 0; i < n; i++){
                if(daftar_belanja[i] == daftar_belanja[ubah]){
                    cout << "Ganti nama item: ";
                    cin.ignore();
                    getline(cin, daftar_belanja[i]);
                    cout << "Ganti jumlah item: ";
                    cin >> jumlah_item[i];
                    cout << "Item nomor " << ubah+1 << " berhasil diupdate!" << endl;
                    no_item = true;
                    cout << endl;
                }
            }
            if(no_item == false){
                cout << "Nomor item yang kamu pilih tidak ada." << endl;
            }
        }   
        else{
            cout << "\nWah, daftar belanja kamu kosong nih." << endl;
            cout << "Ayo tambahkan itemnya terlebih dahulu." << endl;
            cout << "\nTekan Enter untuk melanjutkan";
            cout << endl;
            cin.ignore(); 
            cin.get();
        }
    }
    else if(pilihan == '4'){
        if(kosong == false){
            cout << "===================================" << endl;
            cout << "##        DAFTAR   ITEM          ##" << endl;
            cout << "===================================" << endl;
            for(i = 0; i < n; i++){
                cout << i + 1 << ". " << daftar_belanja[i] << " (" <<jumlah_item[i] << ") " << "Unit" << endl;
        }
            cout << endl;
            cout << "Pilih nomor item yang ingin kamu hapus" << endl;
            cout << "Nomor item: ";
            cin >> ubah;
            cout << "Yakin ingin hapus item nomor " << ubah << "?[Y/N]" << endl;
            char konfirmasi;
            cin >> konfirmasi; 
            no_item = false;
            ubah -= 1;
            if(konfirmasi == 'y' || konfirmasi == 'Y'){
            for(i = 0; i < n; i++){
                if(daftar_belanja[i] == daftar_belanja[ubah]){
                    for(j = i; j < n; j++){
                        daftar_belanja[j] = daftar_belanja[j+1];
                    }
                    cout << "Item nomor " << ubah+1 << " berhasil dihapus" << endl;
                    no_item = true;
                    n--;
                }
            }
            }
            else if(konfirmasi == 'n' || konfirmasi == 'N'){
                cout << "Item nomor " << ubah+1 << " tidak dihapus" << endl;
                no_item = true;
            }
            else{
                cout << "Pilihan kamu tidak valid" << endl;
                no_item = true;
            }
            if(no_item == false){
                cout << "Nomor item yang kamu pilih tidak ada." << endl;
            }
            if(n == 0){
                kosong = true;
            }
        }   
        else{
            cout << "\nWah, daftar belanja kamu kosong nih." << endl;
            cout << "Ayo tambahkan itemnya terlebih dahulu." << endl;
            cout << "\nTekan Enter untuk melanjutkan";
            cout << endl;
            cin.ignore(); 
            cin.get();
        }
    }
    else if(pilihan == '5'){
        cout << "Keluar dari program" << endl;
        ulang = 't';
    }
    else{
        cout << endl;
        cout << "Pilihan kamu tidak valid" << endl;
    }
    }
 }

int main(){
    login();
    crud();
    return 0;
}
