#include<iostream>

using namespace std;

// O(n^2)
// Cho n so, lap di lap lai (n-1) buoc sau:
// Danh dau gia tri dau tien chua duoc sap xep
// Tim gia tri nho nhat trong cac so chua duoc sap xep
// => Hoan doi gia tri danh dau voi gia tri nho nhat tim dc
void SelectionSort(int a[], int n){
    for(int i = 0; i < n-1; i++){
        int min = i; //min_pos array
        //compare begin i+1 to end with min
        for(int j = i+1; j < n; j++){
            if(a[j] < a[min]) min = j;
        }
        //swap min and a[i]
        int tmp = a[i];
        a[i] = a[min];
        a[min] = tmp;
    }
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    SelectionSort(a,n);
    for(int i = 0; i < n; i++) cout << a[i] << " ";
}