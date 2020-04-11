#include <bits/stdc++.h>
using namespace std;

int main()
{

    // Get the inputs
    int H;
    int W;
    cin >> H >> W;
    vector<vector<char>> map(H, vector<char>(W));
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> map[i][j];
        }
    }

    // main
    vector<vector<int>> ans(H, vector<int>(W));
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (map[i][j] == '#')
            {
                for (int k = -1; k <= 1; k++)
                {
                    for (int l = -1; l <= 1; l++)
                    {

                        if (0 <= i + k && i + k < H && 0 <= j + l && j + l < W)
                        {
                            ans[i + k][j + l] += 1;
                        }
                    }
                }
            }
        }
    }

    //Print the result
    for (int i = 0; i < H; i++)
    {
        string ansrow = "";
        for (int j = 0; j < W; j++)
        {
            if (map[i][j] == '#')
            {
                ansrow += '#';
            }
            else
            {
                ansrow += char(ans[i][j] + '0');
            }
        }

        cout << ansrow << endl;
    }
}
