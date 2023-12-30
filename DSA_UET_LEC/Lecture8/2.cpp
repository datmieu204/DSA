#include <iostream>

using namespace std;

bool check(int a[], int n, int X)
{
    if (X == 0)
        return true;
    if (n == 0 || X < 0)
        return false;
    return check(a, n - 1, X - a[n - 1]) || check(a, n - 1, X);
}

int main()
{
    int n, X;
    cin >> n >> X;
    int a[n];
    for (int &x : a)
        cin >> x;
    if (check(a, n, X))
        cout << "YES";
    else
        cout << "NO";
}