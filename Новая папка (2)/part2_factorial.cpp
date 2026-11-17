#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

const int MAX_SIZE = 10;

// =========================================================
// 1. Ініціалізація квадратної матриці (int, double, char)
// =========================================================
void initMatrix(int matrix[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 90 + 10; // Цілі числа [10; 99]
        }
    }
}

void initMatrix(double matrix[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = (rand() % 900 + 100) / 10.0; // Дробові числа [10.0; 99.9]
        }
    }
}

void initMatrix(char matrix[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = static_cast<char>('A' + rand() % 26); // Великі латинські літери
        }
    }
}

// =========================================================
// 2. Вивід матриці на екран (int, double, char)
// =========================================================
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << '\n';
    }
}

void printMatrix(const double matrix[MAX_SIZE][MAX_SIZE], int n) {
    cout << fixed << setprecision(1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(7) << matrix[i][j];
        }
        cout << '\n';
    }
}

void printMatrix(const char matrix[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(4) << matrix[i][j];
        }
        cout << '\n';
    }
}

// =========================================================
// 3. Мінімум та максимум на головній діагоналі (int, double, char)
// =========================================================
void findDiagonalMinMax(const int matrix[MAX_SIZE][MAX_SIZE], int n, int& minVal, int& maxVal) {
    minVal = matrix[0][0];
    maxVal = matrix[0][0];
    for (int i = 1; i < n; i++) {
        if (matrix[i][i] < minVal) minVal = matrix[i][i];
        if (matrix[i][i] > maxVal) maxVal = matrix[i][i];
    }
}

void findDiagonalMinMax(const double matrix[MAX_SIZE][MAX_SIZE], int n, double& minVal, double& maxVal) {
    minVal = matrix[0][0];
    maxVal = matrix[0][0];
    for (int i = 1; i < n; i++) {
        if (matrix[i][i] < minVal) minVal = matrix[i][i];
        if (matrix[i][i] > maxVal) maxVal = matrix[i][i];
    }
}

void findDiagonalMinMax(const char matrix[MAX_SIZE][MAX_SIZE], int n, char& minVal, char& maxVal) {
    minVal = matrix[0][0];
    maxVal = matrix[0][0];
    for (int i = 1; i < n; i++) {
        if (matrix[i][i] < minVal) minVal = matrix[i][i];
        if (matrix[i][i] > maxVal) maxVal = matrix[i][i];
    }
}

// =========================================================
// 4. Сортування за зростанням кожного рядка (int, double, char)
// =========================================================
void sortMatrixRows(int matrix[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            for (int k = 0; k < n - j - 1; k++) {
                if (matrix[i][k] > matrix[i][k + 1]) {
                    int temp = matrix[i][k];
                    matrix[i][k] = matrix[i][k + 1];
                    matrix[i][k + 1] = temp;
                }
            }
        }
    }
}

void sortMatrixRows(double matrix[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            for (int k = 0; k < n - j - 1; k++) {
                if (matrix[i][k] > matrix[i][k + 1]) {
                    double temp = matrix[i][k];
                    matrix[i][k] = matrix[i][k + 1];
                    matrix[i][k + 1] = temp;
                }
            }
        }
    }
}

void sortMatrixRows(char matrix[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            for (int k = 0; k < n - j - 1; k++) {
                if (matrix[i][k] > matrix[i][k + 1]) {
                    char temp = matrix[i][k];
                    matrix[i][k] = matrix[i][k + 1];
                    matrix[i][k + 1] = temp;
                }
            }
        }
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    srand(static_cast<unsigned int>(time(nullptr)));

    int n;
    cout << "Введіть розмір квадратної матриці N (від 2 до " << MAX_SIZE << "): ";
    cin >> n;

    if (n < 2 || n > MAX_SIZE) {
        cout << "Помилка: некоректний розмір матриці." << endl;
        return 1;
    }

    // --- 1. Робота з матрицею int ---
    int intMat[MAX_SIZE][MAX_SIZE];
    int intMin, intMax;
    initMatrix(intMat, n);
    cout << "\n=== Матриця INT ===\n";
    printMatrix(intMat, n);
    findDiagonalMinMax(intMat, n, intMin, intMax);
    cout << "Головна діагональ -> min: " << intMin << ", max: " << intMax << '\n';
    sortMatrixRows(intMat, n);
    cout << "Після сортування рядків за зростанням:\n";
    printMatrix(intMat, n);

    // --- 2. Робота з матрицею double ---
    double dblMat[MAX_SIZE][MAX_SIZE];
    double dblMin, dblMax;
    initMatrix(dblMat, n);
    cout << "\n=== Матриця DOUBLE ===\n";
    printMatrix(dblMat, n);
    findDiagonalMinMax(dblMat, n, dblMin, dblMax);
    cout << "Головна діагональ -> min: " << dblMin << ", max: " << dblMax << '\n';
    sortMatrixRows(dblMat, n);
    cout << "Після сортування рядків за зростанням:\n";
    printMatrix(dblMat, n);

    // --- 3. Робота з матрицею char ---
    char charMat[MAX_SIZE][MAX_SIZE];
    char charMin, charMax;
    initMatrix(charMat, n);
    cout << "\n=== Матриця CHAR ===\n";
    printMatrix(charMat, n);
    findDiagonalMinMax(charMat, n, charMin, charMax);
    cout << "Головна діагональ -> min: '" << charMin << "', max: '" << charMax << "'\n";
    sortMatrixRows(charMat, n);
    cout << "Після сортування рядків за зростанням:\n";
    printMatrix(charMat, n);

    return 0;
}