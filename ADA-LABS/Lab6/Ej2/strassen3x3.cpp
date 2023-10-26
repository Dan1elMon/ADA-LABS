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
Matrix multiply2x2(Matrix A, Matrix B) {
    Matrix C;
    C.m[0][0] = A.m[0][0] * B.m[0][0] + A.m[0][1] * B.m[1][0];
    C.m[0][1] = A.m[0][0] * B.m[0][1] + A.m[0][1] * B.m[1][1];
    C.m[1][0] = A.m[1][0] * B.m[0][0] + A.m[1][1] * B.m[1][0];
    C.m[1][1] = A.m[1][0] * B.m[0][1] + A.m[1][1] * B.m[1][1];
    return C;
}
Matrix strassen(Matrix A, Matrix B) {
    
    Matrix A11, A12, A21, A22, B11, B12, B21, B22;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            A11.m[i][j] = A.m[i][j];
            A12.m[i][j] = A.m[i][j+2];
            A21.m[i][j] = A.m[i+2][j];
            A22.m[i][j] = A.m[i+2][j+2];
           
            B11.m[i][j] = B.m[i][j];
            B12.m[i][j] = B.m[i][j+2];
            B21.m[i][j] = B.m[i+2][j];
            B22.m[i][j] = B.m[i+2][j+2];
        }
    }
    
    Matrix C11 = add(multiply2x2(A11, B11), multiply2x2(A12, B21));
    Matrix C12 = add(multiply2x2(A11, B12), multiply2x2(A12, B22));
    Matrix C21 = add(multiply2x2(A21, B11), multiply2x2(A22, B21));
    Matrix C22 = add(multiply2x2(A21, B12), multiply2x2(A22, B22));


    
    Matrix C;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            C.m[i][j] = C11.m[i][j];
            C.m[i][j+2] = C12.m[i][j];
            C.m[i+2][j] = C21.m[i][j];
            C.m[i+2][j+2] = C22.m[i][j];
        }
    }
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
    cout << "Resultado de la multiplicacion:" << endl;
    printMatrix(C);
    return 0;
}
