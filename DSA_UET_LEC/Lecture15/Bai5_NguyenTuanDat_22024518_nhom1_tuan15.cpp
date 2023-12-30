#include <iostream>

using namespace std;

int n, k, a[1000000], ok;

void init()
{
    for (int i = 1; i <= n; i++)
        a[i] = 0;
}

void solve()
{
    int i = n;
    while (i > 0 && a[i] == 1)
    {
        a[i] = 0;
        i--;
    }

    if (i == 0)
        ok = 0;
    else
        a[i] = 1;
}

bool checkBit1()
{
    int cnt = 0;
    int cntBit0 = 0;
    for (int i = 1; i <= n; i++)
    {
        cnt += a[i];
        if (a[i] == 0)
            cntBit0++;
    }
    return cnt <= cntBit0;
}


int main()
{
    cin >> n;
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