#include <iostream>
using namespace std;

int main() {
    int matrix[4][4];
    int value;

    cout << "Enter 16 integers for the 4x4 matrix: " << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Enter the value to search for: ";
    cin >> value;

    bool found = false;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (matrix[i][j] == value) {
                cout << "Value found at row " << i << " and column " << j << endl;
                found = true;
            }
        }
    }

    if (!found) {
        cout << "Value not found in the matrix." << endl;
    }

    return 0;
}
