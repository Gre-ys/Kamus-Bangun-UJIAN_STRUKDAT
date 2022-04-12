#include<iostream>
#include<string>
#include<limits>
#include<cstdlib>

using namespace std;

namespace latihan{

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

struct queueQuiz{
    int top;
    string soal[5];
    string answerA[5];
    string answerB[5];
    string answerC[5];
    string answerD[5];
    char answer[5];

    char kunjaw;
    string question, a, b, c, d;
    int score;

    queueQuiz *left, *right;
}quiz;

queueQuiz *pohon, *root;

//tree and family
void firstDefinition(){
    pohon = NULL;
}

void insertTree(queueQuiz** root, int nilai){
    queueQuiz *new_node;

    //jika data kosong
    if((*root) == NULL){
        //deklarasi
        int kkm = 50;
        new_node = new queueQuiz;
        new_node -> score = nilai;
        new_node -> left = new_node -> right;

        (*root) = new queueQuiz;
        (*root) -> score = nilai;
        (*root) -> left = (*root) -> right;

        //cout<<new_node -> score<<" Nilai ditambahkan"<<endl;
    }

    if(nilai < (*root) -> score){
        insertTree(&(*root) -> left, nilai);
        cout<<nilai<<" Nilai dibawah SNI"<<endl;
    }

    if(nilai > (*root) -> score){
        insertTree(&(*root) -> right, nilai);
        cout<<nilai<<" Nilai diatas SNI"<<endl;
    }
}

void preOrder(queueQuiz *root){
    if(root != NULL){
        if(root->score != 50){
            cout<<root->score<<endl;
        }
            preOrder(root -> left);
            preOrder(root -> right);


    }
}

void displayTree(){
    //reset display
    system("cls");

    cout<<"============="<<endl;
    cout<<"|   SCORE   |"<<endl;
    cout<<"============="<<endl;

    if(pohon == NULL){
        cout<<"Score masih kosong"<<endl;
    } else {
        preOrder(pohon);
        cout<<endl;
    }
}

//queue
void createqueue(){
    quiz.top = 0;
}

int isEmpty(){
    if(quiz.top == 0){
        return 1;
    } else {
        return 0;
    }
}

int isFull(){
    if(quiz.top == 5){
        return 1;
    } else {
        return 0;
    }
}

void insertQuiz(string question, string a, string b, string c, string d, char answer){
    quiz.soal[quiz.top] = question;
    quiz.answerA[quiz.top] = a;
    quiz.answerB[quiz.top] = b;
    quiz.answerC[quiz.top] = c;
    quiz.answerD[quiz.top] = d;
    quiz.answer[quiz.top] = answer;
    quiz.top++;
}

void makeQuestion(){
    system("cls");

    if(isFull() == 1){
        cout<<"Soal sudah penuh"<<endl;
    } else {
        cout<<"Masukan soal"<<endl;
        cout<<"Soal : ";getline(cin, quiz.question);
        cout<<"\nMasukan jawaban"<<endl;
        cout<<"a :";getline(cin, quiz.a);
        cout<<"b :";getline(cin, quiz.b);
        cout<<"c :";getline(cin, quiz.c);
        cout<<"d :";getline(cin, quiz.d);
        cout<<"\nMasukan kunci jawaban"<<endl;

        ulang:
        cout << "Kunci jawaban : ";quiz.kunjaw = validate(quiz.kunjaw);

        if(toupper((quiz.kunjaw != 'a') && (quiz.kunjaw != 'b') && (quiz.kunjaw != 'c') && (quiz.kunjaw != 'd'))){
            cout<<"masukan a, b, c, dan d."<<endl;
            goto ulang;
        } else {
        }

        insertQuiz(quiz.question, quiz.a, quiz.b, quiz.c, quiz.d,quiz.kunjaw);
    }
}

void displayQ(){
    //reset
    system("cls");

    if(isEmpty() == 1){
        cout<<"Soal Kosong"<<endl;
    } else {
        //deklarasi
        char jawaban;
        int counter = 0;

        cout<<"================"<<endl;
        cout<<"       Soal   "<<endl;
        cout<<"================"<<endl;

        for(int i = 0; i < quiz.top; i++){
            //menampilkan soal
            cout<<"\n"<<i+1<<". "<<quiz.soal[i]<<endl;
            cout<<"a. "<<quiz.answerA[i]<<endl;
            cout<<"b. "<<quiz.answerB[i]<<endl;
            cout<<"c. "<<quiz.answerC[i]<<endl;
            cout<<"d. "<<quiz.answerD[i]<<endl;

            //mengisi jawaban
            ulang:
            cout<<"Masukan Jawaban : ";jawaban= validate(jawaban);

            if(toupper((jawaban != 'a') && (jawaban != 'b') && (jawaban != 'c') && (jawaban != 'd'))){
                cout<<"masukan a, b, c, dan d."<<endl;
                goto ulang;
            } else {
            }

            if(jawaban == quiz.kunjaw){
                counter++;
            }

        }

        quiz.score = counter * 20;

        insertTree(&pohon, quiz.score);
    }
}

void removeQuiz(){
    system("cls");

    if(isEmpty()==1){
        cout<<"Kosong"<<endl;
    } else {

        for(int i = 1; i < quiz.top; i++){
            quiz.soal[i-1] = quiz.soal[i];
            quiz.answerA[i-1] = quiz.answerA[i];
            quiz.answerB[i-1] = quiz.answerB[i];
            quiz.answerC[i-1] = quiz.answerC[i];
            quiz.answerD[i-1] = quiz.answerD[i];
            quiz.answer[i-1] = quiz.answer[i];
        }
        cout<<"Soal dikeluarkan"<<endl;
        quiz.top--;
    }
}

int displayQuiz(){
    //Reset Dipslay
    system("cls");

    //Deklarasi
    int option;

    cout << "==================" << endl;
    cout << "|      Quiz      |" << endl;
    cout << "==================" << endl;
    cout << "1. Buat Soal" << endl;
    cout << "2. Soal" << endl;
    cout << "3. Hapus Soal" << endl;
    cout << "4. Riwayat Score" << endl;
    cout << "5. Kembali" << endl;
    cout << "==================" << endl;
    cout << "Pilih (1-5) : ";
    option = validate(option);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return option;
}

int main(){
    //deklarasi
    int pilihmenu = displayQuiz();
    int size;
    char lanjut;
    firstDefinition();
    insertTree(&pohon, 50);


    while(pilihmenu != 5){
        switch(pilihmenu){
            case 1:
                makeQuestion();
                break;
            case 2:
                displayQ();
                break;
            case 3:
                removeQuiz();
                break;
            case 4:
                displayTree();
                break;
            default:
                cout<<"Tidak ada"<<endl;
                break;
        }

        cobalagi:
        cout << "Lanjut (Y/N) : ";
        cin >> lanjut;

        if ((lanjut == 'y') | (lanjut == 'Y')){
            pilihmenu = displayQuiz();

        } else if ((lanjut == 'n') | (lanjut == 'N')){
            break;

        } else {
            goto cobalagi;

        }
    }
}

}
