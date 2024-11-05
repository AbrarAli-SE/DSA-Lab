#include <iostream>
#include <vector>
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

int main()
{
    vector<int> arr = {33, 12, 52, 3, 75, 29, 41, 6, 19};

    cout << "Array before sorting: ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    quickSort(arr, 0, arr.size() - 1);

    cout << "Array after sorting: ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n\n\tAbrar Ali\n\tID: 55843";

    return 0;
}
