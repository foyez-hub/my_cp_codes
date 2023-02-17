// f_o_y_e_z
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long ull;
#define pb push_back

int main()
{

   ll t;
   cin >> t;
   while (t--)
   {
      ll a, b, c, d;
      cin >> a >> b>>c>>d;

      ll Arr[50][50];
      Arr[1][2]=1,Arr[1][3]=1,Arr[1][4]=2,Arr[1][5]=3,Arr[1][6]=3,Arr[1][7]=4; 
      Arr[2][3]=2,Arr[2][4]=1,Arr[2][5]=2,Arr[2][6]=2,Arr[2][7]=3; 
      Arr[3][4]=1,Arr[3][5]=2,Arr[3][6]=2,Arr[3][7]=3; 
      Arr[4][5]=1,Arr[4][6]=1,Arr[4][7]=2; 
      Arr[5][6]=2,Arr[5][7]=1;
      Arr[6][7]=1;

      ll ans=Arr[min(a,c)][max(a,c)]+Arr[min(b,d)][max(b,d)];
      swap(a,b);
      ans=min(ans,Arr[min(a,c)][max(a,c)]+Arr[min(b,d)][max(b,d)]);
      cout<<ans<<endl;
 
     


    
     
   }
}
