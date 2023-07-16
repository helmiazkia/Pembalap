#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "pembalap.h"
#include "circuit.h"
#include "menampilkan.h"


using namespace std;

void tampilMenu() {
    cout << "===============================================================" << endl;
    cout << "  Selamat datang di program pendataan balap F1 (balap mobil)   " << endl;
    cout << "===============================================================" << endl;
    cout << "Pilih menu yang ingin kamu lakukan:" << endl;
    cout << "1. Masuk menu Data Circuit" << endl;
    cout << "2. Masuk menu Data Pembalap" << endl;
    cout << "3. Masuk menu Tampilkan Data" << endl;
    cout << "4. Keluar" << endl;
    cout << "======================================================" << endl;
}

void menu2() {
    int pilihan;
    Pembalap pembalap;

    do {
        system("cls");
        cout << "Pilih menu yang ingin kamu lakukan:" << endl;
        cout << "1. Tambah Data Pembalap" << endl;
        cout << "2. Lihat Data Pembalap" << endl;
        cout << "3. Edit Data Pembalap" << endl;
        cout << "4. Hapus Data Pembalap" << endl;
        cout << "5. Kembali ke Menu Awal" << endl;
        cout << "==================================" << endl;
        cout << "Masukkan pilihan (1-5): ";
        cin >> pilihan;
        int nomorPembalap;
        switch (pilihan) {
            case 1:
                pembalap.inputDataTim();
                break;
            case 2:
                pembalap.lihatPembalap(nomorPembalap);
                break;
            case 3:
                pembalap.editDataPembalap(nomorPembalap);
                break;
            case 4:
                pembalap.deleteDataPembalap(nomorPembalap);
                break;
            case 5:
                system("cls");
                tampilMenu();
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }

        cout << endl;
        cout << "Tekan enter untuk melanjutkan...";
        cin.ignore();
        cin.get();
        system("cls");
    } while (pilihan != 5);
}

void menu1() {
    int pilihan;
    Circuit circuit;

    do {
        system("cls");
        cout << "Pilih menu yang ingin kamu lakukan:" << endl;
        cout << "1. Input data circuit " << endl;
        cout << "2. Lihat data race/circuit" << endl;
        cout << "3. Edit data race" << endl;
        cout << "4. Hapus data race" << endl;
        cout << "5. Kembali ke Menu Awal" << endl;
        cout << "Masukkan pilihan (1-7): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                circuit.inputDataRace();
                break;
            case 2:
                circuit.lihatDataRace();
                break;
            case 3:
                circuit.editDataRace();
                break;
            case 4:
                circuit.hapusDataRace();
                break;
            case 5:
                system("cls");
                tampilMenu();
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }

        cout << endl;
        cout << "Tekan enter untuk melanjutkan...";
        cin.ignore();
        cin.get();
        system("cls");
    } while (pilihan != 5);
}

void menu3() {
    int pilihan;
    Menampilkan menampilkan;

    do {
        system("cls");
        cout << "Pilih menu yang ingin kamu lakukan:" << endl;
        cout << "1. Tampilkan data balapan F1" << endl;
        cout << "2. Kembali ke Menu Awal" << endl;
        cout << "Masukkan pilihan (1-2): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                menampilkan.tampilkanData();
                break;
            case 2:
                system("cls");
                tampilMenu();
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }

        cout << endl;
        cout << "Tekan enter untuk melanjutkan...";
        cin.ignore();
        cin.get();
        system("cls");
    } while (pilihan != 2);
}


#endif // MENU_H
