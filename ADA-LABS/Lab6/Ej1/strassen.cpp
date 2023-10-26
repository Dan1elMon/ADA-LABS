#include <iostream>
using namespace std;
//definir estructura para representar la matriz 2x2
struct Matrix {
    int m[2][2];
};
//suma de matrices
Matrix add(Matrix A, Matrix B) {
    Matrix C;
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            C.m[i][j] = A.m[i][j] + B.m[i][j];
    return C;
}
//resta de matrices
Matrix subtract(Matrix A, Matrix B) {
    Matrix C;
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            C.m[i][j] = A.m[i][j] - B.m[i][j];
    return C;
}
// multiplicando con strassen
Matrix strassen(Matrix A, Matrix B) {
    Matrix C;

    int m1 = (A.m[0][0] + A.m[1][1]) * (B.m[0][0] + B.m[1][1]);
    int m2 = (A.m[1][0] + A.m[1][1]) * B.m[0][0];
    int m3 = A.m[0][0] * (B.m[0][1] - B.m[1][1]);
    int m4 = A.m[1][1] * (B.m[1][0] - B.m[0][0]);
    int m5 = (A.m[0][0] + A.m[0][1]) * B.m[1][1];
    int m6 = (A.m[1][0] - A.m[0][0]) * (B.m[0][0] + B.m[0][1]);
    int m7 = (A.m[0][1] - A.m[1][1]) * (B.m[1][0] + B.m[1][1]);

    C.m[0][0] = m1 + m4 - m5 + m7;
    C.m[0][1] = m3 + m5;
    C.m[1][0] = m2 + m4;
    C.m[1][1] = m1 - m2 + m3 + m6;

    return C;
}
//imprimir matriz
void printMatrix(Matrix M) {
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            cout << M.m[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    Matrix A = {{{1, 3}, {5, 7}}};
    Matrix B = {{{8, 4}, {6, 2}}};

    Matrix C = strassen(A,  B);

    cout << "Resultado de la multiplicacion:" << endl;
    printMatrix(C);

    return 0;
}