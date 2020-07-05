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
    ll N;
    cin >> N;

    ll ans = 0;
    map<ll, ll> M;
    for (ll i = 2; i <= N; i++)
    {

        if (M.count(i))
        {
            continue;
        }

        ll j = 1;
        while (pow(i, j) <= N)
        {
            M[pow(i, j)] = j;
        }

        for (auto p : M)
        {
            ll temp =
                if ()
            {
                break;
            }
        }
    }

    cout << ans << endl;
}
