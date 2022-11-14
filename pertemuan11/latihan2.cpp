#include <iostream>
#include <string>
using namespace std;

class MHS {
    protected:
        string MHSname;

    public:
        MHS(string mhs) {
            MHSname = mhs;
        }

        void printname(){
            cout << MHSname << endl;
        }
        string getName(){
            return MHSname;
        }
};

int main(){
    MHS mhs2("Muhammad Ali");
    mhs2.printname();
    cout << mhs2.getName();
}
