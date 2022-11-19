#include "algorithm.h"

//
// Private
//

//
// Public
//
void bubble_sort(int *a, int n)
{

    int temp;

    for (int j = 0; j < n - 1; j++)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] > a[i + 1])
            {
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
    }
}

void insertion_sort(int *a, int n)
{
    for (int i = 1; i < n; i++)
    {
        int comp = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > comp)
        {

            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = comp;
    }
}

int partition(int *a, int l, int h)
{
    int pivot, lower, upper, temp;
    pivot = a[l];
    lower = l + 1;
    upper = h;
    do
    {
        while (a[lower] <= pivot && lower <= upper)
            lower = lower + 1;
        while (a[upper] > pivot && lower <= upper)
            upper = upper - 1;
        if (lower <= upper)
        {
            temp = a[lower];
            a[lower] = a[upper];
            a[upper] = temp;
            lower = lower + 1;
            upper = upper - 1;
        }
    } while (lower <= upper);
    temp = a[upper];
    a[upper] = a[l];
    a[l] = temp;
    return upper;
}

void quickSortBE(int *a, int low, int high)
{

    int k;
    if (low < high)
    {
        k = partition(a, low, high);
        quickSortBE(a, low, k - 1);
        quickSortBE(a, k + 1, high);
    }
}

void quick_sort(int *a, int n)
{
    quickSortBE(a, 0, n - 1);
}

bool linear_search(const int *a, int n, int v)
{
    for (int i = 0; i < n; i++)
    {
        if (v == a[i])
        {
            return true;
        }
    }

    return false;
}

bool binary_search(const int *a, int n, int v)
{

    return false; // TODO: binary search
}
