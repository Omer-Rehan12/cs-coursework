#include <iostream>
using namespace std;

void insert(int A[], int n){
    int i = n;
    while(i > 1 && A[i] > A[i/2]){
        int temp = A[i];
        A[i] = A[i/2];
        A[i/2] = temp;
        i = i/2;
    }
}

int main(){
    int A[6] = {0, 10, 20, 30, 56, 60};

    for(int i = 1; i <= 5; i++){
        insert(A, i);
    }

    for(int i = 1; i <= 5; i++){
        cout << A[i] << " ";
    }
}
