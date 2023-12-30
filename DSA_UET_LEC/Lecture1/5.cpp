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
    int a[5];
    for(int i=0; i<5; i++) cin >> a[i];
    BubbleSort(a, 5);
    int sum = 0;
    sum = a[0] + a[4];
    cout << sum << endl;
}