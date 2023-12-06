#include <iostream>
#include <vector>
#include <list>
using namespace std;

struct Graph {
    int V;
    vector<list<int>> adj;
};

using vertex = int;

int cnt;
vector<int> pre;

void dfsR(Graph G, vertex v) {
    pre[v] = cnt++;
    cout << "Visitando vertice " << v << endl;

    for (int w : G.adj[v]) {
        if (pre[w] == -1) {
            cout << "Explorando arista: " << v << " -> " << w << endl;
            dfsR(G, w);
        }
    }
}

void GRAPHdfs(Graph G) {
    cnt = 0;
    pre.assign(G.V, -1);

    for (vertex v = 0; v < G.V; ++v) {
        if (pre[v] == -1) {
            cout << "Comenzando nueva componente conectada desde el vertice " << v << endl;
            dfsR(G, v);
            cout << "Finalizada componente conectada desde el vertice " << v << endl;
        }
    }
}

int main() {
    // Caso 1: G->A es 0
    Graph G1;
    G1.V = 5;
    G1.adj.resize(G1.V);

    cout << "Resultado cuando G->A es 0:" << endl;
    GRAPHdfs(G1);


    return 0;
}
