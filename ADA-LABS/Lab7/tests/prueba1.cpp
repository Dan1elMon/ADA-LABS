#include <iostream>
using namespace std;

int sep(int v[], int p, int r) {
    int i = p, j = r;
    int q = v[(p + r) / 2]; // Cambio en la selección del pivote

    do {
        while (v[i] < q) // Cambio en la condición
            ++i;
        while (v[j] > q) // Cambio en la condición
            --j;

        if (i <= j) {
            int t = v[i];
            v[i] = v[j];
            v[j] = t;
            ++i;
            --j;
        }
    } while (i <= j);

    return i;
}

void quicksort(int v[], int p, int r) {
    if (p < r) {
        int q = sep(v, p, r);
        quicksort(v, p, q - 1);
        quicksort(v, q, r);
    }
}

int main() {
    int v[] = {66,55,44,33,22,11};
    int n = sizeof(v) / sizeof(v[0]);

    quicksort(v, 0, n - 1);

    cout << "Arreglo ordenado: ";
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}
