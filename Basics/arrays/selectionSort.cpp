#include <iostream>
using namespace std;
void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] <= arr[min])
            {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

int main()
{
    // In selection sort, in each iteration we bring smallest number to the left side of the array
    // And in each outer iteration, one element comes to its correct position
    // Smallest element is first to reach its correct position and largest is last
    int arr[10] = {1, 6, 2, 90, -4, 0, -100, 6, 66, 6};
    int n = sizeof(arr) / sizeof(int);
    selection_sort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}