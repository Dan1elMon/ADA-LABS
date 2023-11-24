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

void GRAPHdestroy(Graph& G) {
    for (int v = 0; v < G.V; ++v) {
        Node* current = G.adj[v];
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    G.adj.clear();

    G.V = 0;
}

int main() {

    Graph G;


    G.adj.resize(G.V, nullptr);

    GRAPHinsertArc(G, 0, 1);
    GRAPHinsertArc(G, 0, 2);
    GRAPHinsertArc(G, 1, 3);
    GRAPHinsertArc(G, 2, 3);
    GRAPHinsertArc(G, 3, 4);

    GRAPHdestroy(G);

    cout << "El grafo ha sido destruido." << endl;

    return 0;
}

