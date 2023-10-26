#include <iostream>
using namespace std;

struct Matrix {
    int m[8][8];
};

Matrix add(Matrix A, Matrix B) {
    Matrix C;
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            C.m[i][j] = A.m[i][j] + B.m[i][j];
    return C;
}

Matrix subtract(Matrix A, Matrix B) {
    Matrix C;
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            C.m[i][j] = A.m[i][j] - B.m[i][j];
    return C;
}

Matrix multiply2x2(Matrix A, Matrix B) {
    Matrix C;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            C.m[i][j] = 0;
            for(int k = 0; k < 8; k++) {
                C.m[i][j] += A.m[i][k] * B.m[k][j];
            }
        }
    }
    return C;
}

Matrix strassen(Matrix A, Matrix B) {
    if(A.m[0][0] < 8) {
        return multiply2x2(A, B);
    }

    Matrix A11, A12, A21, A22, B11, B12, B21, B22;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            A11.m[i][j] = A.m[i][j];
            A12.m[i][j] = A.m[i][j+4];
            A21.m[i][j] = A.m[i+4][j];
            A22.m[i][j] = A.m[i+4][j+4];
            
            B11.m[i][j] = B.m[i][j];
            B12.m[i][j] = B.m[i][j+4];
            B21.m[i][j] = B.m[i+4][j];
            B22.m[i][j] = B.m[i+4][j+4];
        }
    }

    Matrix S1 = subtract(B12, B22);
    Matrix S2 = add(A11, A12);
    Matrix S3 = add(A21, A22);
    Matrix S4 = subtract(B21, B11);
    Matrix S5 = add(A11, A22);
    Matrix S6 = add(B11, B22);
    Matrix S7 = subtract(A12, A22);
    Matrix S8 = add(B21, B22);
    Matrix S9 = subtract(A11, A21);
    Matrix S10 = add(B11, B12);

    Matrix P1 = strassen(A11, S1);
    Matrix P2 = strassen(S2, B22);
    Matrix P3 = strassen(S3, B11);
    Matrix P4 = strassen(A22, S4);
    Matrix P5 = strassen(S5, S6);
    Matrix P6 = strassen(S7, S8);
    Matrix P7 = strassen(S9, S10);

    Matrix C11 = add(subtract(add(P5, P4), P2), P6);
    Matrix C12 = add(P1, P2);
    Matrix C21 = add(P3, P4);
    Matrix C22 = subtract(subtract(add(P5, P1), P3), P7);

    Matrix C;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            C.m[i][j] = C11.m[i][j];
            C.m[i][j+4] = C12.m[i][j];
            C.m[i+4][j] = C21.m[i][j];
            C.m[i+4][j+4] = C22.m[i][j];
        }
    }

    return C;
}

void printMatrix(Matrix M) {
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            cout << M.m[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {

    // Inicializa tus matrices A y B aquí
Matrix A = {{{1, 5, 0, 0, 0, 0, 0, 0},
            {2, 4, 0, 0, 0, 0, 0, 0},
            {7, 9, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0}}};

Matrix B = {{{1, 2, 3, 4, 5, 0, 0, 0},
            {6, 7, 8, 9, 1, 0, 0, 0},
            {2, 3, 4, 5, 5, 0, 0, 0},
            {7, 8, 9, 1, 2, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0}}};

    Matrix C = strassen(A, B);

    cout << "Resultado de la multiplicacion:" << endl;
    printMatrix(C);

    return 0;
}
