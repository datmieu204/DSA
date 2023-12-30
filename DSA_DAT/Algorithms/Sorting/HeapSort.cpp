#include<iostream>
#include<algorithm>

using namespace std;

// O(n logn)
void heapify(int a[], int n, int i){
    int largest = i; // chỉ số của số lớn nhất
    int left = 2*i + 1; // chỉ số của con trái
    int right = 2*i + 2; // chỉ số của con phải 

    if(left < n && a[left] > a[largest]) largest = left;
    if(right < n && a[right] > a[largest]) largest = right;

    if(largest != i){ 
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n){
    // bắt đầu từ nốt không phải là lá là (n/2 - 1)
    for(int i = n/2 -1; i >= 0; i--) heapify(a, n, i);

    /* phần tử a[0] là MAX_HEAP, swap với phần tử cuối 
            trong mảng và không xét phần tử cuối đó */
    for(int i = n - 1; i >= 0; i--){
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

int main(){
    int n = 6;
    int a[1000];
    for(int i = 0; i <  n; i++) cin >> a[i];
    heapSort(a, n);
    for(int i = 0; i < n; i++) cout << a[i] << " " ;
    return 0;
}