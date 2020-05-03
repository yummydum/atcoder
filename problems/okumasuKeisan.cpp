#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _GLIBCXX_DEBUG
#define rep(i, c) for (int i = 0; i < (int)c; i++)
#define debug(x) cout << #x << " = " << x << endl
#define print(x) cout << x << endl;
const ll MOD = 1000000007;

ll prodUnderX(ll X, vector<ll> A, vector<ll> B)
{
    ll ans = 0;
    for (ll a : A)
    {
        ans += (upper_bound(B.begin(), B.end(), X / a) - B.begin());
    }
    return ans;
}

int main()
{
    int N, K;
    cin >> N >> K;
    vector<ll> A(N);
    vector<ll> B(N);

    ll max_a = -1;
    rep(i, N)
    {
        cin >> A[i];
        max_a = max(A[i], max_a);
    }
    rep(i, N)
    {
        cin >> B[i];
    }

    sort(B.begin(), B.end());

    ll upper = max_a * B[B.size() - 1];
    ll lower = 0;
    while (upper - lower > 1)
    {
        ll mid = (upper + lower) / 2;

        ll res = prodUnderX(mid, A, B);
        if (res >= K)
        {
            upper = mid;
        }
        else if (res < K)
        {
            lower = mid;
        }
    }

    cout << upper << endl;
}
