#include <iostream>
using namespace std;

void intercala(int p, int q, int r, int v[], int& inversions) {
    int n1 = q - p + 1;
    int n2 = r - q;

    int left[n1], right[n2];

    for (int i = 0; i < n1; i++)
        left[i] = v[p + i];
    for (int j = 0; j < n2; j++)
        right[j] = v[q + 1 + j];

    int i = 0, j = 0, k = p;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            v[k++] = left[i++];
        } else {
            v[k++] = right[j++];
            inversions += (n1 - i);
        }
    }

    while (i < n1) {
        v[k++] = left[i++];
    }

    while (j < n2) {
        v[k++] = right[j++];
    }
}

void mergesort(int p, int r, int v[], int& inversions) {
    if (p < r) {
        int q = (p + r) / 2;
        mergesort(p, q, v, inversions);
        mergesort(q + 1, r, v, inversions);
        intercala(p, q, r, v, inversions);
    }
}

int countInversions(int v[], int n) {
    int inversions = 0;
    mergesort(0, n - 1, v, inversions);
    return inversions;
}

int main() {
    int v[] = {111,999,222,999,333,888,444,777,5555,666,555};
    int n = sizeof(v) / sizeof(v[0]);

    int inversions = countInversions(v, n);

    cout << "Numero de inversiones: " << inversions << endl;

    return 0;
}

