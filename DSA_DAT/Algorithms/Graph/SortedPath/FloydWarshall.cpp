/*
Thuật toán Floyd-Warshll dùng để giải quyết bài toán đường đi ngắn nhất mọi cặp đỉnh (All-pairs shortest path), đồ thị có thể có trọng số âm.

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N = 510;
int n, m, s, t;
int d[1001][1001];
int INF = 1e9;
int pre[1001][1001];

void init()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            pre[i][j] = i;

            if (i == j)
                d[i][j] = 0;
            else
                d[i][j] = INF;
        }
    }
}

void input()
{
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        d[x][y] = w;
        // d[y][x] = w; // nếu là đồ thị vô hướng
    }
}

void floydWarshall()
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (d[i][j] > d[i][k] + d[k][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                    pre[i][j] = pre[k][j];
                }
            }
        }
    }
}

void sortPath(int s, int t)
{
    if (d[s][t] == INF)
    {
        cout << "Khong co duong di tu " << s << " den " << t << endl;
        return;
    }
    else
    {
        cout << d[s][t] << endl;
    }

    vector<int> path;

    while(s != t){
        path.push_back(t);
        t = pre[s][t];
    }

    path.push_back(s);

    for(int i = path.size() - 1; i >= 0; i--){
        cout << path[i] << " ";
    }

    cout << endl;
}

void dis() {
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (d[i][j] == INF)
                cout << "INF ";
            else
                cout << d[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    init();
    input();
    floydWarshall();
    sortPath(s, t);
    dis();
    return 0;
}