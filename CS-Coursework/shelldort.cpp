#include <iostream>
using namespace std;

#include<iostream>

void countsort(int arr[],int n,int exp){
    int count[10]{0};
    int *temparr=new int[n];
    for(int i=0;i<n;i++){
        int val=(arr[i]/exp)%10;
        count[val]++;
    }
    for(int i=1;i<10;i++){
        count[i]+=count[i-1];
    }
    for(int i=n;i>=0;i--){
        int digit=(arr[i]/exp)%10;
        temparr[count[digit]-1]=arr[i];
        count[digit]--;
    }
    for(int i=0;i<n;i++){
        arr[i]=temparr[i];
    }
}
void radixsort(int arr[],int n){
    int maxval=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>maxval)maxval=arr[i];
    }
    for(int exp=1;maxval/exp>0;exp*=10){
        countsort(arr,n,exp);
    }
}
int main() {
    int arr[]{6, 5, 4, 3, 2, 1};
    int n = 6;
    
    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    radixsort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl; // Output: 1 2 3 4 5 6 
    
    return 0;
}