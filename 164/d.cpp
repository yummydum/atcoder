#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _GLIBCXX_DEBUG
#define rep(i, c) for (int i = 0; i < (int)c; i++)
#define debug(x) cout << #x << " = " << x << endl
#define print(x) cout << x << endl;
const ll MOD = 1000000007;

ll modPow(ll a, ll n, ll p)
{
    if (n == 1)
        return a % p;
    if (n % 2 == 1)
        return (a * modPow(a, n - 1, p)) % p;
    ll t = modPow(a, n / 2, p);
    return (t * t) % p;
}

int main()
{
    string S;
    cin >> S;

    ll ans = 0;
    ll now = 0;
    for (char i : S)
    {
        now *= 10;
        int temp = i - '0';
        now += temp;
        now %= 2019;

        debug(now);

        if (now % 2019 == 0)
        {
            ans = 2 * ans + 1;
        }
    }

    cout << ans << endl;
}
