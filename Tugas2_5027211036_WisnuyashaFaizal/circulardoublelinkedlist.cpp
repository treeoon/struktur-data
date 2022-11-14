#include <stdlib.h>
#include <iostream>
using namespace std;

struct data {
    string nama, email, jurusan;
    data *prev;
    data *next;
}; data *head, *tail, *cur, *newNode, *del, *nextNode;

void createcdll(string x[3]) {
    head = new data();
    head->nama = x[0];
    head->email = x[1];
    head->jurusan = x[2];
    head->prev = head;
    head->next = head;
    tail = head;
}

void printcsll() {
    if(head == NULL){
        cout << "please create a csll first";
    } else {
        cur = head;
        while(cur->next != head){
            cout << "\n" << "Nama : " << cur->nama << endl;
            cout << "Email : " << cur->email << endl;
            cout << "Jurusan : " << cur->jurusan << "\n" << endl;
            cur = cur->next;
        }
        cout << "\n" << "Nama : " << cur->nama << endl;
        cout << "Email : " << cur->email << endl;
        cout << "Jurusan : " << cur->jurusan << "\n" << endl;
    }
}

void addfirst(string x[3]) {
    newNode = new data();
    newNode->nama = x[0];
    newNode->email = x[1];
    newNode->jurusan = x[2];
    newNode->next = head;
    newNode->prev = tail;
    tail->next = newNode;
    head->prev = newNode;
    head = newNode;
}

void addlast(string x[3]) {
    newNode = new data();
    newNode->nama = x[0];
    newNode->email = x[1];
    newNode->jurusan = x[2];
    newNode->next = head;
    newNode->prev = tail;
    tail->next = newNode;
    head->prev = newNode;
    tail = newNode;
}

void addmiddle(string x[3], int on) {
    newNode = new data();
    newNode->nama = x[0];
    newNode->email = x[1];
    newNode->jurusan = x[2];
    cur = head;
    while(int i=1 < on-1) {
        cur = cur->next;
        i++; 
    }
    nextNode = cur->next;
    cur->next = newNode;
    nextNode->prev = newNode;
    newNode->prev = cur;
    newNode->next = nextNode;
}

int main(){

    // string input[3] = {"inu", "ganteng@gmail.com", "it"};
    string input[3];
    for(int i=0; i <=2; i++) {
        cin >> input[i];
    }
    createcdll(input);
    printcsll();

    // string inputfirst[3] = {"ira", "jelek@gmail.com", "ie"};
    string inputfirst[3];
    for(int i=0; i <=2; i++) {
        cin >> inputfirst[i];
    }
    addfirst(inputfirst);
    printcsll();

    // string inputlast[3] = {"milo", "smol@gmail.com", "tc"};
    string inputlast[3];
    for(int i=0; i <=2; i++) {
        cin >> inputlast[i];
    }
    addlast(inputlast);
    printcsll();

    // string inputmiddle[3] = {"moli", "chonk@gmail.com", "te"};
    string inputmiddle[3];
    for(int i=0; i <=2; i++) {
        cin >> inputmiddle[i];
    }
    addmiddle(inputmiddle, 1);
    printcsll();
}