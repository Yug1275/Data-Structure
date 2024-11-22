#include <iostream>
#include <queue>
using namespace std;

#define MAX 100 // Maximum number of vertices in the graph

// Graph adjacency matrix
class Graph {
private:
    int adjMatrix[MAX][MAX]; // Adjacency matrix
    int vertices;            // Number of vertices

public:
    Graph(int v) {
        vertices = v;
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                adjMatrix[i][j] = 0; // Initialize adjacency matrix to 0
            }
        }
    }

    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1; // Add edge u -> v
        adjMatrix[v][u] = 1; // Add edge v -> u (for undirected graph)
    }

    void BFS(int start) {
        bool visited[MAX] = {false}; // Array to keep track of visited nodes
        queue<int> q;                // Queue for BFS

        visited[start] = true; // Mark the start vertex as visited
        q.push(start);         // Enqueue the start vertex

        cout << "BFS Traversal: ";

        while (!q.empty()) {
            int current = q.front(); // Get the front element
            q.pop();
            cout << current << " ";

            // Explore all neighbors of the current vertex
            for (int i = 0; i < vertices; i++) {
                if (adjMatrix[current][i] == 1 && !visited[i]) {
                    visited[i] = true; // Mark neighbor as visited
                    q.push(i);         // Enqueue the neighbor
                }
            }
        }
        cout << endl;
    }
};

int main() {
    int v, e;
    cout << "Enter the number of vertices: ";
    cin >> v;

    Graph g(v);

    cout << "Enter the number of edges: ";
    cin >> e;

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int start;
    cout << "Enter the start vertex for BFS: ";
    cin >> start;

    g.BFS(start);

    return 0;
}
