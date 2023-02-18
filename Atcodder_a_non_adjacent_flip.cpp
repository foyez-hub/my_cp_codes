#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long ull;
#define pb push_back

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        ll cnt = 0;
        ll ct = 0;
        for (ll i = 0; i < n; i++)
        {

            if (s[i] == '1')
            {
                cnt++;
            }

            if (i + 1 < n && s[i] == '1' && s[i + 1] == '1')
            {
                ct++;
            }
        }

        if (n == 3)
        {
            if (cnt >= 1)
            {

                if (s[0] == '1' && s[2] == '1' && s[1] == '0')
                {
                    cout << 1 << endl;
                }
                else
                    cout << -1 << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
        else
        {
            if (cnt % 2 == 0)
            {

                if (ct == 1)
                {

                    if (n == 4&&s[0] == '0' && s[2] == '1' && s[1] == '1' && s[3] == '0')
                    {
                        
                            cout << 3 << endl;
        
                    }
                    else cout << 2 << endl;
                }
                else{
                    cout << cnt / 2 << endl;
                }
            }
            else
            {

                cout << -1 << endl;
            }
        }
    }
}