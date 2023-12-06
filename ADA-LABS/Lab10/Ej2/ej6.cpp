#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Graph {
    int V;
    vector<vector<int>> adj;
};

// Función recursiva para explorar el grafo y marcar los vértices alcanzables desde s
bool reachR(Graph& G, int s, int t, vector<int>& visited, stack<int>& path) {
    visited[s] = 1;
    path.push(s);

    if (s == t) {
        // Imprimir el camino
        cout << "Camino de " << s << " a " << t << ": ";
        while (!path.empty()) {
            cout << path.top() << " ";
            path.pop();
        }
        cout << endl;
        return true; // Se encontró un camino, devolver true
    }

    // Recorrer todos los vértices adyacentes a s
    for (int i : G.adj[s]) {
        if (!visited[i]) {
            if (reachR(G, i, t, visited, path)) {
                return true; // Se encontró un camino, devolver true
            }
        }
    }

    path.pop(); // Retirar el vértice del camino si no lleva a t
    return false; // No se encontró un camino hasta el momento
}

// Función principal para verificar si hay un camino desde s hasta t en el grafo
bool GRAPHreach(Graph& G, int s, int t) {
    vector<int> visited(G.V, 0);
    stack<int> path;

    return reachR(G, s, t, visited, path);
}

int main() {

    Graph G;
    G.V = 6;

    // Inicializar la lista de adyacencia
    G.adj.resize(G.V);
    G.adj[0] = {2,3,4};
    G.adj[1] = {};
    G.adj[2] = {4,1};
    G.adj[3] = {4,5};
    G.adj[4] = {1,5};
    G.adj[5] = {1};

    int source = 0; // Vértice de inicio
    int target = 5; // Vértice de destino


    if (GRAPHreach(G, source, target)) {
        cout << "Se encontró un camino desde " << source << " hasta " << target << endl;
    } else {
        cout << "No hay camino desde " << source << " hasta " << target << endl;
    }

    return 0;
}
