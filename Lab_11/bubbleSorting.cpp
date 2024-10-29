#include <iostream>
using namespace std;
void bubbleSorting(int arr[])
{
    for (int i = 0; i < 10 - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < 10 - i - 1; j++)
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
        {
            break;
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

    bubbleSorting(arr);

    cout << "\nFinal sorted array: ";
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
