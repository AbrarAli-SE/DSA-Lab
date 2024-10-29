#include <iostream>
using namespace std;

void selectionSorting(int arr[])
{
    for (int i = 0; i < 9; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < 10; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
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

    selectionSorting(arr);

    cout << "\nFinal sorted array: ";
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
