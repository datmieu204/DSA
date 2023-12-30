#include<iostream>
#include<map>

using namespace std;

int kaDaneSolve(int X, multimap<int, int, greater<int>> m){
    int res[X+1] = {0};

    for(auto it = m.begin(); it != m.end(); it++){
        for(int i = X; i >= it->first; i--){
            res[i] = max(res[i], res[i - it->first] + it->second);
        }
    }

    return res[X];
}

int main(){
    int n; cin >> n;
    int X; cin >> X;
    int w, v;

    multimap<int, int, greater<int>> m;

    while(n--){
        cin >> w >> v;
        m.insert({w, v});
    }

    cout << kaDaneSolve(X, m) << endl;


    return 0;
}