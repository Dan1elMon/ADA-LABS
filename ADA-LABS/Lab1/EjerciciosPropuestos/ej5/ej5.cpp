#include <iostream>
using namespace std;

int main() {
    const int MAX_ELEMENTOS = 100;
    int numeros[MAX_ELEMENTOS];
    int n;

    cout << "Ingrese la cantidad de elementos: ";
    cin >> n;

    if (n <= 1 || n > MAX_ELEMENTOS) {
        cout << "La cantidad de elementos debe ser mayor que 1 y menor o igual a " << MAX_ELEMENTOS << "." << endl;
        return 1;
    }

    for (int i = 0; i < n; i++) {
        cout << "Ingrese el elemento " << i << ": ";
        cin >> numeros[i];
    }

    for (int i = 0; i < n; i++) {
        int sumaResto = 0;
        for (int j = 0; j < n; j++) {
            if (j != i) {
                sumaResto += numeros[j];
            }
        }

        if (numeros[i] == sumaResto) {
            cout << numeros[i] << " equivale a la suma de los demás números." << endl;
            return 0;
        }
    }
    cout << "No hay ningún número que cumpla la condición." << endl;
    return 0;
}
