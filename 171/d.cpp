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
    map<ll, ll> A;
    ll S = 0;
    rep(i, N)
    {
        ll temp;
        cin >> temp;
        if (!A.count(temp))
        {
            A[temp] = 0;
        }
        A[temp]++;
        S += temp;
    }

    ll Q;
    cin >> Q;
    rep(i, Q)
    {
        ll b, c;
        cin >> b >> c;
        S += (c - b) * A[b];

        if (!A.count(c))
        {
            A[c] = 0;
        }

        ll temp = A[b];
        A[c] += temp;
        A[b] = 0;
        cout << S << endl;
    }
}
