#include <iostream>
using namespace std;
int main() {
    int size;
    cout << "Enter the size of the array (1-20): ";
    cin >> size;

    if (size < 1 || size > 20) {
        cout << "Invalid size. Please enter a value between 1 and 20." << endl;
        return 1;
    }

    int* arr = new int[size];
    cout << "Enter " << size << " integers (0-12): ";
    int sum = 0;

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
        if (arr[i] < 0 || arr[i] > 12) {
            cout << "Invalid input. Please enter a value between 0 and 12." << endl;
            delete[] arr;
            return 1;
        }
        sum += arr[i];
    }

    double average = sum / size;
    cout << "Average of array elements: " << average << endl;

    for (int i = 0; i < size; i++) {
        int factorial = 1;
        for (int j = 1; j <= arr[i]; j++) {
            factorial *= j;
        }
        cout << "Factorial of " << arr[i] << " is " << factorial << endl;
    }

    delete[] arr;
    return 0;
}
