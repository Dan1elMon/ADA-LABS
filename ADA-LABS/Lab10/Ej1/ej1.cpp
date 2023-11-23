#include <iostream>
#include <vector>

using namespace std;

// Definición de la estructura del grafo
struct Graph {
    int V; // Número de vértices
    vector<vector<int>> adj; // Lista de adyacencia
};

// Función recursiva para explorar el grafo y marcar los vértices alcanzables desde s
void reachR(Graph& G, int s, vector<int>& visited) {
    visited[s] = 1; // Marcar el vértice como visitado

    // Recorrer todos los vértices adyacentes a s
    for (int i : G.adj[s]) {
        if (!visited[i]) {
            reachR(G, i, visited); // Llamada recursiva para el vértice adyacente no visitado
        }
    }
}

// Función principal para verificar si hay un camino desde s hasta t en el grafo
bool GRAPHreach(Graph& G, int s, int t) {
    vector<int> visited(G.V, 0); // Inicializar el vector de visitados

    reachR(G, s, visited); // Llamar a la función de búsqueda desde el vértice s

    return visited[t] == 1; // Devolver true si t es alcanzable desde s, false en caso contrario
}

int main() {
    // Ejemplo de uso
    Graph G;
    G.V = 6; // Número de vértices

    // Inicializar la lista de adyacencia 
    G.adj.resize(G.V);
    G.adj[0] = {3,4,2};
    G.adj[1] = {};
    G.adj[2] = {4,1};
    G.adj[3] = {4,5};
    G.adj[4] = {1,5};
    G.adj[5] = {1};

    int source = 2; // Vértice de inicio
    int target = 3; // Vértice de destino

    // Verificar si hay un camino desde source hasta target
    if (GRAPHreach(G, source, target)) {
        cout << "Hay un camino desde " << source << " hasta " << target << endl;
    } else {
        cout << "No hay camino desde " << source << " hasta " << target << endl;
    }

    return 0;
}
