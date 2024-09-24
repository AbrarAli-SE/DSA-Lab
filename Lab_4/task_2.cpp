#include <iostream>
using namespace std;
int find(int arr[], int high, int low, int key)
{
    int mid = (high + low) / 2;
    if(low>high)
    return -1;
    if (arr[mid] == key)
    {
        return mid;
    }

    if (arr[mid] > key)
    {
        return find(arr, mid - 1, low, key);
    }
    else if (arr[mid] < key)
    {
        return find(arr, high, mid + 1, key);
    }
}
int main()
{
    int n = 7;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value  " <<i+1<< " : ";
        cin >> arr[i];
    }
    // sort arry
    for (int i = 0; i < n ; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    
    }
    for (int i = 0; i < n; i++)
    {
        cout << "  ";
        cout<< arr[i];
    }

    int key;
    cout << "Enter the value to be searched: ";
    cin >> key;
    int result = find(arr, n - 1, 0, key);
    if (result == -1)
    {
        cout << "Value is not present in array";
    }
    else
    {
        cout << "Value " << key << " is present at index " << result;
    }
}