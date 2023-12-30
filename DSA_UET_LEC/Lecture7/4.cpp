#include<iostream>

using namespace std;

int n, a[1000000], res;

void init(){
    for(int i=1; i <= n; i++) a[i] = 0;
}

void solve(){
    int i = n;
    while(i > 0 && a[i] == 1){
        a[i] = 0;
        i--;
    }
    if(i == 0) res = 0;
    else a[i] = 1;
  
}

int main(){
    cin >> n;
    res = 1;
    init();
    while(res){
        for(int i=1; i <= n; i++){
            cout << a[i];
        }
        cout << endl;
        solve();
    }
}