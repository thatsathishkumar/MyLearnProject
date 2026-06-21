#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <bits/stdc++.h>
#include "../printArray.h"

using namespace std;

// Marked inline so multiple includes don't clash
inline int Partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

inline void QuickSortAlg(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int p = Partition(arr, low, high);
        QuickSortAlg(arr, low, p - 1);
        QuickSortAlg(arr, p + 1, high);
    }
}

inline void quickSort(vector<int> arr, int n)
{
    QuickSortAlg(arr, 0, n - 1);
    printArray("Quick Sort     : ", arr, n);
}

#endif
