//F_O_Y_E_Z
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long ull;
#define pb push_back

int main()
{

  ll nc;
  cin>>nc;
  map<ll,vector<ll> > mp;
  for (int i =1; i <=nc; i++)
  {
    ll p;
    cin>>p;
    for (int j = 0; j < p; j++)
    {
        ll nd;
        cin>>nd;
        mp[i].pb(nd);

    }
    
  }
  ll q;
  cin>>q;
  for (int i = 0; i < q; i++)
  {
    ll c1,c2,d,m,y;
    cin>>c1>>c2>>d>>m>>y;
    ll sum=0;
    for (int j = 0; j < mp[c1].size(); j++)
    {
        sum+=mp[c1][j];
    }
    sum*=(y-1);
     for (int j = 0; j <m-1; j++)
    {
        sum+=mp[c1][j];
    }
    sum+=d;
    // cout<<sum<<endl;

   ll year=0;
   ll month=0;
   ll day=0;
    for (int j = 0; ; )
    {
        if(j==0) year++;
        ll val=mp[c2][j];
       
        if(sum<=val){
            // cout<<j+1<<endl;
            day=j+1;
            break;
        }
        else{
            sum-=val;
        }
         j++;
        j=j%mp[c2].size();
       
    }
    cout<<sum<<" "<<day<<" "<<year<<endl;
    
    
  }
  
  

}