#include "analyze.h"
#include "algorithm.h"

//
// Private
//

void makeArr(int *arr, int lenght, case_t c)
{

    if (c == best_t)
    {
        for (int i = 0; i < lenght; i++)
        {

            arr[i] = i;
        }
    }
    else if (c == worst_t)
    {
        for (int i = 0; i < lenght; i++)
        {

            arr[i] = lenght - 1;
        }
    }
    else if (c == average_t)
    {
        for (int i = 0; i < lenght; i++)
        {

            arr[i] = rand() % lenght;
        }
    }
}

//
// Public
//
void benchmark(const algorithm_t a, const case_t c, result_t *buf, int n)
{

    switch (a)
    {

    case bubble_sort_t:
        makearraySort(bubble_sort, c, buf);
        break;

    case quick_sort_t:
        makearraySort(quick_sort, c, buf);
        break;

    case insertion_sort_t:
        makearraySort(insertion_sort, c, buf);
        break;

    case linear_search_t:
        // makearraySearch(linear_search, c, buf, 0);
        break;

    case binary_search_t:
        // makearraySearch(binary_search, c, buf, 0);
        break;

    default:
        break;
    }
}

// gör en array baserad på vilket case det är
void makearraySort(sortFunc func, case_t c, result_t *buf)
{
    int size = SIZE_START;

    for (int i = 0; i < ITERATIONS; i++)
    {
        int a[size];
        makeArr(a, size, c);
        buf[i].time = sortTime(func, a, size);
        size = size * 2;
    }
}

void makearraySearch(searchFunc func, case_t c, result_t *buf, int v)
{
    int size = SIZE_START;

    for (int i = 0; i < ITERATIONS; i++)
    {
        int a[size];
        makeArr(a, size, c);
        buf[i].time = searchTime(func, a, size, v);
        size = size * 2;
    }
}
