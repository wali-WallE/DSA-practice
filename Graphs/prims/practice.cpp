#include <iostream>
#include <vector>
#include <climits> 

using namespace std;

#define V 5

void addEdge(vector<pair<int, int>> adj[], int u, int v, int w) {
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}

int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void printMST(int parent[], int key[]) {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " \t" << key[i] << " \n";
    }
}

void primMST(vector<pair<int, int>> adj[]) {
    int parent[V];      
    int key[V];         
    bool mstSet[V];     

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX; 
        mstSet[i] = false;
    }

    key[0] = 0;     
    parent[0] = -1; 

    for (int count = 0; count < V - 1; count++) {
        
        int u = minKey(key, mstSet);

        mstSet[u] = true;

        for (auto it : adj[u]) {
            int v = it.first;       
            int weight = it.second; 

            if (mstSet[v] == false && weight < key[v]) {
                parent[v] = u;
                key[v] = weight;
            }
        }
    }

    printMST(parent, key);
}

int main() {
    vector<pair<int, int>> adj[V];

    addEdge(adj, 0, 1, 2);
    addEdge(adj, 0, 3, 6);
    addEdge(adj, 1, 2, 3);
    addEdge(adj, 1, 3, 8);
    addEdge(adj, 1, 4, 5);
    addEdge(adj, 2, 4, 7);
    addEdge(adj, 3, 4, 9);

    cout << "Running Prim's Algorithm (Adjacency List Version)...\n";
    primMST(adj);

    return 0;
}