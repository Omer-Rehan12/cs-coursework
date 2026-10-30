#include <iostream>

using namespace std;

class YourClass {

friend class YourOtherClass; // Declare a friend class

public:

YourClass() : topSecret(0){}

void printMember() { cout << topSecret << endl; }

private:

int topSecret;};

class YourOtherClass {

public:

void change( YourClass& yc, int x ){

yc.topSecret = x;}};

int main() {

YourClass c1;

YourOtherClass oc1;

c1.printMember();

oc1.change(c1, 5 );

c1.printMember();}