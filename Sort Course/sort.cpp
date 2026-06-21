#include <bits/stdc++.h>
#include "All Sorts/InsertionSort.h"
#include "All Sorts/SelectionSort.h"
#include "All Sorts/QuickSort.h"
#include "All Sorts/MergeSort.h"
#include "All Sorts/HeapSort.h"

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    vector<int> arr = {5, 1, 4, 6, 3, 6, 2, 4};
    int n = arr.size();
    while (true)
    {
        int userInput = 0;
        if (userInput == 0)
        {
            cout << "Choose a sorting algorithm:\n";
            cout << "1. Insertion Sort\n";
            cout << "2. Selection Sort\n";
            cout << "3. Quick Sort\n";
            cout << "4. Merge Sort\n";
            cout << "5. Heap Sort\n";
            cout << "6. Exit\n";
            cin >> userInput;
        }
        if (userInput >= 6)
        {
            cout << "Exiting the program.\n";
            break;
        }
        int key = userInput;

        switch (key)
        {
        case 1:
            InsertionSort(arr, n);
            break;
        case 2:
            selectionSort(arr, n);
            break;
        case 3:
            quickSort(arr, n);
            break;
        case 4:
            mergeSort(arr, n);
            break;
        case 5:
            heapSort(arr, n);
            break;
        default:
            break;
        }
        userInput = 0;
    }
    return 0;
}