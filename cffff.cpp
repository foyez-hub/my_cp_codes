#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long ull;
#define pb push_back




ll getKthBit(ll n, ll k)
{
    return ((n & (1 << (k - 1))) >> (k - 1));
}



int main(){

    ll n,q;
    cin>>n>>q;
    ll a[n];
    map<ll,ll> mp;
    for (ll i = 0; i < n; i++)
    {
          cin>>a[i];
          mp[a[i]]++;

    }
    ll pp[40];
    ll mul=1;
    
    for (ll i =0; i <=36; i++)
    {
        pp[i]=mul;
        mul*=2;
    }
    

    while (q--)
    {
        ll qq;
        cin>>qq;
        ll ans=0;
        ll flag=0;
        vector<ll> v;

        for (ll i =1; i <=36; i++)
        {

            if(getKthBit(qq,i)==1){
                v.pb(i-1);
            }

            
            
        }

        reverse(v.begin(),v.end());
        int cnt=0;
        
        for (int i = 0; i < v.size(); i++)
        {
               ll val=v[i];
               ll cur=pp[val];
               bool ck=false;
               for (ll j =val; j >=0; j--)
               {
                  ll power=pp[j];
                  ll need=cur/power;
                  if(mp[power]>=need){
                    mp[power]-=need;
                    ans+=need;
                    ck=true;
                    break;
                  }
               }

               if(ck){
                cnt++;
                  
               }
               
        }

        if(cnt==v.size()){

            cout<<ans<<endl;
        }
        else{
            cout<<-1<<endl;
        }
        
    }
    
    


    

    
}