#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _GLIBCXX_DEBUG
#define rep(i, c) for (int i = 0; i < (int)c; i++)
#define debug(x) cout << #x << " = " << x << endl
#define print(x) cout << x << endl;
const ll MOD = 1000000007;

int A, B;

// これを線形時間で解くのが本質
bool win(int n, vector<ll> M)
{
    ll count = 0;
    rep(i, M.size())
    {
        if (M[i] > B * n)
        {
            double temp = M[i] - n * B;
            count += ceil(temp / (A - B));
        }
    }

    debug(count);
    debug(n);
    return count <= n;
}

int main()
{
    int N;
    cin >> N >> A >> B;
    vector<ll> M(N);

    rep(i, N)
    {
        cin >> M[i];
    }

    sort(M.begin(), M.end());

    ll upper = LLONG_MAX / 2;
    ll lower = 0;

    while (upper - lower > 1)
    {

        debug(upper);
        debug(lower);
        ll mid = (upper + lower) / 2;
        debug(mid);

        if (win(mid, M))
        {
            upper = mid;
        }
        else
        {
            lower = mid;
        }
    }

    cout << upper << endl;
}
