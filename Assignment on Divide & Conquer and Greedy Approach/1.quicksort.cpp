#include <bits/stdc++.h>
using namespace std;

int partition_arr(int arr[], int startind, int endind)
{
    int x = arr[endind]; 
    int i = startind - 1;     

    for (int j = startind; j <= endind - 1; j++)
    {
        if (arr[j] <= x)
        {
            i=i+1; 
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[endind]);
    return i + 1;

  

}

void QuickSort(int arr[], int startind, int endind)
{

    if (startind > endind)
    {
           return;
    }
    else if (startind == endind)
    {
        /// array with 1 element
        return;
    }
    else
    {
   
        /// Partition the array
        int part = partition_arr(arr, startind, endind);
        /// QuickSort the left subarray
        
        QuickSort(arr, startind, part - 1);

        /// QuickSort the right subarray
        QuickSort(arr, part + 1, endind);
  
    }
}
int main()
{
    int arr[] = {2, 8, 7, 1, 3, 5, 6, 4};
    int sz = sizeof(arr) / sizeof(int);

    QuickSort(arr, 0, sz - 1);
    /// printing the output
    for (int ind = 0; ind < sz; ind++)
    {
        cout << arr[ind] << " ";
    }
    cout << endl;
    return 0;
}
