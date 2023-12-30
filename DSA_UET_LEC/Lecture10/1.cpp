#include<iostream>
#include<vector>

using namespace std;

int n, m;
vector<int> dsKe[1000];
bool visited[1001];

void input(){
    cin >> n >> m;
    while(m--) {
        int u, v;
        cin >> u >> v;
        dsKe[u].push_back(v);
        dsKe[v].push_back(u);
    }
}

void DFS(int u) {
    visited[u] = true;

    for(int v : dsKe[u]){
        if(!visited[v]) DFS(v);
    }
}

int connectedComponent() {
    int count = 0;
    visited[1001] = {false};    
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            count++;
            DFS(i); 
        }
    }
    return count; 
}

int main(){
    input();
    cout << connectedComponent();
    return 0;   
}