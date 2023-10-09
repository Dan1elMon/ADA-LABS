#include <iostream>
using namespace std;



void recursiveInsertionSort(int arr[], int n) {
    if (n <= 1) return;

    recursiveInsertionSort(arr, n-1);

    int last = arr[n-1];
    int j = n - 2;

    while (j >= 0 && arr[j] > last) {
        arr[j+1] = arr[j];
        j--;
    }

    arr[j+1] = last;
}

int main() {
    int arr[] = {9, 5, 3, 7, 1, 8, 2, 6, 10, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Arreglo original: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    recursiveInsertionSort(arr, n);

    cout << "Arreglo ordenado (recursivo): ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int arr2[] = {9, 5, 3, 7, 1, 8, 2, 6, 10, 4};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);


    cout << endl;

    return 0;
}