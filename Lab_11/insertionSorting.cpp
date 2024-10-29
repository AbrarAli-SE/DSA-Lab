#include <iostream>
using namespace std;

void insertionSorting(int arr[])
{
    for (int i = 1; i < 10; i++)
    {
        int key = arr[i];
        int j = i - 1;
        bool swapped = false; 

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
            swapped = true;
        }
        arr[j + 1] = key;

        if (swapped)
        {
            cout << "Sorted array after inserting element " << i << ": ";
            for (int k = 0; k < 10; k++)
            {
                cout << arr[k] << " ";
            }
            cout << endl;
        }
    }
}

int main()
{
    int arr[10];
    cout << "Enter 10 elements to sort:\n";
    for (int i = 0; i < 10; i++)
    {
        cin >> arr[i];
    }

    insertionSorting(arr);

    cout << "\nFinal sorted array: ";
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
