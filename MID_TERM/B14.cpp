/*
    Viết chương trình cài đặt thuật toán Sắp xếp chèn để sắp xếp một mảng số nguyên nhập từ bàn phím.
    Không sắp xếp phần tử đầu và cuối dãy.

    Input:
    Đầu vào gồm 2 dòng
    Dòng đầu tiên chứa một số nguyên n. Dòng tiếp theo chứa n số nguyên.

    Output:
    Một dòng duy nhất chứa n số nguyên đã sắp xếp theo thứ tự tăng dần như trên.
    Yêu cầu: Sinh viên PHẢI cài đặt hàm void insertionSort(int* a, int n) và gọi hàm đó trong chương trình chính.

    For example:
    Input Result
    5
    1 4 2 5 3
    1 2 4 5 3
    6
    -1 -5 -2 7 0 6
    -1 -5 -2 0 7 6
*/

#include <iostream>

using namespace std;

void insertionSort(int *a, int n)
{

    for (int i = 2; i < n - 1; i++)
    {
        int tmp = a[i];
        int j = i - 1;
        while (j >= 0 && tmp < a[j])
        {
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = tmp;
    }
}

int main()
{
    int n;
    cin >> n;

    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    insertionSort(a, n);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
