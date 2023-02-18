#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long ull;
#define pb push_back

bool f(string s)
{

   for (int i = 0; i < s.size() - 1; i++)
   {
      if (s[i] == s[i + 1])
      {
         return false;
      }
   }

   return true;
}
int main()
{
   ll t;
   cin >> t;
   while (t--)
   {
      ll l1, l2;
      cin >> l1 >> l2;
      string s1, s2;
      cin >> s1 >> s2;

      string tem = "";
      tem += s1;

      if (l2 >= 2)
      {
         string ss = s2.substr(1, l2 - 1);
         reverse(ss.begin(), ss.end());
         tem += ss;
      }

      // cout<<tem<<endl;

      if (f(tem))
      {
         cout << "YES" << endl;
         continue;
      }
      else
      {
         string tem1="";
         string tem2="";

         for (int i = 0; i < tem.size() - 1; i++)
         {
             tem1+=tem[i];
            if (tem[i] == tem[i + 1])
            {
               string ss = tem.substr(i + 1, tem.size() - i);
               reverse(ss.begin(), ss.end());
               tem2+=s2[0];
               tem2+=ss;
               break;
            }

         }

         // cout<<tem1<<" "<<tem2<<endl;

         if(f(tem1)&&f(tem2)){
            cout<<"YES"<<endl;
         }
         else{
            cout<<"NO"<<endl;
         }


      }
   }
}