#include<bits/stdc++.h>

using namespace std;

/*  O(nlogn) 
    O(n^2)
    PHÂN HOẠCH LOMUTO

int partition(int a[], int l, int r){
    int pivot = a[r]; //Chốt 
    int i = l-1;

    for(int j=l; j<r; j++){
        if(a[j] <= pivot){
            ++i;
            swap(a[j], a[i]);
        }
    }
    ++i;
    swap(a[i], a[r]);
    
    return i; //vị trí chốt 
}

void quickSort(int a[], int l, int r){
    if(l >= r) return; //điều kiện dừng khi chỉ còn 1 phần tử 
    int p = partition(a, l, r);
    quickSort(a, l, p-1);
    quickSort(a, p+1, r);
}

-----------------------------------------------------------------------------------------------------------------------------------------------------
PHÂN HOẠCH HOARE*/

int partition(int a[], int l, int r){
    int pivot = a[l];
    int i = l-1;
    int j = r+1;

    while(true){
        do{
            ++i;
        }while(a[i] < pivot);
        do{
            --j;
        }while(a[j] > pivot);

        if(i<j) swap(a[i], a[j]); //swap 2 cặp nghịch thế 
        else return j;
    }
}

void quickSort(int a[], int l, int r){
    if(l >= r) return;
    int p = partition(a, l ,r);
    quickSort(a, l, p);
    quickSort(a, p+1, r);
}

int main(){
    int n; cin >> n;
    int a[1000];
    for(int i=0; i<n; i++) cin >> a[i];
    quickSort(a, 0, n-1);
    for(int i=0; i<n; i++) cout << a[i] << " ";
    return 0;
}