#include <iostream>
#include <fstream>
using namespace std;

class Test {
    int ID;
    string name;
    static int genID;

public:
    Test(string n) {
        ID = ++genID;
        name=n;

        
    }

    // Overload + operator to write data to file
    void operator+(const char* filename) {
        ofstream fout(filename, ios::app);
        if (fout.is_open()) {
            fout << "ID = " << ID << ", Name = " << name << endl;
            fout.close();
        }
    }
};

int Test::genID = 0;

int main() {
    Test t1("0001"), t2("0002");
    

    
    t1 + "outfile.txt";
    t2 + "outfile.txt";
    return 0;
}
