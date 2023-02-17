#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long ull;
#define pb push_back

int vis[1000][1000];

char mat[1000][1000];
int deg[1000][1000];

isvalid(int x, int y, int r, int c)
{

   if (x < 0 || x >= r || y < 0 || y >= c || vis[x][y] == 1 || mat[x][y] == '.')
   {
      return false;
   }

   return true;
}

int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int c3 = 0;
int c4 = 0;
void dfs(int i, int j, int r, int c)
{

   if (deg[i][j] == 3)
   {
      c3++;
   }
   if (deg[i][j] == 4)
   {
      c4++;
   }

   vis[i][j] = 1;

   for (int k = 0; k < 8; k++)
   {

      int X = dx[k] + i;
      int Y = dy[k] + j;

      if (isvalid(X, Y, r, c))
      {
         deg[i][j]++;

         dfs(X, Y, r, c);
      }
   }
}

int main()
{

   ifstream fin("votes.in");

   int t;
   // cin >> t;
   fin>>t;

   while (t--)
   {
      for (int i = 0; i < 1000; i++)
      {
         for (int j = 0; j < 1000; j++)
         {
            vis[i][j] = 0;
            deg[i][j] = 0;
         }
      }

      int r, c;
      // cin >> r >> c;
      fin>>r>>c;


      for (int i = 0; i < r; i++)
      {
         for (int j = 0; j < c; j++)
         {
            // cin >> mat[i][j];
            fin>>mat[i][j];
         }
      }

      for (int i = 0; i < r; i++)
      {
         for (int j = 0; j < c; j++)
         {
            if (mat[i][j] == '#')
            {

               for (int k = 0; k < 8; k++)
               {

                  int x = dx[k] + i;
                  int y = dy[k] + j;

                  if (x >= 0 && x <= r && y >= 0 && y <= c && mat[x][y] == '#')
                  {
                     deg[i][j]++;
                  }
               }
            }
         }
      }

      // for (int i = 0; i < r; i++)
      // {
      //    for (int j = 0; j < c; j++)
      //    {
      //       cout << deg[i][j] << " ";
      //    }
      //    cout << endl;
      // }

      int cnt = 0;
      int cy = 0;
      int ch = 0;
      c3 = 0;
      c4 = 0;

      for (int i = 0; i < r; i++)
      {
         for (int j = 0; j < c; j++)
         {
            if (vis[i][j] == 0 && mat[i][j] == '#')
            {

               cnt++;
               dfs(i, j, r, c);

               if (c4 > 1)
               {

                  ch++;
               }
               else if (c3 == 1)
               {

                  cy++;
               }

               c3 = 0;
               c4 = 0;
            }
         }
      }

      int cm = cnt - cy - ch;

      cout << ch << " " << cm << " " << cy << endl;
   }
}
