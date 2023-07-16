#ifndef PEMBALAP_H
#define PEMBALAP_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <vector>

using namespace std;

const string FILENAME_PEMBALAP = "pembalap.txt";

class Pembalap {
public:
    struct TimData {
        string namaTim;
        string namaPembalap;  // Tambahkan variabel namaPembalap
        int nomorPembalap;
        int lap;
        int jam;
        int menit;
        int detik;
    };

    vector<TimData> dataTim;

    void inputDataTim() {
        TimData newData;

        cout << "Masukkan nama tim: ";
        cin.ignore();
        getline(cin, newData.namaTim);

        cout << "Masukkan nama pembalap: ";  // Tambahkan input nama pembalap
        getline(cin, newData.namaPembalap);

        cout << "Pilih nomor pembalap: ";
        cin >> newData.nomorPembalap;

        cout << "Masukkan jumlah lap: ";
        cin >> newData.lap;

        cout << "Masukkan waktu tempuh dalam 1 race (jam): ";
        cin >> newData.jam;

        cout << "Masukkan waktu tempuh dalam 1 race (menit): ";
        cin >> newData.menit;

        cout << "Masukkan waktu tempuh dalam 1 race (detik): ";
        cin >> newData.detik;

        dataTim.push_back(newData);

        ofstream fout(FILENAME_PEMBALAP, ios::app);
        if (fout.is_open()) {
            fout << newData.namaTim << "," << newData.namaPembalap << "," << newData.nomorPembalap << "," << newData.lap << "," << newData.jam << "," << newData.menit << "," << newData.detik << endl;
            fout.close();
            cout << "Data tim berhasil dimasukkan." << endl;
        } else {
            cout << "Gagal membuka file untuk menulis data." << endl;
        }
    }

    void bacaDataTim() {
        ifstream fin(FILENAME_PEMBALAP);
        if (fin.is_open()) {
            dataTim.clear();

            string line;
            while (getline(fin, line)) {
                TimData newData;

                size_t pos1 = line.find(',');
                newData.namaTim = line.substr(0, pos1);

                size_t pos2 = line.find(',', pos1 + 1);
                newData.namaPembalap = line.substr(pos1 + 1, pos2 - pos1 - 1);

                size_t pos3 = line.find(',', pos2 + 1);
                newData.nomorPembalap = stoi(line.substr(pos2 + 1, pos3 - pos2 - 1));

                size_t pos4 = line.find(',', pos3 + 1);
                newData.lap = stoi(line.substr(pos3 + 1, pos4 - pos3 - 1));

                size_t pos5 = line.find(',', pos4 + 1);
                newData.jam = stoi(line.substr(pos4 + 1, pos5 - pos4 - 1));

                newData.menit = stoi(line.substr(pos5 + 1));

                dataTim.push_back(newData);
            }

            fin.close();
        } else {
            cout << "Gagal membuka file untuk membaca data." << endl;
        }
    }

    string getNamaTim(int nomorPembalap) {
        int i = 0;
        while (i < dataTim.size()) {
            if (dataTim[i].nomorPembalap == nomorPembalap) {
                return dataTim[i].namaTim;
            }
            i++;
        }
        return "";
    }

    void lihatPembalap(int nomorPembalap) {
        ifstream fin(FILENAME_PEMBALAP);
        if (fin.is_open()) {
            cout << "\nData Pembalap Tim " << nomorPembalap << ":\n";
            cout << "+-----------------------------------------------------------------------+" << endl;
            cout << "| No. | Nama Pembalap     | Nomer Pembalap | Waktu Balapan     | Lap |" << endl;
            cout << "+-----------------------------------------------------------------------+" << endl;

            int no = 1;
            string line;
            while (getline(fin, line)) {
                istringstream iss(line);
                int tim, nomor;
                string nama;
                int jam, menit, detik, lap;

                iss >> tim >> nama >> nomor >> jam >> menit >> detik >> lap;

                if (nomor == nomorPembalap) {
                    cout << "| " << setw(3) << no << " | ";
                    cout << setw(17) << nama << " | ";
                    cout << setw(13) << nomor << " | ";
                    cout << setw(2) << jam << ":" << setw(2) << menit << ":" << setw(2) << detik << "     | ";
                    cout << setw(3) << lap << " |";
                    cout << endl;
                    no++;
                }
            }

            cout << "+-----------------------------------------------------------------------+" << endl;
            fin.close();
        } else {
            cout << "Gagal membuka file untuk membaca data." << endl;
        }
    }


    void editDataPembalap(int nomorPembalap) {
        int i = 0;
        while (i < dataTim.size()) {
            if (dataTim[i].nomorPembalap == nomorPembalap) {
                TimData& pembalap = dataTim[i];

                cout << "Masukkan nama tim: ";
                cin.ignore();
                getline(cin, pembalap.namaTim);

                cout << "Masukkan nama pembalap: ";
                getline(cin, pembalap.namaPembalap);

                cout << "Pilih nomor pembalap: ";
                cin >> pembalap.nomorPembalap;

                cout << "Masukkan jumlah lap: ";
                cin >> pembalap.lap;

                cout << "Masukkan waktu tempuh dalam 1 race (jam): ";
                cin >> pembalap.jam;

                cout << "Masukkan waktu tempuh dalam 1 race (menit): ";
                cin >> pembalap.menit;

                cout << "Masukkan waktu tempuh dalam 1 race (detik): ";
                cin >> pembalap.detik;

                ofstream fout(FILENAME_PEMBALAP, ios::trunc);  // Ubah mode menjadi ios::trunc
                if (fout.is_open()) {
                    int j = 0;
                    while (j < dataTim.size()) {
                        const TimData& data = dataTim[j];
                        fout << data.namaTim << "," << data.namaPembalap << "," << data.nomorPembalap << "," << data.lap << "," << data.jam << "," << data.menit << "," << data.detik << endl;
                        j++;
                    }
                    fout.close();
                    cout << "Data pembalap berhasil diubah." << endl;
                } else {
                    cout << "Gagal membuka file untuk menulis data." << endl;
                }

                return;
            }
            i++;
        }

        cout << "Nomor pembalap tidak ditemukan." << endl;
    }

    void deleteDataPembalap(int nomorPembalap) {
        int i = 0;
        while (i < dataTim.size()) {
            if (dataTim[i].nomorPembalap == nomorPembalap) {
                dataTim.erase(dataTim.begin() + i);

                ofstream fout(FILENAME_PEMBALAP);
                if (fout.is_open()) {
                    int j = 0;
                    while (j < dataTim.size()) {
                        const TimData& data = dataTim[j];
                        fout << data.namaTim << "," << data.namaPembalap << "," << data.nomorPembalap << "," << data.lap << "," << data.jam << "," << data.menit << "," << data.detik << endl;
                        j++;
                    }
                    fout.close();
                    cout << "Data pembalap berhasil dihapus." << endl;
                } else {
                    cout << "Gagal membuka file untuk menulis data." << endl;
                }

                return;
            }
            i++;
        }

        cout << "Nomor pembalap tidak ditemukan." << endl;
    }
};

#endif // PEMBALAP_H
