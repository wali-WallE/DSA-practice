#include <iostream>
#include <vector>

using namespace std;

void dfsRecursive(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adj[node]) {
        
        if (!visited[neighbor]) {
            dfsRecursive(neighbor, adj, visited);
        }
    }
}

void dfs(int startNode, vector<vector<int>>& adj, int V) {
    vector<bool> visited(V, false);
    
    cout << "DFS Traversal: ";
    dfsRecursive(startNode, adj, visited);
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

    dfs(0, adj, V);

    return 0;
}