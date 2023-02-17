#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long ull;
#define pb push_back

int segmax(int l,int r,int a[]){

   if(l>r){
    return -1;
   }

   return max(a[l],segmax(l+1,r,a));
}

void P(int a[],int n){
    for (int i =1; i <=n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    
}

int f(int a[], int n, int l, int r)
{
    if (r-l==1)
        return 0;

    int mid = (l + r) / 2;
    int sz=(r-l)+1;

    int leftmax=segmax(l,mid,a);
    int rightmax=segmax(mid,r,a);
   
    // P(a,n);   
    int ans=0;
  
    if (leftmax>rightmax)
    {
        ans++;

        for (int i = l; i <= mid; i++)
        {
          if(i+(sz/2)<=r) swap(a[i], a[i + (sz/2)]);
          else break;
        }

    }


    return f(a, n, l, mid)+ f(a, n, mid, r) + ans;

    
}

int main()
{

    ll t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n+1];
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        if (n == 1)
        {
            cout << 0 << endl;
            continue;
        }

     
        cout<<f(a, n, 1, n)<<endl;
         
    }
}