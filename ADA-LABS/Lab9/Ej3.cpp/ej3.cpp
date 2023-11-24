#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int w;
    Node* next;
};


struct Graph {
    int V;
    vector<Node*> adj;
};

Node* NEWnode(int w, Node* next) {
    Node* a = new Node;
    a->w = w;
    a->next = next;
    return a;
}

void GRAPHinsertArc(Graph& G, int v, int w) {
    G.adj[v] = NEWnode(w, G.adj[v]);
}

void GRAPHshow(const Graph& G) {
    for (int v = 0; v < G.V; ++v) {
        cout << "Vértice " << v << ": ";
        for (Node* a = G.adj[v]; a != nullptr; a = a->next) {
            cout << a->w << " ";
        }
        cout << endl;
    }
}

int main() {
    Graph G;
    G.V = 5; // Número de vértices

    // Inicializar la lista de adyacencia
    G.adj.resize(G.V, nullptr);

    // Insertar algunos arcos en el grafo dirigido
    GRAPHinsertArc(G, 0, 1);
    GRAPHinsertArc(G, 0, 2);
    GRAPHinsertArc(G, 1, 3);
    GRAPHinsertArc(G, 2, 3);
    GRAPHinsertArc(G, 3, 4);

    // Mostrar los vértices adyacentes a cada vértice en el grafo
    GRAPHshow(G);

    return 0;
}
