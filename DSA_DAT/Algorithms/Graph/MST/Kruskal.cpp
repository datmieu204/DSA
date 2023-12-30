#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct edge {
    int u, v, w;
};

int n, m; // n: số đỉnh, m: số cạnh
int parent[1001];
int Size[1001];
vector<edge> canh;

//==============================================================================================
// Disjoint Set - Union-Find
void makeSet() {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        Size[i] = 1;
    }
}

int find(int v) {
    if(v == parent[v]) return v;
    return parent[v] = find(parent[v]);
}

bool Union(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return false; // a và b đã ở chung 1 tập hợp
    if(Size[a] < Size[b]) swap(a, b);
    parent[b] = a;
    Size[a] += Size[b];
    return true;
}
//==============================================================================================

void input() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        canh.push_back({u, v, w});
    }
}

bool cmp(edge a, edge b) {
    return a.w < b.w;
}

void krusal() {
    vector<edge> mst; // cay khung nho nhat
    int d = 0; // tong trong so cua cay khung nho nhat

    // sap xep danh sach canh tang dan theo trong so
    sort(canh.begin(), canh.end(), cmp);

    // lap
    for( int i = 0; i < m; i++) {
        if((int)mst.size() == n - 1) break;

        edge e = canh[i]; // lay canh co trong so nho nhat

        if(Union(e.u, e.v)) {
            mst.push_back(e);
            d += e.w;
        }
    }

    if((int)mst.size() == n - 1) {
        cout << d << endl;
        for(edge e : mst) {
            cout << e.u << " " << e.v << " " << e.w <<  endl;
        }
    } else {
        cout << "Khong ton tai cay khung nho nhat" << endl;
    }
}

int main() {
    input();
    makeSet();
    krusal();
    return 0;
}