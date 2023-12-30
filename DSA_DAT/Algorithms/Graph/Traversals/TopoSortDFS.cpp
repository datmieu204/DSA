// đồ thị có hướng không có chu trình
/*
duyệt DFS từ đỉnh u nào đó -> đỉnh cuối cùng được duyệt là đỉnh kết thúc
-> đưa vào stack
-> lặp lại cho đến khi không còn đỉnh nào chưa duyệt
*/

#include <iostream>
#include <vector>

using namespace std;

int n, m;
bool visited[1001];
vector<int> dsKe[1001];
vector<int> topo;

void input(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        dsKe[x].push_back(y);
    }
    visited[1001] = {false};
}

void DFS(int u){
    visited[u] = true;
    for(int x : dsKe[u]){
        if(!visited[x]) DFS(x);
    }
    topo.push_back(u); // thêm vào topo
}

int main(){
    input();

    for(int i = 1; i <= n; i++){
        if(!visited[i]) DFS(i);
    }

    for(int i = topo.size() - 1; i >= 0; i--){
        cout << topo[i] << " ";
    }

    return 0;
}