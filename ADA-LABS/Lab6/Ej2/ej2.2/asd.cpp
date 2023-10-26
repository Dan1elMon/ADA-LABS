#include <iostream>
using namespace std;

struct Matrix {
    int m[4][4];
};

Matrix add(Matrix A, Matrix B) {
    Matrix C;
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            C.m[i][j] = A.m[i][j] + B.m[i][j];
    return C;
}

Matrix subtract(Matrix A, Matrix B) {
    Matrix C;
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            C.m[i][j] = A.m[i][j] - B.m[i][j];
    return C;
}

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

    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            C.m[i][j] = A.m[i][j] + B.m[i][j];
    
    for(int i = 2; i < 4; i++)
        for(int j = 0; j < 2; j++)
            C.m[i][j] = A.m[i][j] + B.m[i][j];

    for(int i = 0; i < 2; i++)
        for(int j = 2; j < 4; j++)
            C.m[i][j] = A.m[i][j] + B.m[i][j];

    for(int i = 2; i < 4; i++)
        for(int j = 2; j < 4; j++)
            C.m[i][j] = A.m[i][j] + B.m[i][j];

    return C;
}

void printMatrix(Matrix M) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            cout << M.m[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    Matrix A = {{{7, 6, 9, 4}, {8, 5, 3, 2}, {7, 7, 9, 9}, {4, 3, 8, 5}}};
    Matrix B = {{{3, 2, 9, 5}, {7, 5, 6, 4}, {4, 6, 9, 1}, {9, 3, 8, 7}}};
    
    Matrix C = strassen(A, B);

    cout << "Resultado de la multiplicación:" << endl;
    printMatrix(C);

    return 0;
}
