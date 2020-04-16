#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _GLIBCXX_DEBUG
#define rep(i, c) for (int i = 1; i < (int)c; i++)
#define debug(x) cout << #x << " is " << endl

int main()
{
    int K;
    cin >> K;

    ll ans = 0;
    rep(a, K + 1)
    {
        rep(b, K + 1)
        {
            rep(c, K + 1)
            {
                // cout << __gcd(__gcd(a, b), c) << endl;
                ans += __gcd(__gcd(a, b), c);
            }
        }
    }

    cout << ans << endl;
}
