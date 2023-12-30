#include<iostream>
#include<vector>
#include<queue>

using namespace std;

using ll = long long;
int n, m, s, t; 
vector<pair<int, int>> dsKe[1001];
const int INF = 1e9;
int pre[1001];
int d[1001];

void input() {
    cin >> n >> m >> s >> t;
    for(int i = 0; i < m; i++){
        int x, y, w; 
        cin >> x >> y >> w;
        dsKe[x].push_back({y, w});
        dsKe[y].push_back({x, w});
    }
}


void dijkstra(int s, int t) {
    // khoảng cách từ s đến các đỉnh còn lại
    for(int i = 1; i <= n; i++){
        d[i] = INF;
    }
    d[s] = 0; // khoảng cách từ s đến s là 0
    pre[s] = s;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    // Q là hàng đợi ưu tiên, mỗi phần tử của Q là một cặp (khoảng cách, đỉnh)

    Q.push({0, s}); // thêm đỉnh s vào Q

    while(!Q.empty()){
        // chon đỉnh u có khoảng cách từ s đến u là nhỏ nhất
        pair<int, int> top = Q.top(); Q.pop(); 

        int u = top.second; // lấy đỉnh của top
        int kc = top.first; // lấy khoảng cách của top

        if(kc > d[u]) continue; // nếu khoảng cách của top lớn hơn khoảng cách từ s đến u thì bỏ qua

        // relaxation : cap nhat khoảng cách từ s đến các đỉnh kề với u
        for(auto it : dsKe[u]){
            int v = it.first; // lấy đỉnh kề với u
            int w = it.second; // lấy trọng số của cạnh (u, v)
            if(d[v] > d[u] + w){
                d[v] = d[u] + w; // cập nhật khoảng cách từ s đến v
                Q.push({d[v], v}); // thêm v vào Q
                pre[v] = u;
            }
        }
    }

    cout << d[t] << endl;

    vector<int> path;

    while(1){
        path.push_back(t);
        if(t == s) break;
        t = pre[t];
    }

    for(int i = path.size() - 1; i >= 0; i--){
        cout << path[i] << " ";
    }
    
}

int main() {
    input();
    dijkstra(s, t);
    return 0;
}