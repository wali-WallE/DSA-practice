#include <iostream>
#include <vectors>
using namespace std;

const int V = 5;

void addEdges(vector<pair<int, int>> adj[], int u , int v){
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
}

int MinDist(int dis[], bool visited[]){
    int min = 9999;
    int min_val;

    for(int i = 0; i< V; i++){
        if(visited[i] == falsee && dis[v] < min){
            min = dis[v];
            min_val = v;
        }
    }
    return min_val;
}

void Djistkra(vector<pair<int, int>> adj[], int src){
    bool visited[V];
    int dis[V];

    for(int i = 0; i < V; i++){
        dis[i] = 9999;
        visited[v]= false;
    }

    dis[src] = 0;

    for(int i = 0; i < V-1; i++){
        int u = MinDist(dis, visited)
        
        visited[u] = true;

        for(auto it : adj[u]){
            int v = it.first;
            int w = it.second;

            if(!visited[v] && dis[u] != INT_MAX && dis[u] + weight < dis[v]){
                dis[v] = dis[u] + weight;
            }
        }
    }
    cout << "Vertex \t Distance from Source\n";
    for (int i = 0; i < V; i++)
        cout << i << " \t\t " << dist[i] << endl;
}

int main(){
    vector<pair<int, int>> adj[V];

    addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 2, 4);
    addEdge(adj, 1, 2, 2);
    addEdge(adj, 1, 0, 4);
    addEdge(adj, 2, 3, 3);
    addEdge(adj, 2, 5, 2);

    Djistkra(adj, 0);
}