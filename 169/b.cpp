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
    int N;
    cin >> N;
    ll ans = 1;
    rep(i, N)
    {
        ll temp;
        cin >> temp;
        ans *= temp;
        if (ans > (ll)1000000000000000000)
        {
            cout << -1 << endl;
            return 0;
        }
    }

    if (ans > (ll)1000000000000000000)
    {
        cout << "-1" << endl;
        return 0;
    }
    cout << ans << endl;
}
