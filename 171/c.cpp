
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _GLIBCXX_DEBUG
#define rep(i, c) for (int i = 0; i < (int)c; i++)
#define debug(x) cout << #x << " = " << x << endl
#define print(x) cout << x << endl;
const ll MOD = 1000000007;

string alphabet = "abcdefghijklmnopqrstuvwxyz";

int main()
{
    ll N;
    cin >> N;

    ll l = 0;
    ll M = 0;
    for (ll i = 1; i < 100; i++)
    {
        l++;
        if (M + pow(26, i) >= N)
        {
            break;
        }
        else
        {
            M += pow(26, i);
        }
    }

    // kth num in l digit base-26
    ll k = N - M - 1;
    string ans = "";
    rep(i, l)
    {
        if (i == l - 1)
        {
            ans += alphabet[k];
        }
        else
        {
            ll d = pow(26, l - 1 - i);
            ll q = k / d;
            ans += alphabet[q];
            k -= d * q;
        }
    }

    cout << ans << endl;
}
