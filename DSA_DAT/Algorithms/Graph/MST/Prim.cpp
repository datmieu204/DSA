//SD PRIORiRY QUEUE, MIN HEAP

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m; // n: số đỉnh, m: số cạnh
int d[1001];
int parent[1001];
vector<pair<int, int>> a[1001]; // danh sách kề
bool used[1001]; // cây khung Vmst khi used[i] = true, nếu used[i] = false thì đỉnh i thuộc tập V


struct canh {
    int u, v, w;
};

void input() {
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        a[u].push_back({v, w});
        a[v].push_back({u, w});
    }
    used[1001] = {false};

    for(int i = 1; i <= n; i++) {
        d[i] = INT_MAX;
    }
}

void prim(int u) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q; // hàng đợi ưu tiên, min heap
    vector<canh> MST; // cây khung nhỏ nhất
    int res = 0; // tổng trọng số của cây khung nhỏ nhất

    Q.push({0, u}); // thêm đỉnh u vào hàng đợi ưu tiên, trọng số của đỉnh u là 0

    // lặp n - 1 lần
    while(!Q.empty()){
        pair<int, int> top = Q.top(); // lấy đỉnh đầu tiên trong hàng đợi ưu tiên
        Q.pop(); // xóa đỉnh đầu tiên trong hàng đợi ưu tiên

        int dinh = top.second; // lấy đỉnh
        int trongSo = top.first; // lấy trọng số

        if(used[dinh]) continue; // nếu đỉnh đã được thêm vào cây khung nhỏ nhất thì bỏ qua

        res += trongSo; // cập nhật trọng số của cây khung nhỏ nhất

        used[dinh] = true; // thêm đỉnh vào cây khung nhỏ nhất

        if(u != dinh) {
            MST.push_back({dinh, parent[dinh], trongSo});
        }

        // duyệt các đỉnh kề với đỉnh đang xét
        for(auto it : a[dinh]) {
            int y = it.first; // lấy đỉnh kề với đỉnh đang xét
            int w = it.second; // lấy trọng số của cạnh

            if(!used[y] && d[y] > w) {
                Q.push({w, y});
                d[y] = w;
                parent[y] = dinh;
            }
        }
    }

    cout << res << endl;

    for(canh i : MST) {
        cout << i.u << " " << i.v << " " << i.w << endl;
    }
}

int main()  {
    input();
    prim(1);
    return 0;
}
    

/*C2

#include<iostream>
#include<vector>

using namespace std;

int n, m; // n: số đỉnh, m: số cạnh

vector<pair<int, int>> a[1001]; // danh sách kề
bool used[1001]; // đánh thêm vào cây khung Vmst khi used[i] = true, used[i] = false thì đỉnh i thuộc tập V
                 
struct canh {
    int u, v, w;
};

void input() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        a[u].push_back({v, w});
        a[v].push_back({u, w});
    }
    used[1001] = {false};
}

void prim(int u) {
    vector<canh> MST; // cây khung nhỏ nhất
    int d = 0; // tổng trọng số của cây khung nhỏ nhất
    used[u] = true; // thêm đỉnh u vào cây khung nhỏ nhất

    // lặp n - 1 lần
    while((int)MST.size() < n - 1) {
        int minW = INT_MAX; // chon canh co trong so nho nhat co X thuoc V, Y thuoc Vmst
        int x, y;
        
        for (int i = 1; i <= n; i++) {
            // neu dinh i thuoc Vmst
            if(used[i]) {
                for (pair<int, int> it : a[i]) {
                    int j = it.first; // dinh ke cua i
                    int trongSo = it.second; // trong so cua canh (i, j)
                    if(!used[j] && trongSo < minW) {
                        minW = trongSo;
                        y = i;
                        x = j;
                    }
                }
            }
        }

        MST.push_back({x, y, minW});
        d += minW;
        used[x] = true; // them dinh x vao Vmst, loai dinh x khoi V
    }

    cout << d << endl;

    for(canh i : MST) {
        cout << i.u << " " << i.v << " " << i.w << endl;
    }
}

int main()  {
    input();
    prim(1);
    return 0;
}
    
*/