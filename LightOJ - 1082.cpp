#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define mx 100001
int arr[mx];
int tree[mx * 3];
int inf=10000000;

void init(int node, int b, int e)
{


    if (b == e)
    {

        tree[node] = arr[b];

        return;
    }


    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);

    tree[node] = min(tree[Left] ,tree[Right]);
}

int Q(int node, int b, int e, int st, int ed)
{
    if (b >= st && e <= ed)
    {
        return tree[node];
    }
    else if (b > ed || e < st)
    {
        return inf;
    }

    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    return min(Q(Left, b, mid, st, ed),
    Q(Right, mid + 1, e, st, ed));
}

void show(int node, int b, int e)
{
    cout << b << " " << e << " val->" << tree[node] << endl;
    if (b == e)
    {
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    show(Left, b, mid);
    show(Right, mid + 1, e);
}
void solve(){

        int n,q;
        cin>>n>>q;
        for (int i =1; i <=n; i++)
        {
             cin>>arr[i];

        }

        init(1,1,n);
        // show(1,1,n);
       
        while (q--)
        {

            int l,r;
            cin>>l>>r;

            cout<<Q(1,1,n,l,r)<<endl;



            
        }
        

}



int main()
{


    int t;
    cin>>t;
    int ca=1;
    while (t--)
    {
       cout<<"Case "<<ca<<":"<<endl;

       solve();
       ca++;
    }
    
    return 0;

}
