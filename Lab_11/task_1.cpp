#include <iostream>
using namespace std;

// Function to implement Insertion Sort
void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function to print an array
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
    int arr1[] = {1, 2, 3, 5, 4, 6, 7, 8, 9, 10};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    int arr3[] = {5, 2, 9, 1, 5, 6, 7, 8, 10, 3};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    
    insertionSort(arr1, size1);
    cout << "Sorted array 1: ";
    printArray(arr1, size1);

    insertionSort(arr2, size2);
    cout << "Sorted array 2: ";
    printArray(arr2, size2);

    insertionSort(arr3, size3);
    cout << "Sorted array 3: ";
    printArray(arr3, size3);

    return 0;
}
