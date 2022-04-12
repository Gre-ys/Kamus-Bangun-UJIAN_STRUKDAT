//library
#include<iostream>
#include<String>
#include<cstdlib>
#include<limits>

using namespace std;

namespace materi{

//Validate
template <typename T>
T validate(T &var){
    cin >> var;
    while (!cin.good()){
        cout << "Masukan tidak Valid" << endl;
        cin.clear();
        cin.ignore(1, '\n');
        cin >> var;
    }
    return var;
}

//struct stack materi
struct stackMateri{
    int top;
    string tmptitle[5];
    string tmptext[5];
    string title;
    string text;
}materi;

//========================
//stack family
//buat stack
void createStack(){
    materi.top = 1;
}

//data kosong
int isEmpty(){
    if(materi.top == -1){
        return 1;
    } else {
        return 0;
    }
}

//data penuh
int isFull(){
    if(materi.top == 5-1){
        return 1;
    } else {
        return 0;
    }
}

//buat stack
void pushMateri(string judul, string isi){
    if(isFull() == 1){
        cout<<"Materi sudah penuh"<<endl;
    } else {
        //deklarasi
        stackMateri last;

        cout<<materi.top<<endl;

        materi.top++;
        materi.tmptitle[materi.top] = judul;
        materi.tmptext[materi.top] = isi;

    }
}

void deleteMateri(){
    if(isEmpty() == 1){
        cout<<"Materi Kosong"<<endl;
    } else {
        materi.top--;
        cout<<"Materi dihapus"<<endl;
    }
}

void showMateri(){
    if(isEmpty() == 1){
        cout<<"Materi Kosong"<<endl;
    } else {
        //deklarasi

        for(int i = materi.top; i > 0; i--){
            cout<<"\n"<<i<<". "<<materi.tmptitle[i]<<endl;
            cout<<materi.tmptext[i]<<endl;
        }
    }
}

//buat soal
void makeMateri(){
    //reset display
    system("cls");

    //deklarasi

    cout<<"Masukan Judul dan isi"<<endl;
    cout<<"Judul : ";getline(cin, materi.title);
    cout<<"isi   : ";getline(cin, materi.text);

    pushMateri(materi.title, materi.text);
}

//void menu materi
int displayMateri(){
    //Reset Dipslay
    system("cls");

    //Deklarasi
    int option;

    cout << "==================" << endl;
    cout << "|     Materi     |" << endl;
    cout << "==================" << endl;
    cout << "1. Buat Materi" << endl;
    cout << "2. Hapus Materi" << endl;
    cout << "3. Lihat Materi" << endl;
    cout << "4. Kembali" << endl;
    cout << "==================" << endl;
    cout << "Pilih (1-4) : ";
    option = validate(option);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return option;
}

int main(){
    //deklarasi
    int pilihmenu = displayMateri();
    char lanjut;

    while(pilihmenu != 4){
        switch(pilihmenu){
            case 1:
                makeMateri();
                break;
            case 2:
                deleteMateri();
                break;
            case 3:
                system("cls");
                showMateri();
                break;
            default:
                cout<<"Tidak ada"<<endl;
                break;
        }

        cobalagi:
        cout << "Lanjut (Y/N) : ";
        cin >> lanjut;

        if ((lanjut == 'y') | (lanjut == 'Y')){
            pilihmenu = displayMateri();

        } else if ((lanjut == 'n') | (lanjut == 'N')){
            break;

        } else {
            goto cobalagi;

        }
    }
}

}
