#include <iostream>
#include <string>
#include <limits>
#include <math.h>
using namespace std;

namespace kalkulator
{
    int pilihrumus;
    char kembali = '1';

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

    struct bangun
    {
        double panjang;
        double lebar;
        double tinggi;
        double luas;
        double keliling;
        string nama;
    };
    //queue History kalkulator

    struct queue
    {
        int top;
        bangun data[10];
    } q;

    void createQueue()
    {
        q.top = 0;
    }

    bool isEmpty()
    {
        if (q.top == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isFull()
    {
        if (q.top == 10)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void deleteQueue()
    {
        if (isEmpty())
        {
        }
        else
        {
            int i = 1;
            while (i < q.top)
            {
                q.data[i - 1] = q.data[i];
                i++;
            }
            q.top--;
        }
    }

    void insertQueue(bangun data)
    {
        if (isFull())
        {
            deleteQueue();
            insertQueue(data);
        }
        else
        {
            q.data[q.top] = data;
            q.top++;
        }
    }

    // persegi panjang
    void persegipanjang()
    {
        bangun p_panjang;
        //input
        cout << "Masukan panjang Bangun tersebut : ";
        p_panjang.panjang = validate(p_panjang.panjang);
        cout << "Masukan Lebar Bangun tersebut   : ";
        p_panjang.lebar = validate(p_panjang.lebar);
        //prosess
        p_panjang.luas = p_panjang.lebar * p_panjang.panjang;
        p_panjang.keliling = 2 * (p_panjang.panjang + p_panjang.lebar);
        //output

        cout << "----------------------------------------------------------\n";
        cout << "Luas bangun datar tersebut     : " << p_panjang.luas << endl;
        cout << "Keliling bangun datar tersebut : " << p_panjang.keliling;
        p_panjang.nama = "Persegi Panjang ";

        insertQueue(p_panjang);
    }

    // persegi
    void persegiempat()
    {
        bangun p_empat;
        //input
        cout << "Masukan panjang sisi Bangun tersebut : ";
        p_empat.panjang = validate(p_empat.panjang);
        //prosess
        p_empat.luas = pow(p_empat.panjang, 3);
        p_empat.keliling = p_empat.panjang * 4;
        //output
        cout << "----------------------------------------------------------\n";
        cout << "Luas bangun datar tersebut     : " << p_empat.luas << endl;
        cout << "Keliling bangun datar tersebut : " << p_empat.keliling << endl;
        p_empat.nama = "     Persegi    ";

        insertQueue(p_empat);
    }

    //Persegi tiga
    void segitiga()
    {
        bangun segitiga;
        cout << "Masukan panjang atau sisi ke 1 Bangun tersebut  : ";
        segitiga.panjang = validate(segitiga.panjang);
        cout << "Masukan alas    atau sisi ke 2 Bangun tersebut  : ";
        segitiga.lebar = validate(segitiga.lebar);
        cout << "Masukan tinggi  atau sisi ke 3 Bangun tersebut  : ";
        segitiga.tinggi = validate(segitiga.tinggi);
        //prosess
        segitiga.luas = segitiga.lebar * segitiga.tinggi / 2;
        segitiga.keliling = segitiga.panjang + segitiga.tinggi + segitiga.lebar;
        //output
        cout << "----------------------------------------------------------\n";
        cout << "Luas bangun datar tersebut     : " << segitiga.luas << endl;
        cout << "Keliling bangun datar tersebut : " << segitiga.keliling << endl;
        segitiga.nama = "Segitiga        ";
        insertQueue(segitiga);
    }

    //Lingkaran
    void lingkaran()
    {
        bangun lingkaran;
        //input
        cout << "Masukan jari-jari Bangun tersebut  : ";
        lingkaran.panjang = validate(lingkaran.panjang);
        //prosess
        lingkaran.luas = 22 * lingkaran.panjang * lingkaran.panjang / 7;
        lingkaran.keliling = 2 * 22 * lingkaran.panjang / 7;
        //output
        cout << "----------------------------------------------------------\n";
        cout << "Luas bangun datar tersebut         : " << lingkaran.luas << endl;
        cout << "Keliling bangun datar tersebut     : " << lingkaran.keliling << endl;
        lingkaran.nama = "Lingkaran       ";
        insertQueue(lingkaran);
    }

    //jajargenjang
    void jajargenjang()
    {
        bangun jg;
        //input
        cout << "Masukan panjang sisi miring Bangun tersebut  : ";
        jg.panjang = validate(jg.panjang);
        cout << "Masukan alas Bangun tersebut                 : ";
        jg.lebar = validate(jg.lebar);
        cout << "Masukan tinggi Bangun tersebut               : ";
        jg.tinggi = validate(jg.tinggi);
        //prosess
        jg.luas = jg.lebar * jg.tinggi;
        jg.keliling = 2 * (jg.lebar + jg.panjang);
        //output
        cout << "----------------------------------------------------------\n";
        cout << "Luas bangun datar tersebut     : " << jg.luas << endl;
        cout << "Keliling bangun datar tersebut : " << jg.keliling << endl;
        jg.nama = "Jajar Genjang   ";
        insertQueue(jg);
    }

    //Trapesium
    void trapesium()
    {
        bangun trapesium;
        double miring;
        //input
        cout << "Masukan panjang sisi atas Bangun tersebut     : ";
        trapesium.panjang = validate(trapesium.panjang);
        cout << "Masukan panjang sisi bawah Bangun tersebut    : ";
        trapesium.lebar = validate(trapesium.lebar);
        cout << "Masukan panjang sisi miring Bangun tersebut   : ";
        miring = validate(miring);
        cout << "Masukan tinggi Bangun tersebut                : ";
        trapesium.tinggi = validate(trapesium.tinggi);
        //prosess
        trapesium.luas = (trapesium.panjang + trapesium.lebar) * trapesium.tinggi / 2;
        trapesium.keliling = trapesium.panjang + trapesium.lebar + miring + trapesium.tinggi;
        //output
        cout << "----------------------------------------------------------\n";
        cout << "Luas bangun datar tersebut     : " << trapesium.luas << endl;
        cout << "Keliling bangun datar tersebut : " << trapesium.keliling << endl;
        trapesium.nama = "Trapesium       ";
        insertQueue(trapesium);
    }

    //Belah Ketupat
    void belahketupat()
    {
        bangun bk;
        //input
        cout << "Masukan panjang diagonal 1 Bangun tersebut     : ";
        bk.panjang = validate(bk.panjang);
        cout << "Masukan panjang diagonal 2 Bangun tersebut    : ";
        bk.lebar = validate(bk.lebar);
        //prosess
        bk.luas = bk.panjang * bk.lebar / 2;
        bk.keliling = sqrt((pow(bk.panjang, 2) / 2)) + ((pow(bk.lebar, 2) / 2));
        //output
        cout << "----------------------------------------------------------\n";
        cout << "Luas bangun datar tersebut     : " << bk.luas << endl;
        cout << "Keliling bangun datar tersebut : " << bk.keliling << endl;
        bk.nama = "Belah Ketupat   ";
        insertQueue(bk);
    }

    //Layang-layang
    void layang()
    {
        bangun layang;
        double atas, bawah;
        //input
        cout << "Masukan panjang diagonal 1 Bangun tersebut    : ";
        layang.panjang = validate(layang.panjang);
        cout << "Masukan panjang diagonal 2 Bangun tersebut    : ";
        layang.lebar = validate(layang.lebar);
        cout << "Masukan panjang sisi bagian atas              : ";
        atas = validate(atas);
        cout << "Masukan panjang sisi bagian bawah             : ";
        bawah = validate(bawah);
        //prosess
        layang.luas = layang.panjang * layang.lebar / 2;
        layang.keliling = 2 * (atas + bawah);
        //output
        cout << "----------------------------------------------------------\n";
        cout << "Luas bangun datar tersebut     : " << layang.luas << endl;
        cout << "Keliling bangun datar tersebut : "
             << layang.keliling << endl;
        layang.nama = "Layang-layang   ";
        insertQueue(layang);
    }

    //Kubus
    void kubus()
    {
        bangun kubus;
        //input
        cout << "Masukan panjang Sisi Bangun Ruang tersebut    : ";
        kubus.panjang = validate(kubus.panjang);
        //prosess
        kubus.luas = kubus.panjang * kubus.panjang * kubus.panjang;
        kubus.keliling = 6 * (kubus.panjang * kubus.panjang);
        //output
        cout << "----------------------------------------------------------\n";
        cout << "Volume Bangun Ruang tersebut         : " << kubus.luas << endl;
        cout << "Luas Permukaan Bangun Ruang tersebut : "
             << kubus.keliling << endl;
        kubus.nama = "Kubus           ";
        insertQueue(kubus);
    }
    //Balok
    void balok()
    {
        bangun balok;
        double tinggi;
        //input
        cout << "Masukan panjang Bangun Ruang tersebut    : ";
        balok.panjang = validate(balok.panjang);
        cout << "Masukan panjang Bangun Ruang tersebut    : ";
        balok.lebar = validate(balok.lebar);
        //prosess
        balok.luas = balok.panjang * balok.lebar * balok.tinggi;
        balok.keliling = 2 * ((balok.panjang * balok.lebar) + (balok.tinggi * balok.panjang) + (balok.lebar * balok.tinggi));
        //output
        cout << "----------------------------------------------------------\n";
        cout << "Volume Bangun Ruang tersebut         : " << balok.luas << endl;
        cout << "Luas Permukaan Bangun Ruang tersebut : "
             << balok.keliling << endl;
        balok.nama = "Balok           ";
        insertQueue(balok);
    }
    //Tabung
    void tabung()
    {
        bangun tabung;
        //input
        cout << "Masukan tinggi Bangun Ruang tersebut    : ";
        tabung.panjang = validate(tabung.panjang);
        cout << "Masukan jari-jari Bangun Ruang tersebut    : ";
        tabung.lebar = validate(tabung.lebar);
        //prosess
        tabung.luas = 22 * tabung.panjang * tabung.lebar * tabung.lebar / 7;
        tabung.keliling = 2 * ((tabung.panjang + tabung.lebar) * 22 * tabung.lebar) / 7;
        //output
        cout << "----------------------------------------------------------\n";
        cout << "Volume Bangun Ruang tersebut         : " << tabung.luas << endl;
        cout << "Luas Permukaan Bangun Ruang tersebut : " << tabung.keliling << endl;
        tabung.nama = "Tabung          ";
        insertQueue(tabung);
    }
    //Kerucut
    void kerucut()
    {
        bangun kerucut;
        double s;
        //input
        cout << "Masukan tinggi Bangun Ruang tersebut    : ";
        kerucut.panjang = validate(kerucut.panjang);
        cout << "Masukan jari-jari Bangun Ruang tersebut    : ";
        kerucut.lebar = validate(kerucut.lebar);
        s = sqrt(pow(kerucut.panjang, 2) + pow(kerucut.lebar, 2));
        //prosess
        kerucut.luas = (22 * kerucut.panjang * kerucut.lebar * kerucut.lebar / 7) / 3;
        kerucut.keliling = (22 * kerucut.lebar * kerucut.lebar / 7) + (22 * kerucut.lebar * s / 7);
        //output
        cout << "----------------------------------------------------------\n";
        cout << "Volume Bangun Ruang tersebut         : " << kerucut.luas << endl;
        cout << "Luas Permukaan Bangun Ruang tersebut : "
             << kerucut.keliling << endl;
        kerucut.nama = "Kerucut         ";
        insertQueue(kerucut);
    }

    //Limas Segi Tiga
    void L_segitiga()
    {
        bangun lst;
        double tinggi, l1, l2, l3;
        //input
        cout << "Masukan tinggi Bangun Ruang tersebut               : ";
        lst.panjang = validate(lst.panjang);
        cout << "Masukan alas segitiga Bangun Ruang tersebut        : ";
        lst.lebar = validate(lst.lebar);
        cout << "Masukan tinggi segitiga alas Bangun Ruang tersebut :";
        tinggi = validate(tinggi);
        //prosess

        lst.luas = lst.panjang * (lst.lebar * tinggi / 2) / 3;
        cout << "----------------------------------------------------------\n";
        cout << "Volume Bangun Ruang tersebut         : " << lst.luas << endl;
        cout << "----------------------------------------------------------\n";
        cout << "Untuk mencari Luas Permukaan \n " << endl;
        cout << "Masukan luas sisi tegak 1 : ";
        l1 = validate(l1);
        cout << "Masukan luas sisi tegak 2 : ";
        l2 = validate(l2);
        cout << "Masukan luas sisi tegak 3 : ";
        l3 = validate(l3);
        lst.keliling = (lst.lebar * tinggi / 2) + l1 + l2 + l3;
        //output
        cout << "----------------------------------------------------------\n";
        cout << "Volume Bangun Ruang tersebut         : " << lst.luas << endl;
        cout << "Luas Permukaan Bangun Ruang tersebut : "
             << lst.keliling << endl;
        lst.nama = "Limas Segi Tiga ";
        insertQueue(lst);
    }
    //limas Segi Empat
    void L_segiempat()
    {
        bangun lse;
        double l1, l2, l3, l4;
        //input
        cout << "Masukan luas alas Bangun Ruang tersebut               : ";
        lse.panjang = validate(lse.panjang);
        cout << "Masukan tinggi Bangun Ruang tersebut        : ";
        lse.lebar = validate(lse.lebar);
        //prosess
        lse.luas = (lse.panjang * lse.lebar) / 2;
        cout << "----------------------------------------------------------\n";
        cout << "Volume Bangun Ruang tersebut         : " << lse.luas << endl;
        cout << "----------------------------------------------------------\n";
        cout << "Untuk mencari Luas Permukaan \n " << endl;
        cout << "Masukan luas sisi tegak 1 : ";
        l1 = validate(l1);
        cout << "Masukan luas sisi tegak 2 : ";
        l2 = validate(l2);
        cout << "Masukan luas sisi tegak 3 : ";
        l3 = validate(l3);
        cout << "Masukan luas sisi tegak 4 : ";
        l4 = validate(l4);

        lse.keliling = lse.panjang + l1 + l2 + l3 + l4;
        //output
        cout << "----------------------------------------------------------\n";
        cout << "Volume Bangun Ruang tersebut         : " << lse.luas << endl;
        cout << "Luas Permukaan Bangun Ruang tersebut : "
             << lse.keliling << endl;
        lse.nama = "Limas Segi Empat";
        insertQueue(lse);
    }
    //Bola
    void bola()
    {
        bangun bola;
        //input
        cout << "Masukan jari-jari Bangun Ruang tersebut    : ";
        bola.panjang = validate(bola.panjang);
        //prosess
        bola.luas = 4 * (22 * pow(bola.panjang, 3) / 7) / 3;
        bola.keliling = 4 * (22 * pow(bola.panjang, 2) / 7);
        //output
        cout << "----------------------------------------------------------\n";
        cout << "Volume Bangun Ruang tersebut         : " << bola.luas << endl;
        cout << "Luas Permukaan Bangun Ruang tersebut : "
             << bola.keliling << endl;
        bola.nama = "Bola            ";
        insertQueue(bola);
    }

    //Prisma
    void prisma()
    {
        bangun prisma;
        double kk;
        //input
        cout << "Masukan Luas alas Bangun Ruang tersebut           : ";
        prisma.panjang = validate(prisma.panjang);
        cout << "Masukan tinggi Bangun Ruang tersebut              : ";
        prisma.lebar = validate(prisma.lebar);
        cout << "Masukan Keliling alas Bangun Ruang tersebut       : ";
        kk = validate(kk);
        //prosess
        prisma.luas = prisma.panjang * prisma.lebar;
        prisma.keliling = (prisma.lebar * kk) + (2 * prisma.panjang);
        //output
        cout << "----------------------------------------------------------\n";
        cout << "Volume Bangun Ruang tersebut         : " << prisma.luas << endl;
        cout << "Luas Permukaan Bangun Ruang tersebut : "
             << prisma.keliling << endl;
        prisma.nama = "Prisma           ";
        insertQueue(prisma);
    }

    //History kalkulator
    void history()
    {
        if (isEmpty())
        {
        }
        else
        {
            cout << "\n           HISTORY KALKULATOR" << endl
                 << endl;
            int i = 0;
            cout << "| Bangun     \t| Keliling\t| Luas\t|" << endl;
            while (i < q.top)
            {
                cout << "| " << q.data[i].nama << "\t|" << q.data[i].keliling << "\t\t|" << q.data[i].luas << "\t|" << endl;
                i++;
            }
        }
    }
    void rumusruang()
    {
        system("CLS");
        cout << "------------------------------\n";
        cout << "|            RUMUS           |\n";
        cout << "------------------------------\n";
        cout << "|  1. Kubus                  |\n";
        cout << "|  2. Balok                  |\n";
        cout << "|  3. Tabung                 |\n";
        cout << "|  4. Kerucut                |\n";
        cout << "|  5. Limas Segi Tiga        |\n";
        cout << "|  6. Limas Segi Empat       |\n";
        cout << "|  7. Bola                   |\n";
        cout << "|  8. Prisma                 |\n";
        cout << "|  9. History Kalkulator     |\n";
        cout << "------------------------------\n";
    }
    void ruangrumus()
    {
        createQueue();
        do
        {
            rumusruang();
            cout << "Silahkan Pilih  : ";
            cin >> pilihrumus;
            switch (pilihrumus)
            {
            case 1:
                kubus();
                break;
            case 2:
                balok();
                break;
            case 3:
                tabung();
                break;
            case 4:
                kerucut();
                break;
            case 5:
                L_segitiga();
                break;
            case 6:
                L_segiempat();
                break;
            case 7:
                bola();
                break;
            case 8:
                prisma();
                break;
            case 9:
                history();
                break;
            default:
                cout << "Inputan Salah!, silahkan" << endl;
            }

            cout << "Kembali Ke Rumus Utama input angka (1) jika tidak input angka (0) : ";
            kembali = validate(kembali);
        } while (kembali == '1' || kembali == '1');
    }
    //menu rumus
    void rumusdatar()
    {
        system("CLS");
        cout << "------------------------------\n";
        cout << "|            RUMUS           |\n";
        cout << "------------------------------\n";
        cout << "|  1. Persegi                |\n";
        cout << "|  2. Persegi Panjang        |\n";
        cout << "|  3. Persegi Tiga           |\n";
        cout << "|  4. Lingkaran              |\n";
        cout << "|  5. Jajargenjang           |\n";
        cout << "|  6. Trapesium              |\n";
        cout << "|  7. Belah Ketupat          |\n";
        cout << "|  8. Layang-layang          |\n";
        cout << "|  9. History Kalkulator     |\n";
        cout << "------------------------------\n";
    }

    void datarrumus()
    {
        createQueue();
        do
        {
            rumusdatar();
            cout << "Silahkan Pilih  : ";
            cin >> pilihrumus;
            switch (pilihrumus)
            {
            case 1:
                persegiempat();
                break;
            case 2:
                persegipanjang();
                break;
            case 3:
                segitiga();
                break;
            case 4:
                lingkaran();
                break;
            case 5:
                jajargenjang();
                break;
            case 6:
                trapesium();
                break;
            case 7:
                belahketupat();
                break;
            case 8:
                layang();
                break;
            case 9:
                history();
                break;

            default:
                cout << "Inputan Salah!, silahkan" << endl;
            }

            cout << "Kembali Ke Rumus Utama input angka (1) jika tidak input angka (0) : ";
            kembali = validate(kembali);
        } while (kembali == '1' || kembali == '1');
    }
    void menu()
    {
        system("CLS");
        cout << "------------------------------\n";
        cout << "|            RUMUS           |\n";
        cout << "------------------------------\n";
        cout << "|  1. Bangun Datar           |\n";
        cout << "|  2. Bangun Ruang           |\n";
        cout << "------------------------------\n";
    }
    int main()
    {
        createQueue();
        do
        {
            menu();
            cout << "Silahkan Pilih  : ";
            cin >> pilihrumus;
            switch (pilihrumus)
            {
            case 1:
                datarrumus();
                break;
            case 2:
                ruangrumus();
                break;
            default:
                cout << "Inputan Salah!, silahkan" << endl;
                break;
            }

            cout << "Kembali Ke Rumus Utama input angka (1) jika tidak input angka (0) : ";
            kembali = validate(kembali);
        } while (kembali == '1' || kembali == '1');
    }

}
