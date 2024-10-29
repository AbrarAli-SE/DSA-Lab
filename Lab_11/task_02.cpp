#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    int arr3[] = {5, 2, 9, 1, 5, 6, 7, 8, 10, 3};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);

    bubbleSort(arr1, size1);
    cout << "Sorted array 1: ";
    printArray(arr1, size1);

    bubbleSort(arr2, size2);
    cout << "Sorted array 2: ";
    printArray(arr2, size2);

    bubbleSort(arr3, size3);
    cout << "Sorted array 3: ";
    printArray(arr3, size3);

    return 0;
}
