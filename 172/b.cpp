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
    string S, T;
    cin >> S >> T;

    int ans = 0;
    rep(i, S.size())
    {
        if (S[i] != T[i])
        {
            ans++;
        }
    }

    cout << ans << endl;
}
