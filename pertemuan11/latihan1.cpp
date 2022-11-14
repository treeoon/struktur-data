#include <iostream>
#include <string>

using namespace std;

class MHS {
    public:
        string MHSname;
        void printname(){
            cout << MHSname;
        }
};

int main(){
    MHS mhs1;
    mhs1.MHSname = "Rahmat Budi";
    mhs1.printname();
}