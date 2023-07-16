#ifndef MENAMPILKAN_H
#define MENAMPILKAN_H

#include <iostream>
#include <iomanip>
#include "circuit.h"
#include "pembalap.h"

using namespace std;

class Menampilkan {
public:
    void tampilkanData() {
        Circuit circuit;
        circuit.bacaDataRace();

        Pembalap pembalap;
        pembalap.bacaDataTim();

        cout << "Jumlah data circuit: " << circuit.dataRace.size() << endl;
        cout << "Jumlah data pembalap: " << pembalap.dataTim.size() << endl;

        if (!circuit.dataRace.empty()) {
            cout << "\nCircuit Information:\n";
            cout << "Nama Circuit       : " << circuit.dataRace[0].namaCircuit << endl;
            cout << "Jumlah Lap         : " << circuit.dataRace[0].jumlahLap << endl;
            cout << "Tanggal Balapan    : " << circuit.dataRace[0].tanggalBalapan << endl;
        }

        cout << "\nData Tim:\n";
        cout << "+-------------------------------------------------------------------+" << endl;
        cout << "| No. | Nama Tim               | Nama Pembalap     | Nomer Pembalap |" << endl;
        cout << "+-------------------------------------------------------------------+" << endl;

        int i = 0;
        while (i < pembalap.dataTim.size()) {
            cout << "| " << setw(3) << i + 1 << " | ";
            cout << setw(23) << pembalap.getNamaTim(pembalap.dataTim[i].nomorPembalap) << " | ";
            cout << setw(17) << pembalap.dataTim[i].namaTim << " | ";
            cout << setw(13) << pembalap.dataTim[i].nomorPembalap << " | ";
            cout << endl;
            i++;
        }

        cout << "+-------------------------------------------------------------------+" << endl;
    }
};

#endif // MENAMPILKAN_H
