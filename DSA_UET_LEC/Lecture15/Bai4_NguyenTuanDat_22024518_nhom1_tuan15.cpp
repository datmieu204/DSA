#include<iostream>  

using namespace std;

int n, a[1000000], ok;

void init(){
    for(int i=1; i<=n; i++) a[i] = i;
}

void permutation(){
    int i = n - 1;
  
    while(i > 0 && a[i] > a[i + 1]) i--;

    if(i == 0) ok = 0; // stop
    else{
        int j = n;
        while(a[i] > a[j]) --j;
        swap(a[i], a[j]);
        int l = i + 1, r = n;

        while(l <= r){
            swap(a[l], a[r]);
            ++l; --r;
        } 
    }
}

int main(){
    cin >> n;
    ok = 1;
    init();
    while(ok){
        for(int i=1; i<=n; i++) cout << a[i];
        cout << endl;
        permutation();
    }
    return 0;
}