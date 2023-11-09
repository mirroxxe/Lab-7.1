#include <iostream>
#include <iomanip>
#include <ctime>
#include <algorithm>
using namespace std;

void Create(int a[][6], const int Rows, const int ColCount, const int Low, const int High);
void Print(int a[][6], const int Rows, const int ColCount);
void Sort(int a[][6], const int Rows, const int ColCount);
void Calc(int a[][6], const int Rows, const int ColCount, int& S, int& k);

int main() {
    srand((unsigned)time(NULL));
    const int Rows = 7;
    const int ColCount = 6;
    int Low = 9;
    int High = 61;
    int a[Rows][ColCount];

    Create(a, Rows, ColCount, Low, High);
    cout << "Original Matrix:" << endl;
    Print(a, Rows, ColCount);
    Sort(a, Rows, ColCount);
    cout << "Sorted Matrix:" << endl;
    Print(a, Rows, ColCount);
    cout << "Modified Matrix:" << endl;
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < ColCount; j++) {
            int value = (a[i][j] % 2 == 1 || (i + j) % 7 == 0) ? 0 : 1;
            if (a[i][j] == 0) {
                value = 1; 
            }
            cout << setw(4) << value;
        }
        cout << endl;
    }

    int S = 0;
    int k = 0;
    Calc(a, Rows, ColCount, S, k);
    cout << "S = " << S << endl;
    cout << "k = " << k << endl;

    return 0;
}

void Create(int a[][6], const int Rows, const int ColCount, const int Low, const int High) {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < ColCount; j++) {
            a[i][j] = Low + rand() % (High - Low + 1);
        }
    }
}

void Print(int a[][6], const int Rows, const int ColCount) {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < ColCount; j++) {
            cout << setw(4) << a[i][j];
        }
        cout << endl;
    }
}

void Sort(int a[][6], const int Rows, const int ColCount) {
    for (int i = 0; i < Rows; i++) {
        sort(a[i], a[i] + ColCount);
    }

    int b[6][7]{};
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < ColCount; j++) {
            b[j][i] = a[i][j];
        }
    }

    for (int i = 0; i < ColCount; i++) {
        sort(b[i], b[i] + Rows);
    }

    for (int i = 0; i < ColCount; i++) {
        for (int j = 0; j < Rows; j++) {
            a[j][i] = b[i][j];
        }
    }
}

void Calc(int a[][6], const int Rows, const int ColCount, int& S, int& k) {
    S = 0;
    k = 0;
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < ColCount; j++) {
            if (a[i][j] % 2 == 0 && (i + j) % 7 != 0) {
                S += a[i][j];
                k++;
                a[i][j] = 0;
            }
        }
    }
}
