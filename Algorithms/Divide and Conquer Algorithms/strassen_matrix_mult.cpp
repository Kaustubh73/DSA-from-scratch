#include <iostream>
#include <vector>

using namespace std;

// Function to add two vectors element-wise
vector<vector<int>> addVectors(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    return C;
}

// Function to subtract two vectors element-wise
vector<vector<int>> subtractVectors(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }

    return C;
}

// Function to multiply two matrices using Strassen's algorithm
vector<vector<int>> strassenMultiply(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();

    // Base case: If the matrix size is 1x1
    if (n == 1) {
        return {{A[0][0] * B[0][0]}};
    }

    // Create submatrices for division
    int halfSize = n / 2;
    vector<vector<int>> A11(halfSize, vector<int>(halfSize));
    vector<vector<int>> A12(halfSize, vector<int>(halfSize));
    vector<vector<int>> A21(halfSize, vector<int>(halfSize));
    vector<vector<int>> A22(halfSize, vector<int>(halfSize));
    vector<vector<int>> B11(halfSize, vector<int>(halfSize));
    vector<vector<int>> B12(halfSize, vector<int>(halfSize));
    vector<vector<int>> B21(halfSize, vector<int>(halfSize));
    vector<vector<int>> B22(halfSize, vector<int>(halfSize));

    // Divide matrices into submatrices
    for (int i = 0; i < halfSize; i++) {
        for (int j = 0; j < halfSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + halfSize];
            A21[i][j] = A[i + halfSize][j];
            A22[i][j] = A[i + halfSize][j + halfSize];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + halfSize];
            B21[i][j] = B[i + halfSize][j];
            B22[i][j] = B[i + halfSize][j + halfSize];
        }
    }

    // Recursive calls for submatrix multiplication
    vector<vector<int>> P1 = strassenMultiply(A11, subtractVectors(B12, B22));
    vector<vector<int>> P2 = strassenMultiply(addVectors(A11, A12), B22);
    vector<vector<int>> P3 = strassenMultiply(addVectors(A21, A22), B11);
    vector<vector<int>> P4 = strassenMultiply(A22, subtractVectors(B21, B11));
    vector<vector<int>> P5 = strassenMultiply(addVectors(A11, A22), addVectors(B11, B22));
    vector<vector<int>> P6 = strassenMultiply(subtractVectors(A12, A22), addVectors(B21, B22));
    vector<vector<int>> P7 = strassenMultiply(subtractVectors(A11, A21), addVectors(B11, B12));

    // Compute quadrants of the resulting matrix
    vector<vector<int>> C11 = subtractVectors(addVectors(addVectors(P5, P4), P6), P2);
    vector<vector<int>> C12 = addVectors(P1, P2);
    vector<vector<int>> C21 = addVectors(P3, P4);
    vector<vector<int>> C22 = subtractVectors(subtractVectors(addVectors(P5, P1), P3), P7);

    // Combine quadrants to assemble the final matrix
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < halfSize; i++) {
        for (int j = 0; j < halfSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + halfSize] = C12[i][j];
            C[i + halfSize][j] = C21[i][j];
            C[i + halfSize][j + halfSize] = C22[i][j];
        }
    }

    return C;
}

// Function to print a matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
}

int main() {
    // Example usage
    vector<vector<int>> A = {{1, 2}, {3, 4}};
    vector<vector<int>> B = {{5, 6}, {7, 8}};

    cout << "Matrix A:" << endl;
    printMatrix(A);
    cout << endl;

    cout << "Matrix B:" << endl;
    printMatrix(B);
    cout << endl;

    vector<vector<int>> C = strassenMultiply(A, B);

    cout << "Matrix C (Result):" << endl;
    printMatrix(C);

    return 0;
}
