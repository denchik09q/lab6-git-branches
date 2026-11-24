#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Ukrainian");

    // 1. Ініціалізація масиву в коді (вимога п. 7)
    const int N = 12;
    int A[N] = { 4, 2, 6, 8, 5, 10, 16, 20, 2, 4, 8, 12 };
    double C[N];

    cout << "Початковий масив A: ";
    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    // 2. Пошук другого непарного елемента
    int oddCount = 0;
    int secondOddIndex = -1;
    int secondOddValue = 0;

    for (int i = 0; i < N; i++) {
        if (A[i] % 2 != 0) {
            oddCount++;
            if (oddCount == 2) {
                secondOddIndex = i;
                secondOddValue = A[i];
                break;
            }
        }
    }

    // 3. Перевірка умови та формування масиву C
    if (secondOddIndex == -1) {
        cout << "Помилка: у масиві менше двох непарних елементів!" << endl;
    }
    else {
        int cSize = 0;
        for (int i = secondOddIndex; i < N; i++) {
            C[cSize] = (double)A[i] / secondOddValue;
            cSize++;
        }

        cout << "Новоутворений масив C (ділення на " << secondOddValue << "): ";
        for (int i = 0; i < cSize; i++) {
            cout << C[i] << " ";
        }
        cout << endl;
    }

    return 0;
}