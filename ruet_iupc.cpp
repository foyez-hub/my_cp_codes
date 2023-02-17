#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long ull;
#define pb push_back

map<int,int> pa;
bool isSubsetSumMatch(int set[], int n, int sum,int p)
{

    pa[n]=p; 
    if (sum == 0){
      // int pp=pa[n];
      // while(pp!=-1){
      //   cout<<set[pp]<<" ";
      //   pp=pa[pp];
      // }
      // cout<<endl;
        
        
        return true;

    }
    if (n == 0)
        return false;
  
   
    if (set[n - 1] > sum)
        return isSubsetSumMatch(set, n - 1, sum,n);

    return isSubsetSumMatch(set, n - 1, sum,n)
           || isSubsetSumMatch(set, n - 1, sum - set[n - 1],n);
}


int main()
{
  
    int set[] = { 3, 34, 4, 12, 5, 2 };
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);
    if (isSubsetSumMatch(set, n, sum,-1) == true)
         cout <<"Found a subset with given sum";
    else
        cout <<"No subset with given sum";
    return 0;
}
