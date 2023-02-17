#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long ull;
#define pb push_back
map<int, int> parent;
map<int,int> index;



int find(int v)
{
    if ((v == parent[v]))
        return v;

    return parent[v]=find(parent[v]);
}
void Union(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        if(index[a]<=index[b]){
           parent[b] = a;
        }
        else{
            
            parent[a] = b;

        }
        
    }
}

void makeP(int v)
{
    parent[v] =v;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        parent.clear();
        index.clear();
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            makeP(i);
        }
      
         for (int k =1; k <=m; k++)
         {
            
         
         
            int ty, a, b;
            cin >> ty >> a >> b;
          
            if (ty == 1)
            {
                if(index.find(a)==index.end()) {
                    index[a]=k;
                }
                if(index.find(b)==index.end()) index[b]=k;
                 Union(a,b);
            }
            else
            {
                // cout<<find(a)<<" "<<find(b)<<endl;

                if (find(a) == find(b))
                {
                    // cout << "Yes" << endl;
                    cout<<max(index[a],index[b])<<endl;
                }
                else cout<<-1<<endl;
                    // cout << "No" << endl;
            }


         }
        
    }
}
