#include<iostream>
using namespace std;

void BubbleSort(int a[], int n){
    for(int i=0; i< n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(a[j] > a[j+1]){
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] =tmp;
            }
        }
    }
}

int main(){
    int n; cin >> n;
    int arr[100];
    for(int i=0; i<n; i++) cin >> arr[i];
    BubbleSort(arr, n);
    for(int i=0; i<n; i++) cout << arr[i] << " ";
    return 0;
}