#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long ull;
#define pb push_back

int main()
{
    
  
  ll n;
  cin>>n;
  fflush(stdin);

  string s;
  getline(cin,s);
  map<char,ll> mp;
  map<ll,char> mp1;

  ll c=1;
  for (char i ='a'; i <='z'; i++)
  {
       mp[i]=c;
       mp1[c]=i;
       c++;
  }
  for (ll i = 0; i < s.size(); i++)
  {

      char ch=s[i];
      ll tem=n;
      ll pos=mp[ch];
      if(ch!=' '){
      while (tem--)
      {
           
           pos--;
           if(pos==0) pos=26;

      }

      cout<<mp1[pos];

      }
      else{
          cout<<" ";
      }
      

  }
  cout<<endl;
  
  
   
         
}