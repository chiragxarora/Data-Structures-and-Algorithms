// Function as a parameter
// Comparator example

#include <iostream>     // 5 4 3 2 1
using namespace std;

bool compare(int a, int b){
    return a < b;       // This is the logic of sorting, changing this can change the order
}

void bubble_sort(int arr[], int n, bool (&cmp)(int a, int b))
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 1; j < n - i; j++)
        {
            if (cmp(arr[j-1], arr[j]))
            {
                int temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
    // In bubble sort, in each iteration we bring largest number to the right side of the array, by swapping it multiple times in inner iterations whenever we encounter a number smaller than that
    // And in each outer iteration, one element comes to its correct position
    // Largest element is first to reach its correct position and smallest is last
    int arr[10] = {1, 6, 2, 90, -4, 0, -100, 6, 66, 6};
    int n = sizeof(arr) / sizeof(int);
    bubble_sort(arr, n, compare);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}