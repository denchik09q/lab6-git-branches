#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Ukrainian");

    int n;
    cout << "Введіть кількість елементів масиву A: ";
    cin >> n;

    int* A = new int[n];
    double* C = new double[n];

    cout << "Введіть " << n << " цілих чисел через пробіл: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int oddCount = 0, secondOddIndex = -1, secondOddValue = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] % 2 != 0) {
            oddCount++;
            if (oddCount == 2) {
                secondOddIndex = i;
                secondOddValue = A[i];
                break;
            }
        }
    }

    if (secondOddIndex == -1) {
        cout << "Помилка: у масиві менше двох непарних елементів!" << endl;
    } else {
        int cSize = 0;
        for (int i = secondOddIndex; i < n; i++) {
            C[cSize++] = (double)A[i] / secondOddValue;
        }
        cout << "Новоутворений масив C (ділення на " << secondOddValue << "): ";
        for (int i = 0; i < cSize; i++) {
            cout << C[i] << " ";
        }
        cout << endl;
    }

    delete[] A;
    delete[] C;
    return 0;
}
