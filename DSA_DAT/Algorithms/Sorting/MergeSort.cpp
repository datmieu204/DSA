#include<iostream>
#include<vector>

using namespace std;

// O(n logn)
// Trộn 2 dãy con được sắp xếp tăng dần 
void merge(int a[], int left, int mid, int right){
    vector<int> leftarray(a+left, a+mid+1); //dãy bên trái 
    vector<int> rightarray(a+mid+1, a+right+1); //dãy bên phải
    int i=0; // chỉ số dãy trái
    int j=0; // chỉ số dãy phải 

    while(i < (int)leftarray.size() && j < (int)rightarray.size()){
        if(leftarray[i] <= rightarray[j]){
            a[left] = leftarray[i];
            ++left;
            ++i;
        }else{
            a[left] = rightarray[j];
            ++left;
            ++j;
        }
    }
    
    // in nốt phần tử của dãy bên trái (có số phần tử lớn hơn dãy bên phải)
    while(i < (int)leftarray.size()){
        a[left] = leftarray[i];
        ++left;
        ++i;
    }

    // in nốt phần tử của dãy bên phải (có số phần tử lớn hơn dãy bên trái)
    while(j < (int)rightarray.size()){
        a[left] = rightarray[j];
        ++left;
        ++j;
    }
}

void mergeSort(int a[], int left, int right){
    if(left >= right) return;
    int mid = (left + right)/2;
    mergeSort(a, left, mid); // đệ quy dãy trái
    mergeSort(a, mid+1, right); // đệ quy dãy phải 
    merge(a, left, mid, right); // trộn 2 dãy đc sắp xếp
}

int main(){
    int n, a[1000];
    cin >> n;
    for(int i = 0; i < n ; i++) cin >> a[i];

    mergeSort(a, 0, n-1);

    for(int i = 0; i < n ; i++) cout << a[i] << " " ;
    return 0;
}


// Cách trình bày khác 
/*
    void merge(int a[], int left[], int left_size, int right[], int right_size){
        int i = 0, j = 0; // index of left array anhd right array
        int k = 0; // index of array a

        // So sánh và trộn các phần tử của 2 nửa
        while(i < left_size && j < right_size){
            if(left[i] <= right[i]){
                a[k] = left[i];
                i++;
            }else{
                a[k] = right[j];
                j++;
            }
            k++;
        }

        // đưa các phần tử còn lại của hai nửa vào mảng kết quả 
        while(i < left_size){
            a[k] = left[i];
            i++;
            k++;
        }
        while(j < right_size){
            a[k] = right[j];
            j++;
            k++;
        }
    }

    void mergeSort(int a[], int size){
        if(size <= 1) return;

        int mid = size/2;
        int left[mid];
        int right[size-mid];

        // Chia mảng thành 2 nửa 
        for(int i = 0; i < mid; i++) left[i] = a[i];
        for(int i = mid; i < size; i++) right[i-mid] = a[i];

        // Đệ quy sắp xếp từng nửa 
        mergeSort(left, mid);
        mergeSort(right, size-mid);

        // Trộn 2 nửa đã sắp xếp 
        merge(a, left, mid, right, size-mid);
    }
*/

/*==================================================================================================================================================

ĐÊM SỐ CẶP NGHỊCH THẾ TRONG MẢNG = MERGE_SORT 

int merge(int a[], int l, int r, int m){
    vector<int> x(a+l, a+m+1);
    vector<int> y(a+m+1, a+r+1);

    int i = 0, j = 0;
    int cnt = 0;

    while( i < x.size() && j < y.size()){
        if(x[i] <= y[j]){
            a[l] = x[i];
            ++l;
            ++i;
        }else{
            cnt += x.size() - i; //Tong so cap nghich the 
            a[l] = y[j];
            ++l;
            ++j; 
        }
    }

    while( i < x.size()){
        a[l] = x[i];
        ++l;
        ++i;
    }

    while( j < y.size()){
        a[l] = y[j];
        ++l;
        ++j;
    }

    return cnt;
}

int mergeSort(int a[], int l, int r){
    int cnt = 0;
    if(l < r){
        int m = (r+l)/2;
        cnt += mergeSort(a, l, m); // tong cap nghich the trai
        cnt += mergeSort(a, m+1, r); // tong cap nghich the phai
        cnt += merge(a, l, r, m); // tong cap nghich the 1 phan tu trai va 1 phan tu phai0
    }
    return cnt;
}

int main(){
    int n = 6;
    int a[1000];
    for(int i = 0 ; i < n ; i++) cin >> a[i];

    int u = mergeSort(a, 0, n-1);
    cout << u << endl;
}

*/