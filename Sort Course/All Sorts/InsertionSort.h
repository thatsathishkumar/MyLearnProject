#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include <bits/stdc++.h>
#include "../printArray.h" // '../' goes back one folder to find printArray.h

using namespace std;

// Added '&' to modify the array, and 'inline' for header safety
inline void InsertionSort(vector<int> &arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int curr = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > curr)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = curr;
    }
    printArray("Insertion Sort : ", arr, n);
}

#endif
