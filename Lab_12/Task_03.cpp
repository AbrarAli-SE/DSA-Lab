#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
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

        quickSort(arr, low, j - 1);
        quickSort(arr, j + 1, high);
    }
}

void measurePerformance(int size)
{
    vector<int> arr(size);
    for (int i = 0; i < size; i++)
    {
        arr[i] = size - i;
    }

    auto start = chrono::high_resolution_clock::now();
    quickSort(arr, 0, size - 1);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;

    cout << "Execution time for " << size << " elements: " << elapsed.count() << " seconds" << endl;
}

int main()
{
    cout << "Performance of Quick Sort on different array sizes:\n";
    measurePerformance(100);
    measurePerformance(1000);
    measurePerformance(10000);

    cout << "\n\n\tAbrar Ali\n\tID: 55843";
    return 0;
}
