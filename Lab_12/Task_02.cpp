#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

void quickSortFixedPivot(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        swap(arr[low], arr[mid]);         
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

        quickSortFixedPivot(arr, low, j - 1);
        quickSortFixedPivot(arr, j + 1, high);
    }
}

int main()
{
    vector<int> arr = {33, 12, 52, 3, 75, 29, 41, 6, 19};

    cout << "Array before sorting (Fixed Pivot - Middle Element): ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    auto start = chrono::high_resolution_clock::now();
    quickSortFixedPivot(arr, 0, arr.size() - 1);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;

    cout << "Array after sorting (Fixed Pivot - Middle Element): ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Execution time with Fixed Pivot: " << elapsed.count() << " seconds" << endl;
    cout << "\n\n\tAbrar Ali\n\tID: 55843";

    return 0;
}
