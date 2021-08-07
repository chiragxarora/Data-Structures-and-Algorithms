#include <iostream>
using namespace std;
void insertion_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int e = arr[i];
        // place this current element at its 'right' position in sorted part
        int j = i - 1;
        while (j >= 0 && arr[j] > e)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = e;
    }
}

int main()
{
    // In insertion sort, we start sorting a part of array from one direction and pick elements next to the sorted part
    // Now we put the element in its correct position relative to the chosen sorted part, by displacing the other elemtns and inserting the element in hand
    int arr[10] = {1, 6, 2, 90, -4, 0, -100, 6, 66, 6};
    int n = sizeof(arr) / sizeof(int);
    insertion_sort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}