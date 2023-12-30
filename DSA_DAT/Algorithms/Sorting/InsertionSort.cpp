#include<iostream>

using namespace std;

// O(n^2)
void InsertionSort(int a[], int n){
    for(int i=1; i<n; i++){
        int tmp = a[i];
        int j = i-1;
        while(j>=0 && tmp < a[j]){
            a[j+1] = a[j];
            --j;
        }
        a[j+1] = tmp;
    }
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    InsertionSort(a,n);
    for(int i = 0; i < n; i++) cout << a[i] << " ";
}