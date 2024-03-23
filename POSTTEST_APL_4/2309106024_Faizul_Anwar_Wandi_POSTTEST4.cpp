#include <iostream>
#include <limits>
using namespace std;

void clearinputbuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

struct detail{
        string detail;
    };
struct item{
        string nama;
        int jumlah;
        detail detail;
    };
    item itm[100];
    detail dtl[100];

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
        cout << "Username atau password kamu salah. (" << kesempatan + 1 << ")x" << endl;
        login(kesempatan + 1);
        }
    }    
    
    else{
    cout << "Kamu telah mencapai batas kesempatan untuk login.\nCoba lagi nanti" << endl;
    exit(0);
}
}

bool create(item, detail, int &n) {
    cout << "Tambah item: ";
    cin.ignore();
    getline(cin, itm[n].nama);
    if(itm[n].nama.empty()){
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
        } else {
            cout << "Jumlah " << itm[n].nama << " = " << itm[n].jumlah << endl;
            break;
        }
    }
    cout << endl;
    cout << "Detail item (merk/varian) atau tekan ENTER jika tidak ada" << endl;
    cout << "Detail: ";
    cin.ignore();
    getline(cin, itm[n].detail.detail);
    if(itm[n].detail.detail.empty()){
        itm[n].detail.detail = '-';
    }
    n++;

    return true;
}

bool read(item, detail, int n) {
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
            cout << "Catatan: " << itm[i].detail.detail << endl;
            cout << endl;
        }
        cout << "\nTekan Enter untuk melanjutkan";
        cin.get();
        clearinputbuffer();
        cout << endl;
        return true;
    }
}

bool update(item, detail, int &n) {
     if (n == 0) {
        cout << "\nWah, daftar belanja kamu kosong nih." << endl;
        cout << "Ayo tambahkan itemnya terlebih dahulu." << endl;
        cout << "\nTekan Enter untuk melanjutkan";
        cout << endl;
        cin.get();
        clearinputbuffer(); 
        return false;
    } 
    read(itm[n], dtl[n], n);
    while (true) {
        cout << endl;
        cout << "Pilih nomor item yang ingin kamu ubah " << endl;
        cout<< "Nomor item: ";
        int ubah;
        if (!(cin >> ubah)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Inputan kamu salah. Pastikan kamu input angka dan maksimal 10 digit." << endl;
            cout << "Tekan ENTER" << endl;
            clearinputbuffer(); 
        }else {
            ubah -= 1;
            if (ubah >= 0 && ubah < n) {
                string nama_baru;
                cout << endl;
                cout << "Ganti nama item " << endl;
                cout << "Nama item: ";
                cin.ignore();
                getline(cin, nama_baru);
                if(nama_baru.empty()){
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
                        getline(cin, itm[ubah].detail.detail);
                        if(itm[ubah].detail.detail.empty()){
                            itm[ubah].detail.detail = '-';
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

bool hapus(item, detail, int &n) {
    if (n == 0) {
        cout << "\nWah, daftar belanja kamu kosong nih." << endl;
        cout << "Ayo tambahkan itemnya terlebih dahulu." << endl;
        cout << "\nTekan Enter untuk melanjutkan";
        cout << endl;
        cin.get();
        clearinputbuffer(); 
        return false;
    } 
    read(itm[n], dtl[n], n);
    while(true){
        cout << endl;
        cout << "Pilih nomor item yang ingin kamu hapus" << endl;
        cout << "Nomor item: ";
        int hapus;
        if(!(cin >> hapus)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Inputan kamu salah. Pastikan kamu input angka dan maksimal 10 digit." << endl;
            cout << "Tekan ENTER" << endl;
            cin.get();
            clearinputbuffer(); 
        }
        else{
            hapus -= 1;
            if (hapus >= 0 && hapus < n) {
            string konfirmasi;
            cout << "Yakin ingin hapus item nomor " << hapus+1 << "? [Y/N] ";
            cin.ignore();
            cin >> konfirmasi;
            if(konfirmasi == "Y" || konfirmasi == "y"){
                for (int i = hapus; i < n - 1; i++) {
                    itm[i].nama = itm[i + 1].nama;
                    itm[i].jumlah = itm[i + 1].jumlah;
                    itm[i].detail.detail = itm[i + 1].detail.detail;
            }
            cout << "Item nomor " << hapus + 1 << " berhasil dihapus" << endl;
            cout << endl;
            n--;
            return true;
            break;
            }
            else if(konfirmasi == "n" || konfirmasi == "N"){
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
}

void crud(){
    int n = 0;
    string pilihan;
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

        if(pilihan == "1"){
            create(itm[n], dtl[n], n);
        }
        else if(pilihan == "2"){
            read(itm[n], dtl[n], n);
        }
        else if(pilihan == "3"){
            update(itm[n], dtl[n], n);
        }
        else if(pilihan == "4"){
            hapus(itm[n], dtl[n], n);
        }
        else if(pilihan == "5"){
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