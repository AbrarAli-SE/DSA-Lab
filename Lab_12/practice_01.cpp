#include <iostream>
#include <vector>
using namespace std;

void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivot = arr[high]; 
        int i = low - 1;      
        for (int j = low; j < high; j++)
        {

            if (arr[j] <= pivot)
            {
                i++; 
                swap(arr[i], arr[j]);
            }
            
        }
       for (int i = 0; i < 9; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        swap(arr[i + 1], arr[high]);
        int pi = i + 1;

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    vector<int> arr = {33,12,52,3,75,29,41,6,19};
    int n = arr.size();

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}