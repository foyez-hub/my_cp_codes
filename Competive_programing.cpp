#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long ull;
#define pb push_back

int main()
{

   ll t;
   cin>>t;
   while (t--)
   {
      ll n,m,d;
      cin>>n>>m>>d;

      ll a[n];
      ll b[m];
      for (ll i = 0; i < n; i++)
      {
          cin>>a[i];
      }
      for (ll i = 0; i < m; i++)
      {
           cin>>b[i];
      }

      ll res=0;
      ll pre=-1;

      for (ll i = 0; i < m; i++)
      {
         int pos=-1;
         for (ll j = 0; j < n; j++)
         {
            if(a[j]==b[i]){
               pos=j;
               break;
            }
         }
         
         if(pre!=-1){
            if(pos<=pre){
               res+=(pre-pos+d)/d;
            }
            pre=pos;
         }
         else{
            pre=pos;
         }
         
      }
      cout<<res<<endl;
      
      
      

   }
   
}
