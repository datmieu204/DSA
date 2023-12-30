/*
Cài đặt bằng đệ quy (STACK)
Ưu tiên duyệt xuống sâu nhất trước khi quay lại

//================================================================================================================
bắt đầu duyệt từ đỉnh u
DFS(u) {
    <thăm đỉnh u>
    visited[u] = true; // đánh dấu đã thăm đỉnh u

    // duyệt các đỉnh kề với u
    for (int v : a[u]) {
        if (!visited[v]) { // nếu chưa thăm đỉnh v
            DFS(v); // gọi đệ quy duyệt DFS(v) đỉnh chưa được thăm
        }
    }
}
//================================================================================================================

Độ phức tạp phụ thuộc vào cách biểu diễn đồ thị G = (V, E)

- Ma trận kề: O(V * V) = O(n^2)
- Danh sách cạnh: O(V * E) = O(m)
- Danh sách kề: O(V + E) = O(n + m)

//================================================================================================================
VD:
                      1                             Dỉnh | Visited
                    /\   \                           1   |  false     -> true
                   /  \   5                          2   |  false       -> true
                  /    \   \                         3   |  false               -> true
                 2     3    8                        4   |  false          -> true
                 |    / \ \ |                        5   |  false                                   -> true
                 4    6  7  9                        6   |  false                   -> true
                                                     7   |  false                       -> true
                                                     8   |  false                               -> true
Stack   |     |     |     |                          9   |  false                           -> true
        |     |     |     |
        |     |     |     |               DFS(1) = 1, 2, 4, 3 ,6, 7, 9, 8, 5
        |     |     |     |
        |     |     |     |
        |     |     |     |
        |  4  |     |     |
        |  2  |     |  3  |
        |  1  |     |  1  |
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
input : 9 9
        1 2
        1 3
        1 5
        2 4
        3 6
        3 7
        3 9
        5 8
        8 9
*/

// SD danh sach ke, hoạt động theo STACK, BACKTRACKING
int n, m;              // so dinh, so canh
vector<int> dsKe[100]; // danh sach ke
bool visited[1001];    // danh dau dinh da duyet hay chua

void input()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v; // u -> v
        cin >> u >> v;
        dsKe[u].push_back(v);
        dsKe[v].push_back(u); // vo huong, co huong thi bo dong nay
    }
    visited[1001] = {false};
}

// void DFS(int u) {
//     cout << u << " ";
//     visited[u] = true;

//     for (int v : dsKe[u]) {
//         if (!visited[v]) {
//             DFS(v);
//         }
//     }
// }

/* Khi dùng STACK
 */

void DFS(int u)
{
    stack<int> st;
    st.push(u);
    visited[u] = true;

    cout << u << " ";

    while (!st.empty())
    {
        int s = st.top();
        bool flag = false; // ktra xem co dinh nao chua duyet hay khong

        for (int v : dsKe[s])
        {
            if (!visited[v])
            {
                st.push(v);
                visited[v] = true;
                cout << v << " ";
                flag = true; // đánh dấu đã thêm đỉnh chưa được duyệt vào stack
                break;
            } 
        }

        if (!flag) st.pop(); // nếu không có đỉnh nào chưa được duyệt thì pop ra khỏi stack
    }
}

int main()
{
    input();
    DFS(1);
    return 0;
}
