#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long ull;
#define pb push_back

int main()
{
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
         cin>>a[i];
    }

    sort(a,a+n);
    if(a[1]>=a[0]*2){
        cout<<a[0]<<endl;
        
    }
    else{
    int div1=a[0]/2;
    
    if(a[0]%2==0){
        div1--;
    }
   

    cout<<div1<<endl;

    }

    
}