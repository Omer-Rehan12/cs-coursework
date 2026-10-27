#include <iostream>
using namespace std;

class A {

public:

A(int a) {

cout << a << endl;
}};

class B : virtual public A {

public:

B():A(2) {
}};

class C : virtual public A {

public:

C():A(3) {}};

class D : public B ,public C {

public:

D(): A(1){
}};

int main(){

D object; // object creation of class d

return 0;}