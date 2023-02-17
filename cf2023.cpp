#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define mx 100001
int arr[mx
int main()
{
    cin >> s;
    int n = s.size();
    int q;
    cin >> q;

    init(1, 1, n);

    while (q--)
    {
        char ch;
        cin >> ch;
        if (ch == 'I')
        {
            int l, r;
            cin >> l >> r;

            rangeSum(1, 1, n, l, r);
            show(1, 1, n);
        }
        else
        {

            int i;
            cin >> i;

            int ans = tree[i];
            int val = s[i - 1] - '0';
            if (ans == 1)
            {
                val = val ^ 1;
            }

            cout << val << endl;
        }
    }

    return 0;
}
