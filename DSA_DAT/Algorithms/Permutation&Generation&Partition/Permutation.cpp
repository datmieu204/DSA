/*
    VD: n = 9
    số 123498765
    xét a[i] < a[i + 1] -> i = 4 -> tìm số > 4 nhỏ nhất
    -> swap(4, 5) -> 123548764
    nhưng để có cấu hình nhỏ nhất thì -> 123546789
*/

#include<iostream>  

using namespace std;

int n, a[1000000], ok;

void init(){
    for(int i=1; i<=n; i++) a[i] = i;
}

void permutation(){
    int i = n - 1;
    // đi tìm a[i] < a[i + 1] trong đoạn [i+1, n]
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
        } // reverse from i + 1 to n : reverse(a + i + 1, a + n + 1);
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

/* C2: ------------------------------------------------------------------------

#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
       a[i] = i + 1;
    }

    do{
        for(int i = 0; i < n; i++){
            cout << a[i];
        }
        cout << endl;
    }while(next_permutation(a, a + n));
    return 0;
}


Hàm hoán vị phía trước của một hoán vị: 
    a[i] = n - i;
    prev_permutation(a, a + n);
Với vector: next_permutation(a.begin(), a.end());
            prev_permutation(a.begin(), a.end());

*/

