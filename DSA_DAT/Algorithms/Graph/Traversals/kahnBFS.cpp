// thuật toán xóa dần đỉnh, có hướng không có chu trình
/*
Chọn đỉnh có bậc vào bằng 0, đưa vào hàng đợi
-> Xóa đỉnh đó khỏi đồ thị
-> Cập nhật lại bậc vào của các đỉnh còn lại
-> Lặp lại cho đến khi không còn đỉnh nào trong đồ thị
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<int> dsKe[1001];
int inDegree[1001];
vector<int> topo;

void input(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        dsKe[x].push_back(y);
        inDegree[y]++; // cập nhật bậc vào
    }
}

void kahn(){
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(inDegree[i] == 0) q.push(i);
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for(int v : dsKe[u]){
            inDegree[v]--;
            if(inDegree[v] == 0) q.push(v);
        }
    }

    for(int x : topo){
        cout << x << " ";
    }
}

int main(){
    input();
    kahn();
    return 0;
}