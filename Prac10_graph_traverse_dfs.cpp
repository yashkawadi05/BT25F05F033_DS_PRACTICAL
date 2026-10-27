#include <iostream>
using namespace std;

int graph[10][10], visited[10], n;

void DFS(int v) {
    cout << v << " ";
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

int main() {
    int edges, u, v;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> edges;

    for (int i = 0; i < edges; i++) {
        cout << "Enter edge (u v): ";
        cin >> u >> v;

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    cout << "DFS Traversal: ";
    DFS(0);

    return 0;
}