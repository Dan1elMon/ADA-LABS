#include <iostream>
using namespace std;

int busquedaBinaria(int x, int n, int v[]) {
    int i = -1, d = n;

    while (i < d - 1) {
        int m = (i + d) / 2;
        if (v[m] < x)
            i = m;
        else
            d = m;
    }

    return d;
}

int main() {
    int arreglo[] = {1, 3, 5, 7, 9, 11, 13, 15};
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