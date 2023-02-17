#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int main()
{

    int t;
    cin >> t;
    while(t--)
    {


        int n;
        cin >> n;
        vector<int>vec,v;
        int m=sqrt(n);
        for(int i=2;i<=m;i++)
        {
            if(n%i==0)
            {
                vec.pb(i);
            }
            if(vec.size()==2) break;
        }
        if(vec.size()!=2)
        {
            cout << "NO\n";cout<<"he";
            continue;
        }
        int x= vec[0]*vec[1];
        int y=n/x;
        if(y*x==n && y!=vec[0] && y!=vec[1] && y!=1)
        {
            cout << "YES" << "\n";
            cout << vec[0] << " " << vec[1] << " "<<y << "\n";
        }
        else
        {
            cout << "NO\n";
        }

    }
    return 0;
}
