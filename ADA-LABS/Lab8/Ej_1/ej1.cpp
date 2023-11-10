#include <iostream>
using namespace std;

void intercambia(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

static void construyeHeap(int m, int v[]) {
    for (int k = 1; k < m; ++k) {
        int f = k + 1;
        while (f > 1 && v[f/2] < v[f]) {
            intercambia(v[f/2], v[f]);
            f /= 2;
        }
    }
}

static void criba(int m, int v[]) {
    int f = 2;
    while (f <= m) {
        if (f < m && v[f] < v[f+1]) ++f;
        if (v[f/2] >= v[f]) break;
        intercambia(v[f/2], v[f]);
        f *= 2;
    }
}

void heapsort(int n, int v[]) {
    construyeHeap(n, v);
    for (int m = n; m >= 2; --m) {
        intercambia(v[1], v[m]);
        criba(m-1, v);
    }
}

int main() {
    int v[] = {0, 5, 3, 1, 6, 4, 2};
    int n = sizeof(v) / sizeof(v[0]) - 1;

    heapsort(n, v);

    cout << "Arreglo ordenado: ";
    for (int i = 1; i <= n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}
