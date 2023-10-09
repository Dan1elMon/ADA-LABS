#include <iostream>
#include <cstdlib>

void insertionsort(int n, int v[]) {
    for (int j = 1; j < n; ++j) {
        int x = v[j];
        int i;
        for (i = j - 1; i >= 0 && v[i] > x; --i) {
            v[i + 1] = v[i];
        }
        v[i + 1] = x;
    }
}

int main() {
    const int size = 5;
    int numbers[size];

    // Generar 5 números aleatorios entre 1 y 36
    for (int i = 0; i < size; ++i) {
        numbers[i] = rand() % 36 + 1;
    }

    std::cout << "Arreglo original: ";
    for (int i = 0; i < size; ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    insertionsort(size, numbers);

    std::cout << "Arreglo ordenado: ";
    for (int i = 0; i < size; ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}