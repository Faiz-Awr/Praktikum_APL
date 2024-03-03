#include <iostream>
#include <iomanip>
using namespace std;
void login(){
    int i;
    string username;
    string password;
    
    for (i = 1; i < 4; i++) {
    cout << "\nSilahkan login" << endl;
    cout << "USERNAME: ";
    cin >> username;
    cout << "PASSWORD: ";
    cin >> password;
  
        if(username == "Faiz" && password == "2309106024"){
            cout << "\nLogin berhasil";
            break;
        }else {
            cout << "Username atau Password anda salah, silahkan coba lagi (" << i << "x)" << endl;
        }
    }
    if (username != "Faiz" && password != "2309106024"){
    cout << "Anda telah mencapai batas kesempatan untuk login.\nCoba lagi nanti" << endl;
    exit(0);
    }
    }
void konversi(){
    int pilihan;
    char ulang;
    double rupiah, dollar, euro, yen;
    while(ulang != 't'){
        cout << endl;
        cout << "===================================" << endl;
        cout << "##      Konversi Mata Uang       ##" << endl;
        cout << "===================================" << endl;
        cout << "1. Rupiah ---> Dollar, Euro, Yen" << endl;
        cout << "2. Dollar ---> Rupiah, Euro, Yen" << endl;
        cout << "3. Euro   ---> Rupiah, Dollar, Yen" << endl;
        cout << "4. Yen    ---> Rupiah, Dollar, Euro" << endl;
        cout << "5. EXIT" << endl;
        cout << "\nPilihan anda: " << endl;
        cin >> pilihan;
    
    if (pilihan == 1){
        cout << "Konversi Rupiah ---> Dollar, Euro, Yen" << endl;
        cout << "Rupiah: ";  
        cin >> rupiah;
        
        dollar = rupiah * 0.000064;
        euro = rupiah * 0.000059;
        yen = rupiah * 0.0096;

        cout << "\nHasil Konversi: " << endl;
        cout << "Rp " << rupiah << " ---> " << "$" << fixed << setprecision(2) << dollar << endl;
        cout << "Rp " << rupiah << " ---> " << euro << fixed << setprecision(2) << " Euro " << endl;
        cout << "Rp " << rupiah << " ---> " << yen << fixed << setprecision(2) << " Yen" << endl;

        }else if (pilihan == 2){
        cout << "Konversi Dollar ---> Rupiah, Euro, Yen" << endl;
        cout << "Dollar: ";
        cin >> dollar;

        rupiah = dollar * 15701.95;
        euro = dollar * 0.92;
        yen = dollar * 150.10;

        cout << "\nHasil Konversi: " << endl;
        cout << "$" << dollar << " ---> " << rupiah << fixed << setprecision(2) << " Rupiah" << endl;
        cout << "$" << dollar << " ---> " << euro << fixed << setprecision(2) << " Euro " << endl;
        cout << "$" << dollar << " ---> " << yen << fixed << setprecision(2) << " Yen" << endl;

        }else if (pilihan == 3){
        cout << "Konversi Euro ---> Rupiah, Dollar, Yen" << endl;
        cout << "Euro: ";
        cin >> euro;

        rupiah = euro * 17043.68;
        dollar = euro * 1.09;
        yen = euro * 162.93;

        cout << "\nHasil Konversi: " << endl;
        cout << euro << " Euro" << " ---> " << rupiah << fixed << setprecision(2) << " Rupiah" << endl;
        cout << euro << " Euro" << " ---> " << dollar << fixed << setprecision(2) << " Dollar " << endl;
        cout << euro << " Euro" << " ---> " << yen << fixed << setprecision(2) << " Yen" << endl;

        }else if (pilihan == 4){
        cout << "Konversi Yen ---> Rupiah, Dollar, Euro" << endl;
        cout << "Yen: ";
        cin >> yen;

        rupiah = yen * 104.61;
        dollar = yen * 0.0067;
        euro = yen * 0.0061;

        cout << "\nHasil Konversi: " << endl;
        cout << yen << " Yen" << " ---> " << rupiah << fixed << setprecision(2) << " Rupiah" << endl;
        cout << yen << " Yen" << " ---> " << dollar << fixed << setprecision(2) << " Dollar " << endl;
        cout << yen << " Yen" << " ---> " << euro << fixed << setprecision(2) << " Euro" << endl;

        }else if (pilihan == 5){
        cout << "Keluar dari program" << endl;
        ulang = 't';
        }else{
         cout << "Pilihan anda tidak valid" << endl;
        }
    }
}
int main(){
login();
konversi(); 
    }
    
