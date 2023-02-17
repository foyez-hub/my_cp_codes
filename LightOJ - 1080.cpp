#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long ull;
#define pb push_back

#define mx 100000*3

struct node{
    ll value=0;
    ll lazy=0;
};

ll arr[mx];
node tree[mx*4];

void build(ll L,ll R,ll at){

    if(L==R){

        tree[at].value=arr[L];
        return;
    }

    ll mid=(L+R)/2;
    ll left = 2*at;
    ll right=2*at+1;

    build(L,mid,left);
    build(mid+1,R,right);
    tree[at].value+=tree[left].value+tree[right].value;

}

void update(ll l,ll r,ll x,ll L,ll R,ll at){

    if(l>R||r<L) return;
    if(L>=l&&R<=r){
        tree[at].value+=(R-L+1)*x;
        tree[at].lazy+=x;
        return;
    }
    ll mid = (L+R)/2;
    ll left = at*2;
    ll right = at*2+1;
    update(l,r,x,L,mid,left);
    update(l,r,x,mid+1,R,right);
    tree[at].value = tree[left].value+tree[right].value+(R-L+1)*tree[at].lazy;

}


ll query(ll l,ll r,ll L,ll R,ll at,ll carry){

    if(l>R||r<L) return 0;

    if(L>=l&&R<=r){
        return tree[at].value+carry*(R-L+1);
    }

    ll mid = (L+R)/2;
    ll left=at*2;
    ll right=at*2+1;
    ll carryValue = carry+tree[at].lazy;
    ll x = query(l,r,L,mid,left,carryValue);
    ll y = query(l,r,mid+1,R,right,carryValue);

    return x+y;
}




int main()
{
//   ll t;
//   cin >> t;
//   ll ca=1;

//   while (t--)
//   {
//     cout<<"Case "<<ca<<":"<<endl;
//     ca++;
//     for (ll i = 0; i <mx*4; i++)
//     {
//         tree[i].lazy=0;
//         tree[i].value=0;
//     }
    

    
   ll n,q;
   cin>>n>>q;
   ll a[n];
   for (ll i = 0; i < n; i++)
   {
      cin>>a[i];
   }

   for (ll i =1; i <=n; i++)
    {
        arr[i]=a[i-1];

    }
    

    build(1,n,1);

    

   
    

    while (q--)
    {
        ll ty,l,r;
        cin>>ty;
        cin>>l>>r;
        if(ty==2){
          
          ll val=query	(l,r,1,n,1,0);

        
          
        }
        else{

         
          update(l,r,1,1,n,1);


        }
    }

   
    
    
    
    
       
  }
// }
