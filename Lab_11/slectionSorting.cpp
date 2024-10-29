#include <iostream>
using namespace std;

void slectionSorting(int arr[])
{
    for (int i = 0; i < 10; i++)
    {

        bool swapped = false;

        for(int j=i;j<10;j++)
        {
           if( arr[j] > arr[j])
           {
            int temp = arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=arr[j];
            swapped = true;
           }
        }
        if (swapped)
        {
            cout << "Sorted array after inserting element " << i << ": ";
            for (int k = 0; k < 10; k++)
            {
                cout << arr[k] << " ";
            }
            cout << endl;
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

    slectionSorting(arr);

    cout << "\nFinal sorted array: ";
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
