// F_O_Y_E_Z
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long ull;
#define pb push_back

    
int main()
{
   
 ll t;
 cin>>t;
 ll ca=1;
 while (t--)
 {
   ll n;
   cin>>n;
   ll a[n];
   for (ll i = 0; i < n; i++)
   {
        cin>>a[i];
   }
   sort(a,a+n);
   ll ans=0;
   ll sum=0;
   for (ll i = 0; i < n; i++)
   {
      if(sum+a[i]<=2*a[i]){
         ans++;
         sum+=a[i];

      }


      
   }
   
   
   
   



   cout<<"Case #"<<ca<<": "<<ans<<endl;
   ca++;

 }
 


}


     
     

     


