#include<iostream>

using namespace std;

int n, a[1000000], res;

/*
    - khởi tạo 1 mảng a[] gồm n phần tử có giá trị 0
    - cấu hình đầu tiên là 0
    - cấu hình cuối cùng là điều kiện dừng
    while(<chưa là cấu hình cuối cùng>){
        - in ra cấu hình hiện tại
        - sinh cấu hình tiếp theo
    }
*/
void init(){
    for(int i=1; i <= n; i++) a[i] = 0;
}

void solve(){
    // bắt đầu từ bit cuối cùng đi tìm bit 0 đầu tiên
    int i = n;
    while(i > 0 && a[i] == 1){
        a[i] = 0;
        i--;
    }
    // ĐK dừng
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