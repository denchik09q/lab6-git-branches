#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    setlocale(LC_ALL, "Ukrainian");

    const int N = 12;
    int A[N] = { 4, 3, 6, 8, 5, 10, 15, 20, 2, 7, 9, 12 };
    double C[N];

    cout << "Початковий масив A:\n";
    int i = 0;
    while (i < N) {
        cout << setw(5) << A[i];
        i++;
    }
    cout << endl;

    int oddCount = 0, secondOddIndex = -1, secondOddValue = 0;
    for (int j = 0; j < N; j++) {
        if (A[j] % 2 != 0) {
            oddCount++;
            if (oddCount == 2) {
                secondOddIndex = j;
                secondOddValue = A[j];
                break;
            }
        }
    }

    if (secondOddIndex == -1) {
        cout << "Помилка: у масиві менше двох непарних елементів!" << endl;
    }
    else {
        int cSize = 0;
        for (int j = secondOddIndex; j < N; j++) {
            C[cSize++] = (double)A[j] / secondOddValue;
        }

        cout << "Форматований масив C (ділення на " << secondOddValue << "):\n";
        cout << fixed << setprecision(2);
        int k = 0;
        while (k < cSize) {
            cout << setw(7) << C[k];
            k++;
        }
        cout << endl;
    }

    return 0;
}