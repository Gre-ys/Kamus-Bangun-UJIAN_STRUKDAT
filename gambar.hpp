#include <iostream>
using namespace std;

// Global variabel
int vertex;
char **adj;
int counter = 0;

namespace gambar
{

    // Validasi inputan
    template <typename T>
    T validate(T var)
    {
        cin >> var;
        while (!cin.good())
        {
            cin.clear();
            cin.ignore(1, '\n');
            cout << "Masukan tidak valid" << endl;
            cout << ": ";
            cin >> var;
        }
        return var;
    }

    // Membuat matrix graph [mxn]
    void buatGraph(int v)
    {

        adj = new char *[v];

        for (int baris = 0; baris < v; baris++)
        {
            adj[baris] = new char[v];
            for (int kolom = 0; kolom < v; kolom++)
            {
                adj[baris][kolom] = '-';
            }
        }
    }

    // Membentuk koneksi
    void tambahEdge(int vAwal, int vTujuan)
    {
        adj[vAwal][vTujuan] = '$';
        counter++;
    }

    // Menampilkan gambar
    void show()
    {
        if (vertex == 0)
        {
            cout << "Bidang Tidak Dibentuk, karena panjang 0 " << endl;
        }
        else
        {
            cout << "    ";
            for (int i = 0; i < vertex; i++) // For Header
            {
                cout << i << "  ";
            }
            cout << endl;

            cout << "   ";
            for (int i = 0; i < vertex; i++) // For Border
            {
                cout << "___";
            }
            cout << endl;

            for (int i = 0; i < vertex; i++) // For content
            {
                cout << i << " | ";
                for (int j = 0; j < vertex; j++)
                {
                    cout << adj[i][j] << "  ";
                }
                cout << endl;
            }
        }
    }

    // Membuat titik gambar bangun
    void buatGambar()
    {
        int baris, kolom;
        char option;

        show();
        cout << endl;
        while (counter != (vertex * vertex))
        {
        label_ulangMasukanBuat:
            cout << "Bentuk Titik Bangun(baris,kolom)" << endl;
            cout << "baris: ";
            baris = validate(baris);
            if ((baris > vertex - 1) || (baris < 0))
            {
                cout << "Masukan harus sesuai, antara 0-" << vertex - 1 << endl
                     << endl;
                goto label_ulangMasukanBuat;
            }

            cout << "kolom: ";
            kolom = validate(kolom);
            if ((kolom > vertex - 1) || (kolom < 0))
            {
                cout << "Masukan harus sesuai, antara 0-" << vertex - 1 << endl
                     << endl;
                goto label_ulangMasukanBuat;
            }

            // cek keadaan titik
            if (adj[baris][kolom] == '$')
            {
                cout << "Titik ini sudah dibentuk" << endl;
            }
            else
            {
                tambahEdge(baris, kolom);
                system("cls");
                show();
            }

        label_ulang:
            cout << "Gambar Lagi?(y/n): ";
            option = validate(option);
            if ((option == 'n') || (option == 'N'))
            {
                cout << "Gambar yang bagus, ayo terus belajar..." << endl;
                break;
            }
            else if ((option == 'y') || (option == 'Y'))
            {
            }
            else
            {
                cout << "Pilih sesuai opsi yang tertera...(y/n)" << endl;
                goto label_ulang;
            }
        }
    }

    // Mengahapus titik gambar bangun
    void hapusGambar()
    {
        show();
        cout << endl;
        int baris, kolom;

    label_ulangMasukanHapus:
        cout << "Masukan titik bangun yang ingin dihapus(baris,kolom)" << endl;
        cout << "Baris: ";
        baris = validate(baris);
        if ((baris > vertex - 1) || (baris < 0))
        {
            cout << "Masukan harus sesuai, antara 0-" << vertex - 1 << endl
                 << endl;
            goto label_ulangMasukanHapus;
        }

        cout << "Kolom: ";
        kolom = validate(kolom);
        if ((kolom > vertex - 1) || (kolom < 0))
        {
            cout << "Masukan harus sesuai, antara 0-" << vertex - 1 << endl
                 << endl;
            goto label_ulangMasukanHapus;
        }

        // cek keadaan titik
        if (adj[baris][kolom] == '-')
        {
            cout << "titik belum digambar sebelumnya" << endl;
        }
        else
        {
            adj[baris][kolom] = '-';
            counter--;
        }
    }

    // Menu menggambar
    void menuGambar()
    {
        int opsi;
        char opsiLanjut;

    label_menu:
        cout << "Menu Menggambar" << endl;
        cout << "---------------" << endl
             << endl;
        cout << "1. Bentuk titik" << endl;
        cout << "2. Hapus titik" << endl;
        cout << "3. Keluar" << endl
             << endl;

    label_ulangOpsi:
        cout << "Pilih: ";
        opsi = validate(opsi);

        if (opsi != 3)
        {
            switch (opsi)
            {
            case 1:
                // membentuk titik gambar
                cout << endl;
                system("cls");
                buatGambar();
                break;
            case 2:
                // menghapus titik gambar
                cout << endl;
                system("cls");
                hapusGambar();
                break;
            default:
                cout << "Pilih opsi yang tertera..." << endl;
                goto label_ulangOpsi;
                break;
            }
        label_ulangOpsiMenu:
            cout << "\nMasuk ke menu?(y/n): ";
            opsiLanjut = validate(opsiLanjut);
            if ((opsiLanjut == 'n') || (opsiLanjut == 'N'))
            {
            }
            else if ((opsiLanjut == 'Y') || (opsiLanjut == 'y'))
            {
                system("cls");
                show();
                cout << endl;
                goto label_menu;
            }
            else
            {
                cout << "Pilih sesuai opsi yang tertera(y/n)" << endl;
                goto label_ulangOpsiMenu;
            }
        }
    }

    main()
    {

        system("cls");
        cout << "Membuat Bangun" << endl;
        cout << "--------------" << endl;
        cout << "Masukan Panjang Bidang Gambar: ";
        vertex = validate(vertex);

        // membuat bidang
        buatGraph(vertex);

        // tampilkan bentuk bidang
        show();

        cout << endl;

        // menu gambar
        menuGambar();

        cin.get();
    }

}
