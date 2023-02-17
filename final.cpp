#include <bits/stdc++.h>
using namespace std;
map<int,bool> vis;
map<int,vector<int> > adj;
int nodesCount;
bool dfs(int src){
    cout<<src<<" parent"<<endl;
    nodesCount++;
    vis[src]=true;
    for(int i=0;i<adj[src].size();i++){
        int child=adj[src][i];
        if(!vis[child]){
            dfs(child);

        }

    }

}

int main()
{
    int nodes;
    int edges;
    cin>>nodes>>edges;
    for (int i = 0; i <edges; i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);

    }
    int C;
    cin>>C;
    vector<int> cites;
    for (int i = 0; i < C; i++)
    {
        int cc;
        cin>>cc;
        cites.push_back(cc);
    }
    
    bool Exist=false;
    for (int i = 0; i < C; i++)
    {
        cout<<cites[i]<<" ";
    }
    cout<<endl;
    
    for (int i = 0; i <C; i++)
    {
        vis.clear();
        nodesCount=0;

        dfs(cites[i]);
        if(nodesCount==nodes){
            Exist=true;
            break;
        }

    }
    
    if(Exist){
        cout<<"Exist!"<<endl;
    }
    else cout<<"Not Exist!"<<endl;
    

    
   
}
