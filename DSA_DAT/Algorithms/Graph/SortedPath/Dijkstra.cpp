/* Trọng số dương

thuật toán Dijkstra cũng tối ưu hóa đường đi bằng cách xét các cạnh (u,v)
, so sánh hai đường đi S→v
 sẵn có với đường đi S→u→v
.

Thuật toán hoạt động bằng cách duy trì một tập hợp các đỉnh trong đó ta đã biết chắc chắn đường đi ngắn nhất. Mỗi bước, thuật toán sẽ chọn ra một đỉnh u
 mà chắc chắn sẽ không thể tối ưu hơn nữa, sau đó tiến hành tối ưu các đỉnh v
 khác dựa trên các cạnh (u,v)
 đi ra từ đỉnh u
. Sau N
 bước, tất cả các đỉnh đều sẽ được chọn, và mọi đường đi tìm được sẽ là ngắn nhất.

Cụ thể hơn, thuật toán sẽ duy trì đường đi ngắn nhất đến tất cả các đỉnh. Ở mỗi bước, chọn đường đi S→u
 có tổng trọng số nhỏ nhất trong tất cả các đường đi đang được duy trì. Sau đó tiến hành tối ưu các đường đi S→v
 bằng cách thử kéo dài thành S→u→v
 như đã mô tả trên.
*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

using ll = long long;
int n, m, s; 
vector<pair<int, int>> dsKe[1000];
int d[1000];
const int INF = 1e9;

void input() {
    cin >> n >> m >> s;
    for(int i = 0; i < m; i++){
        int x, y, w; 
        cin >> x >> y >> w;
        dsKe[x].push_back({y, w});
        // dsKe[y].push_back({x, w}); // nếu là đồ thị vô hướng thì thêm dòng này
    }
}


void dijkstra(int s) {
    for(int i = 1; i <= n; i++){
        d[i] = INF;
    }
    vector<bool> visited(n + 1, false);
    d[s] = 0; // khoảng cách từ s đến s là 0

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    // Q là hàng đợi ưu tiên, mỗi phần tử của Q là một cặp (khoảng cách, đỉnh)

    Q.push({0, s}); // thêm đỉnh s vào Q

    while(!Q.empty()){
        // chon đỉnh u có khoảng cách từ s đến u là nhỏ nhất
        pair<int, int> top = Q.top(); Q.pop(); 

        int u = top.second; // lấy đỉnh của top

        if(visited[u]) continue; // nếu khoảng cách của top lớn hơn khoảng cách từ s đến u thì bỏ qua
        visited[u] = true;

        // relaxation : cap nhat khoảng cách từ s đến các đỉnh kề với u
        for(auto it : dsKe[u]){
            int v = it.first; // lấy đỉnh kề với u
            int w = it.second; // lấy trọng số của cạnh (u, v)
            if(d[v] > d[u] + w){
                d[v] = d[u] + w; // cập nhật khoảng cách từ s đến v
                Q.push({d[v], v}); // thêm v vào Q
            }
        }
    }

    for(int i = 1; i <= n; i++){
        cout << d[i] << " ";
    }
    
}

int main() {
    input();
    dijkstra(s);
    return 0;
}