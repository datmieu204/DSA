// Tìm đường đi ngắn nhất có trọng số âm, chu trình âm
/*
Thuật toán Bellman-Ford dùng để giải quyết bài toán đường đi 
ngắn nhất từ một đỉnh đến tất cả các đỉnh còn lại, đồ thị có thể có trọng số âm.
*/

#include<iostream>
#include<vector>

using namespace std;

struct edge {
    int u, v, w;
};

int n, m;
vector<edge> dsCanh;
int d[1001];

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w; 
        cin >> u >> v >> w;
        dsCanh.push_back({u, v, w});
    }
}

void bellmanFord(int s) {
    for (int i = 1; i <= n; i++) {
        d[i] = 1e9;
    }
    d[s] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (edge e : dsCanh) {
            int u = e.u;
            int v = e.v;
            int w = e.w;

            if (d[u] < 1e9) { // canh (u, v) co trong so am
                d[v] = min(d[v], d[u] + w);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << d[i] << " ";
    }
}

int main() {
    input();
    bellmanFord(1);
    return 0;
}