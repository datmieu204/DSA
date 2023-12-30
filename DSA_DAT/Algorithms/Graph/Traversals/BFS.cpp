/*
Cài đặt bằng Queue
Tìm kiếm ưu tiên chiều rộng trước
//================================================================================================================

BFS(u) {
    queue = rỗng
    queue.push(u) // thêm đỉnh u vào hàng đợi
    visited[u] = true // đánh dấu đã thăm đỉnh u

    while (queue không rỗng) {
        v = queue.front() // lấy đỉnh đầu tiên trong hàng đợi
        queue.pop() // xóa đỉnh đầu tiên trong hàng đợi

        <thăm đỉnh v>
        // duyệt các đỉnh kề với v mà chưa được thăm
        for (int x : a[v]) {
            if (!visited[x]) { // nếu chưa thăm đỉnh v
                queue.push(x) // thêm đỉnh v vào hàng đợi
                visited[x] = true // đánh dấu đã thăm đỉnh v
            }
        }
    }
}
//================================================================================================================
- Độ thức tạp thuật toán phụ thuộc vào cách biểu diễn đồ thị G = (V, E)
- Ma trận kề: O(V * V) = O(n^2)
- Danh sách cạnh: O(V * E) = O(m)
- Danh sách kề: O(V + E) = O(n + m)

//================================================================================================================
VD:
    Đỉnh | Visited
    1   |  false     -> true
    2   |  false        -> true
    3   |  false               -> true
    4   |  false     -> true
    5   |  false                    -> true
    6   |  false     -> true
    7   |  false     -> true
    8   |  false     -> true
    9   |  false     -> true
    10  |  false                        -> true


                                Hàng đợi 
BACK  ->_____________________________________________________________________ FRONT ->
            |   |   |   |   |   |   |  | 8 | 9 | 7 | 6 | 4 | 10 | 5 | 3 | 2 |
        _____________________________________________________________________

BFS(1) = 1, 2, 3, 5, 10, 4, 6, 7, 9, 8

                          1  ---- 10
                      /  /  \  
                     /  /    5 
                   2    3     \   
                   |   /  \ \  8
                   4  /    \ \  /
                      6----7   9       
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
input: 10 11
       1 2
       1 3
       1 5
       1 10
       2 4
       3 6
       3 7
       3 9
       6 7
       5 8
       8 9 
*/

int n, m;
vector<int> dsKe[1001];
bool visited[1001];

void input() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        dsKe[u].push_back(v);
        dsKe[v].push_back(u); // vo huong, co huong thi bo dong nay
    }
    visited[1001] = {false};
}

void BFS(int u) {
    // khoi tao
    queue<int> q;
    q.push(u);
    visited[u] = true;

    // buoc lap
    while (!q.empty()) {
        int v = q.front();
        q.pop();

        cout << v << " ";

        for (int x : dsKe[v]) {
            if (!visited[x]) {
                q.push(x);
                visited[x] = true;
            }
        }
    }
}

int main() {
    input();
    BFS(1);
    return 0;
}