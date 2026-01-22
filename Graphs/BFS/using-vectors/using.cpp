#include <iostream>
#include <vector>
#include <queue> 

using namespace std;

void bfs(int startNode, vector<vector<int>>& adj, int V) {
    vector<bool> visited(V, false);
    
    queue<int> q;

    visited[startNode] = true; 
    q.push(startNode);         

    cout << "BFS Traversal: ";

    while (!q.empty()) {
        
        int u = q.front();
        q.pop(); 
        
        cout << u << " ";

        for (int neighbor : adj[u]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true; 
                q.push(neighbor);         
            }
        }
    }
    cout << endl;
}

int main() {
    int V = 5;
    
    vector<vector<int>> adj(V);

    auto addEdge = [&](int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    };

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 4);

    bfs(0, adj, V);

    return 0;
}