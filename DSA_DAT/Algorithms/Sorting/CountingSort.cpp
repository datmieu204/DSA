#include<iostream>

using namespace std;

// O(n+max)
int cnt[10000001];

int main(){
    int n, a[1000], MAX = INT_MIN;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        cnt[a[i]]++;
        MAX = max(MAX, a[i]);
    }

    for(int i = 0; i <= MAX; i++){
        if(cnt[i] != 0)
            for(int j = 0; j < cnt[i]; j++)
                cout << i << " ";
    }

    return 0;
}