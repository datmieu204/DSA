#include <iostream>
#include <vector>
#include<fstream>

using namespace std;

int n, m;
bool visited[1001];
vector<int> dsKe[1001];
vector<int> topo;

ifstream fileInp("D://Meow//DSA_UET_LEC//Lecture12//jobs.txt");
ofstream fileOut("D://Meow//DSA_UET_LEC//Lecture12//jobs.out");

void input(){
    if(fileInp.is_open()){
        fileInp >> n >> m;
        for(int i = 0; i < m; i++){
            int x, y;
            fileInp >> x >> y;
            dsKe[x].push_back(y);
        }
        visited[1001] = {false};
    }
    else cout << "Unable to open file";
}

void DFS(int u){
    visited[u] = true;
    for(int x : dsKe[u]){
        if(!visited[x]) DFS(x);
    }
    topo.push_back(u); // thêm vào topo
}

int main(){
    input();

    for(int i = 1; i <= n; i++){
        if(!visited[i]) DFS(i);
    }

    for(int i = topo.size() - 1; i >= 0; i--){
        fileOut << topo[i] << " ";
    }

    return 0;
}