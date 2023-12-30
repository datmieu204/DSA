#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n; cin >> n;

    int a[100000];
    int cnt[100000]; //mang luu do dai day con tang dai nhat

    for (int i = 0; i < n; i++) cin >> a[i];
    
    cnt[0] = 1;

    for (int i = 1; i < n; i++)
    {
        int cntMax = 0; // luu gia tri max cua cnt = 0;

        // duyet tu 0 den i-1
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i])
                if (cnt[j] > cntMax)  
                    cntMax = cnt[j];
        }
        cnt[i] = cntMax + 1;
    }

    int lengMax = 0; // do dai day con tang dai nhat

    for (int i = 0; i < n; i++)
        if (cnt[i] > lengMax)
            lengMax = cnt[i];
        
    int b[lengMax];
    int index = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        if (cnt[i] == lengMax)
        {
            b[index] = a[i];
            lengMax--;
            index++;
        }
    }

    for (int i = index - 1; i >= 0; i--)
        cout << b[i] << " ";
    
    return 0;
}