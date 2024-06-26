﻿#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int sumOfPositiveEvenElements(const vector<vector<int>>& matrix) {
    int sum = 0;
    for (const auto& row : matrix) {
        for (int element : row) {
            if (element > 0 && element % 2 == 0) {
                sum += element;
            }
        }
    }
    return sum;
}
void replaceMatrixWithIdentity(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = (i == j) ? 1 : 0;
        }
    }
}
int main() {
    setlocale(LC_ALL, "Rus");
    ifstream inFile("input.txt");
    ofstream outFile1("output1.txt");
    ofstream outFile2("output2.txt");
    int k, m, n;
    inFile >> k;
    cout << "Количество матриц: " << k << endl;
    for (int matrixNum = 0; matrixNum < k; ++matrixNum) {
        inFile >> m >> n;
        cout << "Матрица " << matrixNum + 1 << ": размер " << m << "x" << n << endl;
        vector<vector<int>> matrix(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                inFile >> matrix[i][j];
            }
        }
        cout << "Содержимое матрицы " << matrixNum + 1 << ":" << endl;
        for (const auto& row : matrix) {
            for (int element : row) {
                cout << element << " ";
            }
            cout << endl;
        }
        int sum = sumOfPositiveEvenElements(matrix);
        cout << "Сумма положительных четных элементов матрицы " << matrixNum + 1 << ": " << sum << endl;
        if (sum % 2 == 0) {
            replaceMatrixWithIdentity(matrix);
            for (const auto& row : matrix) {
                for (int element : row) {
                    outFile2 << element << " ";
                }
                outFile2 << endl;
            }
        }
        else {
            for (const auto& row : matrix) {
                for (int element : row) {
                    outFile1 << element << " ";
                }
                outFile1 << endl;
            }
        }
    }
    inFile.close();
    outFile1.close();
    outFile2.close();
    return 0;
}