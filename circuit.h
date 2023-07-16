#ifndef CIRCUIT_H
#define CIRCUIT_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const string FILENAME = "circuit.txt";

class Circuit {
public:
    struct RaceData {
        string namaCircuit;
        int jumlahLap;
        string tanggalBalapan;
    };

    vector<RaceData> dataRace;

    void inputDataRace() {
        RaceData newData;

        cout << "Masukkan nama circuit: ";
        cin.ignore();
        getline(cin, newData.namaCircuit);

        cout << "Masukkan jumlah lap: ";
        cin >> newData.jumlahLap;

        cout << "Masukkan tanggal balapan: ";
        cin.ignore();
        getline(cin, newData.tanggalBalapan);

        dataRace.push_back(newData);

        ofstream fout(FILENAME, ios::app);
        if (fout.is_open()) {
            fout << newData.namaCircuit << "," << newData.jumlahLap << "," << newData.tanggalBalapan << endl;
            fout.close();
            cout << "Data race berhasil dimasukkan." << endl;
        } else {
            cout << "Gagal membuka file untuk menulis data." << endl;
        }
    }

    void bacaDataRace() {
        ifstream fin(FILENAME);
        if (fin.is_open()) {
            dataRace.clear();

            string line;
            while (getline(fin, line)) {
                RaceData newData;

                size_t pos1 = line.find(',');
                newData.namaCircuit = line.substr(0, pos1);

                size_t pos2 = line.find(',', pos1 + 1);
                newData.jumlahLap = stoi(line.substr(pos1 + 1, pos2 - pos1 - 1));

                newData.tanggalBalapan = line.substr(pos2 + 1);

                dataRace.push_back(newData);
            }

            fin.close();
        } else {
            cout << "Gagal membuka file untuk membaca data." << endl;
        }
    }

    void lihatDataRace() {
        cout << "--------------------------------------------------------------" << endl;
        cout << "No. | Nama Circuit       | Jumlah Lap | Tanggal Balapan      |" << endl;
        cout << "--------------------------------------------------------------" << endl;

        int no = 1;
        while (no <= dataRace.size()) {
            const RaceData& data = dataRace[no - 1];
            cout << setw(3) << no << " | ";
            cout << setw(18) << left << data.namaCircuit << " | ";
            cout << setw(10) << right << data.jumlahLap << " | ";
            cout << setw(20) << left << data.tanggalBalapan << " | " << endl;
            no++;
        }

        cout << "--------------------------------------------------------------" << endl;
    }

    void editDataRace() {
        lihatDataRace();

        if (dataRace.empty()) {
            cout << "Tidak ada data race yang tersedia." << endl;
            return;
        }

        int pilihan;
        cout << "Masukkan nomor data race yang ingin diedit: ";
        cin >> pilihan;

        if (pilihan >= 1 && pilihan <= dataRace.size()) {
            RaceData& data = dataRace[pilihan - 1];

            cout << "Nama Circuit: " << data.namaCircuit << endl;
            cout << "Jumlah Lap: " << data.jumlahLap << endl;
            cout << "Tanggal Balapan: " << data.tanggalBalapan << endl;

            cout << "Masukkan nama circuit baru: ";
            cin.ignore();
            getline(cin, data.namaCircuit);

            cout << "Masukkan jumlah lap baru: ";
            cin >> data.jumlahLap;

            cout << "Masukkan tanggal balapan baru: ";
            cin.ignore();
            getline(cin, data.tanggalBalapan);

            ofstream fout(FILENAME);
            if (fout.is_open()) {
                for (const RaceData& newData : dataRace) {
                    fout << newData.namaCircuit << "," << newData.jumlahLap << "," << newData.tanggalBalapan << endl;
                }
                fout.close();
                cout << "Data race berhasil diubah." << endl;
            } else {
                cout << "Gagal membuka file untuk menulis data." << endl;
            }
        } else {
            cout << "Nomor data race tidak valid." << endl;
        }
    }

    void hapusDataRace() {
        lihatDataRace();

        if (dataRace.empty()) {
            cout << "Tidak ada data race yang tersedia." << endl;
            return;
        }

        int pilihan;
        cout << "Masukkan nomor data race yang ingin dihapus: ";
        cin >> pilihan;

        if (pilihan >= 1 && pilihan <= dataRace.size()) {
            dataRace.erase(dataRace.begin() + pilihan - 1);

            ofstream fout(FILENAME);
            if (fout.is_open()) {
                for (const RaceData& data : dataRace) {
                    fout << data.namaCircuit << "," << data.jumlahLap << "," << data.tanggalBalapan << endl;
                }
                fout.close();
                cout << "Data race berhasil dihapus." << endl;
            } else {
                cout << "Gagal membuka file untuk menulis data." << endl;
            }
        } else {
            cout << "Nomor data race tidak valid." << endl;
        }
    }
};

#endif
