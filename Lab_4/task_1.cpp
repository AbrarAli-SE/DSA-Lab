#include <iostream>
using namespace std;
int linear_search(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
            return i;
    }
    return -1;
}
int main()
{
    int n = 5;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
    cout << "Enter value "<<i+1<<": ";
        cin >> arr[i];
    }
    int key;
    cout << "Enter the value to be searched: ";
    cin >> key;
    int result = linear_search(arr, n, key);
    if (result == -1)
    {
        cout << "Element is not present in array";
    }
    else
    {
        cout << "Element "<<key<<" is present at index " << result;
    }
}
