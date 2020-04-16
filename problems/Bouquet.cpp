#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _GLIBCXX_DEBUG
#define rep(i, c) for (int i = 0; i < (int)c; i++)
#define debug(x) cout << #x << " = " << x << endl
#define print(x) cout << x << endl;
ll MOD = 1000000007;

ll modPow(ll a, ll n, ll p)
{
    if (n == 1)
        return a % p;
    if (n % 2 == 1)
        return (a * modPow(a, n - 1, p)) % p;
    long long t = modPow(a, n / 2, p);
    return (t * t) % p;
}

ll modInv(ll a, ll p)
{
    ll b = p, u = 1, v = 0;
    while (b)
    {
        ll t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= p;
    if (u < 0)
        u += p;
    return u;
}

int main()
{
    ll n, a, b;
    cin >> n >> a >> b;

    ll nCa = 1;
    ll nCb = 1;

    ll a_inv = 1;
    ll b_inv = 1;
    for (ll i = 0; i < a; i++)
    {
        nCa = (nCa * (n - i)) % MOD;
        a_inv = (a_inv * (i + 1)) % MOD;
    }

    for (ll i = 0; i < b; i++)
    {
        nCb = (nCb * (n - i)) % MOD;
        b_inv = (b_inv * (i + 1)) % MOD;
    }

    nCa = (nCa * modInv(a_inv, MOD)) % MOD;
    nCb = (nCb * modInv(b_inv, MOD)) % MOD;

    ll ans = (modPow(2, n, MOD) - 1 - nCa - nCb) % MOD;
    if (ans < 0)
    {
        ans += MOD;
    }
    cout << ans << endl;
}