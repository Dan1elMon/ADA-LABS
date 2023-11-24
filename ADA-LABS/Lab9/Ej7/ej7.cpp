#include <iostream>
#include <vector>
#include <unordered_set>

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

bool GRAPHundir(const Graph& G) {
    unordered_set<int> visited;

    for (int v = 0; v < G.V; ++v) {
        for (Node* a = G.adj[v]; a != nullptr; a = a->next) {
            int w = a->w;
            if (visited.find(w) == visited.end()) {
                // Si el vértice w aún no ha sido visitado desde v
                visited.insert(v);
            } else {
                // El vértice w ya ha sido visitado desde v, el grafo no es no dirigido
                return false;
            }
        }
    }

    return true;
}

int main() {
    Graph G;
    G.V = 5;
    G.adj.resize(G.V, nullptr);

    GRAPHinsertArc(G, 0, 1);
    GRAPHinsertArc(G, 1, 0);  // Agregamos el arco inverso
    GRAPHinsertArc(G, 0, 2);
    GRAPHinsertArc(G, 1, 3);
    GRAPHinsertArc(G, 2, 3);
    GRAPHinsertArc(G, 3, 4);
    GRAPHinsertArc(G, 4, 3);  // Agregamos el arco inverso

    if (GRAPHundir(G)) {
        cout << "El grafo es no dirigido." << endl;
    } else {
        cout << "El grafo es dirigido." << endl;
    }

    return 0;
}
