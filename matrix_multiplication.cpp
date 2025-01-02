#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

const int MAX = 2;

void add(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtract(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void strassen(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int size) {
    if (size == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = size / 2;
    int A11[MAX][MAX], A12[MAX][MAX], A21[MAX][MAX], A22[MAX][MAX];
    int B11[MAX][MAX], B12[MAX][MAX], B21[MAX][MAX], B22[MAX][MAX];
    int C11[MAX][MAX], C12[MAX][MAX], C21[MAX][MAX], C22[MAX][MAX];
    int M1[MAX][MAX], M2[MAX][MAX], M3[MAX][MAX], M4[MAX][MAX], M5[MAX][MAX], M6[MAX][MAX], M7[MAX][MAX];
    int temp1[MAX][MAX], temp2[MAX][MAX];

    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // M1 = (A11 + A22) * (B11 + B22)
    add(A11, A22, temp1, newSize);
    add(B11, B22, temp2, newSize);
    strassen(temp1, temp2, M1, newSize);

    // M2 = (A21 + A22) * B11
    add(A21, A22, temp1, newSize);
    strassen(temp1, B11, M2, newSize);

    // M3 = A11 * (B12 - B22)
    subtract(B12, B22, temp2, newSize);
    strassen(A11, temp2, M3, newSize);

    // M4 = A22 * (B21 - B11)
    subtract(B21, B11, temp2, newSize);
    strassen(A22, temp2, M4, newSize);

    // M5 = (A11 + A12) * B22
    add(A11, A12, temp1, newSize);
    strassen(temp1, B22, M5, newSize);

    // M6 = (A21 - A11) * (B11 + B12)
    subtract(A21, A11, temp1, newSize);
    add(B11, B12, temp2, newSize);
    strassen(temp1, temp2, M6, newSize);

    // M7 = (A12 - A22) * (B21 + B22)
    subtract(A12, A22, temp1, newSize);
    add(B21, B22, temp2, newSize);
    strassen(temp1, temp2, M7, newSize);

    // C11 = M1 + M4 - M5 + M7
    add(M1, M4, temp1, newSize);
    subtract(temp1, M5, temp2, newSize);
    add(temp2, M7, C11, newSize);

    // C12 = M3 + M5
    add(M3, M5, C12, newSize);

    // C21 = M2 + M4
    add(M2, M4, C21, newSize);

    // C22 = M1 - M2 + M3 + M6
    subtract(M1, M2, temp1, newSize);
    add(temp1, M3, temp2, newSize);
    add(temp2, M6, C22, newSize);

    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }
}

int main() {
    int A[MAX][MAX]= {{10,25},{5,12}};
    int B[MAX][MAX] = {{12,32},{12,33}} ;
    int C[MAX][MAX] = {0};
    strassen(A , B , C , MAX);
    for(int i = 0 ; i<MAX;i++)
    {
        for(int j = 0 ; j<MAX; j ++){
            cout<<C[i][j]<<"  ";
        }
        cout <<endl;
    }

    return 0;
}
