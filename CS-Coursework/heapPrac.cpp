#include <iostream>
using namespace std;

void insert(int A[], int n){
    int i = n;
    int temp;
    while(i > 1 && A[i] < A[i/2]){
        temp = A[i];
        A[i] = A[i/2];
        A[i/2] = temp;
        i = i/2;
    }
}

void heapify(int A[], int n, int m){
	int i, j;
    i=n;
    j=i*2;
    int temp1;
    
    while(j+1<=m){
    	if(A[j+1]>A[j]){
    		j=j+1;
		}
		
		if(A[i]<A[j]){
		   temp1=A[j];
		   A[j]=A[i];
		   A[i]=temp1;
		   i=j;
		   j=j*2;
		}
		
		else break;
	}

}

int main(){
    int A[] = {0, 10, 20, 30, 56, 60, 67, 45, 33, 21};
    
    for(int i =9/2; i>=1; i--){
        heapify(A, i, 9);
    }

    for(int i = 1; i <= 9; i++){
        cout << A[i] << " ";
    }

    return 0;
}
