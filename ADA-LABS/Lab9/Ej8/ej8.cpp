#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct Graph {
    int V;
    vector<unordered_set<int>> adj; // Lista de adyacencia usando conjuntos para evitar aristas duplicadas
};

// Función para insertar una arista en un grafo no dirigido
void UGRAPHinsertEdge(Graph& G, int v, int w) {
    // Agregar v a los vértices adyacentes de w
    G.adj[w].insert(v);
    // Agregar w a los vértices adyacentes de v
    G.adj[v].insert(w);
}

// Función para mostrar las aristas de un grafo no dirigido
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

    cout << "Grafo no dirigido después de la inserción de aristas:" << endl;
    UGRAPHshow(G);

    return 0;
}
