#include <iostream>
#include <string>
#include <array>

using namespace std;

struct datavaloit{
    int nrp;
    string nama;
    float tglahir[10];
    string rankvalo;
};

int main(){
    struct datavaloit valo[20];
    for(int i=0; i<20; i++) {
        cin>>valo[i].nrp >> valo[i].nama;
        for(int j=0;j<3;j++){
            cin>>valo[i].tglahir[j];
        }
        cin>>valo[i].rankvalo;
    }
    for(int i=0;i<20;i++){
        cout<<"====Data Ke-"<<i+1<<"===="<<endl;
        cout<<"NRP AKHIR : "<<valo[i].nrp<<endl;
        cout<<"NAMA PANGGILAN: "<<valo[i].nama<<endl;
        cout<<"TANGGAL LAHIR: ";
        for(int j=0;j<3;j++){
            cout<<valo[i].tglahir[j];
             if(j < 2){
                cout<<"-";
            }
        }
        cout<<endl;
        cout<<"RANK VALORANT: "<<valo[i].rankvalo<<endl;
    }

}