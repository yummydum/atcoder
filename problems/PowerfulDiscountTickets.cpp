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
    ll N, M;
    cin >> N >> M;
    priority_queue<ll> A;

    ll max_elem = 0;
    rep(i, N)
    {
        ll temp;
        cin >> temp;
        A.push(temp);
    }

    rep(i, M)
    {
        ll maxPrice = A.top();
        A.pop();
        A.push(maxPrice / 2);
    }

    ll ans = 0;
    while (!A.empty())
    {
        ll p = A.top();
        A.pop();
        ans += p;
    }

    cout << ans << endl;
}
