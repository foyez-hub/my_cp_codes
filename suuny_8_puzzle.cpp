#include <bits/stdc++.h>

using namespace std;

void printNode(vector<vector<int>>node){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<node[i][j]<<" ";
		}cout<<endl;
	}
	cout<<endl;
}


void bfs(vector<vector<int>>maze, vector<vector<int>>goal){

    queue<pair<vector<vector<int>>,int>> q;
    map<vector<vector<int>>,bool>isVisited;
    pair<vector<vector<int>>,int> pr;
    vector<vector<int>> node;
    q.push({maze,0});
    int brance = 0;
    int foundAt = 0;
    while(!q.empty()){
        pr = q.front();
        node = pr.first;
        brance = pr.second;
        q.pop();
        isVisited[node] = true;

        int i=0,j=0;
        int temp;
        if(node==goal){
          foundAt = brance;
        }
       // printNode(node);
        for(i=0;i<3;i++){
        	bool cond =false;
        	for(j=0;j<3;j++){
        		if(node[i][j]==0){
        			cond = true;
        			break;
        		}
        	}
        	if(cond){
        			break;
        	}
        }
        cout<<i<<" "<<j<<endl<<endl;;
        if(i-1>=0){
           temp = node[i-1][j];
           node[i-1][j] = 0;
           node[i][j] = temp;
           auto it = isVisited.find(node);
           if(it==isVisited.end()){
           	 isVisited[node] = false;
           	 q.push({node,brance+1});
           }
           node[i][j] = 0;
           node[i-1][j] = temp;
        }
        if(i+1<3){
           temp = node[i+1][j];
           node[i+1][j] = 0;
           node[i][j] = temp;
           auto it = isVisited.find(node);
           if(it==isVisited.end()){
           	 isVisited[node] = false;
           	 q.push({node,brance+1});
           }
           node[i][j] = 0;
           node[i+1][j] = temp;
        }
        if(j-1>=0){
           temp = node[i][j-1];
           node[i][j-1] = 0;
           node[i][j] = temp;
           auto it = isVisited.find(node);
           if(it==isVisited.end()){
           	 isVisited[node] = false;
           	 q.push({node,brance+1});
           }
           node[i][j] = 0;
           node[i][j-1] = temp;
        }
        if(j+1<3){
           temp = node[i][j+1];
           node[i][j+1] = 0;
           node[i][j] = temp;
           auto it = isVisited.find(node);
           if(it==isVisited.end()){
           	 isVisited[node] = false;
           	 q.push({node,brance+1});
           }
          node[i][j] = 0;
           node[i][j+1] = temp;
        }
    }
    cout<<"Total brance: "<<brance<<" -- Found At: "<<foundAt<<endl;
}



int main(){
   vector<vector<int>> maze,goal;

   for(int i=0;i<3;i++){
       vector<int>temp;
       for(int j=0;j<3;j++){
       	 int num;cin>>num;
       	 temp.push_back(num);
       }
       maze.push_back(temp);
   }
   for(int i=0;i<3;i++){
       vector<int>temp;
       for(int j=0;j<3;j++){
       	 int num;cin>>num;
       	 temp.push_back(num);
       }
       goal.push_back(temp);
   }

   bfs(maze,goal);

}
