#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _GLIBCXX_DEBUG
#define rep(i, c) for (int i = 0; i < (int)c; i++)
#define debug(x) cout << #x << " = " << x << endl
#define print(x) cout << x << endl;
const ll MOD = 1000000007;

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

ll modComb(ll n, ll r, ll p)
{
    ll ans = 1;
    for (ll i = 1; i <= r; i++)
    {
        ans = (ans * (n - i + 1)) % p;
        ans = (ans * modInv(i, p)) % p;
    }

    return ans;
}

int main()
{
    int X, Y;
    cin >> X >> Y;

    if ((X + Y) % 3)
    {
        cout << 0 << endl;
        return 0;
    }

    if (Y > 2 * X)
    {
        cout << 0 << endl;
        return 0;
    }

    if (X > 2 * Y)
    {
        cout << 0 << endl;
        return 0;
    }

    ll stairs = (X + Y) / 3;
    ll ans = modComb(stairs, X - stairs, MOD);
    cout << ans << endl;
}
