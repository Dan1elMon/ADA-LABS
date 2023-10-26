#include <iostream>
using namespace std;

struct Matrix {
    int m[3][2];
};

struct Matrix2 {
    int m[4][5];
};

Matrix2 multiply(Matrix A, Matrix2 B) {
    Matrix2 C;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 5; j++) {
            C.m[i][j] = 0;
            for(int k = 0; k < 2; k++) {
                C.m[i][j] += A.m[i][k] * B.m[k][j];
            }
        }
    }

    return C;
}

void printMatrix(Matrix2 M) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 5; j++) {
            cout << M.m[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    Matrix A = {{{1, 5}, {2, 4}, {7, 9}}};
    Matrix2 B = {{{1, 2, 3, 4, 5}, {6, 7, 8, 9, 1}, {2, 3, 4, 5, 5}, {7, 8, 9, 1, 2}}};

    Matrix2 C = multiply(A, B);

    cout << "Resultado de la multiplicacion:" << endl;
    printMatrix(C);

    return 0;
}
