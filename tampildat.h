#ifndef TAMPILDAT_H
#define TAMPILDAT_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

class Tampilkan {
public:
    void tampilkanData() {
        ifstream filePembalap("data_pembalap.txt");
        ifstream fileCircuit("data_circuit.txt");

        if (filePembalap.is_open() && fileCircuit.is_open()) {
            string linePembalap, lineCircuit;

            cout << "Data Balapan F1:" << endl;
            cout << "+-------------------------------------------------------------+" << endl;
            cout << "| No. | Nama Pembalap      | Nama Tim          | Nama Circuit |" << endl;
            cout << "+-------------------------------------------------------------+" << endl;

            int nomor = 1;
            while (getline(filePembalap, linePembalap) && getline(fileCircuit, lineCircuit)) {
                string namaPembalap, namaTim, namaCircuit;

                // Mengambil data dari file pembalap
                size_t pos = linePembalap.find(" ");
                namaTim = linePembalap.substr(0, pos);
                linePembalap.erase(0, pos + 1);

                pos = linePembalap.find(" ");
                namaPembalap = linePembalap.substr(0, pos);
                linePembalap.erase(0, pos + 1);

                // Mengambil data dari file circuit
                namaCircuit = lineCircuit;

                // Menampilkan data yang sudah digabungkan
                cout << "| " << setw(3) << nomor << " | " << setw(18) << namaPembalap << " | " << setw(18) << namaTim << " | " << setw(13) << namaCircuit << " |" << endl;

                nomor++;
            }

            cout << "+-------------------------------------------------------------+" << endl;

            filePembalap.close();
            fileCircuit.close();
        } else {
            cout << "Gagal membuka file." << endl;
        }
    }
};

#endif // TAMPILDAT_H
