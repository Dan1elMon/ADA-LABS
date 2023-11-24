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

Graph GRAPHreverse(const Graph& G) {
    Graph reversedGraph;
    reversedGraph.V = G.V;
    reversedGraph.adj.resize(G.V, nullptr);

    for (int v = 0; v < G.V; ++v) {
        for (Node* a = G.adj[v]; a != nullptr; a = a->next) {
            GRAPHinsertArc(reversedGraph, a->w, v);
        }
    }

    return reversedGraph;
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
    G.V = 5;
    G.adj.resize(G.V, nullptr);

    GRAPHinsertArc(G, 0, 1);
    GRAPHinsertArc(G, 0, 2);
    GRAPHinsertArc(G, 1, 3);
    GRAPHinsertArc(G, 2, 3);
    GRAPHinsertArc(G, 3, 4);

    cout << "Grafo original:" << endl;
    GRAPHshow(G);

    Graph reversedG = GRAPHreverse(G);

    cout << "\nGrafo invertido:" << endl;
    GRAPHshow(reversedG);

    return 0;
}
