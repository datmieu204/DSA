/*
    Vd: n = 5, k = 3
    1 2 3   
    1 2 4
    1 2 5
    1 3 4
    1 3 5
    1 4 5
    2 3 4
    2 3 5
    2 4 5
    3 4 5
    - cấu hình đầu tiên là 1 2 3, cuối là 3 4 5
    - giá trị khởi tạo là 1 2 3, ta xét bit cuối i = 3, 
    giá trị max của bit cuối sẽ là  = 5
    - mà bit cuối đang là 3 < 5 -> cần tăng bit cuối lên 4
    -> cấu hình tiếp theo sẽ là 1 2 4 -> tăng lên 5
    -> cấu hình tiếp theo sẽ là 1 2 5 -> bit cuối đã đạt giá trị max
    -> dịch bit sang trái, giá trị max bit 2 đạt đc là (n - k + i) = 5 - 3 + 2 = 4
    ...

    - Tổng quát: 1 2 3 ... k
    - giá trị khởi tạo là 1 2 3 ... k
    - cấu hình cuối cùng là (n - k + 1) (n - k + 2) ... n
    - giá trị thứ i sẽ chạy từ 1 -> n - k + i
*/

#include<iostream>

using namespace std;

int n, k, a[1000000], ok;

void init()
{
    for (int i = 1; i <= k; i++)  a[i] = i;
}

void solve(){
    int i = k;
    // Khi bit ở vị trí i đạt max thì dịch bit sang trái
    while(i > 0 && a[i] == n - k + i){
        i--;
    }

    if(i == 0) ok = 0; // cấu hình cuối cùng
    else{ // khi bit i chưa đạt giá trị max
        a[i]++;
        // duyệt từ bit i + 1 -> k
        for(int j = i + 1; j <= k; j++){
            a[j] = a[j - 1] + 1;
        }
    }
}

int main(){
    cin >> n >> k;
    ok = 1;
    init();
    while(ok){
        for(int i=1; i <= k; i++){
            cout << a[i];
        }
        cout << endl;
        solve();
    }
    return 0;
}