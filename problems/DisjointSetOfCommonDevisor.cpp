#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _GLIBCXX_DEBUG
#define rep(i, c) for (int i = 0; i < (int)c; i++)
#define debug(x) cout << #x << " = " << x << endl
#define print(x) cout << x << endl;
const ll MOD = 1000000007;

map<ll, ll> factorize(ll N)
{
    map<ll, ll> res;
    for (ll i = 2; i * i <= N; i++)
    {
        if (N % i != 0)
            continue;
        ll ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % i == 0)
        {
            ++ex;
            N /= i;
        }

        res[i] = ex;
    }

    // 最後に残った数
    if (N != 1)
        res[N] = 1;
    return res;
}

int main()
{
    ll A, B;
    cin >> A >> B;

    auto devA = factorize(A);
    auto devB = factorize(B);

    ll ans = 0;
    for (auto f : devA)
    {
        if (devB.count(f.first))
        {
            ans++;
        }
    }

    cout << ans + 1 << endl;
}
