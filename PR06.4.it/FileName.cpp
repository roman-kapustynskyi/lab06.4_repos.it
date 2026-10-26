#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

void fillArray(double* arr, const int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = (rand() % 401) / 10.0 - 20.0;
    }
}

void printArray(const double* arr, const int n) {
    for (int i = 0; i < n; i++) {
        cout << setw(6) << arr[i];
    }
    cout << endl;
}

int findminIndex(const double* arr, const int n) {
    int minindex = 0;
    for (int i = 1; i < n; i++) {
        if (abs(arr[i]) < abs(arr[minindex])) {
            minindex = i;
        }
    }
    return minindex;
}

double findsumIndex(const double* arr, const int n) {
    double findsum = 0;
    int findmin = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            findmin = i;
            break;
        }
    }
    if (findmin != -1) {
        for (int i = findmin + 1; i < n; i++) {
            findsum += abs(arr[i]);
        }
    }
    return findsum;
}

void compresarray(double* arr, const int n, double a, double b) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < a || arr[i] > b) {
            arr[k] = arr[i];
            k++;
        }
    }
    for (int i = k; i < n; i++) {
        arr[i] = 0;
    }
}

int main() {
    srand((unsigned)time(0));
    int n;
    cout << "n = ";
    cin >> n;

    double* arr = new double[n];


    fillArray(arr, n);

    cout << "Initial: ";

    printArray(arr, n);

    double findsum = findsumIndex(arr, n);
    cout << "Sum: " << findsum << endl;

    int minIdx = findminIndex(arr, n);
    cout << "Index of min abs: " << minIdx << endl;

    double a, b;
    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;

    compresarray(arr, n, a, b);

    cout << "Modified: ";
    printArray(arr, n);

    delete[] arr;
    return 0;
}