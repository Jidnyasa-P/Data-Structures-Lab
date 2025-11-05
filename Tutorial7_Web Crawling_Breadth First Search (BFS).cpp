#include <iostream>
using namespace std;

#define MAX 10

int adj[MAX][MAX]; // Adjacency matrix
int visited[MAX];  // Visited array

void DFS(int v, int n) {
    visited[v] = 1;
    cout << " Indexed page: " << v << endl;
    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && visited[i] == 0) {
            DFS(i, n);
        }
    }
}

int main() {
    int n, edges;
    cout << "Enter number of web pages (max 10): ";
    cin >> n;

    cout << "Enter number of hyperlinks: ";
    cin >> edges;

    // Initialization
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
    }

    cout << "Enter links (from to):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1; // For undirected graph
    }

    int start;
    cout << "Enter seed (start) page number: ";
    cin >> start;

    cout << "\nStarting DFS web crawling from page: " << start << endl;
    DFS(start, n);

    return 0;
}

