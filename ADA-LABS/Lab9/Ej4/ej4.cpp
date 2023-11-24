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

void GRAPHremoveArc(Graph& G, int v, int w) {
    Node* prev = nullptr;
    Node* current = G.adj[v];

    while (current != nullptr && current->w != w) {
        prev = current;
        current = current->next;
    }

    if (current != nullptr) {
        if (prev != nullptr) {
            prev->next = current->next;
        } else {
            G.adj[v] = current->next;
        }
        delete current;
    }
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

    cout << "Grafo antes de eliminar el arco:" << endl;
    GRAPHshow(G);

    GRAPHremoveArc(G, 2, 3);

    cout << "\nGrafo después de eliminar el arco 2-3:" << endl;
    GRAPHshow(G);

    return 0;
}
