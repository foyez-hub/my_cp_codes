#include<bits/stdc++.h>
using namespace std;



void bfs(){
   int n;
    // scanf("%d",&n);
    cin>>n;
   vector<vector<int> >grp(1000000);
   bool isVisited[1000000];
   for(int i=0;i<=n;i++){

      isVisited[i] = false;

   }
   

    for(int i=0;i<n-1;i++){
        int u,v;
        // scanf("%d%d",&u,&v);
        cin>>u>>v;
        grp[u].push_back(v);
        grp[v].push_back(u);

    }
    
    bool cond = true;

        queue<pair<int,bool>>q;
        pair<int,bool>node;
        node = {1,true};
        q.push(node);


       while(!q.empty()){

        node = q.front();
        int parent = node.first;
        cond = node.second;
        q.pop();


        isVisited[parent] = true;

        for(int i = 0;i<grp[parent].size();i++){
            int it = grp[parent][i];
            if(isVisited[it]==false){
                
                if(cond){
                   cout<<parent<<" "<<it<<endl;
                   q.push({it,false});
                }else{
                    cout<<it<<" "<<parent<<endl;
                    q.push({it,true});
                }
            }
        }

        

    }

}
    




int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    // scanf("%d",&t);
    cin>>t;
    int cs = 1;
    while (t--)
    {
        cout<<"Case "<<cs<<":"<<endl;
        bfs();
        cs++;
    }

}
