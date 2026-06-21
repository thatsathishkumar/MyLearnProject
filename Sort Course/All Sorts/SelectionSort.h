#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include <bits/stdc++.h>
#include "../printArray.h"

using namespace std;

// Added '&', fixed tracking logic, and added 'inline'
inline void selectionSort(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
    printArray("Selection Sort : ", arr, n);
}

#endif
