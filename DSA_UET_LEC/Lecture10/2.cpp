#include<iostream>
#include<vector>
#include<queue>

using namespace std;

using ll = long long;
int n, m, s, t; 
vector<pair<int, int>> dsKe[1001];

void input() {
    cin >> n >> m >> s >> t;
    for(int i = 0; i < m; i++){
        int x, y, w = 1; 
        cin >> x >> y ;
        dsKe[x].push_back({y, w});
        dsKe[y].push_back({x, w});
    }
}

const int INF = 1e9;
int pre[1001];

void dijkstra(int s, int t) {
    vector<ll> d(n + 1, INF); 
    d[s] = 0;
    pre[s] = s;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
   

    Q.push({0, s});

    while(!Q.empty()){
        pair<int, int> top = Q.top(); Q.pop(); 

        int u = top.second; 
        int kc = top.first; 

        if(kc > d[u]) continue;

        for(auto it : dsKe[u]){
            int v = it.first; 
            int w = it.second; 
            if(d[v] > d[u] + w){
                d[v] = d[u] + w; 
                Q.push({d[v], v});
                pre[v] = u;
            }
        }
    }

    cout << d[t] << endl;
}

int main() {
    input();
    dijkstra(s, t);
    return 0;
}