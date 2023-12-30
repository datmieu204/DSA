#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>

using namespace std;

struct edge {
    int u, v, w;
};

int n, m; 
int parent[1001];
int Size[1001];
vector<edge> canh;

ifstream file("D://Meow//DSA_UET_LEC//Lecture12//connection.txt");
ofstream file_out("D://Meow//DSA_UET_LEC//Lecture12//connection.out");

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
    if(a == b) return false; 
    if(Size[a] < Size[b]) swap(a, b);
    parent[b] = a;
    Size[a] += Size[b];
    return true;
}

void input() {
    if(file.is_open()) {
        file >> n >> m;
        for (int i = 1; i <= m; i++) {
            int u, v, w; file >> u >> v >> w;
            canh.push_back({u, v, w});
        }
    }
}

bool cmp(edge a, edge b) {
    return a.w < b.w;
}

void krusal() {
    vector<edge> mst; 
    int d = 0; 

    sort(canh.begin(), canh.end(), cmp);


    for( int i = 0; i < m; i++) {
        if((int)mst.size() == n - 1) break;

        edge e = canh[i]; 

        if(Union(e.u, e.v)) {
            mst.push_back(e);
            d += e.w;
        }
    }

    if((int)mst.size() == n - 1) {
        file_out << d << endl;
        for(edge e : mst) {
            file_out << e.u << " " << e.v << " " << e.w <<  endl;
        }
    } else {
        file_out << "Khong ton tai cay khung nho nhat" << endl;
    }
}

int main() {
    input();
    makeSet();
    krusal();
    return 0;
}