#include <stdlib.h>
#include <iostream>
using namespace std;

struct data {
    string nama, email, jurusan;
    data *prev;
    data *next;
}; data *head, *tail, *cur, *newNode, *del, *nextNode;

void createdll(string x[3]) {
    head = new data();
    head->nama = x[0];
    head->email = x[1];
    head->jurusan = x[2];
    head->prev = NULL;
    head->next = NULL;
    tail = head;
}

void printdll() {
    if(head == NULL){
        cout << "please create a dll first";
    } else {
        cur = head;
        while(cur!=NULL){
            cout << "\n" << "Nama : " << cur->nama << endl;
            cout << "Email : " << cur->email << endl;
            cout << "Jurusan : " << cur->jurusan << "\n" << endl;
            cur = cur->next;
        }
    }
}

void addfirst(string x[3]) {
    newNode = new data();
    newNode->nama = x[0];
    newNode->email = x[1];
    newNode->jurusan = x[2];
    newNode->prev = NULL;
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void addlast(string x[3]) {
    newNode = new data();
    newNode->nama = x[0];
    newNode->email = x[1];
    newNode->jurusan = x[2];
    newNode->prev = tail;
    newNode->next = NULL;
    tail->next = newNode;
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
    newNode->prev = cur;
    newNode->next = nextNode;
    cur->next = newNode;
    nextNode->prev = newNode;
}

void removeFirst()
{
  if( head == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{
    del = head;
    head = head->next;
    head->prev = NULL;
    delete del;
  }
}

void removeLast()
{
  if( head == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{
    del = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete del;
  }
}

void removeMiddle(int posisi){
  if( head == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{
      int nomor = 1;
      cur = head;
      while( nomor < posisi - 1 ){
        cur = cur->next;
        nomor++;
      }
      del = cur->next;
      nextNode = del->next;
      cur->next = nextNode;
      nextNode->prev = cur;
      delete del;
  }
}

int main(){

    string input[3];
    for(int i=0; i <=2; i++) {
        cin >> input[i];
    }
    createdll(input);
    printdll();

    string inputfirst[3];
    for(int i=0; i <=2; i++) {
        cin >> inputfirst[i];
    }
    addfirst(inputfirst);
    printdll();

    string inputlast[3];
    for(int i=0; i <=2; i++) {
        cin >> inputlast[i];
    }
    addlast(inputlast);
    printdll();

    string inputmid[3];
    for(int i=0; i <=2; i++) {
        cin >> inputmid[i];
    }
    addmiddle(inputmid, 1);
    printdll();

}
