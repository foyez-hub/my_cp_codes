#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long ull;
#define pb push_back
struct node
{
    int score;
    map<int,bool> mp;
    int sz;
};

int main()
{

    int t;
    scanf("%d", &t);
    int ca = 1;
    while (t--)
    {
        int n;
        scanf("%d", &n);
        node a[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i].score);
            a[i].mp[i+1]=true;
            a[i].sz=1;

        }
        int q;
        scanf("%d", &q);
        while (q--)
        {
            int ty;
            scanf("%d",&ty);

            if (ty == 1)
            {
                int x, y;
                scanf("%d%d", &x, &y);
                if(x>y){
                    a[x-1].score+=a[y-1].score;
                    a[x-1].sz+=a[y-1].sz;
                    a[y-1].sz=0;
                    a[y-1].score=0;
                    

                    
                }
                else{

                    a[y-1].score+=a[x-1].score;
                    a[y-1].sz+=a[x-1].sz;
                    a[x-1].sz=0;
                    a[x-1].score=0;


                }
            }
            else if (ty == 2)
            {
                int x;
                scanf("%d",&x);
            }
            else
            {
                int x;
                scanf("%d",&x);

            }
        }
    }
}