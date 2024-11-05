#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

void insertionSort(vector<int> &arr, int low, int high)
{
    for (int i = low + 1; i <= high; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= low && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void quickSortWithInsertion(vector<int> &arr, int low, int high)
{
    if (high - low < 10)
    { // Fallback to Insertion Sort for small subarrays
        insertionSort(arr, low, high);
        return;
    }

    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (i <= j)
    {
        while (i <= high && arr[i] <= pivot)
            i++;
        while (j >= low && arr[j] > pivot)
            j--;
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);

    quickSortWithInsertion(arr, low, j - 1);
    quickSortWithInsertion(arr, j + 1, high);
}

int main()
{
    vector<int> arr = {33, 12, 52, 3, 75, 29, 41, 6, 19};

    cout << "Array before sorting (Quick Sort with Insertion Sort Fallback): ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    auto start = chrono::high_resolution_clock::now();
    quickSortWithInsertion(arr, 0, arr.size() - 1);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;

    cout << "Array after sorting: ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Execution time: " << elapsed.count() << " seconds" << endl;
    cout << "\n\n\tAbrar Ali\n\tID: 55843";

    return 0;
}
