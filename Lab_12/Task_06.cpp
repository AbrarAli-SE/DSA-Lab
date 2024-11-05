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
    {
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

void merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void compareSorts(int size)
{
    vector<int> arr1(size), arr2(size);
    for (int i = 0; i < size; i++)
        arr1[i] = arr2[i] = size - i;

    cout << "\nArray Size: " << size << endl;

    auto start = chrono::high_resolution_clock::now();
    quickSortWithInsertion(arr1, 0, size - 1);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsedQuickSort = end - start;
    cout << "Quick Sort with Insertion Fallback: " << elapsedQuickSort.count() << " seconds" << endl;

    start = chrono::high_resolution_clock::now();
    mergeSort(arr2, 0, size - 1);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsedMergeSort = end - start;
    cout << "Merge Sort: " << elapsedMergeSort.count() << " seconds" << endl;
}

int main()
{
    compareSorts(100);
    compareSorts(1000);
    compareSorts(10000);

    cout << "\n\n\tAbrar Ali\n\tID: 55843";
    return 0;
}
