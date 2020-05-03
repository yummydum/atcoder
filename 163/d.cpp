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
    int N, K;
    cin >> N >> K;
    vector<int> cumalative(N);

    rep(i, N + 1)
    {
        if (i == 0)
        {
            cumalative[i] = 0;
        }
        else
        {
            cumalative[i] = cumalative[i - 1] + i;
            cumalative[i] = cumalative[i] % MOD;
        }
    }

    ll ans = 0;
    for (int i = K; i <= N + 1; i++)
    {
        ans += cumalative[N] - cumalative[N - i] - cumalative[i - 1] + 1;
        ans = ans % MOD;
    }

    if (ans < 0)
    {
        ans += MOD;
    }
    cout << ans << endl;
}