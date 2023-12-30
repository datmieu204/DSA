#include<iostream>
#include<vector>
#include<queue>

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
    cout << u << " ";
    for(int v : dsKe[u]){
        if(!visited[v]) DFS(v);
    }
}

void BFS(int u) {
    queue<int> q;
    q.push(u);
    visited[u] = true;

    while(!q.empty()){
        int s = q.front(); q.pop();
        cout << s << " ";
        for(int t : dsKe[s]){
            if(!visited[t]){
                q.push(t);
                visited[t] = true;
            }
        }
    }
}


int connectedComponent() {
    int count = 0;
    visited[1001] = {false};    
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            count++;
            cout << "cac dinh thuoc thanh phan lien thong thu " << count << " la: ";
            DFS(i);
        }
    }

    //if(count == 1) return 1;  //ếu = 1 thì đồ thị liên thông
    return count; // kiểm tra số thành phần liên thông
}

int main(){
    input();
    cout << connectedComponent();
    return 0;   
}