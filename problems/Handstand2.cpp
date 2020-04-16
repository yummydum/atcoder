#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _GLIBCXX_DEBUG
#define rep(i, c) for (int i = 0; i < (int)c; i++)
#define debug(x) cout << #x << " = " << x << endl
#define print(x) cout << x << endl;

int main()
{
    int N;
    cin >> N;

    vector<vector<ll>> table(9, vector<ll>(9, 0));

    ll num = 0;
    for (int k = 1; k <= N; k++)
    {
        string k_str = to_string(k);
        int i = k_str.at(0) - '0';
        int j = k_str.at(k_str.size() - 1) - '0';
        if (j == 0)
        {
            continue;
        }
        table[i - 1][j - 1] += 1;
    }

    ll ans = 0;
    for (int i = 1; i <= N; i++)
    {
        string i_str = to_string(i);
        int l = i_str.at(0) - '0';
        int m = i_str.at(i_str.size() - 1) - '0';

        if (m == 0)
        {
            continue;
        }

        ans += table[m - 1][l - 1];
    }

    cout << ans << endl;
}
