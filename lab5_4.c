#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int MAX_SIZE = 10;
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int n) {
    cout << "Введіть елементи матриці " << n << "x" << n << ":\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
}
void randomMatrix(int matrix[MAX_SIZE][MAX_SIZE], int n, int minVal = 1, int maxVal = 100) {
    srand(time(0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matrix[i][j] = rand() % (maxVal - minVal + 1) + minVal;
}
void printMatrixByIndex(int matrix[MAX_SIZE][MAX_SIZE], int n) {
    cout << "Матриця (доступ через індекси):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << "\t";
        cout << endl;
    }
}
void printMatrixByPointer(int matrix[MAX_SIZE][MAX_SIZE], int n) {
    cout << "Матриця (доступ через вказівники):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << *(*(matrix + i) + j) << "\t";
        cout << endl;
    }
}
bool isMagicSquare(int matrix[MAX_SIZE][MAX_SIZE], int n) {
    int magicSum = 0;
    for (int j = 0; j < n; j++)
        magicSum += matrix[0][j];
    for (int i = 1; i < n; i++) {
        int rowSum = 0;
        for (int j = 0; j < n; j++)
            rowSum += matrix[i][j];
        if (rowSum != magicSum)
            return false;
    }
    for (int j = 0; j < n; j++) {
        int colSum = 0;
        for (int i = 0; i < n; i++)
            colSum += matrix[i][j];
        if (colSum != magicSum)
            return false;
    }
    return true;
}
int main() {
    int n;
    cout << "Введіть розмір квадратної матриці (n x n, n <= " << MAX_SIZE << "): ";
    cin >> n;
    int matrix[MAX_SIZE][MAX_SIZE];
    int choice;
    cout << "Оберіть спосіб формування матриці:\n1 - введення з клавіатури\n2 - випадкова генерація\n";
    cin >> choice;
    if (choice == 1)
        inputMatrix(matrix, n);
    else
        randomMatrix(matrix, n);
    printMatrixByIndex(matrix, n);
    printMatrixByPointer(matrix, n);
    if (isMagicSquare(matrix, n))
        cout << "Це магічний квадрат!\n";
    else
        cout << "Це не магічний квадрат.\n";
    return 0;
}
