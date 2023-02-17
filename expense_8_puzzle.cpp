#include <bits/stdc++.h>
using namespace std;

vector< vector<int> > goal{
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 0}};
int times=0;
map< vector< vector<int> > , bool> vis;

bool isgoal(vector< vector<int> > mat)
{

    int cnt = 0;

    for (int l = 0; l < 3; l++)
    {
        for (int r = 0; r < 3; r++)
        {
            cout<<mat[l][r]<<" ";
            if (mat[l][r] != goal[l][r])
            {
                cnt++;
            }
        }
        cout<<endl;
    }
    cout<<endl;

    if (cnt == 0)
    {
        return true;
    }
}

bool isvalid(int x, int y, vector<vector<int> > mat)
{

    if (x < 0 || x >= 3 || y < 0 || y >= 3 || vis[mat]==false || isgoal(mat)==false )
    {
        return false;
    }
    return true;
}

// Up -Left -Down- Right

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(int i, int j, vector<vector<int> > mat,int depth)
{

    if(depth>10){

        return;
    }

    vis[mat]=true;

    for (int k = 0; k < 4; k++)
    {
        int X = dx[k] + i;
        int Y = dy[k] + j;

        if ( isvalid(X, Y,mat) )
        {
            vector<vector<int> > tem=mat;

            swap(tem[i][j], tem[X][Y]);

            dfs(X, Y, tem,depth+1);
        }
    }
}

int main()
{

    vector<vector<int> > mat{
        {2, 3, 6},
        {1, 0, 7},
        {4, 8, 5}};

    dfs(1,1,mat,0);
}
