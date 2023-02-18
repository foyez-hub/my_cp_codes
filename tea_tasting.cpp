#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long ull;
#define pb push_back

ll bs(ll val, ll L, ll R, ll pre[])
{

    // cout<<L<<" cur "<<R<<endl; 

    ll mm = 1e18;               
    ll l = L;
    ll r = R;

    while (l <= r)
    {

        ll mid = (l + r) / 2;

        ll sum = pre[mid] - pre[L - 1];

        // cout<<l<<" "<<r<<"  sum->"<<sum<<endl;

        if (val - sum <= 0)
        {
            r = mid - 1;
            mm = min(mm, mid);
        }
        else if (val - sum > 0)
        {
            l = mid + 1;
        }
    }

    return mm;
}

struct node
{
    ll value = 0;
    ll lazy = 0;
};

node tree[2 * 100001 * 4];
ll arr[2 * 100001];

void build(ll L, ll R, ll at)
{

    if (L == R)
    {

        tree[at].value =0;
        return;
    }

    ll mid = (L + R) / 2;
    ll left = 2 * at;
    ll right = 2 * at + 1;

    build(L, mid, left);
    build(mid + 1, R, right);

    tree[at].value += tree[left].value + tree[right].value;
}

void update(ll l, ll r, ll x, ll L, ll R, ll at)
{

    if (l > R || r < L)
        return;

    if (L >= l && R <= r)
    {
        tree[at].value += (R - L + 1) * x;
        tree[at].lazy += x;
        return;
    }
    ll mid = (L + R) / 2;
    ll left = at * 2;
    ll right = at * 2 + 1;
    update(l, r, x, L, mid, left);
    update(l, r, x, mid + 1, R, right);
    tree[at].value = tree[left].value + tree[right].value + (R - L + 1) * tree[at].lazy;
}

ll query(ll l, ll r, ll L, ll R, ll at, ll carry)
{

    if (l > R || r < L)
        return 0;

    if (L >= l && R <= r)
    {
        return tree[at].value + carry * (R - L + 1);
    }

    ll mid = (L + R) / 2;
    ll left = at * 2;
    ll right = at * 2 + 1;
    ll carryValue = carry + tree[at].lazy;
    ll x = query(l, r, L, mid, left, carryValue);
    ll y = query(l, r, mid + 1, R, right, carryValue);

    return x + y;
}

int main()
{

    ll t;
    cin >> t;
    while (t--)
    {
        

       

        ll n;
        cin >> n;

        for (ll i = 0; i <=n  * 4; i++)
        {
            tree[i].lazy = 0;
            tree[i].value = 0;
        }

        ll a[n];
        ll b[n];
        ll pre[n + 1];
        pre[0] = 0;
        pre[1] = 0;
        ll sum = 0;

        build(1, n, 1);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
            sum += b[i];

            pre[i + 1] = sum;
        }
       

        map<ll, ll> mp;

        for (int i = 0; i < n; i++)
        {

            ll ans = bs(a[i], i + 1, n, pre);
        //   cout<<ans<<" ans"<<endl;

            if (ans != 1e18)
            {

                ll sum = pre[ans - 1] - pre[i];
                ll rem = abs(sum - a[i]);
                mp[ans] += rem;
            }

            if (ans == 1e18)
            {
                // cout << i + 1 << " " << n << endl;
                update(i+1, n, 1, 1, n, 1);
            }
            else
            {
                // cout << i + 1 << " " << ans-1 << endl;

                update(i+1, ans-1, 1, 1, n, 1);
            }

            //   cout<<endl;
            //   cout<<ans<<" ans"<<endl;
        }

        for (ll i = 1; i <= n; i++)
        {
            cout << mp[i]+(query(i, i, 1, n, 1, 0)*b[i-1]) << " ";
        }

        cout << endl;
    }
}


