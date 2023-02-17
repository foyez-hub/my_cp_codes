#include <bits/stdc++.h>
using namespace std;

int Edit_Distance(string s1, string s2)
{

    int mat[s1.size()][s2.size()];

    for (int i = 0; i <= s1.size(); i++)
    {

        for (int j = 0; j <= s2.size(); j++)
        {

            if (i == 0)
            {
                mat[i][j] = j;
            }
            else if (j == 0)
            {
                mat[i][j] = i;
            }
            else if (s1[i - 1] == s2[j - 1])
            {
                mat[i][j] = mat[i - 1][j - 1];
            }
            else
            {
                mat[i][j] = 1 + min(mat[i][j - 1], min(mat[i - 1][j], mat[i - 1][j - 1]));
            }
        }
    }

    return mat[s1.size()][s2.size()];
}

int main()
{

    cout << "Input 2 strings " << endl;
    string s1, s2;
    cin >> s1 >> s2;

    int ans = Edit_Distance(s1, s2);

    cout << "Edit Distance is-> " << ans << endl;

    return 0;
}
