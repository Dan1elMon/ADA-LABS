#include <iostream>
using namespace std;

void merge(int v[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = v[p + i];
    for (int j = 0; j < n2; j++)
        R[j] = v[q + 1 + j];

    int i = 0, j = 0, k = p;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            v[k] = L[i];
            i++;
        } else {
            v[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        v[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        v[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int v[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;

        mergeSort(v, p, q);
        mergeSort(v, q + 1, r);

        merge(v, p, q, r);
    }
}

int main() {
    int v[] = {3, 2, 6, 5, 4, 1};
    int n = sizeof(v) / sizeof(v[0]);

    mergeSort(v, 0, n - 1);

    cout << "Arreglo ordenado: ";
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}
