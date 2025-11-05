#include <iostream>
using namespace std;

#define MAX 10

int adj[MAX][MAX];      // Adjacency matrix
int visited[MAX];       // Visited array
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int v) {
    if (rear < MAX - 1)
        queue[++rear] = v;
}

int dequeue() {
    if (front != rear)
        return queue[++front];
    return -1;
}

bool isQueueEmpty() {
    return (front == rear);
}

void BFS(int start, int n) {
    enqueue(start);
    visited[start] = 1;
    cout << "\nIndexing pages starting from: " << start << endl;

    while (!isQueueEmpty()) {
        int curr = dequeue();
        cout << "Indexed page: " << curr << endl;
        for (int i = 0; i < n; i++) {
            if (adj[curr][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
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
        adj[v][u] = 1; 
    }

    int start;
    cout << "Enter seed/start page number: ";
    cin >> start;

    BFS(start, n);

    return 0;
}

