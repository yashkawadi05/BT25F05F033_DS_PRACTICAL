#include <iostream>
#include <vector>
using namespace std;

void DFS(int node, vector<int> adj[], bool visited[]) {
    visited[node] = true;
    cout << node << " ";

    for (int i = 0; i < adj[node].size(); i++) {
        int next = adj[node][i];

        if (!visited[next]) {
            DFS(next, adj, visited);
        }
    }
}

int main() {
    int n, e, u, v;

    cout << "Enter number of vertices and edges: ";
    cin >> n >> e;

    vector<int> adj[n];

    cout << "Enter edges:\n";
    for (int i = 0; i < e; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool visited[n] = {false};

    cout << "DFS Traversal: ";
    DFS(0, adj, visited);

    return 0;
}