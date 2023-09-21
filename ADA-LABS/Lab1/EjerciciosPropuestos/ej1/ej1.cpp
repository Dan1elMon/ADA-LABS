#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Ingrese la cantidad de elementos: ";
    cin >> n;

    if (n <= 0) {
        cout << "La cantidad de elementos debe ser mayor que 0." << endl;
        return 1;
    }

    int arr[n];

    int multiplicacion = 1;
    for (int i = 0; i < n; i++) {
        cout << "Ingrese el elemento " << i + 1 << ": ";
        cin >> arr[i];
        multiplicacion *= arr[i];
    }

    cout << "El resultado de la multiplicación es: " << multiplicacion << endl;

    return 0;
}
