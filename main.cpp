#include <iostream>
#include "menu.h"

using namespace std;

int main() {
    int pilihan;

    do {
        system("cls");
        tampilMenu();
        cout << "Masukkan Pilihan (1-3): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                system("cls");
                menu1();
                break;
            case 2:
                system("cls");
                menu2();
                break;
            case 3:
                system("cls");
                menu3();
                break;
            case 4:
                system("cls");
                tampilMenu();
                break;
            case 5:
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                break;
        }

        cout << endl;
        cout << "Tekan enter untuk melanjutkan...";
        cin.ignore();
        cin.get();
        system("cls");
    } while (pilihan != 4);

    return 0;
}
