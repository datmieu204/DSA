#include <iostream> 

using namespace std;

void merge(int A[], int left[], int left_size, int right[], int right_size){
        int i = 0, j = 0; 
        int k = 0;

        while(i < left_size && j < right_size){
            if(left[i] <= right[i]){
                A[k] = left[i];
                i++;
            }else{
                A[k] = right[j];
                j++;
            }
            k++;
        }

        while(i < left_size){
            A[k] = left[i];
            i++;
            k++;
        }
        while(j < right_size){
            A[k] = right[j];
            j++;
            k++;
        }
    }

    void mergeSort(int A[], int n){
        if(n <= 1) return;

        int mid = n/2;
        int left[mid];
        int right[n-mid];

        for(int i = 0; i < mid; i++) left[i] = A[i];
        for(int i = mid; i < n; i++) right[i-mid] = A[i];

        mergeSort(left, mid);
        mergeSort(right, n-mid);
        merge(A, left, mid, right, n-mid);
    }

    int main(){
        int a[] = {5, 4, 3, 2, 1};
        int size = sizeof(a)/sizeof(a[0]);

        mergeSort(a, size);

        for(int i = 0; i < size; i++) cout << a[i] << " ";
        cout << endl;
    }