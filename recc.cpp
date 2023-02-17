#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long ull;
#define pb push_back
struct node
{
   int l,r;
   int sum;
   int sz;
};

void f(int n,int a[])
{
   int mm=-1;
   for (int k = 1; k <= n; k++)
   {

      stack< node > q;
      node src;
      src.l=1;
      src.r=k;
      src.sum=a[k];
      src.sz=1;


      q.push(src);

      while (!q.empty())
      {
         node popnode = q.top();
         q.pop();
         int i = popnode.l;
         int j = popnode.r;
         // cout << i << " " << j << endl;
         if(j==n){
            // cout<<"ans  "<<popnode.sz<<endl;
            mm=max(mm,popnode.sz);
         }
         int psum=a[j]-a[i-1];
         for (int child = j + 1; child <= n; child++)
         {
            node ch;
            ch.l=j+1;
            ch.r=child;
            ch.sum=a[child]-a[j];
            ch.sz=popnode.sz+1;

            if(ch.sum==psum){
                 q.push(ch);
            }
         }
      }
   }

   cout<<n-mm<<endl;
}

int main()
{
   int t;
   cin>>t;
   while (t--)
   {
      
   
   
   int n;
   cin >> n;
   int a[n+1];
   a[0]=0;
   int sum=0;
   for (int  i = 0; i < n; i++)
   {
      int val;
      cin>>val;
      sum+=val;
      a[i+1]=sum;

   }
   
   f(n,a);


   }
}