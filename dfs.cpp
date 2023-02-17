#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long ull;
#define pb push_back


int main()
{


   ll n;

   cin>>n;

   ll a[n];
   vector<ll> v;
   
   

   for (ll i = 0; i < n; i++)
   {
      cin>>a[i];

   }

   map<ll,bool> mp;

   for (ll i = 0; i < n; i++)
   {
        while (i+1<n&&a[i]==a[i+1])
        {
            mp[i]=true;
            i++;
        }
        
       
   }

   for (ll i = 0; i < n; i++)
   {
       if(!mp[i]){
        v.pb(a[i]);
       }
   }


   
   

   
   






   if(v.size()==1){


       cout<<1<<endl;

       
   }
   else{
  

   ll uphill=0;
   ll downhill=0;

   for (ll i = 0; i < v.size(); i++)
   {
       if(i-1>=0&&i+1<v.size()&&v[i]>v[i-1]&&v[i]>v[i+1]){
        uphill++;
       }
       else if(i-1>=0&&i+1<v.size()&&v[i]<v[i-1]&&v[i]<v[i+1]){
        downhill++;
       }
        
       
   }
   

   cout<<uphill+downhill+2<<endl;

   }
   
   
    
    
}
