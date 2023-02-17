#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long ull;
#define pb push_back

vector<vector<int> > adj(1000);
vector<int> colors(110);
vector<int> vis(110,0);

void dfs(int node,int color,int parent){

    cout<<node<<"<-n    color->"<<color<<endl;

    colors[node]=color;
    vis[node]=1;
    for (int i = 0; i < adj[node].size(); i++)
    {
        int child=adj[node][i];
        if(vis[child]==0){
            dfs(child,color^1,node);


        }
        else{
            cout<<"YES  "<<child<<endl;

        }
    }
    

}




int main(){
    int t;
    cin>>t;
    while(t--){

    vis.clear();
    adj.clear();
    colors.clear();


    int nodes,edges;
    cin>>nodes>>edges;

    for (int i = 0; i < edges; i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }


    dfs(1,1,-1);

    vector<int> ans;
    for (int i = 0; i < 110; i++)
    {
        if(colors[i]==1){
            ans.pb(i);
        }
    }
    cout<<ans.size()<<endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    
    



    }
}