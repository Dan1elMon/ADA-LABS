#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct Graph {
    int V;
    vector<unordered_set<int>> adj;
};

void UGRAPHinsertEdge(Graph& G, int v, int w) {
    G.adj[w].insert(v);
    G.adj[v].insert(w);
}

void UGRAPHremoveEdge(Graph& G, int v, int w) {
    G.adj[w].erase(v);
    G.adj[v].erase(w);
}

void UGRAPHshow(const Graph& G) {
    for (int v = 0; v < G.V; ++v) {
        cout << "Vértice " << v << ": ";
        for (int w : G.adj[v]) {
            cout << w << " ";
        }
        cout << endl;
    }
}

int main() {
    Graph G;
    G.V = 5;
    G.adj.resize(G.V);

    UGRAPHinsertEdge(G, 0, 1);
    UGRAPHinsertEdge(G, 0, 2);
    UGRAPHinsertEdge(G, 1, 3);
    UGRAPHinsertEdge(G, 2, 3);
    UGRAPHinsertEdge(G, 3, 4);

    cout << "Grafo no dirigido antes de la eliminación de aristas:" << endl;
    UGRAPHshow(G);

    UGRAPHremoveEdge(G, 0, 2);

    cout << "\nGrafo no dirigido después de la eliminación de la arista 0-2:" << endl;
    UGRAPHshow(G);

    return 0;
}
