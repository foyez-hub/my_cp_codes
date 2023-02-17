#include <bits/stdc++.h>
using namespace std;


int Max_Crossing_Subarray_Sum(int arr[], int low, int mid, int high)
{

    int sum = 0;
    int left_MAX = INT_MIN;
    for (int i = mid; i >= low; i--) {
        sum = sum + arr[i];
        if (sum > left_MAX) left_MAX = sum;
    }
 
    sum = 0;
    int right_MAX = INT_MIN;
    for (int i = mid; i <= high; i++) {
        sum = sum + arr[i];
        if (sum > right_MAX) right_MAX = sum;
    }
 
    return max( max(left_MAX, right_MAX) , left_MAX + right_MAX - arr[mid] );
}


 
int Max_SubArray_Sum(int arr[], int low, int high)
{
      if (low > high) return INT_MIN;
      if (low == high) return arr[low];
 
    int mid = (low + high) / 2;
 
    return max( max( Max_SubArray_Sum(arr, low, mid - 1), Max_SubArray_Sum(arr, mid + 1, high)) ,
               Max_Crossing_Subarray_Sum(arr, low, mid, high) );
}

int main()
{
    int arr[] = { 13, -3, -25, 20, -3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int REmaxsum = Max_SubArray_Sum(arr, 0, n - 1);
    cout<<"Maximum subarray sum is -> "<<REmaxsum<<endl;

    return 0;
}
