#include <iostream>
#include "latihan.hpp"
#include "kalkulator.hpp"
#include "materi.hpp"
#include "gambar.hpp"

using namespace std;

template <typename T>
T validate(T &var)
{
    cin >> var;
    while (!cin.good())
    {
        cout << "Masukan tidak Valid" << endl;
        cin.clear();
        cin.ignore(1, '\n');
        cin >> var;
    }
    return var;
}

int getOption()
{
    int opsi;

    cout << "=======================" << endl;
    cout << "| SILAHKAN PILIH OPSI |" << endl;
    cout << "=======================" << endl
         << endl;

    cout << "1. Materi Bangun" << endl;
    cout << "2. Gambar Bangun" << endl;
    cout << "3. Kalkulator Bangun" << endl;
    cout << "4. Latihan Bangun" << endl;
    cout << "5. Keluar Program" << endl
         << endl;

    cout << "Pilih: ";
    opsi = validate(opsi);

    return opsi;
}

void menuUtama()
{
    int opsi;
    char lanjut;
    system("cls");
    opsi = getOption();

    while (opsi != 5)
    {
        switch (opsi)
        {
        case 1:
            materi::main();
            break;
        case 2:
            gambar::main();
            break;
        case 3:
            kalkulator::main();
            break;
        case 4:
            latihan::main();
            break;
        default:
            system("cls");
            cout << "Pilih sesuai yang tertera!!!" << endl;
            opsi = getOption();
        }
    label_lanjut:
        cout << "\n\n";
        cout << "Lanjut? (y/n): ";
        lanjut = validate(lanjut);

        if ((lanjut == 'y') | (lanjut == 'Y'))
        {
            system("cls");
            opsi = getOption();
        }
        else if ((lanjut == 'n') | (lanjut == 'N'))
        {
            break;
        }
        else
        {
            cout << "Pilih antar y/n !!!" << endl;
            goto label_lanjut;
        }
    }
    cout << "Program Selesai, Terima Kasih..." << endl;
}

int main()
{
    menuUtama();
}
