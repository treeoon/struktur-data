#include <iostream>

using namespace std;

//inisialisasi variabel
struct data 
{
    string nama, hobi;
    int usia;

    data *next;
};

data *head, *tail, *cur, *newNode, *del, *before;

void createSinglist(string nama, string hobi, int usia){
    head = new data();
    head->nama = nama;
    head->hobi = hobi;
    head->usia = usia;
    head->next = NULL;
    tail = head;
}

void addedFirst(string nama, string hobi, int usia) {
    newNode = new data();
    newNode->nama = nama;
    newNode->hobi = hobi;
    newNode->usia = usia;
    newNode->next = head;
    head = newNode;
}

void addedMiddle(string nama, string hobi, int usia, int posisi) {
    newNode = new data();
    newNode->nama = nama;
    newNode->hobi = hobi;
    newNode->usia = usia;
    cur = head;
    int i = 1;
    while(i < posisi-1) {
        cur = cur->next;
        i++;
    }
    newNode->next = cur->next;
    cur->next = newNode;
}

void addedLast(string nama, string hobi, int usia) {
    newNode = new data();
    newNode->nama = nama;
    newNode->hobi = hobi;
    newNode->usia = usia;
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
}

void deleteFirst() {
    del = head;
    head = head->next; //nunjuk node kedua
    delete del;
}

void deleteMiddle(int posisi) {
    cur = head;
    int i = 1;
    while(i <= posisi) {
        if(i == posisi-1) { // posisi dibelakang
            before = cur;
        }
        if(i == posisi) { // posisi yang mau di delete (tengah)
            del = cur; 
        }
        cur = cur->next; // posisi didepan
        i++;
    }
    before->next = cur; // before menunjuk ke posisi yang didepan
    delete del; // menghapus posisi yang ditengah
}

void deleteLast() {
    del = tail;
    cur = head;
    while(cur->next != tail){
        cur = cur->next; // mencari node sebelum tail
    }
    tail = cur; //mengganti tail ke curr
    tail->next = NULL; // tail menunjuk ke null
    delete del; //delete lastnode
}

void updateFirst(string nama, string hobi, int usia) {
    head->nama = nama;
    head->hobi = hobi;
    head->usia = usia;
}

void updateMiddle(string nama, string hobi, int usia, int posisi) {
    cur = head;
    int i = 1;
    while(i<posisi) {
        cur = cur->next;
        i++;
    }
    cur->nama = nama;
    cur->hobi = hobi;
    cur->usia = usia;
}

void updateLast(string nama, string hobi, int usia) {
    tail->nama = nama;
    tail->hobi = hobi;
    tail->usia = usia;
}

void printSinglist() {
    cur = head;
    while(cur != NULL){
        cout << "Nama : " << cur->nama << endl;
        cout << "Hobi : " << cur->hobi << endl;
        cout << "Usia: " << cur->usia << endl;
        cur = cur->next;
    }
}

int main()
{
    createSinglist("inu", "turu", 19);
    printSinglist();
    cout << "\n" << endl;

    addedFirst("ira", "bobo", 19);
    printSinglist();
    cout << "\n" << endl;

    addedLast("milo", "mam", 2);
    printSinglist();
    cout << "\n" << endl;

    addedMiddle("wisnu", "belajar", 19, 2);
    printSinglist();
    cout << "\n" << endl;

    deleteFirst();
    printSinglist();
    cout << "\n" << endl;

    deleteMiddle(2);
    printSinglist();
    cout << "\n" << endl;

    addedLast("nur", "a mimir", 19);
    printSinglist();
    cout << "\n" << endl;

    deleteLast();
    printSinglist();
    cout << "\n" << endl;

    addedFirst("siti", "tidur", 19);
    printSinglist();
    cout << "\n" << endl;
    
    updateFirst("moli", "mew", 7);
    printSinglist();
    cout << "\n" << endl;

    updateMiddle("yasha", "apaya", 19, 2);
    printSinglist();
    cout << "\n" << endl;

    updateLast("arifa", "anu", 19);
    printSinglist();
    cout << "\n" << endl;

}
