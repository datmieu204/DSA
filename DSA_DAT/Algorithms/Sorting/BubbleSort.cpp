#include<iostream>

using namespace std;

// O(n^2) O(n)
// Cho n so, lap di lap lai (n-1) lan cac buoc sau:
// voi moi so ke nhau neu so ben trai > ben phai
// => swap
void BubbleSort(int a[], int n){
    for(int i = 0; i < n-1; i++)
        for(int j = 0; j < n-i-1; j++)
            if(a[j] > a[j+1]){
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    BubbleSort(a,n);
    for(int i = 0; i < n; i++) cout << a[i] << " ";
}