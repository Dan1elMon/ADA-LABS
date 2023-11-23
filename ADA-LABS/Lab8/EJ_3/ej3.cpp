#include <iostream>
using namespace std;

void intercambia(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void cribaRecursiva(int m, int v[], int f) {
    int izq = 2 * f;
    int der = 2 * f + 1;
    int menor = f;

    if (izq <= m && v[izq] < v[menor]) {
        menor = izq;
    }

    if (der <= m && v[der] < v[menor]) {
        menor = der;
    }

    if (menor != f) {
        intercambia(v[f], v[menor]);
        cribaRecursiva(m, v, menor);
    }
}

void criba(int m, int v[]) {
    if (m <= 1) {
        return;
    }

    cribaRecursiva(m, v, 1);
    intercambia(v[1], v[m]);
    criba(m - 1, v);
}

void heapsort(int n, int v[]) {
    // Construimos un Min-Heap
    for (int i = n; i >= 1; i--) {
        criba(i, v);
    }

    // Extraemos elementos del heap
    for (int i = n; i >= 2; i--) {
        intercambia(v[1], v[i]);
        criba(i - 1, v);
    }
}

int main() {
    int v[] = {16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4}; // Se inicia en 1-based indexing, el primer elemento es un 0 dummy.

    int n = sizeof(v) / sizeof(v[0]) - 1; // Restamos 1 para obtener el tamaño correcto.

    heapsort(n, v);

    cout << "Arreglo ordenado en orden descendente: ";
    for (int i = 1; i <= n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}
