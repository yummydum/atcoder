#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _GLIBCXX_DEBUG
#define rep(i, c) for (int i = 0; i < (int)c; i++)
#define debug(x) cout << #x << " = " << x << endl
#define print(x) cout << x << endl;
const ll MOD = 1000000007;

int main()
{
    int H, W, K;
    cin >> H >> W >> K;
    vector<vector<int>> C(H, vector<int>(W, 0));
    ll A = 0;

    rep(i, H)
    {
        rep(j, W)
        {
            char c;
            cin >> c;
            if (c == '.')
            {
                C[i][j] = 0;
            }
            else
            {
                C[i][j] = 1;
            }
        }
    }

    for (int bit = 0; bit < (1 << H); ++bit)
    {
        for (int bit2 = 0; bit2 < (1 << W); ++bit2)
        {
            vector<vector<int>> B = C;
            for (int i = 0; i < H; ++i)
            {
                for (int j = 0; j < W; ++j)
                {
                    if (((bit & (1 << i)) > 0) || ((bit2 & (1 << j)) > 0))
                    {
                        B[i][j] = 0;
                    }
                }
            }

            int temp = 0;
            rep(l, H)
            {
                rep(m, W)
                {
                    temp += B[l][m];
                }
            }

            if (temp == K)
            {
                A++;
            }
        }
    }

    cout << A << endl;
}