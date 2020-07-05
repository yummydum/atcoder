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
    ll N, M, K;
    cin >> N >> M >> K;

    queue<ll> A, B;

    ll cum = 0;
    rep(i, N)
    {
        ll a;
        cin >> a;
        cum += a;
        A.push(cum);
    }

    cum = 0;
    rep(i, M)
    {
        ll b;
        cin >> b;
        cum += b;
        B.push(cum);
    }

    ll ans = 0;
    ll A_cum = 0;
    ll B_cum = 0;

    while (K >= A.front() or K >= B.front())
    {
        if (A.front() <= B.front())
        {
            K -= A.front();
            A.pop();
            A.front() -= A.pop;
        }
        else
        {
            K -= B.front();
            B.pop();
        }

        ans++;
    }

    cout << ans << endl;
}
