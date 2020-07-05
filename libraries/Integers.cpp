#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _GLIBCXX_DEBUG
#define rep(i, c) for (int i = 0; i < (int)c; i++)
#define debug(x) cout << #x << " = " << x << endl
#define print(x) cout << x << endl;
const ll MOD = 1000000007;

bool isPrime(ll N)
{
    if (N == 1)
        return false;
    for (ll i = 2; i * i <= N; i++)
    {
        if (N % i == 0)
        {
            return false;
        }
    }

    return true;
}

vector<ll> enum_divisors(ll N)
{
    vector<ll> res;
    for (ll i = 1; i * i <= N; i++)
    {
        if (N % i == 0)
        {
            res.push_back(i);
            if (N / i != i)
                res.push_back(N / i);
        }
    }
    // 小さい順に並び替える
    sort(res.begin(), res.end());
    return res;
}

vector<pair<ll, ll>> factorize(ll N)
{
    vector<pair<ll, ll>> res;
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

        res.push_back({i, ex});
    }

    // 最後に残った数
    if (N != 1)
        res.push_back({N, 1});
    return res;
}
