#include<iostream>

using namespace std;

int partition(int a[], int l, int r){
    int pivot = a[r];
    int i = l - 1;
    for(int j = l; j < r; j++){
        if(a[j] <= pivot){
            ++i;
            swap(a[i], a[j]);
        }
    }
    ++i;
    swap(a[i], a[r]);
    return i;
}

void quickSort(int a[], int l, int r){
    if(l >= r) return;
    int p = partition(a, l, r);
    quickSort(a, l, p - 1);
    quickSort(a, p + 1, r);
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int &x : a) cin >> x;
    quickSort(a, 0, n-1);
    for(int x : a) cout << x << " ";
    return 0;
}