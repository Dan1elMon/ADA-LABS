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

    cout << "El array en orden inverso es: ";
    for (int i = n - 1; i >= 0; i--) {
        cout << numeros[i];
        if (i != 0) {
            cout << ",";
        }
    }
    cout << endl;

    return 0;
}
