#include <iostream>

using namespace std;

int n, k, a[1000000], ok;

/*
    - khởi tạo 1 mảng a[] gồm n phần tử có giá trị 0
    - cấu hình đầu tiên là 0
    - cấu hình cuối cùng là điều kiện dừng
    while(<chưa là cấu hình cuối cùng>){
        - in ra cấu hình hiện tại
        - sinh cấu hình tiếp theo
    }
*/
void init()
{
    for (int i = 1; i <= n; i++)
        a[i] = 0;
}

void solve()
{
    // bắt đầu từ bit cuối cùng đi tìm bit 0 đầu tiên
    int i = n;
    while (i > 0 && a[i] == 1)
    {
        a[i] = 0;
        i--;
    }
    // ĐK dừng
    if (i == 0)
        ok = 0;
    else
        a[i] = 1;
}

bool checkBit1()
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        cnt += a[i];
    }
    return cnt == k;
}

int main()
{
    cin >> n >> k;
    ok = 1;
    init();
    while (ok)
    {
        if (checkBit1())
        {
            for (int i = 1; i <= n; i++)
            {
                cout << a[i];
            }
            cout << endl;
        }
        solve();
    }
}