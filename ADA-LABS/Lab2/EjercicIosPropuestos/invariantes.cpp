#include <iostream>
using namespace std;

int busquedaBinaria(int x, int n, int v[]) {
    if (v[n-1] < x) return n;
    if (x <= v[0]) return 0;

    int i = 0, d = n - 1;

    while (i <= d) {
        int m = (i + d + 1) / 2;
        if (v[m] < x)
            i = m + 1;
        else
            d = m - 1;
    }

    return i;
}

/*
int busquedaBinaria(int x, int n, int v[]) {
    if (v[n-1] < x) return n;
    if (x <= v[0]) return 0;

    int i = 0, d = n - 1;

    while (i <= d) {
        int m = (i + d + 1) / 2;
        if (v[m] <= x)
            i = m + 1;
        else
            d = m - 1;
    }

    return i;
}

*/

/*
int busquedaBinaria(int x, int n, int v[]) {
    if (v[n-1] < x) return n;
    if (x <= v[0]) return 0;

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
*/
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