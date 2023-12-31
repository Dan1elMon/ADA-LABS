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
    int mayor = f;

    if (izq <= m && v[izq] > v[mayor]) {
        mayor = izq;
    }

    if (der <= m && v[der] > v[mayor]) {
        mayor = der;
    }

    if (mayor != f) {
        intercambia(v[f], v[mayor]);
        cribaRecursiva(m, v, mayor);
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
     for (int i = n; i >= 2; i--) {
        criba(i, v);
        cout << "Iteracion " << n - i + 1 << ": ";
        for (int j = 1; j <= n; j++) {
            cout << v[j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int v[] = {2,4,1,24,31,2455,12,1224}; // Se inicia en 1-based indexing, el primer elemento es un 0 dummy.

    int n = sizeof(v) / sizeof(v[0]) - 1; // Restamos 1 para obtener el tamaño correcto.

    heapsort(n, v);

    cout << "Arreglo ordenado: ";
    for (int i = 1; i <= n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}