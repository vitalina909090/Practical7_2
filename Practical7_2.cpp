#include <iostream>
#include <Windows.h>
using namespace std;

template<typename T>
class Matrix {
private:
    int rows;
    int cols;
    T** mas;

public:
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        mas = new T * [rows];
        for (int i = 0; i < rows; i++) {
            mas[i] = new T[cols];
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] mas[i];
        }
        delete[] mas;
    }

    void input() {
        cout << "Введіть елементи матриці (" << rows << "x" << cols << "):" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << "Елемент [" << i << "][" << j << "]: ";
                cin >> mas[i][j];
            }
        }
    }

    void print() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << mas[i][j] << " ";
            }
            cout << endl;
        }
    }

    T findMax() const {
        T maxVal = mas[0][0];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (mas[i][j] > maxVal) {
                    maxVal = mas[i][j];
                }
            }
        }
        return maxVal;
    }

    T findMin() const {
        T minVal = mas[0][0];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (mas[i][j] < minVal) {
                    minVal = mas[i][j];
                }
            }
        }
        return minVal;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Matrix<int> mat(2, 2);

    mat.input();

    cout << "Матриця:" << endl;
    mat.print();

    cout << "Максимальний елемент: " << mat.findMax() << endl;
    cout << "Мінімальний елемент: " << mat.findMin() << endl;

    return 0;
}
