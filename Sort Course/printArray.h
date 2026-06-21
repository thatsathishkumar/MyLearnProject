#ifndef PRINT_ARRAY_H
#define PRINT_ARRAY_H

#include <bits/stdc++.h>
using namespace std;

inline void printArray(string label, vector<int> arr, int n)
{
    cout << label;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

#endif
