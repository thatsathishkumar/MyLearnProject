#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <bits/stdc++.h>
#include "../printArray.h"

using namespace std;

void Merge(vector<int> &arr, int left, int mid, int right)
{
    // n1 is the size of the left subarray, n2 is the size of the right subarray
    // mid - left + 1 is the number of elements in the left subarray
    // right - mid is the number of elements in the right subarray
    // suppose left = 0, mid = 3, right = 7, then n1 = 4, n2 = 4
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    // Copy data to temp arrays L[] and R[]
    // left + i is the index in the original array for the left subarray
    // For example, if left = 0, then the left subarray starts at index 0, so left + i = i
    // If mid = 3, then the left subarray ends at index 3,
    // so i goes from 0 to n1 - 1 (0 to 3 in this case)
    // So L[0] = arr[0], L[1] = arr[1], L[2] = arr[2], L[3] = arr[3]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    // mid + 1 + j is the index in the original array for the right subarray
    // For example, if mid = 3, then the right subarray starts at index 4, so mid + 1 + j = 4 + j
    // If right = 7, then the right subarray ends at index 7, so j goes from 0 to n2 - 1 (0 to 3 in this case)
    // So R[0] = arr[4], R[1] = arr[5], R[2] = arr[6], R[3] = arr[7]
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temp arrays back into arr[left..right]
    // i is the index for the left subarray, j is the index for the right subarray, k is the index for the merged array
    // Start with the first index of each subarray and the first index of the merged array
    // Compare the elements of the left and right subarrays and copy the smaller element to the merged array
    // If the left subarray is exhausted, copy the remaining elements of the right subarray
    // If the right subarray is exhausted, copy the remaining elements of the left subarray
    // Continue until all elements from both subarrays are copied to the merged array
    // This is the standard merge step of the merge sort algorithm
    int i = 0, j = 0, k = left;

    // Compare elements of L and R and copy the smaller one to arr
    // This loop continues until we reach the end of either L or R
    // For example, if L = [1, 3, 5] and R = [2, 4, 6], then we compare L[0] and R[0], which are 1 and 2
    // Since 1 < 2, we copy 1 to arr[k] and increment i and k
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    // remaining elements of L, if any example: if L = [1, 3, 5] and R = [2, 4], after the above loop, we have copied 1, 2, 3, 4 to arr, and i = 2 (pointing to 5), j = 2 (pointing to end of R), k = 4 (pointing to the next index in arr)
    while (i < n1)
    {
        arr[k] = L[i];
        i++, k++;
    }
    // remaining elements of R, if any example: if L = [1, 3] and R = [2, 4, 6], after the above loop, we have copied 1, 2, 3 to arr, and i = 2 (pointing to end of L), j = 1 (pointing to 4), k = 3 (pointing to the next index in arr)
    while (j < n2)
    {
        arr[k] = R[j];
        j++, k++;
    }
}

void MergeSortAlg(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;
    int mid = low + (high - low) / 2;
    MergeSortAlg(arr, low, mid);
    MergeSortAlg(arr, mid + 1, high);
    Merge(arr, low, mid, high);
}

void mergeSort(vector<int> arr, int n)
{
    MergeSortAlg(arr, 0, n - 1);
    printArray("Merge Sort     : ", arr, n);
}

#endif