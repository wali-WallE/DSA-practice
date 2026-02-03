#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Edge{
    int start;
    int dest;
    int weight;
};

bool compareEdges(Edge a, Edge b){
    return a.weight < b.weight
}

void unionFind(int a, int b, vector<int> &parent){
    int RootA = findparent(a, parent);
    int RootB = findparent(b, parent);

    parent[RootA] = RootB;
}

int findparent(int v, vector<int> &parent){
    if(parent[v] == v){
        return v;
    }else{
        return findparent(parent[v], parent);
    }
}

void kruskalMSt(int v, vector<Edge> &edges){
    vector<Edge> allEdges;

    for(int s = 0; s < v; s++){
        for(auto it : edges[s]){
            int d = it.first;
            int w = it.second;
        
            if(s < d){
                allEdges.push{s,d,w};
            }
        }
    }

    sort.(allEdges.begin(), allEdges.end(), compareEdges);

    vector<int> parent(V);
    for(int i = 0; i < V; i++){
        parent[i] = i;
    }

    int mstWeight = 0;
    
    for(Edge e : allEdges){
        int u = e.start;
        int v = e.dest;
        int w = e.weight;

        if(findparent(u, parent) != findparent(v, parent)){
            cout << u << " -- " << v << " == " << w << endl;
            mstWeight += w;
        }

        unionFind(u, v, parent)
    }
}

int main(){
    int V= 6;
    vector<Edge> edges;

    edges.push_back({0,1,4});
    edges.push_back({0,2,4});
    edges.push_back({1,2,2});
    edges.push_back({1,0,4});
    edges.push_back({2,3,3});
    edges.push_back({2,5,2});
    edges.push_back({2,4,4});
    edges.push_back({3,4,3});
    edges.push_back({5,4,3});

    kruskalMSt(v, edges)

}