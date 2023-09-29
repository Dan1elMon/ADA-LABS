#include <iostream>
using namespace std;

int busquedaBinaria(int x, int n, int v[]) {
    // Si x es mayor que todos los elementos en el arreglo
    if (v[n-1] < x) return n;
    // Si x es menor o igual al primer elemento en el arreglo
    if (x <= v[0]) return 0;

    // Ahora sabemos que v[0] < x <= v[n-1]
    int i = 0, d = n - 1;

    while (i < d) {
        int m = (i + d) / 2;
        if (v[m] < x)
            i = m + 1;
        else
            d = m;
    }

    return d;
}

int main() {
    int arreglo[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    int longitud = sizeof(arreglo) / sizeof(arreglo[0]);
    int numero = 8;

    int indice = busquedaBinaria(numero, longitud, arreglo);

    if (indice < longitud) {
        cout << "El elemento " << numero << " debería insertarse en la posición " << indice << "." << endl;
    } else {
        cout << "El elemento " << numero << " es mayor que todos los elementos en el arreglo." << endl;
    }

    return 0;
}