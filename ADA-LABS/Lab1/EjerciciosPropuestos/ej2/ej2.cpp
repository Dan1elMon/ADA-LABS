#include <iostream>
using namespace std;

int main() {
    const int MAX_ELEMENTOS = 100;
    int numeros[MAX_ELEMENTOS];
    int n;

    cout << "Ingrese la cantidad de elementos: ";
    cin >> n;

    if (n <= 0 || n > MAX_ELEMENTOS) {
        cout << "La cantidad de elementos debe ser mayor que 0 y menor o igual a " << MAX_ELEMENTOS << "." << endl;
        return 1;
    }

    for (int i = 0; i < n; i++) {
        cout << "Ingrese el elemento " << i << ": ";
        cin >> numeros[i];
    }

    for (int i = 0; i < n; i++) {
        cout << i << " -> " << numeros[i] << endl;
    }

    return 0;
}
