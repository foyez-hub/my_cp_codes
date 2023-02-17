#include<bits/stdc++.h>

using namespace std;


int main(){
    int n,m;
    cin>>n>>m;
    string a[n];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]=='C'){
                if(i-1>=0 && a[i-1][j]=='L'){
                    a[i][j] = 'L';
                }
                if(i+1<n && a[i+1][j]=='L'){
                    a[i][j] = 'L';
                }
                if(j-1>=0 && a[i][j-1]=='L'){
                    a[i][j] = 'L';
                }
                if(j+1<m && a[i][j+1]=='L'){
                    a[i][j] = 'L';
                }
            }
        }
    }
    int v[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           v[i][j] = 0;
        }
    }
    int count = 1;
    queue<pair<int,int>>q;
    pair<int,int> node;
    for(int i=0;i<n;i++){
        for(int i=0;i<n;i++){
            if(v[i][j]==0 && a[i][j]=='L'){
                 count++;
                 q.push({i,j});
                 while(!q.empty()){
                    auto node = q.front();
                    int x = node.first;
                    int y = node.second;
                    v[i][j] = 1;
                    if(x-1>=0 && a[x-1][y]=='L' && v[x-1][y]==0){
                       q.push({x-1,y});
                    }
                    else if(x+1<n && a[x+1][y]=='L' && v[x+1][y]==0){
                       q.push({x+1,y});
                    }
                    else if(y-1>=0 && a[x][y-1]=='L' && v[x][y-1]==0){
                        q.push({x,y-1});
                    }
                    else if(y+1<m && a[x][y+1]=='L' && v[x][y+1]==0){
                        q.push({x,y+1});
                    }
                 }
            }
        }
    }       
    
}
